#include <stdio.h>
#include <stdlib.h>


enum content {EMPTY, BLACK, WHITE};
typedef enum content pierre;

typedef pierre  * ptrpierre;
struct tableau {
  ptrpierre t;
  int col;
  int lig;
} ;
typedef struct tableau plateau;

/*Création d'un plateau*/
plateau creer(int x, int y) {
  plateau tab;
  tab.col = y;
  tab.lig = x;
  tab.t = (ptrpierre) malloc ((size_t) (y * x * sizeof(pierre)));
  return tab;
}

/*fonction placer une pierre*/
void placer_pierre(plateau *tab, int i, int j, pierre p) {
  if (i < tab->lig && j < tab->col) {
    tab->t[(i * tab->col) + j] = p;
  }
}

/*fonction affiche tableau */
void voirtab(plateau *tab) {
  int i, j;
  for (j = 0; j < tab->col; j++) {
	printf  (" %2d ", j);
  }
  printf("\n");
  for (i = 0; i < tab->lig; i++) {
	printf ("%d|", i);
	for (j = 0; j < tab->col; j++) {
      printf (" %d ", tab->t[i * tab->col + j]);
	}
	printf("\n");
  }
}


int main (){
    /*déclaration plateau de jeu*/
    int sx, sy;
    plateau tab;
    sx = 6;
    sy = 6;
    tab = creer(sx, sy);

    /*création de pierre*/
    pierre J1 = 1;
    pierre J2 = 2;

    /*Pointeur vers tab*/
    plateau *ptr;
    ptr = &tab;
    
    /*Test utilisation du pointeur*/
    voirtab(ptr);
    /*test placer une pierre */
    placer_pierre(ptr,0,0,J1);
    placer_pierre(ptr,0,1,J2);
    voirtab(ptr);

    return 0;    
}

