#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "Scene.h"

class SceneFactory
{
public:
    SceneFactory();
    virtual Scene *createScene() = 0;
    virtual ~SceneFactory();
};

#endif // SCENEFACTORY_H
