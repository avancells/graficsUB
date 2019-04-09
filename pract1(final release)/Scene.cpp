#include "Scene.h"
#include <iostream>
#include <fstream>

Scene::Scene()
{

}

Scene::~Scene()
{
// TODO Fase 1: Quan s'incloguin nous objectes, cal retocar aquest destructor
    for(unsigned int i = 0; i < objects.size(); ++i){
        if(objects[i]){
            if (dynamic_cast<Sphere*>(objects[i]))
                    delete (Sphere *)(objects[i]);
            if (dynamic_cast<Triangle*>(objects[i]))
                    delete (Triangle *)(objects[i]);
            if (dynamic_cast<Plane*>(objects[i]))
                    delete (Plane *)(objects[i]);
            if (dynamic_cast<BoundaryObject*>(objects[i]))
                    delete (BoundaryObject *)(objects[i]);

        }
    }
    delete cam;
}


/*
** TODO: Metode que testeja la interseccio contra tots els objectes de l'escena (Fase 1)
**
** Si un objecte es intersecat pel raig, el parametre  de tipus IntersectInfo conte
** la informació sobre la interesccio.
** El metode retorna true si algun objecte es intersecat o false en cas contrari.
**
*/
bool Scene::hit(const Ray& raig, float t_min, float t_max, HitInfo& info) const {
    HitInfo possibleHit;
    bool hitObject = false;

    for(int i = 0; i < objects.size(); i++){
        hitObject = objects[i]->hit(raig, t_min, t_max, possibleHit);
        if(hitObject){
            if(possibleHit.t < info.t){
                info = possibleHit;
            }
        }
    }

    if(info.t<std::numeric_limits<float>::infinity()){
        return true;
    }else{
        return false;
    }
    // TODO FASE 0 i FASE 1: Heu de codificar la vostra solucio per aquest metode substituint el 'return true'
    // Una possible solucio es cridar el mètode hit per a tots els objectes i quedar-se amb la interseccio
    // mes propera a l'observador, en el cas que n'hi hagi més d'una.
    // Cada vegada que s'intersecta un objecte s'ha d'actualitzar el HitInfo del raig,
    // pero no en aquesta funcio.
}


/*
** TODO: Funcio ComputeColor es la funcio recursiva del RayTracing.
** A modificar en la Fase 2 de l'enunciat per incloure Blinn-Phong  i ombres
** A modificar en la Fase 2 per a tractar reflexions i transparències
**
*/
vec3 Scene::ComputeColor (Ray &ray, int depth ) {

    vec3 color, blanc, blau, vermell;
    vec3 ray2;
    HitInfo h;
    int MAXDEPTH = 10; // Valor que modifica la profunditat de la recursió
    vec3 materialColor;
    std::vector<Ray> scatterRay;


    /* TODO Fase 0: Canviar segons les instruccions de l'enunciat
     * TODO Fase 2: Canviar aquesta assignacio pel color basat amb la il.luminacio basada amb Phong-Blinn segons
     * el material de l'objecte i les llums per la fase 2 de la practica
     * En aquesta fase 2,  cal fer que tambe es tinguin en compte els rebots de les reflexions.

       Inicialment s'ha posat la direccio del raig per tenir un color diferents per a cada pixel pero
       hitInfo ha d'anar tenint el color actualitzat segons els rebots.
    */


    ray2 = ray.direction;

    blanc = vec3(1.0, 1.0, 1.0);
    blau = vec3(0.5, 0.7, 1.0);
    vermell = vec3(1.0,0.0,0.0);

    // implementació per a l'ús de blinn-phong recursiu
    if(this->hit(ray, 0.02, 200, h)){ // en cas de hit amb un objecte

        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        // Aquest codi s'ha modificat al llarg de la pràctica, hem deixat comentat el codi anterior
        //
        //color = vermell; // si volem que el color obtingut sigui vermell utilitzarem aquesta linea
        //color = abs(h.normal); // si volem que el color obtingut sigui la normal utilitzarem aquesta linea
        //color = BlinnPhong(h.p, h.normal, h.mat_ptr); // si volem Blinn-Phong sense recursió utilitzarem tan sols aquesta linea
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        color = BlinnPhong(h.p, h.normal, h.mat_ptr); // calculem el color a partir de Blinn-Phong
        if(depth < MAXDEPTH){ // si no hem arribat al límit de la recursió
            h.mat_ptr->scatter(ray,h,materialColor,scatterRay); // fem crida a scatter per a obtenir rajos secundaris
            for(int j = 0; j < scatterRay.size(); j++){ // per a cada raig generat per scatter
                color += materialColor * this->ComputeColor(scatterRay[j], depth+1); // afegim la quantitat de color del computeColor del raig secundari
            }
        }

    }else{ // en cas de no haver-hi cap objecte

        color = blau*ray2.y + blanc*(1-ray2.y); // pintem amb el color de background (degradat blanc i blau)
    }

     return color;
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i< objects.size(); i++) {
        if (dynamic_cast<Animable*>(objects[i]) ) objects[i]->update(nframe);
    }
}

