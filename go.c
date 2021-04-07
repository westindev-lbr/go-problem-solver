#include <stdio.h>
#include <stdlib.h>
#include "go.h"

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
    printf("     0    1    2    3    4    5\n");
    printf("  =============================\n");
    for (x = 0; x < tab->lig; x++)
    {
        printf("%d||", x);
        for (y = 0; y < tab->col; y++)
        {

            if (actuel > 0)
                printf("  %d  ", actuel);
            else if (actuel == 0)
                printf("  .  ");
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
    int coin = est_coin(tab, x, y);
    if (actuel > 0)
    {
        /*si la pierre est dans un coin unique cas d'etre isolée*/
        switch (coin)
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
        case PC:        //Pas dans le coin
            if (x == 0) //au bord Nord
            {
                if (sud + est + ouest == 0)
                    return 1;
            }
            else if (x == tab->lig - 1) //Bord Sud
            {
                if (est + nord + ouest == 0)
                    return 1;
            }
            else if (y == 0) //Bord Ouest
            {
                if (sud + est + nord == 0)
                    return 1;
            }
            else if (y == tab->col - 1) //Bord Est
            {
                if (sud + nord + ouest == 0)
                    return 1;
            }
            else if (nord + sud + est + ouest == 0) //Au centre
            {
                return 1;
                break;
            }
        default:
            break;
        }
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

/* Si la pierre est à coté d'une seule autre pierre de la même couleur retourne 1 */
/*int paire(plateau *tab, int x, int y, int x2, int y2)
{
    int coin = est_coin(tab, x, y);
    if (actuel > 0)
    {
        switch (coin)
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
        case PC: // Pas dans le coin
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
                if (nord == actuel)
                {
                    return 1;
                }
                if (sud == actuel)
                {
                    return 1;
                }
                if (ouest == actuel)
                {
                    return 1;
                }
                if (est == actuel)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
*/

/*savoir si 2 pierres sont paires */
int est_paire(plateau *tab, int x, int y, int x2, int y2)
{
    /*si les coordonnées de x,y et x2,y2 sont dans le tableau */
    if (x >= 0 && x < tab->lig && y >= 0 && y < tab->col)
    {
        if (x2 >= 0 && x2 < tab->lig && y2 >= 0 && y2 < tab->col)
        {
            /*si x,y est une pierre et que x2,y2 sont de la meme couleur*/
            if (actuel > 0 && tab->t[x2 * tab->col + y2] == actuel)
            {
                /*si x2,y2 est adjacent à x,y*/
                if (x2 >= x - 1 && x2 <= x + 1 && y2 >= y - 1 && y2 <= y + 1)
                {
                    return 1;
                }
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
void marquage_adjacent(plateau *tab, int x, int y)
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
                    printf("Pierre capturée en (%d,%d)\n", x, y);
                }
            }
        }
    }
}

/*reset du tableau pour fin du tour*/
void update_plateau(plateau *tab)
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
    char c;
    int q;
    int p = 0;
    int x, y;
    int fin = 1;
    //printf("Veuillez saisir quelques pierres (\"BLACK\" = 1 ou \"WHITE\" = 2) sur le plateau de jeu : \n");
    while (fin != 0)
    {
        //voirtab(tab);
    pierre_inconnu:
        printf("Choisissez une pierre : \n 1- BLACK(1) \n 2- WHITE(2) \n");
        scanf("%d", &p);
        switch (p)
        {
        case BLACK:
            puts("Vous avez choisis une pierre: BLACK \n");
            break;
        case WHITE:
            puts("Vous avez choisis une pierre: WHITE \n");
            break;
        default:
            puts("Erreur, merci d'entrer l'entier coorespondant pour sélectionner votre pierre \n");
            goto pierre_inconnu;
        }
    re_saisir_coord:
        puts("Indiquer les coordonnées de la pierre sur le plateau");
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
        q = 1;
        printf("Continuer ? (o/n)\n");
        while (q == 1)
        {
            scanf("%c", &c);
            if (c == 'o')
                q = 0;
            else if (c == 'n')
                return;
        }
    }
}

/* probleme atari simple */
void probleme_atari1(plateau *tab)
{
    int pb = BLACK;
    int pw = WHITE;
    placer_pierre(tab, 1, 2, pb);
    placer_pierre(tab, 2, 1, pb);
    placer_pierre(tab, 2, 3, pb);
    placer_pierre(tab, 2, 2, pw);
    printf("\n");
    voirtab(tab);
    printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
    printf("\n");
}

