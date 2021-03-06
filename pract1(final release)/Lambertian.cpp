#include "Lambertian.h"

Lambertian::Lambertian(const vec3& diffuse, const vec3& ambient, const vec3& specular, float opacity, float shine){
    this->diffuse = diffuse;
    this->ambient = ambient;
    this->specular = specular;
    this->opacity = opacity;
    this->shine = shine;
}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const  {
    vec3 target = rec.p + rec.normal + this->RandomInSphere();
    r_out.push_back( Ray(rec.p, target-rec.p));
    color = diffuse;
    return true;
}

