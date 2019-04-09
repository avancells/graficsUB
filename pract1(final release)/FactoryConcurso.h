#ifndef FACTORYCONCURSO_H
#define FACTORYCONCURSO_H


#include "SceneFactory.h"


class FactoryConcurso : public SceneFactory
{
public:
    FactoryConcurso();
    virtual Scene *createScene();
private:
    void video(Scene *s);
};

#endif // FACTORYCONCURSO_H
