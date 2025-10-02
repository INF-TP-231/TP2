#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud de la liste
typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

// Fonction pour créer un nouveau nœud
Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour insérer un élément dans une liste triée
Noeud* insererTrie(Noeud* tete, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    // Cas 1: Liste vide ou insertion au début
    if (tete == NULL || tete->valeur >= valeur) {
        nouveau->suivant = tete;
        return nouveau;
    }
    
    // Cas 2: Insertion au milieu ou à la fin
    Noeud* courant = tete;
    while (courant->suivant != NULL && courant->suivant->valeur < valeur) {
        courant = courant->suivant;
    }
    
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;
    
    return tete;
}

// Fonction pour afficher la liste
void afficherListe(Noeud* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Noeud* courant = tete;
    printf("Liste: ");
    while (courant != NULL) {
        printf("%d", courant->valeur);
        if (courant->suivant != NULL) {
            printf(" -> ");
        }
        courant = courant->suivant;
    }
    printf("\n");
}

// Fonction pour libérer la mémoire de la liste
void libererListe(Noeud* tete) {
    Noeud* courant = tete;
    Noeud* suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}

// Programme principal de démonstration
int main() {
    Noeud* liste = NULL;
    
    printf("=== Insertion dans une liste simplement chaînée triée ===\n\n");
    
    // Insertions successives
    printf("Insertion de 5:\n");
    liste = insererTrie(liste, 5);
    afficherListe(liste);
    
    printf("\nInsertion de 2:\n");
    liste = insererTrie(liste, 2);
    afficherListe(liste);
    
    printf("\nInsertion de 8:\n");
    liste = insererTrie(liste, 8);
    afficherListe(liste);
    
    printf("\nInsertion de 1:\n");
    liste = insererTrie(liste, 1);
    afficherListe(liste);
    
    printf("\nInsertion de 6:\n");
    liste = insererTrie(liste, 6);
    afficherListe(liste);
    
    printf("\nInsertion de 3:\n");
    liste = insererTrie(liste, 3);
    afficherListe(liste);
    
    printf("\nInsertion de 9:\n");
    liste = insererTrie(liste, 9);
    afficherListe(liste);
    
    // Libération de la mémoire
    libererListe(liste);
    
    return 0;
}
