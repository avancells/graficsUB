#ifndef SCENEFACTORYBASICA_H
#define SCENEFACTORYBASICA_H

#include "SceneFactory.h"

class SceneFactoryBasica : public SceneFactory
{
public:
    SceneFactoryBasica();

    Scene *createScene();

};

#endif // SCENEFACTORYBASICA_H
