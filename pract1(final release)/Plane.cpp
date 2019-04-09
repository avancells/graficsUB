#include "Plane.h"

Plane::Plane(vec3 normal, vec3 punt_de_pas, Material *m) : Object(m){

    this->normal = normal/length(normal); // calculem la normal
    this->punt = punt;
    this->d = -dot(punt_de_pas, this->normal); // producte escalar entre el punt de pas i la normal

}

bool Plane::hit(const Ray& r, float t_min, float t_max, HitInfo& info) const{

    float producteEscalar = dot(r.dirVector(), this->normal); // fem el producte escalar entre la direcció del vector i la normal del pla

    if(abs(producteEscalar) > 0.000001f){ // si el valor absolut del producte escalar supera el llindar
        float t = -(this->d+dot(this->normal,r.initialPoint()))/producteEscalar; // calculem la distància
        if (t < t_max && t > t_min) { // si el valor de distància està entre max i min
            info.t = t; // actualitzem la info
            info.p = r.pointAtParameter(info.t);            
            if(dot(this->normal,r.dirVector())>0){ // si el produte escalar entre normal i vector director és major que 0
                info.normal = -this->normal; // actualitzem la normal però negada
            }else{
                info.normal = this->normal; // si no, l'actualitzem
            }

            info.mat_ptr = material; // actualitzem el material
            return true;
        }
    }
    return false;
}

void Plane::aplicaTG(TG *t){
    if(dynamic_cast<Rotate *>(t)) {
        mat4 objectToWorld = t->getTG();
        vec4 resultA;

        resultA = objectToWorld * vec4(this->normal.x, this->normal.y, this->normal.z, 1);

        this->normal = (vec3) resultA;

    }else if(dynamic_cast<Translate *>(t)){
        this->punt = (vec3) (t->getTG() * vec4( punt.x, punt.y, punt.z,1));
        this->d = -dot(punt, this->normal);
    }
}
