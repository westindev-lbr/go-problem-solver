#include <stdio.h>
#include <stdlib.h>

struct plateau_jeu
{
    int ligne;
    int colonne;
};

typedef struct plateau_jeu plateau;


char** remplir_plateau(plateau plt, size_t l, size_t c)
{
    /* On veut avoir int * tab[N], sauf que tab sera créé dynamiquement */
    int i;
    char **ptab = malloc(plt.colonne * sizeof(char *));
    /* On crée maintenant les N tableaux de M éléments chacun */
    for (i = 0; i < plt.ligne; i++)
    {
        ptab[i] = malloc(plt.colonne * sizeof(int));
    }
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            ptab[i][j] = i * c + j;
            printf("tab[%u][%u] = %d\n", i, j, ptab[i][j]);
        }
    }
    printf("%s\n",&ptab[4][0]);
    return ptab;
}

int main()
{
    plateau plt;
    plt.ligne = 6;
    plt.colonne = 6;

    char **tab = remplir_plateau(plt, plt.ligne, plt.colonne);
    tab[4][0] = 100;

    for (int i = 0; i < plt.ligne; ++i)
    {
        for (int j = 0; j < plt.colonne; ++j)
        {
            printf("tab[%u][%u] = %d\n", i, j, tab[i][j]);
        }
    }

    return 0;
}