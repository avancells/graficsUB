GiV - P1
----------

Abstract
----------
En les fases 0 1 i 2 de la pràctica 1 hem implementat un conjunt d'objectes(triangle, esfera i pla) que els fem servir per a poder realitzar
una escena a partir de la informació que aquests objectes ens proporcionen. Per tal de poder fer representacions variades, hem implementat
diferents transformacions geomètriques per tal de poder moure els objectes en l'espai de representació. A més els diferents objectes poden
ser creats amb un tipus de material diferent. Hi ha tres tipus de material: Lambertian, Metal i Transparent. Per a la visualització de l'escena
es té en compte la trajectòria dels rajos, fins a un cert limit(els rajos no es reflexaran fins l'infinit), fent servir el mètode Blinn-Phong recursiu.

Features
----------

- Figures
    - [FET] Plane - Arnau Vancells, Sergi Martorell i Albert Morales
    - [FET] Triangle - Arnau Vancells, Sergi Martorell i Albert Morales
    - [FET] Sphere - Arnau Vancells, Sergi Martorell i Albert Morales
    - [FET] Boundary Object - Arnau Vancells
- Blinn-Phong
    - [FET] Light - Sergi Martorell
    - [FET] Basic Blinn-Phong - Arnau Vancells, Sergi Martorell i Albert Morales
    - [FET] Recursive Blinn-Phong - Arnau Vancells, Sergi Martorell i Albert Morales
- Material
    - [FET] Metal - Arnau Vancells, Sergi Martorell i Albert Morales
    - [FET] Transparent Arnau Vancells, Sergi Martorell i Albert Morales
- Animaciones
    - [FET] aplicaTG i escenas - Arnau Vancells Sergi Martorell i Albert Morales
        **(fetes transformacions geomètriques i escenes, però no de la fase 3)

Extensions
----------
Com a extra hem implementat:
-Antialiasing
Les extensions de la pràctica estàn explicades al fitxer MEMORIA.pdf que hi ha al repositori del github.

Screenshots
----------
Les captures de pantalla poden ser visualitzades al fitxer MEMORIA.pdf que hi ha al repositori de github.

Additional Information
----------
Hores de dedicació:

-Arnau Vancells: mitja de 15h / setmana

-Sergi Martorell: mitja de  8h / setmana

-Albert Morales: mitja de 6h / setmana


La major part de problemes que hem tingut durant la pràctica han sigut degut a que la informació de les diapositives de teoria no s'havia entès del tot bé, i llavors implementar-ho
sense errors és difícil.
Un dels problemes que haviem tingut va ser que l'escalat de BoundaryObject no es realitzava correctament, però va resultar que funcionava bé, però el punt de vista de l'escena no era correcte
per a veure l'escalat correctament.
El material Metal ens ha donat problemes a l'hora de mostrar el color en les reflexions, i era degut a que al .h de la classe Metal hi haviem declarat les components corresponents a la classe pare(ambient, difussa...)
i això feia que en algún cas es llegís la informació d'aquests paràmetres com a 0, cosa que feia que el color no es mostrés.

Un últim error que no hem pogut arreglar està explicat al final de la memòria que hi ha penjada, els objectes transparents, en certs casos(sobretot quan són intersecats per un altre objecte) generen punts d'acne
negres a la imatge. En les escenes finals es pot veure com hi ha objectes que travessen la esfera transparent(el peó i una esfera lambertiana), i es veuen pixels negres pel voltant de la intersecció i exteriors.
