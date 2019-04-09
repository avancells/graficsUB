#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "Scene.h"

#include "./TG/TranslateG.h"
#include "./TG/Rotate.h"
#include "./TG/RotateBoundary.h"
#include "./TG/ScaleBoundary.h"
#include "./TG/ScaleG.h"

class SceneFactory
{
public:
    SceneFactory();
    virtual Scene *createScene() = 0;
    virtual ~SceneFactory();
};

#endif // SCENEFACTORY_H
