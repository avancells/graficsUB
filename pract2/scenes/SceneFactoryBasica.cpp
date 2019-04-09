#include "SceneFactoryBasica.h"



SceneFactoryBasica::SceneFactoryBasica()
{

}

Scene *SceneFactoryBasica::createScene() {
    Scene *scene = new Scene();

    QString s0("://resources/models/sphere0.obj");

    //Object * obj = new Object(1000000, s0);
    //scene->addObject(obj);

    QString s1("://resources/other models/landlord.obj");
    Object * obj1 = new Object(1000000, s1);
    obj1->setTexture(new QOpenGLTexture(QImage("://resources/other models/LandLord_diffuse.png").mirrored()));

    Animation *anim = new Animation();

    anim->transf = new Rotate(10.0,vec3(0.3,1,0));

    obj1->addAnimation(anim);

    Animation *anim1 = new Animation();

    //anim1->transf = new TranslateG(vec3(0.2,0.2,0));

    obj1->addAnimation(anim1);

    //scene->addObject(obj1);


    scene->addLight(new Light(Puntual));
    //scene->addLight(new Light(Puntual));
    return scene;
}



