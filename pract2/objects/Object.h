#ifndef Object_H
#define Object_H

#include <QObject>
#include <vector>
#include "./library/Common.h"
#include "./cara.h"
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include <QStringList>
#include "./TG/TG.h"

#include "./TG/TranslateG.h"
#include "./TG/Rotate.h"
#include "./TG/RotateBoundary.h"
#include "./TG/ScaleBoundary.h"
#include "./TG/ScaleG.h"

#include "./animations/Animation.h"
#include "Material.h"

using namespace std;

typedef Common::vec4  point4;

// Classe que conte la representacio d'un Objecte: geometria, topologia, material i textures
class Object : public QObject, public Animable {

    Q_OBJECT
protected:
    QString nom;
    vector<Cara> cares;
    vector<point4> vertexs;
    vector<point4> normalsVertexs;
    vector<vec2>   textVertexs;

    // Estructures per passar a la GPU
    GLuint buffer;
    GLuint vao;

    int     numPoints;
    point4 *points;
    point4 *normals;

    // Els colors s'usen en la primera execució però després son prescindibles
    point4 *colors;
    vec2 *coordTex;

    Material *material;


    int Index; // index de control del numero de vertexs a passar a la GPU

    QGLShaderProgram *program;

    QOpenGLTexture *texture;

    vec4 centre;


public:

    Object(const int npoints, QObject *parent = 0);
    Object(const int npoints, QString n);
    ~Object();

    void parseObjFile(const QString &fileName);

    void setTexture(QOpenGLTexture *t);

    virtual void make();
    virtual void toGPU(QGLShaderProgram *p);
    virtual void toGPUTexture(QGLShaderProgram *pr);

    virtual void draw();
    virtual void drawTexture();

    Capsa3D calculCapsa3D();

    virtual void aplicaTG(TG *tg);
    void aplicaTGraw(TG *tg);
    void setMaterial(Material*);




private:
    void initTexture();
    void calcCoord();
};



#endif // Object_H
