#include "FactoryConcurso.h"

FactoryConcurso::FactoryConcurso()
{

}


Scene *FactoryConcurso::createScene() {
    Scene *scene = new Scene();

    //shrek
    QString shrekBodyObj("://resources/other models/shrekBody.obj");
    Object * shrekBody = new Object(1000000, shrekBodyObj);
    shrekBody->setTexture(new QOpenGLTexture(QImage("://resources/other models/Shrek.png").mirrored()));

    QString shrekShirtObj("://resources/other models/shrekRoba.obj");
    Object * shrekShirt = new Object(1000000, shrekShirtObj);
    shrekShirt->setTexture(new QOpenGLTexture(QImage("://resources/other models/shrekshirt.png").mirrored()));

    shrekShirt->aplicaTG(new ScaleG(2.0));
    shrekBody->aplicaTG(new ScaleG(2.0));

    Animation *shrek1 = new Animation();
    Animation *shrek2 = new Animation();
    Animation *shrek3 = new Animation();
    Animation *shrek4 = new Animation();
    Animation *shrek5 = new Animation();
    Animation *shrek6 = new Animation();
    Animation *shrek7 = new Animation();
    Animation *shrek8 = new Animation();
    Animation *shrek9 = new Animation();
    Animation *shrek10 = new Animation();
    Animation *shrekMainTurn = new Animation();

    shrekMainTurn->transf = new RotateBoundary(0.5,vec3(0,1,0));

    shrek1->transf = new RotateBoundary(4.0,vec3(1,0,0));
    shrek1->frameIni = 0;
    shrek1->frameFinal = 14;

    shrek2->transf = new RotateBoundary(-4.3,vec3(1,0,0));
    shrek2->frameIni = 15;
    shrek2->frameFinal = 29;

    shrek3->transf = new RotateBoundary(4.0,vec3(1,0,0));
    shrek3->frameIni = 30;
    shrek3->frameFinal = 44;

    shrek4->transf = new RotateBoundary(-4.0,vec3(1,0,0));
    shrek4->frameIni = 45;
    shrek4->frameFinal = 59;

    shrek5->transf = new RotateBoundary(4.0,vec3(1,0,0));
    shrek5->frameIni = 60;
    shrek5->frameFinal = 74;

    shrek6->transf = new RotateBoundary(-4.0,vec3(1,0,0));
    shrek6->frameIni = 75;
    shrek6->frameFinal = 89;

    shrek7->transf = new RotateBoundary(4.0,vec3(1,0,0));
    shrek7->frameIni = 90;
    shrek7->frameFinal = 104;

    shrek8->transf = new RotateBoundary(-4.0,vec3(1,0,0));
    shrek8->frameIni = 105;
    shrek8->frameFinal = 119;

    shrek9->transf = new RotateBoundary(4.0,vec3(1,0,0));
    shrek9->frameIni = 120;
    shrek9->frameFinal = 134;

    shrek10->transf = new RotateBoundary(-4.0,vec3(1,0,0));
    shrek10->frameIni = 135;
    shrek10->frameFinal = 150;



    shrekBody->addAnimation(shrek1);
    shrekBody->addAnimation(shrek2);
    shrekBody->addAnimation(shrek3);
    shrekBody->addAnimation(shrek4);
    shrekBody->addAnimation(shrek5);
    shrekBody->addAnimation(shrek6);
    shrekBody->addAnimation(shrek7);
    shrekBody->addAnimation(shrek8);
    shrekBody->addAnimation(shrek9);
    shrekBody->addAnimation(shrek10);
    //shrekBody->addAnimation(shrekMainTurn);

    shrekShirt->addAnimation(shrek1);
    shrekShirt->addAnimation(shrek2);
    shrekShirt->addAnimation(shrek3);
    shrekShirt->addAnimation(shrek4);
    shrekShirt->addAnimation(shrek5);
    shrekShirt->addAnimation(shrek6);
    shrekShirt->addAnimation(shrek7);
    shrekShirt->addAnimation(shrek8);
    shrekShirt->addAnimation(shrek9);
    shrekShirt->addAnimation(shrek10);
    //shrekShirt->addAnimation(shrekMainTurn);


    scene->addObject(shrekBody);
    scene->addObject(shrekShirt);


    //capsula 1
    QString sphereObj1("://resources/models/capsule.obj");
    Object * sphere1 = new Object(1000000, sphereObj1);
    sphere1->setTexture(new QOpenGLTexture(QImage("://resources/other models/buscemi.jpeg").mirrored()));
    sphere1->setMaterial(new Material(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(0.1,0.1,0.1),1,5));


    Animation *sphAnim1 = new Animation();
    Animation *sphAnim2 = new Animation();
    Animation *sphAnim3 = new Animation();
    Animation *sphAnim4 = new Animation();

    sphAnim1->transf = new Rotate(-3.0,vec3(1,1,1));
    sphAnim1->frameIni = 0;
    sphAnim1->frameFinal = 74;

    sphAnim2->transf = new Rotate(3.0,vec3(1,1,1));
    sphAnim2->frameIni = 75;
    sphAnim2->frameFinal = 150;

    sphAnim3->transf = new TranslateG(vec3(0.02,0,0.02));
    sphAnim3->frameIni = 0;
    sphAnim3->frameFinal = 74;

    sphAnim4->transf = new TranslateG(vec3(-0.02,0,-0.02));
    sphAnim4->frameIni = 75;
    sphAnim4->frameFinal = 150;


    sphere1->addAnimation(sphAnim1);
    sphere1->addAnimation(sphAnim2);
    sphere1->addAnimation(sphAnim3);
    sphere1->addAnimation(sphAnim4);

    sphere1->aplicaTG(new ScaleG(0.4));
    sphere1->aplicaTG(new TranslateG(vec3(-0.3, -1.5, -0.1)));

    scene->addObject(sphere1);


    //capsula 2
    QString sphereObj2("://resources/models/capsule.obj");
    Object * sphere2 = new Object(1000000, sphereObj2);
    sphere2->setTexture(new QOpenGLTexture(QImage("://resources/other models/nicolas.png").mirrored()));
    sphere2->setMaterial(new Material(vec3(0.0,0.8,0.8),vec3(0.2,0.2,0.2),vec3(0.5,0.5,0.5),1,10));


    Animation *sphAnim12 = new Animation();
    Animation *sphAnim22 = new Animation();
    Animation *sphAnim32 = new Animation();
    Animation *sphAnim42 = new Animation();

    sphAnim12->transf = new Rotate(3.0,vec3(1,1,0));
    sphAnim12->frameIni = 0;
    sphAnim12->frameFinal = 74;

    sphAnim22->transf = new Rotate(-3.0,vec3(1,1,0));
    sphAnim22->frameIni = 75;
    sphAnim22->frameFinal = 150;

    sphAnim32->transf = new TranslateG(vec3(-0.02,0,-0.02));
    sphAnim32->frameIni = 0;
    sphAnim32->frameFinal = 74;

    sphAnim42->transf = new TranslateG(vec3(0.02,0,0.02));
    sphAnim42->frameIni = 75;
    sphAnim42->frameFinal = 150;


    sphere2->addAnimation(sphAnim12);
    sphere2->addAnimation(sphAnim22);
    sphere2->addAnimation(sphAnim32);
    sphere2->addAnimation(sphAnim42);

    sphere2->aplicaTG(new ScaleG(0.4));

    scene->addObject(sphere2);


    //landlord 1
    QString landObj1("://resources/other models/landlord.obj");
    Object * land1 = new Object(1000000, landObj1);
    land1->setTexture(new QOpenGLTexture(QImage("://resources/other models/LandLord_diffuse.png").mirrored()));
    land1->setMaterial(new Material(vec3(0.3,0.8,0.3),vec3(0.2,0.2,0.2),vec3(0.1,0.1,0.1),1,5));



    land1->addAnimation(sphAnim1);
    land1->addAnimation(sphAnim2);
    land1->addAnimation(sphAnim3);
    land1->addAnimation(sphAnim4);

    land1->aplicaTG(new ScaleG(0.95));
    land1->aplicaTG(new TranslateG(vec3(0.3, 1.5, 0.1)));

    scene->addObject(land1);




    scene->addLight(new Light(Direccional));
    Light *light = new Light(Puntual);
    light->setLightPosition(vec4(-3.0,0.0,0.0,1.0));
    scene->addLight(light);
    return scene;
}


