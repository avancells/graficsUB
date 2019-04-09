#include "Triangle.h"
#include "math.h"
#include "glm/gtx/intersect.hpp"

Triangle::Triangle(vec3 vA, vec3 vB, vec3 vC, Material *m) : Object(m)
{
    this->vA = vA; // guardem els diferents vèrtexs del triangle
    this->vB = vB;
    this->vC = vC;
    setNormal(); // calculem i guardem la normal del triangle
}
void Triangle::setNormal(){

    vec3 a_b, a_c;
    float normX, normY, normZ, mod;

    a_b = vB - vA; // guardem la linia entre el vertex B i A
    a_c = vC - vA; // guardem la linia entre el vertex C i A

    normX = a_b.y * a_c.z - a_b.z * a_c.y; // calculem la component X de la normal
    normY = a_b.z * a_c.x - a_b.x * a_c.z; // calculem la component Y de la normal
    normZ = a_b.x * a_c.y - a_b.y * a_c.x; // calculem la component Z de la normal

    mod = sqrt(pow(normX,2) + pow(normY,2) + pow(normZ,2)); // calculem el modul per a normalitzar

    vec3 n(normX/mod, normY/mod, normZ/mod); // creem el nou vector normal, normalitzat

    this->normal = n; // assignem el nou vector, a la normal del triangle
}

bool Triangle::hit(const Ray& r, float t_min, float t_max, HitInfo& info) const{

    float producteEscalar = dot(this->normal,r.dirVector()); // calculem el producte escalar entre la normal i la direcció

    if(abs(producteEscalar)<0.000000001){ // afegim un llindar per a evitar càlculs innecessaris
        return false;
    }

    float d = -dot(this->normal, this->vA); // calculem el producte escalar entre la normal i un punt del triangle
    float t = -(dot(this->normal,r.initialPoint())+d)/producteEscalar; // apliquem la teoria de interseccions

    if(t < 0){ // si la t és negativa no hi ha intersecció
        return false;
    }

    vec3 p = r.origin + t*r.direction;
    vec3 c;

    vec3 edge0 = vB - vA; // calculem el edge
    vec3 vp0 = p - vA;
    c = cross(edge0,vp0); // fem el producte vectorial entre edge i vp

    if(dot(this->normal,c) < 0){ // si el producte escalar entre la normal i el resultat obtingut és negatiu
        return false; // no hi ha intersecció
    }

    // repetim el procés per als diferents vèrtexs del triangle
    vec3 edge1 = vC - vB;
    vec3 vp1 = p - vB;
    c = cross(edge1,vp1);

    if(dot(this->normal,c) < 0){
        return false;
    }

    vec3 edge2 = vA - vC;
    vec3 vp2 = p - vC;
    c = cross(edge2,vp2);

    if(dot(this->normal,c) < 0){
        return false;
    }

    // si la t està entre els llindars establits
    if(t_min < t && t_max > t){
        info.t = t; // assignem la t
        info.p = p; // assignem la p
        if(dot(this->normal, r.dirVector())<0){ // si el producte escalar entre la normal i la direcció és negatiu
            info.normal = this->normal; // assignem la normal
        }else{ // si no
            info.normal = -this->normal; // assignem la normal però negativa
        }
        info.mat_ptr = material; // assignem la informació del material
    }

    return true; // hi ha intersecció
}

void Triangle::aplicaTG(TG *t) {    

    if(dynamic_cast<Translate *>(t) || dynamic_cast<ScaleBoundary *>(t) || dynamic_cast<RotateBoundary *>(t)) {

        mat4 objectToWorld = t->getTG();
        vec4 resultA, resultB, resultC;
        // Multipliquem la matriu de transformació pel vector i guardem el resultat
        resultA = objectToWorld * vec4(vA.x, vA.y, vA.z, 1);
        resultB = objectToWorld * vec4(vB.x, vB.y, vB.z, 1);
        resultC = objectToWorld * vec4(vC.x, vC.y, vC.z, 1);

        this->vA = (vec3) resultA;
        this->vB = (vec3) resultB;
        this->vC = (vec3) resultC;

        setNormal();

    }else if(dynamic_cast<Rotate *>(t) || dynamic_cast<Scale *>(t)) {

        mat4 objectToWorld = t->getTG();
        vec4 resultA, resultB, resultC;
        float centroidX, centroidY, centroidZ;
        vec3 centroid;

        // Hem de fer una translació de l'objecte al centre dels eixos
        // Per poder aplicar la matriu de transformació
        // Fem dues translacions respecte el centre del triangle

        centroidX = (this->vA.x + this->vB.x +this->vC.x)/3;
        centroidY = (this->vA.y + this->vB.y +this->vC.y)/3;
        centroidZ = (this->vA.z + this->vB.z +this->vC.z)/3;

        centroid = vec3(-centroidX, -centroidY, -centroidZ);

        mat4 translate = glm::translate(glm::mat4(1.0f), centroid);


        resultA = translate * vec4(vA.x, vA.y, vA.z, 1);
        resultB = translate * vec4(vB.x, vB.y, vB.z, 1);
        resultC = translate * vec4(vC.x, vC.y, vC.z, 1);

        this->vA = (vec3) resultA;
        this->vB = (vec3) resultB;
        this->vC = (vec3) resultC;

        resultA = objectToWorld * vec4(vA.x, vA.y, vA.z, 1);
        resultB = objectToWorld * vec4(vB.x, vB.y, vB.z, 1);
        resultC = objectToWorld * vec4(vC.x, vC.y, vC.z, 1);

        this->vA = (vec3) resultA;
        this->vB = (vec3) resultB;
        this->vC = (vec3) resultC;

        translate = glm::translate(glm::mat4(1.0f), -centroid);

        resultA = translate * vec4(vA.x, vA.y, vA.z, 1);
        resultB = translate * vec4(vB.x, vB.y, vB.z, 1);
        resultC = translate * vec4(vC.x, vC.y, vC.z, 1);

        this->vA = (vec3) resultA;
        this->vB = (vec3) resultB;
        this->vC = (vec3) resultC;


        setNormal();
    }






}
