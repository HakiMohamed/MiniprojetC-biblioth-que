#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 60
#define MAX_TAILLE_TITRE 15
#define MAX_TAILLE_AUTEUR 15

typedef struct {
    char titre[MAX_TAILLE_TITRE];
    char auteur[MAX_TAILLE_AUTEUR];
    float prix;
    int quantite;
} Livre;


Livre stock[MAX_LIVRES];
int nombreLivres = 0;



void Ajouter() {
    if (nombreLivres >= MAX_LIVRES) {
        printf("Le stock est plein, impossible d'ajouter plus de livres.\n");
        return;
    }

    printf("Saisir le prix (doit être positif) : ");
    scanf("%f", &stock[nombreLivres].prix);
    while (stock[nombreLivres].prix < 0) {
        printf("Prix invalide. Saisir un prix positif : ");
        scanf("%f", &stock[nombreLivres].prix);
    }

    printf("Saisir la quantité (doit être un entier non négatif) : ");
    scanf("%d", &stock[nombreLivres].quantite);
    while (stock[nombreLivres].quantite < 0) {
        printf("Quantité invalide. Saisir une quantité non négative : ");
        scanf("%d", &stock[nombreLivres].quantite);
    }

    printf("Entrer le titre (max 14 caractères) : ");
    scanf("%14s", stock[nombreLivres].titre);

    printf("Entrer l'auteur (max 14 caractères) : ");
    scanf("%14s", stock[nombreLivres].auteur);

    nombreLivres++;
}




void Affichage() {
    if (nombreLivres == 0) {
        printf("Aucun livre dans le stock.\n");
        return;
    }

    for (int i = 0; i < nombreLivres; i++) {
        printf("Titre : %s, Auteur : %s, Prix : %.2f Dh, Quantité : %d\n",
               stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
    }
}



void Recherche() {
    char nomLivre[MAX_TAILLE_TITRE];
    printf("Saisir le nom de livre : ");
    scanf("%14s", nomLivre);

    int trouve = 0;
    for (int i = 0; i < nombreLivres; i++) {
        if (strcmp(stock[i].titre, nomLivre) == 0) {
            printf("Livre trouvé : Titre : %s, Auteur : %s, Prix : %.2f Dh, Quantité : %d\n",
                   stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Ce livre n'existe pas.\n");
    }
}




void ModificationQuantite() {
    char nomLivre[MAX_TAILLE_TITRE];
    printf("Saisir le nom de livre pour changer la quantité : ");
    scanf("%14s", nomLivre);

    int trouve = 0;
    for (int i = 0; i < nombreLivres; i++) {
        if (strcmp(stock[i].titre, nomLivre) == 0) {
            printf("Saisir la nouvelle quantité : ");
            scanf("%d", &stock[i].quantite);
            while (stock[i].quantite < 0) {
                printf("Quantité invalide. Saisir une quantité non négative : ");
                scanf("%d", &stock[i].quantite);
            }
            printf("Quantité mise à jour avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Ce livre n'existe pas.\n");
    }
}




void Suppression() {
    char nomLivre[MAX_TAILLE_TITRE];
    printf("Saisir le nom de livre pour supprimer le livre : ");
    scanf("%14s", nomLivre);

    int trouve = 0;
    for (int i = 0; i < nombreLivres; i++) {
        if (strcmp(stock[i].titre, nomLivre) == 0) {
            for (int j = i; j < nombreLivres - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nombreLivres--;
            printf("Livre supprimé avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Ce livre n'existe pas.\n");
    }
}




void AfficherNombreLivres() {
    printf("Nombre total de livres en stock : %d\n", nombreLivres);
}




int main() {
    int choix;
    while (1) {
        printf("\n1 - Ajouter un livre au stock\n");
        printf("2 - Afficher tous les livres disponibles\n");
        printf("3 - Rechercher un livre par son titre\n");
        printf("4 - Mettre à jour la quantité d'un livre\n");
        printf("5 - Supprimer un livre du stock\n");
        printf("6 - Afficher le nombre total de livres en stock\n");
        printf("0 - Quitter\n");
        printf("CHOISIR UN NOMBRE : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter();
                break;
            case 2:
                Affichage();
                break;
            case 3:
                Recherche();
                break;
            case 4:
                ModificationQuantite();
                break;
            case 5:
                Suppression();
                break;
            case 6:
                AfficherNombreLivres();
                break;
            case 0:
                printf("Quitter le programme.\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }
}
