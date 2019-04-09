#ifndef MATERIAL_H
#define MATERIAL_H

#include "./library/Common.h"
#include <QGLShaderProgram>


// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material(const vec3&, const vec3&, const vec3&, float, float);
    ~Material();

    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float opacity;
    float shine;

    void toGPU(QGLShaderProgram *program);



};

#endif // MATERIAL_H
