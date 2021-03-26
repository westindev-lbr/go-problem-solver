#include <stdio.h>
#include <stdlib.h>
//gcc -wall -Wextra -wpedentic
enum content
{
	EMPTY,
	BLACK,
	WHITE
};
typedef enum content pierre;

typedef pierre *ptrpierre;

struct tableau
{
	ptrpierre t;
	int col;
	int lig;
};
typedef struct tableau plateau;

/*Création d'un plateau*/
plateau creer(int x, int y)
{
	plateau tab;
	tab.col = y;
	tab.lig = x;
	tab.t = (ptrpierre)malloc((size_t)(y * x * sizeof(pierre)));
	return tab;
}

/*fonction placer une pierre*/
void placer_pierre(plateau *tab, int i, int j, pierre p)
{
	if (i < tab->lig && j < tab->col)
	{
		tab->t[(i * tab->col) + j] = p;
	}
}

/*fonction affiche tableau */
void voirtab(plateau *tab)
{
	int i, j;
	for (j = 0; j < tab->col; j++)
	{
		printf(" %2d ", j);
	}
	printf("\n");
	for (i = 0; i < tab->lig; i++)
	{
		printf("%d|", i);
		for (j = 0; j < tab->col; j++)
		{
			printf(" %d ", tab->t[i * tab->col + j]);
		}
		printf("\n");
	}
}

enum corner
{
	PC,
	NO,
	SE,
	NE,
	SO
};
typedef enum corner coin;

int est_coin(plateau *tab, int x, int y)
{

	if (x + y == 0)
		return NO;
	if (x == tab->lig - 1 && y == tab->col - 1)
		return SE;
	if (x == 0 && y == tab->col - 1)
		return NE;
	if (x == tab->lig - 1 && y == 0)
		return SO;
	return PC;
}

int est_isole(plateau *tab, int x, int y)
{
	int nord = tab->t[(x - 1) * tab->col + y];
	int sud = tab->t[(x + 1) * tab->col + y];
	int ouest = tab->t[x * tab->col + (y - 1)];
	int est = tab->t[x * tab->col + (y + 1)];
	int c = est_coin(tab, x, y);
	printf("%d %d %d %d \n", nord, sud, ouest, est);
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
		if (x == 0)
		{
			if (sud + est + ouest == 0)
				return 1;
		}
		else if (x == tab->lig - 1)
		{
			if (est + nord + ouest == 0)
				return 1;
		}
		else if (y == 0)
		{
			if (sud + est + nord == 0)
				return 1;
		}
		else if (y == tab->col - 1)
		{
			if (sud + nord + ouest == 0)
				return 1;
		}
		else if (nord + sud + est + ouest == 0)
		{
			return 1;
			break;
		}
	default:
		break;
	}
	return 0;
}
//nombre de liberté de 1 seule pierre

int nb_liberte(plateau *tab, int x, int y)
{
	int nb = 0;
	int nord = tab->t[(x - 1) * tab->col + y];
	int sud = tab->t[(x + 1) * tab->col + y];
	int ouest = tab->t[x * tab->col + (y - 1)];
	int est = tab->t[x * tab->col + (y + 1)];
	int c = est_coin(tab, x, y);
	switch (c)
	{
	case NO:
		if (sud == 0)
			nb++;
		if (est == 0)
			nb++;
		break;
	case NE:
		if (sud == 0)
			nb++;
		break;
		if (ouest == 0)
			nb++;
		break;
	case SO:
		if (nord == 0)
			nb++;
		if (est == 0)
			nb++;
		break;
	case SE:
		if (nord == 0)
			nb++;
		if (ouest == 0)
			nb++;
		break;
	case PC:
		if (x == 0)
		{
			if (sud == 0)
				nb++;
			if (est == 0)
				nb++;
			if (ouest == 0)
				nb++;
		}
		else if (x == tab->lig - 1)
		{
			if (est == 0)
				nb++;
			if (nord == 0)
				nb++;
			if (ouest == 0)
				nb++;
		}
		else if (y == 0)
		{
			if (sud == 0)
				nb++;
			if (est == 0)
				nb++;
			if (nord == 0)
				nb++;
		}
		else if (y == tab->col - 1)
		{
			if (sud == 0)
				nb++;
			if (nord == 0)
				nb++;
			if (ouest == 0)
				nb++;
		}
		else
		{
			if (nord == 0)
			{
				nb++;
			}
			if (sud == 0)
			{
				nb++;
			}
			if (ouest == 0)
			{
				nb++;
			}
			if (est == 0)
			{
				nb++;
			}
			break;
		}
	default:
		break;
	}
	return nb;
}

