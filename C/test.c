#include <stdio.h>
#include <stdlib.h>

typedef struct element element ;
	struct element
	{
		int entier;
		element * suivant ;
	};

typedef struct pile pile ;
	struct pile
	{
		element *premier;
	};

/*############################*/

void empiler(pile *p,int nv_br);
void affich(pile *p);

/*############################*/

int main()
{









    ///////////////////////////////////////////////////////
    pile *pp=malloc(sizeof(pile));

	int i=10;
	while(i!=0)
	{
	empiler(pp,i);
	i--;
	}
	affich(pp);
	return 0;
}

void empiler(pile *p,int nv_br)
{
	element *E = malloc(sizeof(element));
	E->entier = nv_br;
	E->suivant = p->premier;
	p->premier = E;
}

void affich(pile *p)
{
	element *E;





	//////////////////////////kant E->suivant = p->premier;
	//ERROR
	E = p->premier;
	//////////////////////////




	while(E != NULL)
	{
		printf("=====>%i\n",E->entier);
		E=E->suivant;
	}


}