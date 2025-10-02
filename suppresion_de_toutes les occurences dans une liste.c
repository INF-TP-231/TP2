#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("erreur d'allocation memoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int value){
    Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void freeOccurrence(Node** head, int v) {
    Node* current = *head;
    Node* prev = NULL;
    while(current != NULL){
        if(current->data == v){
            if(prev == NULL){ // Node to be freed is the head
                *head = current->next;
                free(current);
                current = *head; // Update current to the new head
            } else { // Node to be freed is not the head
                prev->next = current->next;
                free(current);
                current = prev->next; // Update current to the next node after deletion
            }
        } else { // Current node does not match the value, move to the next
            prev = current;
            current = current->next;
        }
    }
}

int main(){
    int n, v, i;
    Node* head = NULL;

    printf("saisir le nombre d'element: "); 
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("sasisir l'element %d: ", i + 1); 
        scanf("%d", &v);
        insertAtEnd(&head, v);
    }

    printf("saisir l'element a supprimer: "); 
    scanf("%d", &v);

    freeOccurrence(&head, v);

    Node *current = head;
    printf("Liste apres suppression: "); 
    while(current != NULL){
        printf("%d ", current->data); 
        current = current->next;
    }
    printf("\n"); 

    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL; 

    return 0;
}
