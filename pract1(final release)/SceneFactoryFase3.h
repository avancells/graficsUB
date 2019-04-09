#ifndef SCENEFACTORYFASE3_H
#define SCENEFACTORYFASE3_H

#include "SceneFactory.h"

class SceneFactoryFase3 : public SceneFactory
{
public:
    SceneFactoryFase3();

    virtual Scene *createScene();

private:
    void video(Scene *s);

};

#endif // SCENEFACTORYFASE3_H