/* probleme atari sur groupe */
void probleme_atari2(plateau *tab)
{
    int pb = BLACK;
    int pw = WHITE;
    placer_pierre(tab, 1, 1, pw);
    placer_pierre(tab, 2, 0, pw);
    placer_pierre(tab, 3, 0, pw);
    placer_pierre(tab, 4, 1, pw);
    placer_pierre(tab, 2, 1, pb);
    placer_pierre(tab, 3, 1, pb);
    placer_pierre(tab, 2, 2, pw);
    printf("\n");
    voirtab(tab);
    printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
    printf("\n");
}

void probleme_atari3(plateau *tab)
{
    int pb = BLACK;
    int pw = WHITE;
    placer_pierre(tab, 2, 1, pb);
    placer_pierre(tab, 2, 2, pb);
    placer_pierre(tab, 1, 3, pb);
    placer_pierre(tab, 2, 3, pw);
    placer_pierre(tab, 3, 3, pb);
    placer_pierre(tab, 4, 3, pw);
    placer_pierre(tab, 3, 2, pw);
    placer_pierre(tab, 4, 4, pb);
    printf("\n");
    voirtab(tab);
    printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
    printf("\n");
}

/*S'échappe si 1 liberté restante*/
void echapper(plateau *tab)
{
    int x, y;
    pierre pw = WHITE;
    for (x = 0; x < tab->col; x++)
    {
        for (y = 0; y < tab->col; y++)
        {
            if (actuel == pw)
            {
                marquage(tab, x, y, pw);
                marq_case_vide(tab, pw + 10);
            }
        }
    }
    if (somme_liberte(tab, pw + 10) == 1)
    {
        for (x = 0; x < tab->col; x++)
        {
            for (y = 0; y < tab->col; y++)
            {
                if (actuel == 10)
                    actuel = pw;
            }
        }
    }
    update_plateau(tab);
}

/*Capture un groupe adjacent s'il n'a plus de libertés*/
void capture_groupe(plateau *tab)
{
    int x, y, x_tmp, y_tmp;
    int marq = 10;
    pierre pw = WHITE;
    pierre pb = BLACK;
    for (x = 0; x < tab->col; x++)
    {
        for (y = 0; y < tab->col; y++)
        {
            if (actuel == pw)
            {
                x_tmp = x;
                y_tmp = y;
            }
        }
    }
    marquage_adjacent(tab, x_tmp, y_tmp);
    marq_case_vide(tab, pb + marq);
    if (somme_liberte(tab, pb + marq) == 1)
    {
        for (x = 0; x < tab->col; x++)
        {
            for (y = 0; y < tab->col; y++)
            {
                if (actuel == 10)
                    actuel = pw;
            }
        }
    }
    voirtab(tab);
    eliminer(tab, pb + marq);
    update_plateau(tab);
}

void capturer_atari(plateau *tab)
{
    int x, y;
    int marq = 10;
    pierre pw = WHITE;
    pierre pb = BLACK;
    for (x = 0; x < tab->col; x++)
    {
        for (y = 0; y < tab->col; y++)
        {
            if (actuel == pb)
            {
                if (nb_liberte(tab,x,y) == 1){
                    if (nord + est + sud + ouest == 6){
                        marquage(tab,x,y,pb);
                    }
                }
            }
        }
    }
    marq_case_vide(tab, pb + marq);
    if (somme_liberte(tab, pb + marq) == 1)
    {
        for (x = 0; x < tab->col; x++)
        {
            for (y = 0; y < tab->col; y++)
            {
                if (actuel == 10)
                    actuel = pw;
            }
        }
    }
    //voirtab(tab);
    eliminer(tab, pb + marq);
    update_plateau(tab);
}

void demarrer(plateau *tab)
{
    int menu_select = 0;
    int end = 0;
    menu m;
    while (!end)
    {
        printf("\n");
        voirtab(tab);
        printf("\n");
        printf("MENU JEU DE GO: \n 1- Questions du projet \n 2- Saisir un problème manuellement \n 3- Résoudre un problème simple de go \n 4- Jouer une partie libre contre l'IA \n 5- Vider le Goban \n 6- Quitter \n");
        scanf("%d", &menu_select);
        m = (menu)menu_select;

        switch (m)
        {
        case S1:
            choix_question(tab);
            break;
        case S2:
            saisir_probleme(tab);
            break;
        case S3:
            choix_probleme();
            break;
        case S4:
            jouer(tab);
            break;
        case S5:
            for (int x = 0; x < tab->lig; x++)
                for (int y = 0; y < tab->col; y++)
                    actuel = 0;
            break;
        case S6:
            end = 1;
            break;
        default:
            printf("Terminer \n");
            break;
        }
    }
}

