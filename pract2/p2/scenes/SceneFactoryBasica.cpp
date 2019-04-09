#include "SceneFactoryBasica.h"

SceneFactoryBasica::SceneFactoryBasica()
{

}

Scene *SceneFactoryBasica::createScene() {
    Scene *scene = new Scene();

    QString s0("://resources/models/sphere0.obj");

    Object * obj = new Object(100000, s0);
    scene->addObject(obj);

    QString s1("://resources/models/sphere1.obj");
    Object * obj1 = new Object(100000, s1);
    scene->addObject(obj1);

    return scene;
}



