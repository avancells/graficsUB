#include "TranslateG.h"

TranslateG::TranslateG(vec3 trasl): traslation(trasl)
{
    matTG = Translate(traslation);
}

TranslateG::~TranslateG()
{

}

