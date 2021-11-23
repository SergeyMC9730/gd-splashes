#include "net.hpp"

void NetworkGD::debug_write(const char* url, const char* filename)
{
	FILE* test;
	fopen_s(&test, filename, "wb");

	CURL* curli = curl_easy_init();
	curl_easy_setopt(curli, CURLOPT_URL, url);
	curl_easy_setopt(curli, CURLOPT_WRITEFUNCTION, NetworkGD::write);
	curl_easy_setopt(curli, CURLOPT_WRITEDATA, test);
	curl_easy_setopt(curli, CURLOPT_CONNECTTIMEOUT, 30);
	curl_easy_perform(curli);
	curl_easy_cleanup(curli);
	curli = NULL;

	fclose(test);
}

void NetworkGD::debug_write(const char* url)
{
	debug_write(url, "debug.txt");
}

size_t NetworkGD::write(void* pointer, size_t size, size_t nmemb, FILE* stream)
{
	return fwrite(pointer, size, nmemb, stream);
}

size_t NetworkGD::memwrine(void* c, size_t size, size_t nmemb, void* p)
{
	size_t a = size * nmemb;
	std::string& mem = *static_cast<std::string*>(p);
	mem.append(static_cast<char*>(c), a);
	return a;
}

std::string NetworkGD::cmdcheck(int cmdid){
	CURL* curl_instance = curl_easy_init();
	std::string s;
	
	switch (cmdid) {
	case 0: {
		curl_easy_setopt(curl_instance, CURLOPT_URL, "http://www.c418.tk/gdps/devpassword0.txt");
		break;
	}
	case 1: {
		curl_easy_setopt(curl_instance, CURLOPT_URL, "http://www.c418.tk/gdps/ddevpassword.txt");
		break;
	}
	default: {
		while (true);
		break;
	}
	}
	curl_easy_setopt(curl_instance, CURLOPT_WRITEFUNCTION, memwrine);
	curl_easy_setopt(curl_instance, CURLOPT_WRITEDATA, &s);
	curl_easy_setopt(curl_instance, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36 Edg/95.0.1020.53");
	curl_easy_setopt(curl_instance, CURLOPT_VERBOSE, 1L);

	CURLcode result = curl_easy_perform(curl_instance);

	return s;
}

