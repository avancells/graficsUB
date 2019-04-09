#ifndef SCENEFACTORYFASE2_H
#define SCENEFACTORYFASE2_H

#include "SceneFactory.h"

class SceneFactoryFase2 : public SceneFactory
{
public:
    SceneFactoryFase2();

    virtual Scene *createScene();

private:
    void TwoSphere(Scene *s);
    void MultipleSphere(Scene *s);
    void fase2(Scene *s);
    void EscenaObj(Scene *s);
};

#endif // SCENEFACTORYFASE2_H

