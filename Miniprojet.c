#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int c=0;
float prix[60];
int quantite[60];
char Titre[60][15];
char auteur[60][15];


//-----------------------------fonction d'ajoute----------------------------------------------------------------.



void Ajouter(){
   printf("saisir le prix:");
   scanf("%f",&prix[c]);

   printf("saisir le quantite:");
   scanf("%d",&quantite[c]);

   printf("entrer le titre:");
    scanf("%s",&Titre[c]);

    printf("entrer l'auteur:");

    scanf("%s",&auteur[c]);
   c=c+1;

}

//---------------------------------------fonction d'afficher-----------------------------------.//




void affichage(){

 for(int i=0;i<c;i++){

    printf("le titre :%s,auteur:%s,prix:%.2fDh,quantit�=%d  \n",Titre[i],auteur[i],prix[i],quantite[i]);

 }
}


//------------------------- fonction Recherche.---------------------------------------




void Recherche(){
    char Name[15];
    int N=0;
    printf("saisir le nom de livre: ");
    scanf("%s",&Name);
    for(int i=0;i<c;i++){
        if(strcmp(Titre[i],Name) == 0){
            printf("le titre :%s,auteur:%s,prix:%.2fDh,quantit�=%d  \n",Titre[i],auteur[i],prix[i],quantite[i]);
            N++;
        }
    }
    if(N==0){
            printf("ce livre n'existe pas.\n");
      }

}

//------------------------------------fonction mettre a jour-------------------//

  void ModificationQuantite(){
    char Name[15];
    printf("saisir le nom de livre pour changer la quantite: ");
    scanf("%s",&Name);
    int N=0;
    for(int i=0;i<c;i++){
       if(strcmp(Titre[i],Name) == 0){
            int q;
           printf("saisir la quantite:");
           scanf("%d",&q);
           quantite[i]=q;
           N++;
     }
   }
   if(N==0){
      printf("ce livre n'existe pas.\n");}
    }

//--------------------------------fonction suppression-------------------------------//


void suppression() {
    char Name[15];
    printf("Saisir le nom de livre pour supprimer le livre: ");
    scanf("%s", Name);
    int N = 0;
    for (int i = 0; i < c; i++) {
        if (strcmp(Titre[i], Name) == 0) {
            
            for (int j = i; j < c - 1; j++) {
                strcpy(Titre[j], Titre[j+1]);
                strcpy(auteur[j], auteur[j+1]);
                prix[j] = prix[j+1];
                quantite[j] = quantite[j+1];
            }
            c--;  
            N++;
            printf("Livre supprimé avec succès.\n");
            break;
        }
    }
    if (N == 0) {
        printf("Ce livre n'existe pas.\n");
    }
}



















                          //main fonction.
int main(){
    int N;
    while(1){
        int N;


    printf("1-Ajouter un livre au stock:\n");

    printf("2-Afficher tous les livres disponibles:\n");
    printf("3-Rechercher un livre par son titre:\n");
    printf("4-Mettre � jour la quantit�  d'un livre:\n");
    printf("5-Supprimer un livre du stock:\n");
    printf("6-Afficher le nombre total de livres en stock:\n");
 printf("CHOISIR UN NOMBRE:");
scanf("%d",&N);
switch(N){
case 1:Ajouter();
      break;
case 2:affichage();
      break;
case 3:Recherche();
      break;
case 4:ModificationQuantite();
     break;

case 5:suppression();
     break;
}
}
    return 0;
}
