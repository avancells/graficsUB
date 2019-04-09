#ifndef SCENESIMPLEFACTORY_H
#define SCENESIMPLEFACTORY_H

#include "SceneFactory.h"


class SceneSimpleFactory : public SceneFactory
{
public:
    SceneSimpleFactory();

    virtual Scene *createScene();

private:
    void TwoPlanes(Scene *s);
    void TwoTriangles(Scene *s);
    void Boundary(Scene *s);
};

#endif // SCENESIMPLEFACTORY_H
