#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
    struct Noeud* precedent;
} Noeud;

typedef struct {
    Noeud* tete;
    Noeud* queue;
    int taille;
} Liste;

Liste* creer_liste() {
    Liste* liste = (Liste*)malloc(sizeof(Liste));
    if (!liste) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    liste->tete = NULL;
    liste->queue = NULL;
    liste->taille = 0;
    return liste;
}

Noeud* creer_noeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    nouveau->donnee = valeur;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

int est_vide(Liste* liste) {
    return (liste->tete == NULL);
}

void inserer_trie(Liste* liste, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);

    printf("\n--- INSERTION TRIEE : %d ---\n", valeur);

    if (est_vide(liste)) {
        printf("Liste vide → Premier élément\n");
        liste->tete = nouveau;
        liste->queue = nouveau;
    } else if (valeur < liste->tete->donnee) {
        printf("Insertion avant la tête (ancienne tête = %d)\n", liste->tete->donnee);
        nouveau->suivant = liste->tete;
        liste->tete->precedent = nouveau;
        liste->tete = nouveau;
    } else {
        Noeud* courant = liste->tete;
        while (courant->suivant != NULL && courant->suivant->donnee < valeur) {
            courant = courant->suivant;
        }

        printf("Insertion après %d\n", courant->donnee);
        nouveau->suivant = courant->suivant;
        nouveau->precedent = courant;

        if (courant->suivant != NULL) {
            courant->suivant->precedent = nouveau;
        } else {
            liste->queue = nouveau;
        }
        courant->suivant = nouveau;
    }

    liste->taille++;
    printf("Taille de la liste : %d\n", liste->taille);
}

void afficher_liste_avant(Liste* liste) {
    if (est_vide(liste)) {
        printf("Liste vide\n");
        return;
    }

    printf("\n=== LISTE (croissant) ===\n");
    Noeud* courant = liste->tete;

    while (courant != NULL) {
        printf("[%d]", courant->donnee);
        courant = courant->suivant;
        if (courant != NULL) printf(" ⇄ ");
    }
    printf("\n");
}

void afficher_liste_arriere(Liste* liste) {
    if (est_vide(liste)) {
        printf("Liste vide\n");
        return;
    }

    printf("\n=== LISTE (décroissant) ===\n");
    Noeud* courant = liste->queue;

    while (courant != NULL) {
        printf("[%d]", courant->donnee);
        courant = courant->precedent;
        if (courant != NULL) printf(" ⇄ ");
    }
    printf("\n");
}

void liberer_liste(Liste* liste) {
    Noeud* courant = liste->tete;
    Noeud* suivant;

    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }

    free(liste);
    printf("\nMémoire libérée avec succès !\n");
}

void afficher_menu() {
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║   LISTE DOUBLEMENT CHAÎNÉE TRIEE      ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf("1. Insertion TRIÉE\n");
    printf("2. Afficher la liste (avant)\n");
    printf("3. Afficher la liste (arrière)\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

int main() {
    Liste* liste = creer_liste();
    int choix, valeur;

    printf("╔════════════════════════════════════════════╗\n");
    printf("║   GESTION LISTE DOUBLEMENT CHAÎNÉE TRIEE   ║\n");
    printf("╚════════════════════════════════════════════╝\n");

    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Valeur à insérer (triée) : ");
                scanf("%d", &valeur);
                inserer_trie(liste, valeur);
                afficher_liste_avant(liste);
                break;

            case 2:
                afficher_liste_avant(liste);
                break;

            case 3:
                afficher_liste_arriere(liste);
                break;

            case 0:
                printf("\nFermeture du programme...\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 0);

    liberer_liste(liste);

    return 0;
}