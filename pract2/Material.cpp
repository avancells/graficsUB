#include "Material.h"


Material::Material(const vec3& diffuse, const vec3& ambient, const vec3& specular, float opacity, float shine) {
    this->diffuse = diffuse;
    this->ambient = ambient;
    this->specular = specular;
    this->opacity = opacity;
    this->shine = shine;
}






/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(QGLShaderProgram *program){

    struct{
        GLuint diffuseId;
        GLuint ambientId;
        GLuint specularId;
        GLuint opacityId;
        GLuint shineId;
    }gl_id_material;

    gl_id_material.diffuseId = program->uniformLocation("InfoMaterial.diffuse");
    gl_id_material.ambientId = program->uniformLocation("InfoMaterial.ambient");
    gl_id_material.specularId = program->uniformLocation("InfoMaterial.specular");
    gl_id_material.opacityId = program->uniformLocation("InfoMaterial.opacity");
    gl_id_material.shineId = program->uniformLocation("InfoMaterial.shine");

    glUniform3fv(gl_id_material.diffuseId, 1, this->diffuse);
    glUniform3fv(gl_id_material.ambientId, 1, this->ambient);
    glUniform3fv(gl_id_material.specularId, 1, this->specular);

    glUniform1f(gl_id_material.opacityId, this->opacity);
    glUniform1f(gl_id_material.shineId, this->shine);


}

