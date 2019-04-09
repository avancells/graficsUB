#ifndef SCENEFASE2MIRALL_H
#define SCENEFASE2MIRALL_H


#include "SceneFactory.h"

class SceneFase2Mirall : public SceneFactory
{
public:
    SceneFase2Mirall();

    virtual Scene *createScene();

private:
    void EscenaMirall(Scene *s);
};
#endif // SCENEFASE2MIRALL_H
