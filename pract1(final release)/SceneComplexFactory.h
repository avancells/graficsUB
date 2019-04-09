#ifndef SCENECOMPLEXFACTORY_H
#define SCENECOMPLEXFACTORY_H


#include "SceneFactory.h"


class SceneComplexFactory : public SceneFactory
{
public:
    SceneComplexFactory();

    virtual Scene *createScene();
};

#endif // SCENECOMPLEXFACTORY_H




