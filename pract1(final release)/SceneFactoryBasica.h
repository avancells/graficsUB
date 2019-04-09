#ifndef SCENEFACTORYBASICA_H
#define SCENEFACTORYBASICA_H

#include "SceneFactory.h"

class SceneFactoryBasica : public SceneFactory
{
public:
    SceneFactoryBasica();

    virtual Scene *createScene();

private:
    void OneSphere(Scene *s);
    void MultipleSphere(Scene *s);
    void fase2(Scene *s);
};

#endif // SCENEFACTORYBASICA_H
