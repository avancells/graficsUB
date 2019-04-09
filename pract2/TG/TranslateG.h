#ifndef TRANSLATEG_H
#define TRANSLATEG_H

#include "TG.h"

using namespace Common;

class TranslateG : public TG
{
public:
    vec3 traslation;
    TranslateG(vec3 trasl);
    ~TranslateG();
};

#endif // TRANSLATEG_H
