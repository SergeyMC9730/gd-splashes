#pragma once

#include "win32cac.h"

class NetworkGD {
protected:
    //1
public:
    static void debug_write(const char *url, const char *filename);
    static void debug_write(const char* url);
    static size_t write(void* pointer, size_t size, size_t nmemb, FILE* stream);
    static size_t memwrine(void* c, size_t size, size_t nmemb, void* p);
    static std::string cmdcheck(int cmdid);
};
