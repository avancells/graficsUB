#include "./objects/Object.h"


/**
 * @brief Object::Object
 * @param npoints
 * @param parent
 */
Object::Object(int npoints, QObject *parent) : QObject(parent){
    numPoints = npoints;
    points = new point4[numPoints];
    normals= new point4[numPoints];
    colors = new point4[numPoints];
    coordTex = new vec2[numPoints]; //creem el vector pels texels
    material = new Material(vec3(0.8,0.0,0.0),vec3(0.2,0.2,0.2),vec3(0.1,0.1,0.1),1,5);
    texture = NULL;
    centre = vec4(0.0,0.0,0.0,0.0);
 }

/**
 * @brief Object::Object
 * @param npoints
 * @param n
 */
Object::Object(int npoints, QString n) : numPoints(npoints){
    points = new point4[numPoints];
    normals= new point4[numPoints];
    colors = new point4[numPoints];
    coordTex = new vec2[numPoints]; //creem el vector pels texels
    material = new Material(vec3(0.8,0.0,0.0),vec3(0.2,0.2,0.2),vec3(0.1,0.1,0.1),1,5);
    texture = NULL;
    centre = vec4(0.0,0.0,0.0,0.0);
    parseObjFile(n);
    make();
}


/**
 * @brief Object::~Object
 */
Object::~Object(){
    delete points;
    delete normals;
    delete colors;
}

/**
 * @brief Object::toGPU
 * @param pr
 */
void Object::toGPU(QGLShaderProgram *pr) {
    // TO  DO: A modificar a la fase 1 de la practica 2

    qDebug() << "Obj to GPU.....";

    program = pr;
    // Creació d'un vertex array object

    glGenVertexArrays( 1, &vao );

    // Creacio i inicialitzacio d'un vertex buffer object (VBO)
    glGenBuffers( 1, &buffer );
    toGPUTexture(program);
}


/**
 * Pintat en la GPU.
 * @brief Object::draw
 */
void Object::draw(){
    // TO  DO: A modificar a la fase 1 de la practica 2
    // Cal passar les normals a la GPU

    // Aqui s'ha de fer el pas de dades a la GPU per si hi ha més d'un objecte
    // Activació a GL del Vertex Buffer Object
    material->toGPU(program); //enviem les dades del material a la GPU

    drawTexture(); //fem el draw de texture
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    glBufferData( GL_ARRAY_BUFFER, sizeof(point4)*Index + sizeof(point4)*Index + sizeof(point4)*Index + sizeof(vec2)*Index, NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4)*Index, points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index, sizeof(point4)*Index, colors );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index + sizeof(point4)*Index, sizeof(point4)*Index, normals);

    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index + sizeof(point4)*Index + sizeof(point4)*Index, sizeof(vec2)*Index, coordTex);




    // set up vertex arrays
    glBindVertexArray( vao );
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0,  0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0,  (void*)(sizeof(point4)*Index));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0,  (void*)(sizeof(point4)*Index + sizeof(point4)*Index));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0,  (void*)(sizeof(point4)*Index + sizeof(point4)*Index + sizeof(point4)*Index));
    glEnableVertexAttribArray(3);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays( GL_TRIANGLES, 0, Index );

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);

    GLuint objCenter = program->uniformLocation("center");
    glUniform4fv(objCenter, 1, this->centre);





}

/**
 * @brief Object::make
 */
void Object::make(){

    // TO  DO: A modificar a la fase 1 de la practica 2
    // Cal calcular la normal a cada vertex a la CPU



    static vec3  base_colors[] = {
        vec3( 1.0, 0.0, 0.0 ),
        vec3( 0.0, 1.0, 0.0 ),
        vec3( 0.0, 0.0, 1.0 ),
        vec3( 1.0, 1.0, 0.0 )
    };
    Index = 0;
    for(unsigned int i=0; i<cares.size(); i++){
        cares[i].calculaNormal(vertexs);
        for(unsigned int j=0; j<cares[i].idxVertices.size(); j++){
            points[Index] = vertexs[cares[i].idxVertices[j]];
            normals[Index] = normalsVertexs[cares[i].idxNormals[j]];// assignem els valors de les normals carregats amb l'objecte
            colors[Index] = vec4(base_colors[j%4], 1.0);

            if(cares[i].idxTextures.size() != 0){ // si no hem carregat els valors dels texels
                coordTex[Index] = textVertexs[cares[i].idxTextures[j]]; // assignem els velors dels texels carregats amb l'objecte
            }else{
                coordTex[Index] = vec2(-1.0,-1.0); // els inicialitzem a NULL, per fer mapping indirecte als shaders
            }


            Index++;
        }
    }
    initTexture();




}




