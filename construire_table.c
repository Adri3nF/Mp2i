/*
Boyer-Moore
04/2024
*/


/*  Importation des biblioteque   */
#include <stdio.h> //scanf et print
#include <assert.h> // pour faire des assert
#include <stdlib.h> // pour le rand
#include <time.h> // pour le time 
#include <string.h>

/*Definition variable globale et prototype*/
typedef struct {
    char* tab;
    int nb;
}indice;

/* Fonction */
int** construire_table(char* motif, indice tab_lettres, int nb_motif){
    int** table_decalage = malloc(nb_motif*sizeof(int*));
    assert(table_decalage!=NULL);
    table_decalage[0]= malloc(tab_lettres.nb*sizeof(int));
    for (int i = 0; i < tab_lettres.nb; i++)
    {
        table_decalage[0][i]=-1;
    }
    
    for (int i = 1; i < nb_motif+1; i++)
    {
        table_decalage[i] = malloc(tab_lettres.nb*sizeof(int));
        assert(table_decalage[i] != NULL);
        for (int j = 0; j < tab_lettres.nb; j++)
        {

            if (motif[i-1]==tab_lettres.tab[j])
            {
                table_decalage[i][j]=i-1;
            }   
            else
            {
                table_decalage[i][j]=table_decalage[i-1][j];
            }
            
        }
    }
    return table_decalage;
}

/*Programme principale*/
int main(){
    char* motif = "abracadabra";
    int nb_motif = strlen(motif);
    indice tab;
    tab.nb=5;
    tab.tab = "abrcd";
    int** table =construire_table(motif,tab,nb_motif);
    for (int i = 0; i < nb_motif; i++)
    {
        for (int j = 0; j < tab.nb; j++)
        {
            if (table[i][j]==-1)
            {
                printf(" v ");
            }
            else{
            printf(" %d ",table[i][j]);
            }
        }
        printf("\n");
    }
    return 0 ;
}
