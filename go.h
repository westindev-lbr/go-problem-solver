#ifndef GO_H
#define GO_H

#define actuel tab->t[x * tab->col + y]
#define nord tab->t[(x - 1) * tab->col + y]
#define sud tab->t[(x + 1) * tab->col + y]
#define ouest tab->t[x * tab->col + (y - 1)]
#define est tab->t[x * tab->col + (y + 1)]

enum content
{
	EMPTY,
	BLACK,
	WHITE
};
typedef enum content pierre;

enum section
{
	S1 = 1,
	S2,
	S3,
    S4,
    S5,
    S6
};
typedef enum section menu;

enum quest
{
	Q0,
	Q1,
	Q2,
	Q3,
	Q4,
	Q5,
    Q6
};
typedef enum quest question;

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

typedef enum
{
	PROB1 = 1,
	PROB2,
	PROB3,
} prob;


/*Création d'un plateau*/
plateau creer(int x, int y);

/*fonction placer une pierre*/
void placer_pierre(plateau *tab, int x, int y, pierre p);

/*fonction affiche tableau */
void voirtab(plateau *tab);

/*Savoir si une pierre est dans un coin*/
int est_coin(plateau *tab, int x, int y);

/*savoir si un pierre est isolée*/
int est_isole(plateau *tab, int x, int y);

/* nombre de liberté de 1 seule pierre */
int nb_liberte(plateau *tab, int x, int y);

/* Si le pierre est à coté d'une seule autre pierre de la même couleur retourne 1 */
int est_paire(plateau *tab, int x, int y, int x2, int y2);

/* Le nombre de liberté de la paire de pierre */
int nb_liberte_paire(plateau *tab, int x, int y, int x2, int y2);

/* Fonctionne seulement dans l'ordre croissant ou décroissant ! */
int est_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3);

/* Fonctionne seulement dans l'ordre croissant ou décroissant!*/
int nb_liberte_triplet(plateau *tab, int x, int y, int x2, int y2, int x3, int y3);

/* Marquage groupe pierre placé */
void ft_marquage(plateau *tab, int x, int y, pierre j, int m);

/* appel de ft_marquage */
void marquage(plateau *tab, int x, int y, pierre j);

/* marquage du groupe de pierre opposée adjacente a la pierre placée */
void opp_visiter(plateau *tab, int x, int y);

/*Marquage libertés groupe de la pierre j*/
void marq_case_vide(plateau *tab, pierre j);

/* somme liberté du groupe de la pierre j */
int somme_liberte(plateau *tab, pierre j);

/* Supprimmer un groupe entouré */
void eliminer(plateau *tab, pierre j);

/*reset du tableau pour fin du tour*/
void update_plateau(plateau *tab);

/*Saisir un problème manuellement */
void saisir_probleme(plateau *tab);

/* Sélectionner un problème de Go */
void choix_probleme();

/* Selectionner la question pour avoir une réponse */
void choix_question(plateau *tab);

void jouer(plateau *tab);

void demarrer(plateau *tab);

void ia(plateau *tab, int x, int y, pierre p);

void capturer_atari(plateau *tab);

/*Capture un groupe adjacent s'il n'a plus de libertés*/
void capture_groupe(plateau *tab);

/*S'échappe si 1 liberté restante*/
void echapper(plateau *tab);

void probleme_atari3(plateau *tab);

/* probleme atari sur groupe */
void probleme_atari2(plateau *tab);

/* probleme atari simple */
void probleme_atari1(plateau *tab);

#endif