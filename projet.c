//Deux tableaux 1 pour les lettres du motif
//Un autre pour les entier k selon j
//Remplir le tableau par boucle décroisante sur le temps


/*
PROJET
*/

/*-----------------------------------------*/
/* IMPORTATION DES BIBLIOTHEQUES */
/*-----------------------------------------*/

# include <stdio.h> // Pour printf et scanf
# include <stdint.h> // pour certains types
# include <stdlib.h> // Memoire dynamique
# include <time.h>
# include <stdbool.h> // Booléens
# include <string.h> // chaînes de caractère
# include <assert.h>

/*-----------------------------------------*/
/* DEFINITION DE STUCT*/
/*-----------------------------------------*/
typedef struct {
    char* tab;
    int nb;
}indice;
/*-----------------------------------------*/
/* FONCTIONS */
/*-----------------------------------------*/

indice extraire_lettres(char* motif, int nb_motif);
int** construit_table (char* motif, indice tab_lettres, int nb_motif);

int** construit_table (char* motif, indice tab_lettres, int nb_motif){
    int ind = -1;
    int** tab_decalage= malloc(sizeof(int*)*nb_motif);
    assert(tab_decalage!=NULL);
    int* ligne = malloc(sizeof(int)*tab_lettres.nb);
    assert(ligne!=NULL);
    int* ligne_2;
    for (int i = 0; i < nb_motif ; i++)
    {
        ligne[i]=-2;
    }
    tab_decalage[0]=ligne;
    for (int i = 0; i< nb_motif-1; i++){
        int* test = malloc(sizeof(int)*tab_lettres.nb);
        for(int j = 0; j < tab_lettres.nb; j++)
        {
            test[j]=tab_decalage[i-1][j];
            if (tab_lettres.tab[j]==motif[i]){
                test[j]++;
            }
        }
        tab_decalage[i]=test;
    }
    return tab_decalage;  
}

indice extraire_lettres(char* motif, int nb_motif){
    char chaine[nb_motif];
    char lettre;
    bool a_trouve ;
    int entier = 0;
    for(int i = 0; i<nb_motif; i++){
        lettre = motif[i];
        a_trouve = true;
        for (int j = 0; j < nb_motif; j++)
        {
            if (lettre == chaine[j]){
                a_trouve = false;
                break;
            }
        }
        if (a_trouve == true){
            chaine[entier]=lettre;
            entier++;
        }     
    }
    indice indices;
    indices.tab = chaine;
    indices.nb = entier;
    return indices;
}

/*-----------------------------------------*/
/* MAIN */
/*-----------------------------------------*/
int main(){
    char* motif = "abracadabra";
    int nb_motif = 11;
    indice temp = extraire_lettres(motif, nb_motif);
    for (int i = 0; i < temp.nb; i++)
    {
        printf("%c",(temp.tab)[i]);
    }
    /*int** tableau = construit_table(motif, temp, nb_motif);
    for( int i = 0; i < nb_motif ; i++){
        for (int j = 0; j < temp.nb; j++)
        {
            printf(" %d ", tableau[i][j]);
        }
        printf("\n");
    }*/
    printf("\ntest\n");
    return 0;
}