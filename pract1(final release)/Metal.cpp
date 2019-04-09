#include "Metal.h"

Metal::Metal(const vec3& diffuse, const vec3& ambient, const vec3& specular, float opacity, float shine, float fuzzy){
    this->diffuse = diffuse;
    this->ambient = ambient;
    this->specular = specular;
    this->opacity = opacity;
    this->shine = shine;
    this->fuzzy = fuzzy;
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const  {
    // Fem servir la fórmula per a la reflexió de les diapositives de teoria
    // R = 2 (L · N) N - L
    // L és el vector des de la superfície a la llum
    vec3 target = normalize(r_in.direction) - 2 * dot(normalize(r_in.direction), normalize(rec.normal)) * normalize(rec.normal);
    // El valor fuzzy ens permet modificar l'aleatorietat dels rajos
    vec3 v = target + this->fuzzy * this->RandomInSphere();
    r_out.push_back(Ray(rec.p, v)); // afegim al vector de rajos generats, el raig obtingut
    color = specular; // assignem el color
    return true;
}
