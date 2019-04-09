#include "SceneFase2Mirall.h"

SceneFase2Mirall::SceneFase2Mirall()
{

}


Scene *SceneFase2Mirall::createScene() {
    Scene *s = new Scene();


    // creacio de la camera
    vec3 lookfrom(1, -0.3, 0.7); //0,0,0
    vec3 lookat(0,0,0); //0,0,0
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 600;
    int pixelsY = 400;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);



    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena

    //this->TwoSphere(s);
    this->EscenaMirall(s);

    //this->MultipleSphere(s);

    //this->fase2(s);


    //TODO Fase 2: Cal afegir llums a l'escena
    vec3 Ia(0.1,0.1,0.1);
    s->lights.push_back(new Light(vec3(6, 6, 6),vec3(0.6,0.6,0.6), vec3(0.7,0.7,0.7), vec3(0.5,0.5,0.5), 0.5, 0, 0.01));
    s->AmbientLight = Ia;

    return s;
}




void SceneFase2Mirall::EscenaMirall(Scene *s){
    Sphere * sphere = new Sphere(vec3(-0.5, -0.5, 0), 0.3, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.18,0.3,0.3),1,10,0.1));
    Sphere * sphere2 = new Sphere(vec3(0, -0.9, 0), 0.3, new Metal(vec3(0.7,0.6,0.5),vec3(0.2,0.2,0.2),vec3(0.86,0.07,0.23),1,10,0.1));

    Plane * plane1 = new Plane(vec3(1, 0, 0), vec3(-1, -1, -1), new Metal(vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),1,10,0.05));
    Plane * plane2 = new Plane(vec3(0, 0, 1), vec3(-2, -2, -2), new Metal(vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),vec3(0.4,0.4,0.4),1,10,0.05));
    Plane * plane3 = new Plane(vec3(0, 1, 0), vec3(0, -1, -1.5), new Metal(vec3(0.2,0.2,0.2),vec3(0.2,0.2,0.2),vec3(0.2,0.2,0.2),1,10,0.05));



    //Plane * plane1 = new Plane(vec3(1, 0, 0), vec3(-1, -1, -1), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    //Plane * plane2 = new Plane(vec3(0, 0, 1), vec3(-2, -2, -2), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    //Plane * plane3 = new Plane(vec3(0, 1, 0), vec3(0, -1, -2), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));


    //BoundaryObject * boundaryObject =  new BoundaryObject("../A05-master/resources/peo1K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    //boundaryObject->aplicaTG(new Translate(vec3(24,1,6)));

    s->objects.push_back(plane1);
    s->objects.push_back(plane2);
    s->objects.push_back(plane3);
    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(new Sphere(vec3(0,0,-1), 0.3, new Lambertian(vec3(0.54,0.27,0.07),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10)));

    //s->objects.push_back(boundaryObject);

}
