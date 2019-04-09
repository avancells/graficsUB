#include "SceneFactoryFase2.h"

SceneFactoryFase2::SceneFactoryFase2()
{

}

Scene *SceneFactoryFase2::createScene() {
    Scene *s = new Scene();


    // creacio de la camera
    vec3 lookfrom(3, 0.7, 1); //0,0,0
    vec3 lookat(0,0,-1); //0,0,-1
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 300;
    int pixelsY = 200;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);



    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena

    //this->TwoSphere(s);
    this->EscenaObj(s);

    //this->MultipleSphere(s);

    //this->fase2(s);


    //TODO Fase 2: Cal afegir llums a l'escena
    vec3 Ia(0.1,0.1,0.1);
    s->lights.push_back(new Light(vec3(2,8,10),vec3(0.3,0.3,0.3), vec3(0.7,0.7,0.7), vec3(1.0,1.0,1.0), 0.5, 0, 0.01));
    s->AmbientLight = Ia;

    return s;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random


void SceneFactoryFase2::TwoSphere(Scene *s) {

    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);

}



void SceneFactoryFase2::EscenaObj(Scene *s){
    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));


    Plane * plane1 = new Plane(vec3(1, 0, 0), vec3(-1, -1, -1), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Plane * plane2 = new Plane(vec3(0, 0, 1), vec3(-2, -2, -2), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Plane * plane3 = new Plane(vec3(0, 1, 1), vec3(0, 0, -2), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));


    BoundaryObject * boundaryObject =  new BoundaryObject("../A05-master/resources/peo1K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    boundaryObject->aplicaTG(new Translate(vec3(24,1,6)));

    s->objects.push_back(plane1);
    s->objects.push_back(plane2);
    s->objects.push_back(plane3);
    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(boundaryObject);

}




void SceneFactoryFase2::MultipleSphere(Scene *s){
    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphereMetalica = new Sphere(vec3(-3,1,1), 1, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.7,0.7,0.7),1,10,0.1));

    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphereMetalica);
  }

void SceneFactoryFase2::fase2(Scene *s){
    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8,0.8,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Sphere * sphereMetalica = new Sphere(vec3(-3,1,1), 1, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.7,0.7,0.7),1,10, 0.1));
    Sphere * sphereTrans = new Sphere(vec3(0,1,0), 1, new Transparent(1.5, vec3(1.0,1.0,1.0)));

    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphereMetalica);
    s->objects.push_back(sphereTrans);

}


