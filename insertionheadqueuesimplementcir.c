#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
} Noeud;

// Définition de la structure de la liste circulaire
typedef struct {
    Noeud* dernier;  // Pointeur vers le dernier élément
} ListeCirculaire;

// Fonction pour créer un nouveau nœud
Noeud* creerNoeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->donnee = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour initialiser une liste circulaire vide
ListeCirculaire* creerListe() {
    ListeCirculaire* liste = (ListeCirculaire*)malloc(sizeof(ListeCirculaire));
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    liste->dernier = NULL;
    return liste;
}

// Fonction pour insérer un élément en tête
void insererEnTete(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    // Si la liste est vide
    if (liste->dernier == NULL) {
        nouveau->suivant = nouveau;  // Le nœud pointe vers lui-même
        liste->dernier = nouveau;
    } else {
        // Insérer après le dernier (donc en tête)
        nouveau->suivant = liste->dernier->suivant;
        liste->dernier->suivant = nouveau;
    }
    
    printf("Élément %d inséré en tête\n", valeur);
}

// Fonction pour insérer un élément en queue
void insererEnQueue(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = creerNoeud(valeur);
    
    // Si la liste est vide
    if (liste->dernier == NULL) {
        nouveau->suivant = nouveau;  // Le nœud pointe vers lui-même
        liste->dernier = nouveau;
    } else {
        // Insérer après le dernier
        nouveau->suivant = liste->dernier->suivant;
        liste->dernier->suivant = nouveau;
        liste->dernier = nouveau;  // Mettre à jour le dernier
    }
    
    printf("Élément %d inséré en queue\n", valeur);
}

// Fonction pour afficher la liste circulaire
void afficherListe(ListeCirculaire* liste) {
    if (liste->dernier == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Noeud* courant = liste->dernier->suivant;  // Commence à la tête
    printf("Liste circulaire : ");
    
    do {
        printf("%d -> ", courant->donnee);
        courant = courant->suivant;
    } while (courant != liste->dernier->suivant);
    
    printf("(retour au début)\n");
}

// Fonction pour vérifier si la liste est vide
int estVide(ListeCirculaire* liste) {
    return (liste->dernier == NULL);
}

// Fonction pour libérer la mémoire de la liste
void libererListe(ListeCirculaire* liste) {
    if (liste->dernier == NULL) {
        free(liste);
        return;
    }
    
    Noeud* courant = liste->dernier->suivant;
    Noeud* temp;
    
    // Parcourir et libérer tous les nœuds
    do {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    } while (courant != liste->dernier->suivant);
    
    free(liste);
    printf("Mémoire libérée\n");
}

// Fonction pour afficher le menu
void afficherMenu() {
    printf("\n========== MENU ==========\n");
    printf("1. Insérer en tête\n");
    printf("2. Insérer en queue\n");
    printf("3. Afficher la liste\n");
    printf("4. Vérifier si la liste est vide\n");
    printf("5. Quitter\n");
    printf("==========================\n");
    printf("Votre choix : ");
}

// Programme principal avec interaction utilisateur
int main() {
    ListeCirculaire* maListe = creerListe();
    int choix, valeur;
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║  LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE  ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    do {
        afficherMenu();
        
        // Lecture sécurisée du choix
        if (scanf("%d", &choix) != 1) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');  // Vider le buffer
            continue;
        }
        
        switch (choix) {
            case 1:
                printf("\nEntrez la valeur à insérer en tête : ");
                if (scanf("%d", &valeur) == 1) {
                    insererEnTete(maListe, valeur);
                } else {
                    printf("Erreur de saisie.\n");
                    while (getchar() != '\n');
                }
                break;
                
            case 2:
                printf("\nEntrez la valeur à insérer en queue : ");
                if (scanf("%d", &valeur) == 1) {
                    insererEnQueue(maListe, valeur);
                } else {
                    printf("Erreur de saisie.\n");
                    while (getchar() != '\n');
                }
                break;
                
            case 3:
                printf("\n");
                afficherListe(maListe);
                break;
                
            case 4:
                if (estVide(maListe)) {
                    printf("\nLa liste est vide.\n");
                } else {
                    printf("\nLa liste contient des éléments.\n");
                }
                break;
                
            case 5:
                printf("\n=== Libération de la mémoire ===\n");
                libererListe(maListe);
                //printf("Au revoir !\n");
                break;
                
            default:
                printf("\nChoix invalide. Veuillez choisir entre 1 et 5.\n");
        }
        
    } while (choix != 5);
    
    return 0;
}