vec3 Scene::BlinnPhong(vec3 point, vec3 normal, const Material *material){
    //  Model de Blinn-Phong
    //  Fórmula aplicada extreta de teoria
    // I = Ka * Ia + Kd * Id * L · N + Ks * Is * (N · H)^B
    // Les components amb a corresponen a la Ambient
    // Les components amb d corresponen a Diffuse
    // Les components amb s corresponen a Specular
    // H és la suma de L i V normalitzat
    // L és el vector des de la superfície a la llum
    // B s'usa per calcular la shineness
    // I es correspon a intensitats
    // K es correspon al component ambient del material
    vec3 v = normalize(cam->origin-point); // Normalitzem el vector des del punt de vista a la superfície
    vec3 ka = material->ambient; // guardem els valors ambient, specular i diffuse del material
    vec3 ks = material->specular;
    vec3 kd = material->diffuse;
    vec3 c = this->AmbientLight*ka; // C serà el resultat final d'iluminació, de moment li assignem la llum d'ambient de l'escena

    Ray* raigTemp;
    HitInfo info;

    for(int i = 0; i < lights.size(); i++){ // per a cada llum de la escena
        vec3 Al = lights[i]->Ia;
        vec3 Dl = lights[i]->Id;
        vec3 Sl = lights[i]->Is;
        vec3 L = normalize(lights[i]->position - point); // Normalitzem el vector des de la superfície a la llum

        float d = length(lights[i]->position-point); // calculem al distància de la superfície al focus

        // calculem la atenuació a partir de 1/(a + bd + cd^2)
        float atenuacio = 1/(lights[i]->coefAt_a+lights[i]->coefAt_b*d+lights[i]->coefAt_c*d*d);


        vec3 ambient = ka*Al; // Calculem la component ambient

        float diffuseDot = dot(L,normal); // fem el producte vectorial necessari, assegurant-nos que no hi ha errors
        if(diffuseDot< 0){
            diffuseDot = 0;
        }        
        vec3 diffuse = (kd*Dl)*diffuseDot; // Calculem la component difosa

        float beta = material->shine;
        vec3 H = normalize(L+v); // calculem la H
        float specularDot = dot(normal,H); // fem el producte vectorial necessari, assegurant-nos que no hi ha errors
        if(specularDot < 0){
            specularDot = 0;
        }
        vec3 specular = (ks*Sl)*pow(specularDot,beta); // Calculem la component especular


        raigTemp = new Ray(point+0.01f*L, L); //Creem un nou raig per comprovar si hi ha objectes en la trajectòria
        if(!this->hit(*raigTemp, 0.02, 200, info)){ // si no hi ha cap objecte
            c += (ambient+diffuse+specular)*atenuacio; // afegim a la intensitat ambient les components calculades amb
                                                       //Blinn-Phong i multipliquem pel factor d'atenuació
        }else{
            c += ambient*atenuacio; //En cas d'haver-hi un objecte nomes tenim en compte la component ambient, per a generar
                                    //una projecció d'ombra
        }
        delete(raigTemp);
    }

    return c;
}

