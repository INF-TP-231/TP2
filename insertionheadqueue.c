#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud de la liste doublement chaînée circulaire
typedef struct Noeud {
    int donnee;
    struct Noeud* suivant;
    struct Noeud* precedent;
} Noeud;

// Structure de la liste (pointeur vers le premier élément)
typedef struct {
    Noeud* tete;
    int taille;
} ListeCirculaire;

// Fonction pour créer une nouvelle liste vide
ListeCirculaire* creer_liste() {
    ListeCirculaire* liste = (ListeCirculaire*)malloc(sizeof(ListeCirculaire));
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    liste->tete = NULL;
    liste->taille = 0;
    return liste;
}

// Fonction pour créer un nouveau nœud
Noeud* creer_noeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    nouveau->donnee = valeur;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

// Fonction pour vérifier si la liste est vide
int est_vide(ListeCirculaire* liste) {
    return (liste->tete == NULL);
}

// INSERTION EN TÊTE
void inserer_en_tete(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);
    
    printf("\n--- INSERTION EN TÊTE : %d ---\n", valeur);
    
    if (est_vide(liste)) {
        // Cas 1 : Liste vide
        printf("Liste vide → Premier élément\n");
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
        liste->tete = nouveau;
    } else {
        // Cas 2 : Liste non vide
        Noeud* dernier = liste->tete->precedent;  // Le dernier élément
        
        printf("Ancienne tête : %d\n", liste->tete->donnee);
        printf("Dernier élément : %d\n", dernier->donnee);
        
        // Insérer le nouveau nœud entre le dernier et la tête
        nouveau->suivant = liste->tete;
        nouveau->precedent = dernier;
        
        liste->tete->precedent = nouveau;
        dernier->suivant = nouveau;
        
        // Le nouveau nœud devient la nouvelle tête
        liste->tete = nouveau;
        
        printf("Nouvelle tête : %d\n", liste->tete->donnee);
    }
    
    liste->taille++;
    printf("Taille de la liste : %d\n", liste->taille);
}

// INSERTION EN QUEUE
void inserer_en_queue(ListeCirculaire* liste, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);
    
    printf("\n--- INSERTION EN QUEUE : %d ---\n", valeur);
    
    if (est_vide(liste)) {
        // Cas 1 : Liste vide
        printf("Liste vide → Premier élément\n");
        nouveau->suivant = nouveau;
        nouveau->precedent = nouveau;
        liste->tete = nouveau;
    } else {
        // Cas 2 : Liste non vide
        Noeud* dernier = liste->tete->precedent;  // Le dernier élément actuel
        
        printf("Tête : %d\n", liste->tete->donnee);
        printf("Ancien dernier : %d\n", dernier->donnee);
        
        // Insérer le nouveau nœud entre le dernier et la tête
        nouveau->suivant = liste->tete;
        nouveau->precedent = dernier;
        
        dernier->suivant = nouveau;
        liste->tete->precedent = nouveau;
        
        printf("Nouveau dernier : %d\n", nouveau->donnee);
    }
    
    liste->taille++;
    printf("Taille de la liste : %d\n", liste->taille);
}

// Fonction pour afficher la liste dans le sens direct (sens des suivants)
void afficher_liste_avant(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        printf("Liste vide\n");
        return;
    }
    
    printf("\n=== AFFICHAGE SENS DIRECT (suivant) ===\n");
    printf("Tête → ");
    
    Noeud* courant = liste->tete;
    int compteur = 0;
    
    do {
        printf("[%d]", courant->donnee);
        courant = courant->suivant;
        compteur++;
        
        if (courant != liste->tete) {
            printf(" ⇄ ");
        }
        
        // Sécurité : éviter une boucle infinie
        if (compteur > liste->taille) {
            printf(" (ERREUR: boucle détectée)");
            break;
        }
    } while (courant != liste->tete);
    
    printf(" → (retour à la tête)\n");
}

// Fonction pour afficher la liste dans le sens inverse (sens des précédents)
void afficher_liste_arriere(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        printf("Liste vide\n");
        return;
    }
    
    printf("\n=== AFFICHAGE SENS INVERSE (précédent) ===\n");
    printf("Tête → ");
    
    Noeud* courant = liste->tete->precedent;  // Commencer par le dernier
    int compteur = 0;
    
    do {
        printf("[%d]", courant->donnee);
        courant = courant->precedent;
        compteur++;
        
        if (courant != liste->tete->precedent) {
            printf(" ⇄ ");
        }
        
        // Sécurité
        if (compteur > liste->taille) {
            printf(" (ERREUR: boucle détectée)");
            break;
        }
    } while (courant != liste->tete->precedent);
    
    printf(" → (retour au dernier)\n");
}

// Fonction pour afficher les détails des liaisons
void afficher_details_liaisons(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        printf("\nListe vide - Aucune liaison\n");
        return;
    }
    
    printf("\n=== DÉTAILS DES LIAISONS ===\n");
    Noeud* courant = liste->tete;
    int position = 0;
    
    do {
        printf("Position %d : [%d]\n", position, courant->donnee);
        printf("  ← précédent: [%d]\n", courant->precedent->donnee);
        printf("  → suivant:   [%d]\n", courant->suivant->donnee);
        
        courant = courant->suivant;
        position++;
    } while (courant != liste->tete);
    
    printf("\nTête : [%d]\n", liste->tete->donnee);
    printf("Queue : [%d]\n", liste->tete->precedent->donnee);
}

