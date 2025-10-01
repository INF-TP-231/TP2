#include <stdio.h>
#include <stdlib.h>

// === STRUCTURES ===

// Liste simplement chaînée
typedef struct NodeSimple {
    int data;
    struct NodeSimple* next;
} NodeSimple;

// Liste doublement chaînée
typedef struct NodeDouble {
    int data;
    struct NodeDouble* next;
    struct NodeDouble* prev;
} NodeDouble;

// === FONCTIONS AUXILIAIRES ===

// Créer un noeud simple
NodeSimple* creerNodeSimple(int val) {
    NodeSimple* nouveau = (NodeSimple*)malloc(sizeof(NodeSimple));
    nouveau->data = val;
    nouveau->next = NULL;
    return nouveau;
}

// Créer un noeud double
NodeDouble* creerNodeDouble(int val) {
    NodeDouble* nouveau = (NodeDouble*)malloc(sizeof(NodeDouble));
    nouveau->data = val;
    nouveau->next = NULL;
    nouveau->prev = NULL;
    return nouveau;
}

// Afficher liste simple
void afficherListeSimple(NodeSimple* head) {
    NodeSimple* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Afficher liste double
void afficherListeDouble(NodeDouble* head) {
    NodeDouble* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// === EXERCICE 1 ===
// Supprimer toutes les occurrences d'un élément dans une liste

NodeSimple* supprimerOccurrences(NodeSimple* head, int valeur) {
    NodeSimple *temp = head, *prev = NULL;
    
    // Supprimer les occurrences en tête
    while (head != NULL && head->data == valeur) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    // Supprimer les occurrences dans le reste
    temp = head;
    while (temp != NULL) {
        if (temp->data == valeur) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    
    return head;
}

// === EXERCICE 2 ===
// Insertion dans une liste simplement chaînée triée

NodeSimple* insertionTrieeSimple(NodeSimple* head, int valeur) {
    NodeSimple* nouveau = creerNodeSimple(valeur);
    
    // Liste vide ou insertion en tête
    if (head == NULL || head->data >= valeur) {
        nouveau->next = head;
        return nouveau;
    }
    
    // Trouver la position d'insertion
    NodeSimple* temp = head;
    while (temp->next != NULL && temp->next->data < valeur) {
        temp = temp->next;
    }
    
    nouveau->next = temp->next;
    temp->next = nouveau;
    
    return head;
}

// === EXERCICE 3 ===
// Insertion dans une liste doublement chaînée triée

NodeDouble* insertionTrieeDouble(NodeDouble* head, int valeur) {
    NodeDouble* nouveau = creerNodeDouble(valeur);
    
    // Liste vide
    if (head == NULL) {
        return nouveau;
    }
    
    // Insertion en tête
    if (head->data >= valeur) {
        nouveau->next = head;
        head->prev = nouveau;
        return nouveau;
    }
    
    // Trouver la position d'insertion
    NodeDouble* temp = head;
    while (temp->next != NULL && temp->next->data < valeur) {
        temp = temp->next;
    }
    
    nouveau->next = temp->next;
    nouveau->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = nouveau;
    }
    temp->next = nouveau;
    
    return head;
}

// === EXERCICE 4 ===
// Insertion en tête et en queue dans une liste simplement chaînée circulaire

NodeSimple* insertionTeteCirculaire(NodeSimple* last, int valeur) {
    NodeSimple* nouveau = creerNodeSimple(valeur);
    
    if (last == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    nouveau->next = last->next;
    last->next = nouveau;
    
    return last;
}

NodeSimple* insertionQueueCirculaire(NodeSimple* last, int valeur) {
    NodeSimple* nouveau = creerNodeSimple(valeur);
    
    if (last == NULL) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    nouveau->next = last->next;
    last->next = nouveau;
    
    return nouveau; // Le nouveau noeud devient le dernier
}

void afficherCirculaireSimple(NodeSimple* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    NodeSimple* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(retour au début)\n");
}

// === EXERCICE 5 ===
// Insertion en tête et en queue dans une liste doublement chaînée circulaire

NodeDouble* insertionTeteCirculaireDouble(NodeDouble* last, int valeur) {
    NodeDouble* nouveau = creerNodeDouble(valeur);
    
    if (last == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    NodeDouble* head = last->next;
    
    nouveau->next = head;
    nouveau->prev = last;
    head->prev = nouveau;
    last->next = nouveau;
    
    return last;
}

NodeDouble* insertionQueueCirculaireDouble(NodeDouble* last, int valeur) {
    NodeDouble* nouveau = creerNodeDouble(valeur);
    
    if (last == NULL) {
        nouveau->next = nouveau;
        nouveau->prev = nouveau;
        return nouveau;
    }
    
    NodeDouble* head = last->next;
    
    nouveau->next = head;
    nouveau->prev = last;
    last->next = nouveau;
    head->prev = nouveau;
    
    return nouveau; // Le nouveau noeud devient le dernier
}

void afficherCirculaireDouble(NodeDouble* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    NodeDouble* temp = last->next;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(retour au début)\n");
}

// === FONCTION PRINCIPALE ===

int main() {
    printf("=== EXERCICE INF 231 - 25 SEPTEMBRE 2025 ===\n");
    printf("Etudiant: AKANA SIGNING JOSIAS AARON\n");
    printf("Matricule: 24H2358\n\n");
    
    // Test Exercice 1
    printf("--- EXERCICE 1: Suppression d'occurrences ---\n");
    NodeSimple* liste1 = creerNodeSimple(5);
    liste1->next = creerNodeSimple(3);
    liste1->next->next = creerNodeSimple(5);
    liste1->next->next->next = creerNodeSimple(7);
    liste1->next->next->next->next = creerNodeSimple(5);
    printf("Liste avant: ");
    afficherListeSimple(liste1);
    liste1 = supprimerOccurrences(liste1, 5);
    printf("Liste après suppression de 5: ");
    afficherListeSimple(liste1);
    
    // Test Exercice 2
    printf("\n--- EXERCICE 2: Insertion triée (liste simple) ---\n");
    NodeSimple* liste2 = NULL;
    liste2 = insertionTrieeSimple(liste2, 5);
    liste2 = insertionTrieeSimple(liste2, 2);
    liste2 = insertionTrieeSimple(liste2, 8);
    liste2 = insertionTrieeSimple(liste2, 1);
    liste2 = insertionTrieeSimple(liste2, 6);
    printf("Liste triée: ");
    afficherListeSimple(liste2);
    
    // Test Exercice 3
    printf("\n--- EXERCICE 3: Insertion triée (liste double) ---\n");
    NodeDouble* liste3 = NULL;
    liste3 = insertionTrieeDouble(liste3, 5);
    liste3 = insertionTrieeDouble(liste3, 2);
    liste3 = insertionTrieeDouble(liste3, 8);
    liste3 = insertionTrieeDouble(liste3, 1);
    liste3 = insertionTrieeDouble(liste3, 6);
    printf("Liste triée: ");
    afficherListeDouble(liste3);
    
    // Test Exercice 4
    printf("\n--- EXERCICE 4: Liste circulaire simple ---\n");
    NodeSimple* liste4 = NULL;
    liste4 = insertionQueueCirculaire(liste4, 1);
    liste4 = insertionQueueCirculaire(liste4, 2);
    liste4 = insertionTeteCirculaire(liste4, 0);
    liste4 = insertionQueueCirculaire(liste4, 3);
    printf("Liste circulaire: ");
    afficherCirculaireSimple(liste4);
    
    // Test Exercice 5
    printf("\n--- EXERCICE 5: Liste circulaire double ---\n");
    NodeDouble* liste5 = NULL;
    liste5 = insertionQueueCirculaireDouble(liste5, 1);
    liste5 = insertionQueueCirculaireDouble(liste5, 2);
    liste5 = insertionTeteCirculaireDouble(liste5, 0);
    liste5 = insertionQueueCirculaireDouble(liste5, 3);
    printf("Liste circulaire double: ");
    afficherCirculaireDouble(liste5);
    
    return 0;
}