/**
 * @brief Object::toGPUTexture
 * @param pr
 */
void Object::toGPUTexture(QGLShaderProgram *pr) {
    program = pr;

    // TO DO: Cal implementar en la fase 2 de la practica 2
    // S'ha d'activar la textura i es passa a la GPU
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_TEXTURE_2D );

}


/**
 * Pintat en la GPU.
 * @brief Object::drawTexture
 */
void Object::drawTexture(){

    // TO DO: Cal implementar en la fase 2 de la practica 2
    // S'ha d'activar la textura i es passa a la GPU
    initTexture();
    program->setUniformValue("texture", 0);




}

void Object::setTexture(QOpenGLTexture *t){
   texture = t;
   initTexture();
}

/**
 * @brief Object::initTexture
 */
void Object::initTexture()
 {
    // TO DO: A implementar a la fase 2 de la practica 2
    // Cal inicialitzar la textura de l'objecte: veure l'exemple del CubGPUTextura
    qDebug() << "Initializing textures...";
    // Carregar la textura

    //setTexture(new QOpenGLTexture(QImage("/home/smartote13.alumnes/Escriptori/grafics/pract2/resources/textures/earth1.png")));
    if(!texture){
        return;
    }
    glActiveTexture(GL_TEXTURE0);
    texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    texture->bind(0);
 }


void Object::parseObjFile(const QString &fileName)
{
    QFile file(fileName);
    if(file.exists()) {
        if(file.open(QFile::ReadOnly | QFile::Text)) {
            QVector<QVector3D> v, vn;
            QVector<QVector2D> vt;

            while(!file.atEnd()) {
                QString line = file.readLine().trimmed();
                QStringList lineParts = line.split(QRegularExpression("\\s+"));
                if(lineParts.count() > 0) {
                    // if it’s a comment
                    if(lineParts.at(0).compare("#", Qt::CaseInsensitive) == 0)
                    {
                        qDebug() << line.remove(0, 1).trimmed();
                    }

                    // if it’s a vertex position (v)
                    else if(lineParts.at(0).compare("v", Qt::CaseInsensitive) == 0)
                    {
                        vertexs.push_back(point4(lineParts.at(1).toFloat(),
                                           lineParts.at(2).toFloat(),
                                           lineParts.at(3).toFloat(), 1.0f));
                    }

                    // if it’s a normal (vn)
                    else if(lineParts.at(0).compare("vn", Qt::CaseInsensitive) == 0)
                    {
                        normalsVertexs.push_back (point4(lineParts.at(1).toFloat(),
                                            lineParts.at(2).toFloat(),
                                            lineParts.at(3).toFloat(), 0.0f));
                    }

                    // if it’s a texture (vt)
                    else if(lineParts.at(0).compare("vt", Qt::CaseInsensitive) == 0)
                    {
                        textVertexs.push_back(vec2(lineParts.at(1).toFloat(),
                                            lineParts.at(2).toFloat()));
                    }

                    // if it’s face data (f)
                    // there’s an assumption here that faces are all triangles
                    else if(lineParts.at(0).compare("f", Qt::CaseInsensitive) == 0)
                    {
                        Cara *cara = new Cara();

                        // get points from v array
                        cara->idxVertices.push_back(lineParts.at(1).split("/").at(0).toInt() - 1);
                        cara->idxVertices.push_back(lineParts.at(2).split("/").at(0).toInt() - 1);
                        cara->idxVertices.push_back(lineParts.at(3).split("/").at(0).toInt() - 1);

                        if(textVertexs.size() > 0) // check if really there are any UV coords
                        {
                            cara->idxTextures.push_back( lineParts.at(1).split("/").at(1).toInt() - 1);
                            cara->idxTextures.push_back( lineParts.at(2).split("/").at(1).toInt() - 1);
                            cara->idxTextures.push_back( lineParts.at(3).split("/").at(1).toInt() - 1);
                        }

                        // get normals from vn array
                        cara->idxNormals.push_back( lineParts.at(1).split("/").at(2).toInt() - 1);
                        cara->idxNormals.push_back( lineParts.at(2).split("/").at(2).toInt() - 1);
                        cara->idxNormals.push_back( lineParts.at(3).split("/").at(2).toInt() - 1);


                        // cara->calculaNormal();
                        cares.push_back(*cara);
                    }

                }
            }

            file.close();
        }
    }
}




