#include "SceneFactoryBasica.h"

SceneFactoryBasica::SceneFactoryBasica()
{

}

Scene *SceneFactoryBasica::createScene() {
    Scene *s = new Scene();

    // creacio de la camera
    vec3 lookfrom(0, 0, 0); //0,0,0
    vec3 lookat(0,0,-1); //0,0,-1
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.8; //0.1
    int pixelsX = 200;
    int pixelsY = 200;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);



    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena

    this->OneSphere(s);

    //this->MultipleSphere(s);

    return s;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random


void SceneFactoryBasica::OneSphere(Scene *s) {

   Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.2,0.7),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

   Animation *anim = new Animation();
   anim->transf = new Translate(vec3(0.2));
   sphere->addAnimation(anim);

   s->objects.push_back(sphere);

}

void SceneFactoryBasica::MultipleSphere(Scene *s){
    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));


    s->objects.push_back(sphere);
    s->objects.push_back(new Sphere(vec3(0,-1,-1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10)));
    s->objects.push_back(new Sphere(vec3(1,-1,-1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10)));
    s->objects.push_back(new Sphere(vec3(-1,-1,-1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10)));
    s->objects.push_back(new Sphere(vec3(-1,0,-1), -0.45, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10)));

}
