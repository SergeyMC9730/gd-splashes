#include "win32cac.h"

class Hash {
public:
    static unsigned int rndnums[256];
    static signed int get(const char* string);
    static const char* get(const char* string, bool v);
};