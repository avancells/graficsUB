#include "SceneFactoryFase3.h"

SceneFactoryFase3::SceneFactoryFase3()
{

}

Scene *SceneFactoryFase3::createScene() {
    Scene *s = new Scene();

    vec3 lookfrom(10, 2, 3); //0,0,0
    vec3 lookat(0,0,0); //0,0,0
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 600;
    int pixelsY = 400;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);


    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena

    this->video(s);

    //TODO Fase 2: Cal afegir llums a l'escena
    vec3 Ia(0.1,0.1,0.1);
    //s->lights.push_back(new Light(vec3(15, 5, 5),vec3(0.6,0.6,0.6), vec3(0.7,0.7,0.7), vec3(0.5,0.5,0.5), 0.5, 0, 0.01));
    s->lights.push_back(new Light(vec3(8, 10, 20),vec3(0.6,0.6,0.6), vec3(0.7,0.7,0.7), vec3(0.5,0.5,0.5), 0.5, 0, 0.01));
    s->AmbientLight = Ia;

    return s;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random


void SceneFactoryFase3::video(Scene *s) {
    Triangle * triangle = new Triangle(vec3(0,0,-1), vec3(1,0.5,-1), vec3(0,0.75,-1), new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(1.0,0.5,0.0),1,10,0.1));
    Triangle * triangle2 = new Triangle(vec3(0,0,-5), vec3(5,2.5,-5), vec3(0,3.5,-5), new Lambertian(vec3(0.0,1,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));


    Sphere * sphere = new Sphere(vec3(0, 0, 10), 2, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.18,0.3,0.3),1,10,0.1));
    Sphere * sphere1 = new Sphere(vec3(0, 0, 10), 2, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.86,0.07,0.23),1,10,0.1));

    Plane * plane1 = new Plane(vec3(1, 0, 0), vec3(-10,0,10), new Metal(vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),1,10,0));
    Plane * plane2 = new Plane(vec3(0, 0, 1), vec3(10,0,-10), new Lambertian(vec3(1,0,0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Plane * plane3 = new Plane(vec3(0, 1, 0), vec3(10,-3,-10), new Lambertian(vec3(0,0,1),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    Animation *anim = new Animation();
    Animation *anim1 = new Animation();
    Animation *anim2 = new Animation();
    Animation *anim3 = new Animation();

    Animation *anim5 = new Animation();
    anim5->transf = new TG();
    plane1->addAnimation(anim5);
    plane2->addAnimation(anim5);
    plane3->addAnimation(anim5);

    anim->transf = new Scale(vec3(1.1,1.1,1.1));
    triangle->addAnimation(anim);

    anim1->transf = new Scale(vec3(1.05));
    anim2->transf = new Translate(vec3(0,0,-1));

    anim3->transf = new Rotate(18.0, vec3(0,0,1));
    anim3->frameIni = 10;
    triangle2->addAnimation(anim3);


    sphere->addAnimation(anim1);
    sphere1->addAnimation(anim2);

    //s->objects.push_back(plane1);
    //s->objects.push_back(plane2);
    //s->objects.push_back(plane3);
    s->objects.push_back(triangle2);
    s->objects.push_back(triangle);
    s->objects.push_back(sphere);
    s->objects.push_back(sphere1);
}
