# Practica2GPU2018

GiV - P2
----------  

## Abstract

Aquesta pràctica tan sols conta d'una fase, per a l'entrega obligatòria. En aquesta fase, hem implementat diferents tipus de shading.
Per a fer això, hem reutilitzat codi de la primera pràctica de l'assignatura, per tal de implementar dues classes, per tal de representar les propietats dels objectes(fent servir la classe Material) i les llums d'una escena(fent servir la classe Light). 
Un cop implementades aquestes dos classes, les hem afegit en una escena, per tal de, fent servir els diferents shaders que hem implementat, representar-la.
Seguint l'enunciat de la pràctica, hem implementat diferents shaders(gouraud, phong, toon...), tenint en compte les diferències entre vertex shader i fragment shader, i hem aconseguit representar l'escena correctament, fent servir tècniques de shading diferents.

Hem implementat les diferents parts opcionals de la primera fase de la pràctica, pero no les de la fase 2.

## Features

- Fase 1
    - Material
    - Light
        - [FET] Puntual - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] Direccional - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] (Opcional) Spotlight - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] Ambient Global - Arnau Vancells, Sergi Martorell i Albert Morales
    - Shading
        - [FET] Phong - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] Gouroud - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] (Opcional) Toon - Arnau Vancells, Sergi Martorell i Albert Morales 
    - Textures
        - [FET] Textura com material - Arnau Vancells, Sergi Martorell i Albert Morales
        - [FET] Mapping indirecte - Arnau Vancells, Sergi Martorell i Albert Morales

- Fase 2 (Parts opcionals) 
    - [ ] Normal mapping
    - [ ] Entorn amb textures
    - [ ] Reflexions
    - [ ] Transparencias via objectes.
    - [ ] Transparencias via environmental mapping.

## Screenshots

Les captures de pantalla poden ser visualitzades al fitxer MEMORIA.pdf que hi ha al repositori de github.

## Additional Information

Hores de dedicació:

-Arnau Vancells: mitja de 15h / setmana

-Sergi Martorell: mitja de  15h / setmana

-Albert Morales: mitja de 15h / setmana

Un dels problemes que hem tingut durant aquesta pràctica, ha sigut respecte l'ús del buffer per a transmetre dades a la GPU, doncs, quan guardavem les coordenades de les textures, assignavem la mesura de cada dada a 4, en lloc de 2(estavem treballant amb vec2), i llavors la textura no es mostrava, tot i que no apareixía cap error a l'hora d'executar.

Un altre problema, relacionat amb la part opcional del mapping indirecte, és que degut a com realitzem els càlculs, hi ha una linea de pixels en l'objecte, on la textura no es mostra correctament. Creiem que és degut a que el valor de (u,v) mai arriba a 0 ni a 1, i per això, on la textura està al principi i al final de l'imatge de original, a l'objecte no es mostra completament. Ho podriem solucionar afegint un threshold, que quan el valor estigués molt a prop de 0 o 1, s'arrodonis a aquests valors.

