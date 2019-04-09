#include "FactoryConcurso.h"

FactoryConcurso::FactoryConcurso()
{

}

Scene *FactoryConcurso::createScene() {
    Scene *s = new Scene();


    vec3 lookfrom(20, 7, 0); //0,0,0
    vec3 lookat(5,5,0); //0,0,0

    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 1920;
    int pixelsY = 1080;

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


void FactoryConcurso::video(Scene *s) {


    Sphere * sphere = new Sphere(vec3(5, 5, 0), 0.75, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.18,0.3,0.3),1,10,0.1));
    Sphere * sphere1 = new Sphere(vec3(5, -5, 0),0.75, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.86,0.07,0.23),1,10,0.1));

    Sphere * sphere2 = new Sphere(vec3(5, -8, 0), 1.2, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.3,0.3,1.0),1,10,0.1));
    Sphere * sphere3 = new Sphere(vec3(5, 8, 0), 1.2, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.3,0.3,1.0),1,10,0.1));

    Sphere * nucli = new Sphere(vec3(5, 0, 0), 3, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.2,0.2,0.2),1,10,0.1));


    Triangle * triangle = new Triangle(vec3(0,0,-1), vec3(2,5,-1), vec3(2,5,-2), new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(1.0,0.5,0.0),1,10,0.1));
    Triangle * triangle2 = new Triangle(vec3(0,0,-5), vec3(5,2.5,-5), vec3(0,3.5,-5), new Lambertian(vec3(0.0,1,0.0),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Triangle * triangle3 = new Triangle(vec3(0,4,-5), vec3(5,7,-5), vec3(-10,9,-5), new Transparent(1.5, vec3(0.7,0.7,0.7)));

    triangle3->aplicaTG(new Translate(vec3(-5,7,10)));
    triangle3->aplicaTG(new Scale(vec3(3,3,3)));
    Animation *t3first = new Animation();
    t3first->transf = new Scale(vec3(0.985,0.985,0.985));
    t3first->frameFinal = 50;
    triangle3->addAnimation(t3first);
    Animation *t3last = new Animation();
    t3last->transf = new Scale(vec3(1.015,1.015,1.015));
    t3last->frameIni = 51;
    triangle3->addAnimation(t3last);



    triangle->aplicaTG(new Scale(vec3(4,4,4)));
    triangle->aplicaTG(new Translate(vec3(-10,0,10)));
    Animation *triangleRotate = new Animation();
    triangleRotate->transf = new Rotate(-2.0, vec3(1,0,0));
    triangle->addAnimation(triangleRotate);






    Animation *anim3 = new Animation();
    anim3->transf = new Rotate(4.0, vec3(1,0,0));
    //anim3->frameIni = 0;
    Animation *anim2 = new Animation();
    anim2->transf = new Rotate(4.0, vec3(0,0,1));
    //anim3->frameIni = 0;

    Animation *anim1 = new Animation();
    anim1->transf = new Scale(vec3(1.01,1.01,1.01));
    anim1->frameIni = 7;


    Animation *animAll = new Animation();
    animAll->transf = new  Translate(vec3(-0.1,-0.1,-0.1));

    sphere->addAnimation(animAll);
    sphere1->addAnimation(animAll);

    sphere2->addAnimation(animAll);
    sphere3->addAnimation(animAll);
    nucli->addAnimation(animAll);

    triangle2->addAnimation(anim1);

    sphere->addAnimation(anim3);
    sphere1->addAnimation(anim3);

    sphere2->addAnimation(anim2);
    sphere3->addAnimation(anim2);

    s->objects.push_back(sphere);
    s->objects.push_back(sphere1);

    s->objects.push_back(sphere2);
    s->objects.push_back(sphere3);

    s->objects.push_back(triangle);
    s->objects.push_back(triangle2);
    s->objects.push_back(triangle3);

    s->objects.push_back(nucli);
    //s->objects.push_back(bombolla);
}
