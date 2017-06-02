#include <stdio.h>
#include <stdlib.h>
#include "biblioteka.h"

#define ROW 80
#define KOL 22

#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))

int **create(int wiersze, int kolumny)
{
    int **tab;
    tab=malloc(wiersze*sizeof(*tab));
    if(tab==NULL)
    {
        printf("Niestety coś poszło nie tak");
        return 0;
    }

    int i;
    for(i=0;i<wiersze;i++)
    {
        tab[i]=malloc(kolumny*sizeof(**tab));
        if(tab[i]==NULL)
        {
            printf("Niestety coś poszło nie tak");
            deleteTab(&tab, i);
            return 0;
        }

    }

    return tab;
}


int resize(int ***tab, int wiersze, int kolumny, int nowwier, int nowkol)
{
    int **newtab;
    newtab=create(nowwier, nowkol);
    if(newtab==NULL)
    {
        printf("Niestety coś poszło nie tak");
        return 0;
    }

    int i, j;

    for(i=0;i<wiersze;i++)
    {
        for(j=0;j<kolumny;j++)
        {
            newtab[i][j]=(*tab)[i][j];
        }
    }

    deleteTab(tab, wiersze);
    *tab=newtab;

    return 1;
}



void at(int **tab, int wiersz, int kolumna)
{
    if(tab[wiersz][kolumna]==0) printf(" ");
    else printf("o");
}



void insert(int **tab, int wiersz, int kolumna, int liczba)
{
    tab[wiersz][kolumna]=liczba;
}



void deleteTab(int ***tab, int wiersze)
{
    int i;
    for(i=0;i<wiersze;i++) free((*tab)[i]);

    free(*tab);
    *tab=NULL;
}


void wypelnij(int **tab, int wiersze, int kolumny)
{
	int i, j;
	for(i=0;i<wiersze;i++)
	{
		for(j=0;j<kolumny;j++) insert(tab, i, j, 0);
	}
}


int liczsas(int **tab, int wiersz, int kolumna)
{
	int suma=0;
	int i, j;
	for(i=MAX(wiersz-1,0);i<MIN(wiersz+2,ROW);i++)
	{
		for(j=MAX(kolumna-1,0);j<MIN(kolumna+2,KOL);j++) suma=suma+tab[i][j];
	}
	suma=suma-tab[wiersz][kolumna];

	return suma;

}

int **tabzycie(int **tab, int wiersze, int kolumny)
{
	int i, j, sasiedzi;
	int **nast=create(wiersze, kolumny);
	if(nast==NULL)
	{
		printf("Tablica sasiadow sie nie utworzyla");
		return 0;
	}


    for(j=0;j<kolumny;j++)
	{
		for(i=0;i<wiersze;i++)
		{
			sasiedzi=liczsas(tab, i, j);
			if(sasiedzi == 3) insert(nast, i, j, 1);
			else if(sasiedzi == 2) insert(nast, i, j, tab[i][j]);
			else  insert(nast, i, j, 0);

			at(nast, i, j);

		}
	}

	deleteTab(&tab, wiersze);

	return nast;

}