/* Selectionner la question pour avoir une réponse */
void choix_question(plateau *tab)
{
    question q;
    int question_choisit = 0;
    int x, y, x2, y2, x3, y3;
    printf("\n");
    voirtab(tab);
    printf("\n");
    printf("0- Placer des pierres sur le plateau \n");
    printf("1- Quel est le nombre de libertés de la pierre isolée (x,y) ? \n");
    printf("2- Quel est le nombre de libertés de la paire de pierres (x,y), (x', y') ? \n");
    printf("3- Quel est le nombre de libertés du triplet de pierres (x,y), (x', y'), (x', y') ? \n");
    printf("4- La pierre (x,y) est-elle isolée ?\n");
    printf("5- Quel est le nombre de libertés de la pierre non isolée (x,y) ? \n");
    printf("6- Menu principal\n");

    scanf("%d", &question_choisit);
    q = (question)question_choisit;

    switch (q)
    {
    case Q0:
        saisir_probleme(tab);
        break;

    case Q1:
        voirtab(tab);
        printf("1- Quel est le nombre de libertés de la pierre isolée (x,y) ? \n");
        puts("Indiquer les coordonnées de la pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x);
        puts("La valeur en y :");
        scanf("%d", &y);
        if (est_isole(tab, x, y))
        {
            printf("Réponse : La pierre isolée en (%d,%d) a %d liberté(s)\n", x, y, nb_liberte(tab, x, y));
        }
        else
        {
            printf("Aucune pierre isolée à cet emplacement !\n");
        }
        break;

    case Q2:
        voirtab(tab);
        printf("2- Quel est le nombre de libertés de la paire de pierres (x,y), (x', y') ? \n");
        puts("Indiquer les coordonnées de la première pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x);
        puts("La valeur en y :");
        scanf("%d", &y);
        puts("Indiquer les coordonnées de la seconde pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x2);
        puts("La valeur en y :");
        scanf("%d", &y2);
        if (est_paire(tab, x, y, x2, y2))
        {
            printf("La paire sélectionnée [(%d,%d),(%d,%d)] a %d liberté(s) \n", x, y, x2, y2, nb_liberte_paire(tab, x, y, x2, y2));
        }
        else
        {
            printf("...Aucune paire n'a été trouvée...\n");
        }
        break;

    case Q3:
        voirtab(tab);
        printf("3- Quel est le nombre de libertés du triplet de pierres (x,y), (x', y'), (x', y') ? \n");
        puts("Indiquer les coordonnées de la première pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x);
        puts("La valeur en y :");
        scanf("%d", &y);
        puts("Indiquer les coordonnées de la seconde pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x2);
        puts("La valeur en y :");
        scanf("%d", &y2);
        puts("Indiquer les coordonnées de la troisième pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x3);
        puts("La valeur en y :");
        scanf("%d", &y3);
        if (est_triplet(tab, x, y, x2, y2, x3, y3))
        {
            printf("Le triplet sélectionné [(%d,%d),(%d,%d),(%d,%d)] a %d liberté(s) \n", x, y, x2, y2, x3, y3, nb_liberte_triplet(tab, x, y, x2, y2, x3, y3));
        }
        else
        {
            printf("...Aucun triplet n'a été trouvé...\n");
        }
        break;

    case Q4:
        voirtab(tab);
        printf("4- La pierre (x,y) est-elle isolée ?\n");
        puts("Indiquer les coordonnées de la pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x);
        puts("La valeur en y :");
        scanf("%d", &y);
        if (est_isole(tab, x, y))
        {
            printf("Réponse : Oui, la pierre sélectionnée en (%d,%d) est isolée\n", x, y);
        }
        else if (!est_isole(tab, x, y))
        {
            printf("Réponse : Non, la pierre sélectionnée en (%d,%d) n'est pas iséolée\n", x, y);
        }
        else
        {
            printf("...Aucune pierre sélectionnée...\n");
        }
        break;

    case Q5:
        voirtab(tab);
        printf("5- Quel est le nombre de libertés de la pierre non isolée (x,y) ? \n");
        puts("Indiquer les coordonnées de la pierre sur le plateau");
        puts("La valeur en x :");
        scanf("%d", &x);
        puts("La valeur en y :");
        scanf("%d", &y);
        if (actuel > 0 && !est_isole(tab, x, y))
        {
            printf("Réponse : La pierre non isolée en (%d,%d) a %d libertée(s) \n", x, y, nb_liberte(tab, x, y));
        }
        else
        {
            printf("...La pierre sélectionnée est isolée ou n'existe pas... \n");
        }
        break;

    case Q6:
        return;

    default:
        printf("Terminer\n");
        break;
    }
}

/* Sélectionner un problème de Go */
void choix_probleme(void)
{

    plateau goban;
    goban = creer(6, 6);
    plateau *atari;
    atari = &goban;
    int choix_tmp = 1;
    prob choix;
    char c;
    int q;

    printf("Veuillez choisir un problème : \n");
    printf("1- Echapper a un Atari Simple\n");
    printf("2- Capturer en Atari\n");
    printf("3- Capturer une pierre en Atari\n");

    scanf("%d", &choix_tmp);
    choix = (prob)choix_tmp;
    switch (choix)
    {
    case PROB1:
        probleme_atari1(atari);
        printf("WHITE(2) est entourée par BLACK(1) en atari et peut etre supprimmée au prochain tour de BLACK(1)\n");
        q = 1;
        printf("Résoudre ? (o/n)\n");
        while (q == 1)
        {
            scanf("%c", &c);
            if (c == 'o')
                q = 0;
            else if (c == 'n')
                break;
        }
        echapper(atari);
        printf("\n");
        voirtab(atari);
        printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
        printf("\n");
        printf("WHITE(2) joue et s'échappe\n");
        printf("Problème résolu !\n");

        break;

    case PROB2:
        probleme_atari2(atari);
        printf("BLACK(1) est entourée par WHITE(2) en atari et peut etre supprimmée au prochain tour de WHITE(2)\n");
        q = 1;
        printf("Résoudre ? (o/n)\n");
        while (q == 1)
        {
            scanf("%c", &c);
            if (c == 'o')
                q = 0;
            else if (c == 'n')
                break;
        }
        capture_groupe(atari);
        printf("\n");
        voirtab(atari);
        printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
        printf("\n");
        printf("WHITE(2) joue et prend le groupe BLACK(1) en un coup!\n");
        printf("Problème résolu !\n");

        break;
    case PROB3:
        probleme_atari3(atari);
        printf(" C'est à WHITE(2) de jouer ! Bien qu'il y ait d'autres pierres dans les environs, WHITE(2) devrait quand même prendre une pierre BLACK(1)\n");
        q = 1;
        printf("Résoudre ? (o/n)\n");
        while (q == 1)
        {
            scanf("%c", &c);
            if (c == 'o')
                q = 0;
            else if (c == 'n')
                break;
        }
        capturer_atari(atari);
        printf("\n");
        voirtab(atari);
        printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
        printf("\n");
        printf("WHITE(2) joue et prend la pierre BLACK(1) en atari!\n");
        printf("Problème résolu !\n");
        break;

    default:
        break;
    }
}

void ia(plateau *tab, int x, int y, pierre p)
{
    //int i, j;
    //int test = 0;
    if (actuel == p)
    {
        marquage(tab, x, y, p);
        marq_case_vide(tab, 11);
        if (somme_liberte(tab, 11) > 0)
        {
            if (nord == 10)
                nord = 2;
            else if (est == 10)
                est = 2;
            else if (sud == 10)
                sud = 2;
            else if (ouest == 10)
                ouest = 2;
        }
        eliminer(tab, 11);
    }

    update_plateau(tab);
}

/*Partie Libre contre l'IA comptage manuel*/
void jouer(plateau *tab)
{
    int end = 1;
    int pierre = 1;
    int x, y;
    char c;
    int q = 1;
    while (end)
    {

        printf("\n");
        voirtab(tab);
        printf("JOUEUR = BLACK(1) -- IA = WHITE(2)\n");
        printf("\n");
        printf("Continuer ? (o/n)\n");
        while (q == 1)
        {
            scanf("%c", &c);
            if (c == 'o')
                q = 0;
            else if (c == 'n'){
                return;
            }
        }
        do
        {
            puts("Indiquer les coordonnées de la pierre sur le plateau");
            puts("La valeur en x :");
            scanf("%d", &x);
            puts("La valeur en y :");
            scanf("%d", &y);
            if (x >= 0 && x <= tab->lig - 1 && y >= 0 && y <= tab->col - 1)
            {
                if (actuel == 0)
                {
                    placer_pierre(tab, x, y, pierre);
                    marquage_adjacent(tab, x, y);
                    marq_case_vide(tab, 12);
                    //voirtab(tab);
                    eliminer(tab, 12);
                    update_plateau(tab);
                }
                else
                {
                    printf("\nIl y a dejà une pierre à cet emplacement. Vous passez votre tour... \n");
                }
            }
            else
            {
                printf("ATTENTION, vous ne pouvez pas placer de pierre ici : [x = %d, y = %d] \n", x, y);
            }
        } while (actuel < 1);
        puts("...L'IA Joue... ");
        ia(tab, x, y, pierre);
        q = 1;
    }
}
