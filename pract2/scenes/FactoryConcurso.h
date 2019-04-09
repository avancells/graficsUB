#ifndef FACTORYCONCURSO_H
#define FACTORYCONCURSO_H

#include "SceneFactory.h"

class FactoryConcurso : public SceneFactory
{
public:
    FactoryConcurso();

    Scene *createScene();

};

#endif // FACTORYCONCURSO_H
