# RAPPORT DE PROJET GO
by Axel Labarre & Vincent Vilfeu

1. Très facile :
[x] Quel est le nombre de libertés de la pierre isolée (x,y) ?

4 pierres coins (1,1),(1,6),(6,1),(6,6) = 2lib 
16  pierres bords (2,1),(3,1)(4,1)(5,1) etc = 3lib
16 pierres centre (2,2),(2,3).. (3,3)..(4,4) (5,5) = 4lib

[x] Quel est le nombre de libertés de la paire de pierres (x,y), (x', y') ?

Paires dans le coins = 3lib 
Paires au bord = 4lib
Paire au centre = 6lib 

[x] Quel est le nombre de libertés du triplet de pierres (x,y), (x', y'), (x", y") ?

Triplet sur angle = 3lib 
Triplet verticale sur coins = 4lib 
Triplet sur bord = 5lib 
Triplet horizontale au centre = 8 lib
Triplet en angle au centre = 7lib 

[x] la pierre (x,y) est-elle isolée ?
Elle est isolée si aucune pierre autour (pierre au centre)
la pierre (1,1) non isolée = true 
    si aucune pierre (x+1,y+1)


[x] quel est le nombre de libertés de la pierre non isolée (x,y) ?


Création d'une fonction placer_pierre() pour placer une pierre sur le plateau à une position précise. 

Création de pierre par enumeration. 

Création du plateau de jeu creer() avec malloc de struct plateau + son size x et y. 

Création de la fonction est_coin d'une pierre en paramètre
- Permet de savoir si une pierre se trouve dans un coin du Goban 

Création de la fonction est_isole()
- Permet de savoir si une pierre est isolée

Création de la fonction nb_liberte()
- Permet de savoir le nombre de liberte d'une pierre isolée ou non. 

Création de la fonction est_paire()
- Permet de savoir si deux pierres sont soeurs. 

Création de la fonction nb_liberte_paire()
-Permet de savoir le nb de libertes d'une paire.

Création de la fonction est_triplet()
- Permet de savoir si 3 pierres sont soeurs mais dans l'ordre croissant ou décroissant.

Création de la fonction nb_liberte_triplet()
- Permet de savoir cb de libertes d'un triplet.





