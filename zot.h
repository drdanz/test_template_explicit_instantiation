#ifndef ZOT_H
#define ZOT_H

#include "zot_export.h"

class ZOT_EXPORT Zot
{
public:
    Zot() = delete;
    Zot(int n);
    int zot1();
    int zot2();
    int zot3() { return {}; }
};

#endif // ZOT_H
