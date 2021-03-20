#include <stdio.h>
#include <stdlib.h>

struct pierre{
    char color;
    int x;
    int y;
};

typedef struct pierre pierre;
typedef pierre * tabpierre;
struct tableau {
  tabpierre t;
  int col;
  int lig;
} ;
typedef struct tableau plateau;

/*Création d'un plateau*/
plateau creer(int x, int y) {
  plateau tab;
  tab.col = y;
  tab.lig = x;
  tab.t = (tabpierre) malloc ((size_t) (y * x * sizeof(pierre)));
  return tab;
}

/*fonction placer une pierre*/
void placer_pierre(plateau *tab, int i, int j, pierre p) {
  if (i < tab->lig && j < tab->col) {
	
    tab->t[i + (j * tab->col)] = p;
    p.x=i;
    p.y=j;
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
	  //printf (" %2c ", tab->t->color);
      printf (" %2c ", tab->t[i * tab->col + j].color);
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
    pierre pn;
    pn.color = 'N';

    pierre pb;
    pb.color = 'B';

    /*Pointeur vers tab*/
    plateau *ptr;
    ptr = &tab;
    
    /*Test utilisation du pointeur*/
    voirtab(ptr);
    /*test placer une pierre */
    placer_pierre(ptr,0,0,pb);
    placer_pierre(ptr,0,1,pn);
    voirtab(ptr);

    return 0;    
}

