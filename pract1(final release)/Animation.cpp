#include "Animation.h"

Animable::Animable()
{

}
Animable::~Animable()
{

}

void Animable::addAnimation(Animation *anim) {
    animFrames.push_back(anim);
}

void Animable::update(int nframe) {

    //bool trobat = false;

    //for (i = 0; i<animFrames[animFrames.size()-1]->frameFinal && !trobat; i++)
    //    trobat = animFrames[i]->frameFinal>=nframe;
    int i;
    for(i = 0; i < animFrames.size(); i++){
        if(nframe < animFrames[i]->frameFinal && nframe > animFrames[i]->frameIni){
            aplicaTG(animFrames[i]->transf);
        }
    }


}
