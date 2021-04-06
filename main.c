#include <stdio.h>
#include <stdlib.h>

enum content
{
	EMPTY,
	BLACK,
	WHITE
};
typedef enum content pierre;

enum corner
{
	PC,
	NO,
	SE,
	NE,
	SO
};
typedef enum corner coin;

typedef pierre *ptrpierre;

struct tableau
{
	ptrpierre t;
	int col;
	int lig;
};
typedef struct tableau plateau;

typedef enum{
	PROB1 = 1,
	PROB2,
	PROB3,
}prob;

#define actuel tab->t[x * tab->col + y]
#define	nord tab->t[(x - 1) * tab->col + y]
#define	sud tab->t[(x + 1) * tab->col + y]
#define	ouest tab->t[x * tab->col + (y - 1)]
#define	est tab->t[x * tab->col + (y + 1)]

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
void placer_pierre(plateau *tab, int x, int y, pierre p)
{
	if (x < tab->lig && y < tab->col)
	{
		actuel = p;
	}
}

/*fonction affiche tableau */
void voirtab(plateau *tab)
{
	int x, y;
	printf("     A    B    C    D    E    F\n");
	printf("  =============================\n");
	for (x = 0; x < tab->lig; x++)
	{
		printf("%d||", x);
		for (y = 0; y < tab->col; y++)
		{
			printf("  %d  ", actuel);
		}
		printf("\n");
	}
}

/*Savoir si une pierre est dans un coin*/
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

