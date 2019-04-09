#ifndef TRANSPARENT_H
#define TRANSPARENT_H


#include "Material.h"

class Transparent : public Material
{
public:
    Transparent(float indexRefraccio, vec3 kt);
    virtual ~Transparent();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const;

private:

    float indexRefraccio;
    vec3 kt;
    float nit;
};

#endif // TRANSPARENT_H
