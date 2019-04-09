#include "RealisticSceneFactory.h"
#include <stdlib.h>

RealisticSceneFactory::RealisticSceneFactory()
{

}

Scene *RealisticSceneFactory::createScene() {
    Scene *s = new Scene();


    // creacio de la camera
    vec3 lookfrom(6, 4, 1); //0,0,0
    vec3 lookat(0,0,0); //0,0,0
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 600;
    int pixelsY = 400;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);


    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena

    //this->TwoSphere(s);
    this->realisticScene(s);

    //TODO Fase 2: Cal afegir llums a l'escena
    vec3 Ia(0.1,0.1,0.1);
    s->lights.push_back(new Light(vec3(15, 5, 5),vec3(0.6,0.6,0.6), vec3(0.7,0.7,0.7), vec3(0.5,0.5,0.5), 0.5, 0, 0.01));
    s->AmbientLight = Ia;

    return s;
}




void RealisticSceneFactory::realisticScene(Scene *s){
    Sphere * sphere = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere2 = new Sphere(vec3(0, 0.5, -3), 1, new Lambertian(vec3(1.0,0.0,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere3 = new Sphere(vec3(0, 0.5, 3), 1, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.8,0.8,0.8),1,10,0.1));
    Sphere * sphere4 = new Sphere(vec3(0, 0.5, 0), 1, new Transparent(1.5, vec3(1.0,1.0,1.0)));

    for(int i = 0; i < 50; i++){
        vec3 color(((rand() % 10)/10.0f),((rand() % 10)/10.0f),((rand() % 10)/10.0f));
        vec3 pos(((rand() % 14)-7),((rand() % 10)/10.0f),((rand() % 14)-7));
        Sphere * sphere5 = new Sphere(pos, 0.3, new Lambertian(color,vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
        s->objects.push_back(sphere5);
    }
    for(int i = 0; i < 20; i++){
        vec3 color(((rand() % 10)/10.0f),((rand() % 10)/10.0f),((rand() % 10)/10.0f));
        vec3 pos(((rand() % 14)-7),((rand() % 10)/10.0f),((rand() % 14)-7));
        Sphere * sphere6 = new Sphere(pos, 0.3, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),color,1,10,0.1));
        s->objects.push_back(sphere6);
    }
    for(int i = 0; i < 10; i++){
        vec3 pos(((rand() % 14)-7),((rand() % 10)/10.0f),((rand() % 14)-7));
        Sphere * sphere7 = new Sphere(pos, 0.3, new Transparent(1.5, vec3(1.0,1.0,1.0)));
        s->objects.push_back(sphere7);
    }
    BoundaryObject * boundaryObject =  new BoundaryObject("../A05-master/resources/peo1K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    boundaryObject->aplicaTG(new Translate(vec3(24,3,6)));


    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphere3);
    s->objects.push_back(sphere4);
    s->objects.push_back(boundaryObject);

}
