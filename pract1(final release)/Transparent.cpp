#include "Transparent.h"

Transparent::Transparent(float indexRefraccio, vec3 kt){

    this->indexRefraccio = indexRefraccio;
    this->kt = kt;
    this->nit = 1/this->indexRefraccio;
}

Transparent::~Transparent()
{
}

bool Transparent::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const  {

    vec3 R = normalize(r_in.direction); // Normalitzem la direcció
    vec3 norm = rec.normal;
    float temp_nit = this->nit;
    float cosinus = dot(R, norm); // Calculem el cosinus de l'angle d'incidencia, tan sols cal fer el producte vectorial
                                  // ja que ambdós vectors estan normalitzats

    if((1 - (nit * nit * (1 - cosinus * cosinus))) > 0){ // sempre que la part dreta de la fórmula no sigui negativa

        if(cosinus > 0){ // si el producte vectorial entre R i N és positiu significa que estem dins l'objecte, i hem de girar la normal
            norm = -rec.normal;
            temp_nit = 1.0f / this->nit;
            cosinus = dot(R, norm);
        }
        // Apliquem la fórmula extreta de les diapositives de teoria, adaptada per al funcionament de la pràctica
        // T = Nit * R - N (Nit * Cos(0i) + sqrt(1 - Nit^2 (1 - Cos^2(0i))))
        // T és el vector de transmissió
        // Nit és la relació entre els indexs de refracció dels medis
        // 0i és l'angle d'incidencia

        vec3 T = temp_nit * R - norm * ((temp_nit * cosinus) + sqrt(1 - temp_nit * temp_nit *(1 - cosinus * cosinus)));
        r_out.push_back(Ray(rec.p, T)); // afegim al vector de rajos generats, el raig obtingut
        color = this->kt; // assignem el color
    }else{ // si no
        // Fem servir la fórmula per a la reflexió de les diapositives de teoria
        // reflex = 2 (R · N) N - R
        vec3 reflex = R - 2 * dot(R, norm) * norm;
        r_out.push_back(Ray(rec.p, reflex));
        color = vec3(1.0f) - this->kt; // assignem el color
    }
    return true;

}
