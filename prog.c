#include <stdio.h>
#include <stdlib.h>
#include "go.h"

int main()
{
	/*déclaration plateau de jeu*/
	int sx, sy;
	plateau tab;
	sx = 6;
	sy = 6;
	tab = creer(sx, sy);

	/*création de pierre*/
	//pierre pj1 = BLACK;
	//pierre pj2 = WHITE;

	/*Pointeur vers tab*/
	plateau *ptr;
	ptr = &tab;

	demarrer(ptr);
	return 0;
}
// gcc -Wall -Wextra -Wpedantic
// gcc -Wall -Wextra -Wpedantic prog.c go.c -o prog
// ./prog