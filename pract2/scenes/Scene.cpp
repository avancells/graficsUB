#include "Scene.h"

/**
 * @brief Scene::Scene
 */
Scene::Scene() {
    // Inicialització de la capsa minima
    capsaMinima.pmin = vec3(-1.0, -1.0,-1.0);
    capsaMinima.a = 2;
    capsaMinima.h = 2;
    capsaMinima.p = 2;
    lightAmbientGlobal = vec3(0.3, 0.3, 0.3);
}

/**
 * @brief Scene::~Scene
 */
Scene::~Scene() {
    elements.clear();
    lights.clear();
    delete camera;
}

/**
 * @brief Scene::addObject
 * @param obj
 */
void Scene::addObject(Object *obj) {
    elements.push_back(obj);
    calculCapsaMinCont3DEscena();
}

/**
 * @brief Scene::toGPU
 */
void Scene::toGPU(QGLShaderProgram *p) {
    setAmbientToGPU(p);
    lightsToGPU(p);
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->toGPU(p);
    }    
}

/**
 * @brief Scene::draw
 */
void Scene::draw() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->draw();
    }
}

/**
 * @brief Scene::drawTexture
 */
void Scene::drawTexture() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->drawTexture();
    }
}

/**
 * @brief Scene::getLightActual
 * @return
 */
Light* Scene::getLightActual() {
    // TO DO OPCIONAL: A modificar si es vol canviar el comportament de la GUI
    // Ara per ara dona com a Light actual la darrera que s'ha inserit
    return (lights[lights.size()-1]);
}

/**
 * @brief Scene::setLightActual
 * @param l
 */
void Scene::setLightActual(Light* l){
    lights[lights.size()-1]=l;
}



/**
 * @brief Scene::lightsToGPU
 * @param program
 */
void Scene::lightsToGPU(QGLShaderProgram *program){
// TO DO: A implementar a la fase 1 de la practica 2
    struct gl_id_light{
        GLuint diffuseId;
        GLuint ambientId;
        GLuint specularId;
        GLuint attenuationId;
        GLuint positionId;
        GLuint tipusId;
        GLuint angleId;
        GLuint coneId;
    };

    gl_id_light gl_id_light_array[lights.size()]; // HSDHDFHafegir max de llums

    for(int i=0; i< lights.size(); i++){

        gl_id_light_array[i].diffuseId = program->uniformLocation(QString("light[%1].diffuse").arg(i));
        gl_id_light_array[i].ambientId = program->uniformLocation(QString("light[%1].ambient").arg(i));
        gl_id_light_array[i].specularId = program->uniformLocation(QString("light[%1].specular").arg(i));
        gl_id_light_array[i].attenuationId = program->uniformLocation(QString("light[%1].attenuation").arg(i));
        gl_id_light_array[i].positionId = program->uniformLocation(QString("light[%1].position").arg(i));
        gl_id_light_array[i].tipusId = program->uniformLocation(QString("light[%1].tipus").arg(i));
        gl_id_light_array[i].angleId = program->uniformLocation(QString("light[%1].angle").arg(i));
        gl_id_light_array[i].coneId = program->uniformLocation(QString("light[%1].coneDirection").arg(i));



        glUniform3fv(gl_id_light_array[i].diffuseId, 1, lights[i]->diffuse);
        glUniform3fv(gl_id_light_array[i].ambientId, 1, lights[i]->ambient);
        glUniform3fv(gl_id_light_array[i].specularId, 1, lights[i]->specular);
        glUniform3fv(gl_id_light_array[i].attenuationId, 1, lights[i]->attenuation);
        glUniform4fv(gl_id_light_array[i].positionId, 1, lights[i]->position);
        glUniform1f(gl_id_light_array[i].angleId, lights[i]->angle);
        glUniform3fv(gl_id_light_array[i].coneId, 1, lights[i]->coneDirection);


        if(lights[i]->tipus == Puntual){
            glUniform1i(gl_id_light_array[i].tipusId, 0);
        }else if(lights[i]->tipus == Direccional){
            glUniform1i(gl_id_light_array[i].tipusId, 1);
        }else if(lights[i]->tipus == Spot){
            glUniform1i(gl_id_light_array[i].tipusId, 2);
        }


    }

    struct {
        GLuint numLights;
    }gl_num_light;
    gl_num_light.numLights = program->uniformLocation("numLights.numL");

    glUniform1i(gl_num_light.numLights, lights.size());



}

void Scene::addLight(Light *l) {
    lights.push_back(l);

}

/**
 * @brief Scene::setAmbientToGPU
 * @param program
 */
void Scene::setAmbientToGPU(QGLShaderProgram *program){
    // TO DO: A implementar a la fase 1 de la practica 2
    struct {
        GLuint ambientGlobal;
    }gl_id_ambientGlobal;


    gl_id_ambientGlobal.ambientGlobal = program->uniformLocation("InfoAmbient.ambientGlobal");


    glUniform3fv(gl_id_ambientGlobal.ambientGlobal, 1, this->lightAmbientGlobal);

}

/**
 * @brief Scene::setCamera
 * @param Camera *
 */
void Scene::setCamera(Camera *c) {
    camera = c;
}
/**
 * @brief Scene::calculCapsaMinCont3DEscena
 */

void Scene::calculCapsaMinCont3DEscena()
{
    Capsa3D c;
    vec3 pmax;

    if (elements.size()==1) {
        capsaMinima = elements[0]->calculCapsa3D();
        pmax[0] = capsaMinima.pmin[0]+capsaMinima.a;
        pmax[1] = capsaMinima.pmin[1]+capsaMinima.h;
        pmax[2] = capsaMinima.pmin[2]+capsaMinima.p;
    } else {
        capsaMinima.pmin[0]=200;
        capsaMinima.pmin[1]=200;
        capsaMinima.pmin[2]=200;
        pmax[0] = -200;
        pmax[1] = -200;
        pmax[2] = -200;
    }

    for (unsigned int i=0; i<elements.size(); i++) {
       c = elements[i]->calculCapsa3D();

       if (capsaMinima.pmin[0]>c.pmin[0]) capsaMinima.pmin[0] = c.pmin[0];
       if (capsaMinima.pmin[1]>c.pmin[1]) capsaMinima.pmin[1] = c.pmin[1];
       if (capsaMinima.pmin[2]>c.pmin[2]) capsaMinima.pmin[2] = c.pmin[2];
       if (pmax[0]<c.pmin[0]+c.a) pmax[0] = c.pmin[0]+c.a;
       if (pmax[1]<c.pmin[1]+c.h) pmax[1] = c.pmin[1]+c.h;
       if (pmax[2]<c.pmin[2]+c.p) pmax[2] = c.pmin[2]+c.p;
    }
    capsaMinima.a = pmax[0]-capsaMinima.pmin[0];
    capsaMinima.h = pmax[1]-capsaMinima.pmin[1];
    capsaMinima.p = pmax[2]-capsaMinima.pmin[2];
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i< elements.size(); i++) {
        if (dynamic_cast<Animable*>(elements[i]) ) elements[i]->update(nframe);
    }
}
