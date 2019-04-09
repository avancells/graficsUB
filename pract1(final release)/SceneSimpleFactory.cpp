#include "SceneSimpleFactory.h"

SceneSimpleFactory::SceneSimpleFactory()
{

}

Scene *SceneSimpleFactory::createScene() {
    Scene *s = new Scene();

    // creacio de la camera
    vec3 lookfrom(13, 2, 3); //13,2,3
    vec3 lookat(0, 0, 0); //0,0,0
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 500;
    int pixelsY = 500;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);

    //TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena


    this->TwoPlanes(s);

    this->TwoTriangles(s);

    this->Boundary(s);

    //TODO Fase 2: Cal afegir llums a l'escena
    return s;
}



void SceneSimpleFactory::TwoPlanes(Scene *s){
    //creem els dos plans
    Plane * plane1 = new Plane(vec3(1, 0, 0), vec3(1, 1, 1), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    Plane * plane2 = new Plane(vec3(0, 0, 1), vec3(-2, -2, -2), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    //fem push a objects
    s->objects.push_back(plane1);
    s->objects.push_back(plane2);
}


void SceneSimpleFactory::TwoTriangles(Scene *s){
    //creem els dos plans
    Triangle * triangle = new Triangle(vec3(0,-7,0), vec3(5,2.5,-5), vec3(-5,2.5,0),new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    Sphere * sphere = new Sphere(vec3(0, 0, -1), 3,new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    s->objects.push_back(sphere);


    //fem push a objects
    s->objects.push_back(triangle);

}




void SceneSimpleFactory::Boundary(Scene *s){
    //creem els dos plans
    BoundaryObject * boundaryObject =  new BoundaryObject("../A05-master/resources/peo1K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    //fem push a objects
    s->objects.push_back(boundaryObject);
}


