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

enum corner{PC,NO,SE,NE,SO};
typedef enum corner coin;


int est_coin(plateau *tab, int x, int y){
	
	if ( x + y == 0)
		return NO;
	if (x == tab->lig - 1 && y == tab->col - 1)
		return SE;
	if (x == 0 && y == tab->col - 1)
		return NE;
	if (x == tab->lig - 1 && y == 0)
		return SO;
	return PC;
	
}



int est_isole(plateau *tab, int x, int y){ 
	int nord = tab->t[(x-1) * tab->col + y];
	int sud = tab->t[(x+1) * tab->col + y];
	int ouest = tab->t[x * tab->col + (y-1)];
	int est = tab->t[x * tab->col + (y+1)];
	int c = est_coin(tab,x,y);
	printf( "%d %d %d %d \n", nord,sud,ouest,est);
	switch (c)
	{
		case NO:
			if (sud + est == 0) 
				return 1;
			break;
		case NE:
			if (sud + ouest == 0) 
				return 1;
			break;
		case SO:
			if (nord + est == 0) 
				return 1;
			break;
		case SE:
			if (nord + ouest == 0) 
				return 1;
			break;
		case PC:
			if (x == 0){
				if (sud + est + ouest == 0) 
					return 1;
			}
			else if (x == tab->lig -1){
				if (est + nord + ouest == 0) 
					return 1;
			}
			else if (y == 0){
				if (sud + est + nord == 0) 
					return 1;
			}
			else if (y == tab->col -1){
				if (sud + nord + ouest == 0) 
					return 1;
			}
			else if (nord + sud + est + ouest == 0){ 
				return 1;
			break;
			}
		default:
			break;
	}
	return 0;
}


/*
int nb_liberte(int x, int y){

}
*/

int main (){
    /*déclaration plateau de jeu*/
    int sx, sy;
    plateau tab;
    sx = 6;
    sy = 6;
    tab = creer(sx, sy);

    /*création de pierre*/
    pierre pj1 = BLACK;
    pierre pj2 = WHITE;

    /*Pointeur vers tab*/
    plateau *ptr;
    ptr = &tab;
    
    /*Test utilisation du pointeur*/
    voirtab(ptr);
    /*test placer une pierre */
    placer_pierre(ptr,0,0,pj1);
    placer_pierre(ptr,0,1,pj2);
	placer_pierre(ptr,0,5,pj2);
    placer_pierre(ptr,0,4,pj1);
    placer_pierre(ptr,3,3,pj2);
	placer_pierre(ptr,3,4,pj2);
    voirtab(ptr);
	printf(" 0:PC , 1:NO , 2:SE, 3:NE, 4:SO \n");
	printf(" la pierre est dans le coin : %d \n", est_coin(ptr,0,5));
	printf(" la pierre est isole : %d \n", est_isole(ptr,0,5));

    return 0;    
}

