#ifndef REALISTICSCENEFACTORY_H
#define REALISTICSCENEFACTORY_H

#include "SceneFactory.h"


class RealisticSceneFactory : public SceneFactory
{
public:
    RealisticSceneFactory();
    void realisticScene(Scene *s);
    virtual Scene *createScene();
};



#endif // REALISTICSCENEFACTORY_H
