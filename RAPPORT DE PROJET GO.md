# RAPPORT DE PROJET GO
by Axel Labarre & Vincent Vilfeu

1. Très facile :
- quel est le nombre de libertés de la pierre isolée (x,y) ?

4 pierres coins (1,1),(1,6),(6,1),(6,6) = 2lib 
16  pierres bords (2,1),(3,1)(4,1)(5,1) etc = 3lib
16 pierres centre (2,2),(2,3).. (3,3)..(4,4) (5,5) = 4lib

- quel est le nombre de libertés de la paire de pierres (x,y), (x', y') ?

Paires dans le coins = 3lib 
Paires au bord = 4lib
Paire au centre = 6lib 

- quel est le nombre de libertés du triplet de pierres (x,y), (x', y'), (x", y") ?

Triplet sur angle = 3lib 
Triplet verticale sur coins = 4lib 
Triplet sur bord = 5lib 
Triplet horizontale au centre = 8 lib
Triplet en angle au centre = 7lib 

- la pierre (x,y) est-elle isolée ?
Elle est isolée si aucune pierre autour (pierre au centre)
la pierre (1,1) non isolée = true 
    si aucune pierre (x+1,y+1)


- quel est le nombre de libertés de la pierre non isolée (x,y) ?

Si non isolée de 1 pierre = 

Si enfermé = 0 lib 

Création d'une fonction placer_pierre() pour placer une pierre sur le plateau à une position précise. 

Création de pierre par enumeration. 

Création du plateau de jeu creer() avec malloc de struct plateau + son size x et y. 





