#include <stdio.h>

struct pierre_noire{
    int x;
    int y;
};

struct pierre_blanche{
    int x;
    int y;
};

typedef struct pierre_noire noire;
typedef struct pierre_blanche blanche;


/*Pierre est isolé quand 
aucune autre pierre n'est a coté. 
x',y' ,  +1 ou -1 = vide   

*/
/*
int est_isole(noire n){
    if (p.x)
    switch

}
*/


int main (){
    noire n;
    n.x = 0;
    n.y = 0; 
    printf("pierre noire = (%d,%d)\n", n.x,n.y);



    return 0;
}
