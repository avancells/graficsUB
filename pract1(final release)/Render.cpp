#include "Render.h"


void Render::setScene(Scene *s) {
    scene = s;
}

// Metode Render

// Aquesta funcio transforma cada pixel a coordenades de mon i
// envia un raig des de la camera en aquella direccio cridant al metode CastRay
// i pel pintar la imatge final:
// 1) Neteja la pantalla per a visualitzar el nou frame
// 2) Envia un raig a l'escena per a cada pixel de la pantalla i utilitza el color retornat per a pintar el pixel
// 3) Actualitza la sortida corresponent segons la implementació del mètode setPixelColor de cada fill

//Precondicio:
// La Scene ha d'estar creada i inicialitzada

void Render::rendering() {
    // Recorregut de cada pixel de la imatge final
    int numSamples = 10; // Aquest valor modifica el nombre de mostreigs que es fan per cada raig
    float random = 0.0f;
    for (int y = scene->cam->viewportY-1; y >= 0; y--) {
         for (int x = 0; x < scene->cam->viewportX; x++) {
            vec3 finalColor(0,0,0);
            vec3 col(0, 0, 0);
            for(int i = 0; i < numSamples; i++){ // per cada sample
                random = ((float) rand()/ RAND_MAX +1)/2; //generarem un nombre aleatori entre 0 i 0.5

                float u = float(x+random) / float(scene->cam->viewportX); // sumarem aquest valor random a la component x
                float v = float(y+random) / float(scene->cam->viewportY); // sumarem aquest valor random a la component y

                Ray r = scene->cam->getRay(u, v);
                finalColor += scene->ComputeColor(r,0); // Sumarem al color final el color obtingut
            }
            finalColor = sqrt(finalColor/(float)numSamples); // correcció del color calculat
            setPixelColor(finalColor, x, y);

         }
    }
}

void Render::exitRender() {
    cleanup();
}

void Render::cleanup() {
    if (scene!=NULL)  delete scene;
}

// Metode de suport que fa el rendering per a tots els Renders que no usen GLUT
void Render::startRendering(int argc, char **argv) {
    renderingScene();
}

void Render::renderingScene()  {
    initRender("resultat.ppm");
    rendering();
    exitRender();
}

