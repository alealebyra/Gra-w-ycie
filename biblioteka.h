#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

int **create(int wiersze, int kolumny);
int resize(int ***tab, int wiersze, int kolumny, int nowwier, int nowkol);
void at(int **tab, int wiersz, int kolumna);
void insert(int **tab, int wiersz, int kolumna, int liczba);
void deleteTab(int ***tab, int wiersze);
void wypelnij(int **tab, int wiersze, int kolumny);
int liczsas(int **tab, int wiersz, int kolumna);
int **tabzycie(int **tab, int wiersze, int kolumny);

#endif