/*savoir si un pierre est isolée*/
int est_isole(plateau *tab, int x, int y)
{
	// int nord = tab->t[SIZE = 36];
	// int nord = tab->t[i][j];
	//int coord = x* tab->col + y;
	if(actuel == 0) {
		puts("Il n'y a pas de pierre placer ici !");
		return -1;
	}
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

/* nombre de liberté de 1 seule pierre */
int nb_liberte(plateau *tab, int x, int y)
{
	int nb = 0;
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

/* Si le pierre est à coté d'une seule autre pierre de la même couleur retourne 1 */
int est_paire(plateau *tab, int x, int y, int x2, int y2)
{
	int c = est_coin(tab, x, y);
	switch (c)
	{
	case NO:
		if (sud == actuel)
			return 1;
		if (est == actuel)
			return 1;
		break;
	case NE:
		if (sud == actuel)
			return 1;
		if (ouest == actuel)
			return 1;
		break;
	case SO:
		if (nord == actuel)
			return 1;
		if (est == actuel)
			return 1;
		break;
	case SE:
		if (nord == actuel)
			return 1;
		if (ouest == actuel)
			return 1;
		break;
	case PC:
		if (x == 0)
		{
			if (sud == actuel)
				return 1;
			if (est == actuel)
				return 1;
			if (ouest == actuel)
				return 1;
		}
		else if (x == tab->lig - 1)
		{
			if (est == actuel)
				return 1;
			if (nord == actuel)
				return 1;
			if (ouest == actuel)
				return 1;
		}
		else if (y == 0)
		{
			if (sud == actuel)
				return 1;
			if (est == actuel)
				return 1;
			if (nord == actuel)
				return 1;
		}
		else if (y == tab->col - 1)
		{
			if (sud == actuel)
				return 1;
			if (nord == actuel)
				return 1;
			if (ouest == actuel)
				return 1;
		}
		else
		{
			if (x2 == x - 1)
			{
				return 1;
			}
			if (x2 == x + 1)
			{
				return 1;
			}
			if (y2 == y - 1)
			{
				return 1;
			}
			if (y2 == y + 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

/* Le nombre de liberté de la paire de pierre */
int nb_liberte_paire(plateau *tab, int x, int y, int x2, int y2)
{
	if (est_paire(tab, x, y, x2, x2))
	{
		return nb_liberte(tab, x, y) + nb_liberte(tab, x2, y2);
	}
	return -1;
}

/* Fonctionne seulement dans l'ordre croissant ou décroissant ! */
int est_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3)
{
	if (est_paire(tab, x, y, x2, y2))
	{
		if (est_paire(tab, x2, y2, x3, y3))
		{
			return 1;
		}
	}
	return 0;
}
/* Fonctionne seulement dans l'ordre croissant ou décroissant!*/
int nb_liberte_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3)
{
	if (est_triplet(tab, x, y, x2, y2, x3, y3))
	{
		return nb_liberte(tab, x, y) + nb_liberte(tab, x2, y2) + nb_liberte(tab, x3, y3);
	}
	return -1;
}


/* Marquage groupe pierre placé */
void ft_marquage(plateau *tab, int x, int y, pierre j, int m)
{
	if (j == 0)
	{
		printf(" \n Il n'y a pas de pierre placer ici ! \n");
		return;
	}
	m = 10;
	if (j == actuel)
	{
		ft_marquage(tab, x - 1, y, j, actuel += m);
		m = 0;
		ft_marquage(tab, x + 1, y, j, actuel += m);
		m = 0;
		ft_marquage(tab, x, y + 1, j, actuel += m);
		m = 0;
		ft_marquage(tab, x, y - 1, j, actuel += m);
		m = 0;
	}
}

/* appel de ft_marquage */
void marquage(plateau *tab, int x, int y, pierre j)
{
	ft_marquage(tab, x, y, j, 0);
}

/* marquage du groupe de pierre opposée adjacente a la pierre placée */
void opp_visiter(plateau *tab, int x, int y)
{
	if (actuel == 0)
	{
		printf(" \n Impossible sur une case vide (0) \n");
		return;
	}
	if (nord != actuel && nord > 0)
	{
		marquage(tab, x - 1, y, nord);
	}
	if (est != actuel && est > 0)
	{
		marquage(tab, x, y + 1, est);
	}
	if (sud != actuel && sud > 0)
	{
		marquage(tab, x + 1, y, sud);
	}
	if (ouest != actuel && ouest > 0)
	{
		marquage(tab, x, y - 1, ouest);
	}
}

/*Marquage libertés groupe de la pierre j*/
void marq_case_vide(plateau *tab, pierre j)
{
	int x, y = 0;
	for (x = 0; x < tab->col; x++)
	{
		for (y = 0; y < tab->col; y++)
		{
			if (actuel == j)
			{
				if (nord == 0 && x > 1)
				{
					nord = 10;
				}
				if (est == 0 && y < 5)
				{
					est = 10;
				}
				if (sud == 0 && x < 5)
				{
					sud = 10;
				}
				if (ouest == 0 && y > 1)
				{
					ouest = 10;
				}
			}
		}
	}
}

/* somme liberté du groupe de la pierre j */
int somme_liberte(plateau *tab, pierre j)
{
	int res, x, y;
	res = 0;
	marq_case_vide(tab, j);
	for (x = 0; x < tab->col; x++)
	{
		for (y = 0; y < tab->col; y++)
		{
			if (actuel == 10)
			{
				res++;
			}
		}
	}
	return res;
}

/* Supprimmer un groupe entouré */
void eliminer(plateau *tab, pierre j)
{
	int x, y;
	
	if (somme_liberte(tab, j) == 0)
	{
		for (x = 0; x < tab->col; x++)
		{
			for (y = 0; y < tab->col; y++)
			{
				if (actuel == j)
				{
					actuel = 0;
				}
			}
		}
	}
}

/*reset du tableau pour fin du tour*/
void remise_a_zero(plateau *tab)
{

	int x, y;

	for (x = 0; x < tab->col; x++)
	{
		for (y = 0; y < tab->col; y++)
		{
			if (actuel == 11)
			{
				actuel = 1;
			}
			else if (actuel == 12)
			{
				actuel = 2;
			}
			else
			{
				if (actuel == 10)
					actuel = 0;
			}
		}
	}
}

/*Saisir un problème manuellement */
void saisir_probleme(plateau *tab)
{
	char reponse;
	int p = 0;
	int x, y;
	int fin = 1;
	printf("Veuillez saisir un problème en plaçant des pierres (\"BLACK\" ou \"WHITE\") sur le plateau de jeu : \n");
	while (fin != 0)
	{
	pierre_inconnu:
		voirtab(tab);
		printf("Vous voulez placer une pierre \"BLACK\" ou \"WHITE\" ? \n");
		scanf("%d", &p);
		switch (p)
		{
		case BLACK:
			puts("Vous avez choisit une pierre de la couleur : BLACK");
			break;
		case WHITE:
			puts("Vous avez choisit une pierre de la couleur : WHITE");
			break;
		default:
			puts("Veuillez écrire la couleur de la pierre choisit corretement, merci");
			goto pierre_inconnu;
		}
	re_saisir_coord:
		puts("Indiquer maintenant les coordonnées de la pierre sur le plateau");
		puts("La valeur en x :");
		scanf("%d", &x);
		puts("La valeur en y :");
		scanf("%d", &y);
		if (x >= 0 && x <= tab->lig && y >= 0 && y <= tab->col)
		{
			placer_pierre(tab, x, y, p);
			voirtab(tab);
		}
		else
		{
			printf("ATTENTION, vous ne pouvez pas placer de pierre ici : [x = %d, y = %d] \n", x, y);
			goto re_saisir_coord;
		}
	pierre_suivante:
		printf("Pierre suivante ?  (o / n) \n");
		scanf("%c", &reponse);
		if (scanf("%c", &reponse) == 0)
		{
			puts("");
		}
		if (reponse != 'n' && reponse != 'o')
		{
			puts("Veuillez entrer 'o' ou 'n'");
			goto pierre_suivante;
		}
		if ('n' == reponse)
		{
			voirtab(tab);
			return;
		}
	}
}

/* Sélectionner un problème de Go */
void choix_probleme(void){
	int choix_tmp = 1;
	prob choix; 

	printf("Veuillez choisir un problème : \n");
	printf("1-Probleme 1\n");
	printf("2-Probleme 2\n");
	printf("3-Probleme 3\n");

	scanf("%d", &choix_tmp);
	choix = (prob)choix_tmp;

}


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

	/* Tableau de jeu init */
	voirtab(ptr);
	// printf(" 0:PC , 1:NO , 2:SE, 3:NE, 4:SO \n");
	placer_pierre(ptr, 0, 0, pj1);
	placer_pierre(ptr, 1, 0, pj1);
	placer_pierre(ptr, 0, 1, pj2);
	placer_pierre(ptr, 5, 3, pj2);

	printf(" la pierre est dans le coin : %d \n", est_coin(ptr, 5, 5));
	printf(" la pierre est isole : %d \n", est_isole(ptr, 0, 0));
	printf(" le nombre de liberté est : %d \n", nb_liberte(ptr, 0, 0));
	printf(" le nombre de liberte d'une paire : %d \n", nb_liberte_paire(ptr, 0, 0, 1, 0));
	printf(" Savoir si c'est une paire %d \n", est_paire(ptr, 0, 0, 1, 0));
	printf(" le nombre de liberte d'un triplet : %d \n", nb_liberte_triplet(ptr, 0, 5, 0, 4, 0, 3));
	printf(" Savoir si c'est un triplet %d \n", est_triplet(ptr, 0, 5, 0, 4, 0, 3));

	//opp_visiter(ptr,0,1);

	//marquage(ptr, 3, 2, 2);
	saisir_probleme(ptr);
	//eliminer(ptr,11);
	//printf("nb lib du groupe de la pierre placée vaut : %d \n", somme_liberte(ptr, 12));
	//voirtab(ptr);
	//printf("\n");
	//remise_a_zero(ptr);
	//voirtab(ptr);

	return 0;
}
// gcc -Wall -Wextra -Wpedantic