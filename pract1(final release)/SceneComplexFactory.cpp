#include "SceneComplexFactory.h"

SceneComplexFactory::SceneComplexFactory()
{

}

Scene *SceneComplexFactory::createScene() {
    Scene *s = new Scene();

    // creacio de la camera
    vec3 lookfrom(13, 2, 3); //13,2,3
    vec3 lookat(0, 0, 0); //0,0,0
    float dist_to_focus = 1.0; //1.0
    float aperture = 0.1; //0.1
    int pixelsX = 100;
    int pixelsY = 100;

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus);

    BoundaryObject * boundaryObject =  new BoundaryObject("../A05-master/resources/peo1K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    boundaryObject->aplicaTG(new ScaleBoundary(vec3(10,10,10)));
    boundaryObject->aplicaTG(new Translate(vec3(-16,26,30)));
    boundaryObject->aplicaTG(new RotateBoundary(-100.0, vec3(1,1,0)));

    BoundaryObject * boundaryObject2 =  new BoundaryObject("../A05-master/resources/rei3K.obj", new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    boundaryObject2->aplicaTG(new ScaleBoundary(vec3(10,10,10)));
    boundaryObject2->aplicaTG(new RotateBoundary(60.0, vec3(1,1,0)));


    Plane * plane1 = new Plane(vec3(0, 1, 0), vec3(-20, -80, -10), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));
    plane1->aplicaTG(new Rotate(10.0, vec3(1,0,0)));

    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    sphere->aplicaTG(new Scale(vec3(10,0,0)));
    sphere->aplicaTG(new Translate(vec3(0,0,10)));

    Triangle * triangle = new Triangle(vec3(0,0,-1), vec3(1,0.5,-1), vec3(0,0.75,-1), new Lambertian(vec3(0.5,0.5,0.5),vec3(0.2,0.2,0.2),vec3(1.0,1.0,1.0),1,10));

    triangle->aplicaTG(new Scale(vec3(10,10,10)));
    triangle->aplicaTG(new Rotate(90, vec3(0,0,1)));
    triangle->aplicaTG(new Translate(vec3(0,0,-10)));

    s->objects.push_back(triangle);
    s->objects.push_back(sphere);
    s->objects.push_back(boundaryObject);
    s->objects.push_back(plane1);
    s->objects.push_back(boundaryObject2);

    return s;
}
