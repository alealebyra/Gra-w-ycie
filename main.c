#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "biblioteka.h"

#define ROW 80
#define KOL 22

int main()
{
	int i, j;
	int **tab=create(ROW, KOL);
	if(tab==NULL)
	{
		printf("Tablica sie nie utworzy³a\n");
		return 0;
	}

	wypelnij(tab, ROW, KOL);


	FILE *plik;
	plik=fopen("danewe.txt", "r");
	if(plik==NULL)
	{
		printf("Otwieranie pliku nie udalo sie\n");
		return 0;
	}



	while (feof(plik) == 0)
    {
        fscanf(plik, "%d", &i);

        fscanf(plik, "%d", &j);
        if(i>=ROW || j>=KOL)
        {
        		printf("Zczytane dane nie mieszcza sie w tablicy\n");
        		break;
        }
        insert(tab, i, j, 1);

    }

	fclose(plik);


	for(j=0;j<KOL;j++)
	{
		for(i=0;i<ROW;i++)
        {at(tab, i, j);
        }
	}


	system("cls");
	usleep(1000000);

    for(i=0;i<10;i++)
    {
        tab=tabzycie(tab, ROW, KOL);
        usleep(1000000);
        system("cls");
    }


    return 0;
}
