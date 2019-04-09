#include "main.h"

// Metode principal del programa

int main(int argc, char **argv) {

    // inicialitza l'escena: el constructor de l'escena s'encarrega de
    // crear els objectes i les llums


    //SceneFactory *scFac = new SceneFactoryBasica(); //Fase 0
    //SceneFactory *scFac = new SceneSimpleFactory(); //Fase 1
    //SceneFactory *scFac = new SceneComplexFactory(); //Fase 1 d
    //SceneFactory *scFac = new SceneFactoryFase2(); //Fase 2
    //SceneFactory *scFac = new SceneFase2Mirall();
    //SceneFactory *scFac = new RealisticSceneFactory();
    //SceneFactory *scFac = new SceneFactoryFase3(); //Fase 3
    SceneFactory *scFac = new FactoryConcurso(); //Concurs


    Scene *scene = scFac->createScene();
#ifdef GLUT
    Render *render = new RayTracingGLU(scene);
#else
#ifndef ANIM
    Render *render = new RayTracingPPM(scene);
#else
    Render *render = new AnimPPM(scene);
#endif
#endif

    render->startRendering(argc, argv);

    return(0);
}