int est_paire(plateau *tab, int x, int y, int x2, int y2) {
	if(est_coin(tab, x, y)) {
		if (x2 == x-1)
			{
				return 1;
			}
			if (x2 == x+1)
			{
				return 1;
			}
			if (y2 == y-1)
			{
				return 1;
			}
			if (y2 == y+1)
			{
				return 1;
			}
	}
	return 0;
}

int est_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3) {
	if(est_paire(tab, x, y, x2, y2)) {
		if (est_paire(tab, x2, y2, x3, y3))
			{
				return 1;
			}
			
	}
	return 0;
}


int nb_liberte_paire(plateau *tab, int x, int y, int x2, int y2) {
	if (est_paire(tab,x, y, x2, x2))
	{
		return nb_liberte(tab, x, y) + nb_liberte(tab, x2, y2);
	}
	return -1;	
}

int nb_liberte_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3) {
	if (est_triplet(tab,x, y, x2, x2, x3, x3))
	{
		return nb_liberte(tab, x, y) + nb_liberte(tab, x2, y2) + nb_liberte(tab, x3, y3);
	}
	return -1;
}

int nb_liberte_paire2(plateau *tab, int x, int y)
{
	int current = tab->t[x * tab->col + y];
	int nord = tab->t[(x - 1) * tab->col + y];
	int sud = tab->t[(x + 1) * tab->col + y];
	int ouest = tab->t[x * tab->col + (y - 1)];
	int est = tab->t[x * tab->col + (y + 1)];
	int nb_liberte_current = nb_liberte(tab, x, y);
	if (nord == current)
	{
		return nb_liberte_current + nb_liberte(tab, x - 1, y);
	}
	if (sud == current)
	{
		return nb_liberte_current + nb_liberte(tab, x + 1, y);
	}
	if (ouest == current)
	{
		return nb_liberte_current + nb_liberte(tab, x, y - 1);
	}
	if (est == current)
	{
		return nb_liberte_current + nb_liberte(tab, x, y + 1);
	}
	return -1;
}

//quel est le nombre de libertés de la paire de pierres (x,y), (x', y') ?


int main()
{
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
	placer_pierre(ptr, 0, 0, pj1);
	placer_pierre(ptr, 0, 1, pj1);
	placer_pierre(ptr, 0, 5, pj2);
	placer_pierre(ptr, 0, 4, pj1);
	placer_pierre(ptr, 3, 3, pj2);
	placer_pierre(ptr, 3, 4, pj2);
	voirtab(ptr);
	printf(" 0:PC , 1:NO , 2:SE, 3:NE, 4:SO \n");
	printf(" la pierre est dans le coin : %d \n", est_coin(ptr, 5, 5));
	printf(" la pierre est isole : %d \n", est_isole(ptr, 5, 5));
	printf(" le nombre de liberté est : %d \n", nb_liberte(ptr, 0, 0));
	printf(" le nombre de liberte d'une paire : %d \n", nb_liberte_paire(ptr, 0, 0, 0, 1));
	printf(" Savoir si c'est une paire %d \n", est_paire(ptr, 3, 3, 3, 4));

	return 0;
}
// gcc -Wall -Wextra -Wpedantic