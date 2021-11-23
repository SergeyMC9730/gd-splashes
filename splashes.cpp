#include "splashes.hpp"


const char* Splashes::get() {
    srand(time(0));
    return splashText[rand() % splashSize];
}
float Splashes::get(const char* text) {
    float a = (1.000f / strlen(text) * 10);
    if (a > 1.4f) a = 1.4f;
    if (a < 0.0f || a == 0.0f) a = 1.0f;

    if (strlen(text) < 5 && a < 0.2) a = 0.9f;
    
    return a;
}