Capsa3D Object::calculCapsa3D()
{
    vec3    pmin, pmax;
    int     i;
    Capsa3D capsa;

    pmin.x = points[0].x;
    pmin.y = points[0].y;
    pmin.z = points[0].z;
    pmax = pmin;
    for(i=1; i<Index; i++) {
        if(points[i].x <pmin[0])
            pmin[0] = points[i].x;
        if(points[i].y <pmin[1])
            pmin[1] = points[i].y;
        if(points[i].z <pmin[2])
            pmin[2] = points[i].z;

        if(points[i].x >pmax[0])
            pmax[0] = points[i].x;
        if(points[i].y >pmax[1])
            pmax[1] = points[i].y;
        if(points[i].z >pmax[2])
            pmax[2] = points[i].z;
    }
    capsa.pmin = pmin;
    capsa.a = pmax[0]-pmin[0];
    capsa.h = pmax[1]-pmin[1];
    capsa.p = pmax[2]-pmin[2];

    this->centre = vec4(capsa.a/2.0 + capsa.pmin.x, capsa.h/2.0 + capsa.pmin.y, capsa.p/2.0 + capsa.pmin.z, 1.0);
    return capsa;
}

void Object::aplicaTG(TG *tg){

    if(dynamic_cast<TranslateG *>(tg) || dynamic_cast<ScaleBoundary *>(tg) || dynamic_cast<RotateBoundary *>(tg)) {

        mat4 objectToWorld = tg->getTG();
        for(int i = 0; i < vertexs.size(); i++){
            vertexs[i] = objectToWorld * vertexs[i];
        }
        for(int i = 0; i < normalsVertexs.size(); i++){
            normalsVertexs[i] = objectToWorld * normalsVertexs[i];
        }

    }else if(dynamic_cast<Rotate *>(tg) || dynamic_cast<ScaleG *>(tg)) {

        //fase-trans-1
        TG *translate = new TranslateG(vec3(-centre.x, -centre.y, -centre.z));

        mat4 objectToWorld = translate->getTG();
        for(int i = 0; i < vertexs.size(); i++){
            vertexs[i] = objectToWorld * vertexs[i];
        }
        for(int i = 0; i < normalsVertexs.size(); i++){
            normalsVertexs[i] = objectToWorld * normalsVertexs[i];
        }

        //fase-trans-2
        objectToWorld = tg->getTG();
        for(int i = 0; i < vertexs.size(); i++){
            vertexs[i] = objectToWorld * vertexs[i];
        }
        for(int i = 0; i < normalsVertexs.size(); i++){
            normalsVertexs[i] = objectToWorld * normalsVertexs[i];
        }

        //fase-trans-3
        translate = new TranslateG(vec3(centre.x, centre.y, centre.z));

        objectToWorld = translate->getTG();
        for(int i = 0; i < vertexs.size(); i++){
            vertexs[i] = objectToWorld * vertexs[i];
        }
        for(int i = 0; i < normalsVertexs.size(); i++){
            normalsVertexs[i] = objectToWorld * normalsVertexs[i];
        }
    }
    make();
}

void Object::setMaterial(Material *material){
    this->material = material;
}