// Fonction pour supprimer en tête
int supprimer_en_tete(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        printf("Erreur : Liste vide, suppression impossible\n");
        return -1;
    }
    
    Noeud* ancien_tete = liste->tete;
    int valeur = ancien_tete->donnee;
    
    printf("\n--- SUPPRESSION EN TÊTE : %d ---\n", valeur);
    
    if (liste->tete->suivant == liste->tete) {
        // Cas : un seul élément
        printf("Dernier élément supprimé\n");
        liste->tete = NULL;
    } else {
        // Cas : plusieurs éléments
        Noeud* dernier = liste->tete->precedent;
        Noeud* nouveau_tete = liste->tete->suivant;
        
        dernier->suivant = nouveau_tete;
        nouveau_tete->precedent = dernier;
        
        liste->tete = nouveau_tete;
        printf("Nouvelle tête : %d\n", liste->tete->donnee);
    }
    
    free(ancien_tete);
    liste->taille--;
    printf("Taille de la liste : %d\n", liste->taille);
    
    return valeur;
}

// Fonction pour supprimer en queue
int supprimer_en_queue(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        printf("Erreur : Liste vide, suppression impossible\n");
        return -1;
    }
    
    Noeud* dernier = liste->tete->precedent;
    int valeur = dernier->donnee;
    
    printf("\n--- SUPPRESSION EN QUEUE : %d ---\n", valeur);
    
    if (liste->tete->suivant == liste->tete) {
        // Cas : un seul élément
        printf("Dernier élément supprimé\n");
        liste->tete = NULL;
    } else {
        // Cas : plusieurs éléments
        Noeud* avant_dernier = dernier->precedent;
        
        avant_dernier->suivant = liste->tete;
        liste->tete->precedent = avant_dernier;
        
        printf("Nouveau dernier : %d\n", avant_dernier->donnee);
    }
    
    free(dernier);
    liste->taille--;
    printf("Taille de la liste : %d\n", liste->taille);
    
    return valeur;
}

// Fonction pour libérer toute la liste
void liberer_liste(ListeCirculaire* liste) {
    if (est_vide(liste)) {
        free(liste);
        return;
    }
    
    Noeud* courant = liste->tete;
    Noeud* suivant;
    
    // Briser le lien circulaire
    liste->tete->precedent->suivant = NULL;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    
    free(liste);
    printf("\nMémoire libérée avec succès !\n");
}

// Menu interactif
void afficher_menu() {
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║  LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf("1. Insérer en TÊTE\n");
    printf("2. Insérer en QUEUE\n");
    printf("3. Supprimer en TÊTE\n");
    printf("4. Supprimer en QUEUE\n");
    printf("5. Afficher la liste (sens direct)\n");
    printf("6. Afficher la liste (sens inverse)\n");
    printf("7. Afficher les détails des liaisons\n");
    printf("8. Test automatique\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

// Fonction de test automatique
void test_automatique(ListeCirculaire* liste) {
    printf("\n╔═══════════════════════════════════╗\n");
    printf("║       TEST AUTOMATIQUE            ║\n");
    printf("╚═══════════════════════════════════╝\n");
    
    printf("\n1. Insertion en tête : 10, 20, 30\n");
    inserer_en_tete(liste, 10);
    inserer_en_tete(liste, 20);
    inserer_en_tete(liste, 30);
    afficher_liste_avant(liste);
    
    printf("\n2. Insertion en queue : 5, 3\n");
    inserer_en_queue(liste, 5);
    inserer_en_queue(liste, 3);
    afficher_liste_avant(liste);
    afficher_liste_arriere(liste);
    
    printf("\n3. Détails des liaisons :\n");
    afficher_details_liaisons(liste);
    
    printf("\n4. Suppression en tête\n");
    supprimer_en_tete(liste);
    afficher_liste_avant(liste);
    
    printf("\n5. Suppression en queue\n");
    supprimer_en_queue(liste);
    afficher_liste_avant(liste);
}

int main() {
    ListeCirculaire* liste = creer_liste();
    int choix, valeur;
    
    printf("╔════════════════════════════════════════════╗\n");
    printf("║  GESTION LISTE DOUBLEMENT CHAÎNÉE         ║\n");
    printf("║          CIRCULAIRE EN C                  ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    do {
        afficher_menu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                printf("Valeur à insérer en tête : ");
                scanf("%d", &valeur);
                inserer_en_tete(liste, valeur);
                afficher_liste_avant(liste);
                break;
                
            case 2:
                printf("Valeur à insérer en queue : ");
                scanf("%d", &valeur);
                inserer_en_queue(liste, valeur);
                afficher_liste_avant(liste);
                break;
                
            case 3:
                supprimer_en_tete(liste);
                afficher_liste_avant(liste);
                break;
                
            case 4:
                supprimer_en_queue(liste);
                afficher_liste_avant(liste);
                break;
                
            case 5:
                afficher_liste_avant(liste);
                break;
                
            case 6:
                afficher_liste_arriere(liste);
                break;
                
            case 7:
                afficher_details_liaisons(liste);
                break;
                
            case 8:
                test_automatique(liste);
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
