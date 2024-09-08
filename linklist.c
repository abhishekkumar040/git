#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *add;
};

struct node *start = NULL;

void create();
void insert_first();
void display();
void delete_from_first();
void insert_last();
void delete_from_last();
void insert_middle();
void delete_from_middle();

int main() {
    int choice;
    
    do {
        printf("--------- Linked List ---------\n");
        printf("1. Create\n2. Insert at First\n3. Insert in Middle\n4. Insert at Last\n5. Display\n6. Delete from First\n7. Delete from Middle\n8. Delete from Last\n9. Exit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_first(); break;
            case 3: insert_middle(); break;
            case 4: insert_last(); break;
            case 5: display(); break;
            case 6: delete_from_first(); break;
            case 7: delete_from_middle(); break;
            case 8: delete_from_last(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n"); break;
        }
    } while (choice != 9);

    return 0;
}

void create() {
    int n;
    char ch;
    
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter first element: ");
    scanf("%d", &n);
    start->data = n;
    start->add = NULL;
    
    struct node *temp = start;
    
    printf("Want to continue (Y/N)? ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y') {
        struct node *new1 = (struct node *)malloc(sizeof(struct node));
        if (new1 == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter the next element: ");
        scanf("%d", &n);
        new1->data = n;
        new1->add = NULL;
        
        temp->add = new1;
        temp = new1;
        
        printf("Want to continue (Y/N)? ");
        scanf(" %c", &ch);
    }
}

void insert_first() {
    int n;
    printf("Enter new element to insert: ");
    scanf("%d", &n);
    
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new1->data = n;
    new1->add = start;
    start = new1;
}

void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->add;
    }
    printf("NULL\n");
}

void delete_from_first() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    start = start->add;
    free(temp);
}

void insert_last() {
    int n;
    printf("Enter new element to insert at the end: ");
    scanf("%d", &n);
    
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new1->data = n;
    new1->add = NULL;
    
    if (start == NULL) {
        start = new1;
    } else {
        struct node *temp = start;
        while (temp->add != NULL) {
            temp = temp->add;
        }
        temp->add = new1;
    }
}

void delete_from_last() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (start->add == NULL) {
        free(start);
        start = NULL;
        return;
    }
    
    struct node *temp = start;
    struct node *prev = NULL;
    
    while (temp->add != NULL) {
        prev = temp;
        temp = temp->add;
    }
    free(temp);
    prev->add = NULL;
}

void insert_middle() {
    int n, pos, i;
    printf("Enter the position to insert the new element: ");
    scanf("%d", &pos);
    printf("Enter new element: ");
    scanf("%d", &n);
    
    struct node *new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new1->data = n;
    
    if (pos == 1) {
        new1->add = start;
        start = new1;
        return;
    }
    
    struct node *temp = start;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->add;
    }
    
    if (temp == NULL) {
        printf("Position is out of bounds\n");
        free(new1);
        return;
    }
    
    new1->add = temp->add;
    temp->add = new1;
}

void delete_from_middle() {
    int pos, i;
    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);
    
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (pos == 1) {
        struct node *temp = start;
        start = start->add;
        free(temp);
        return;
    }
    
    struct node *temp = start;
    struct node *prev = NULL;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->add;
    }
    
    if (temp == NULL) {
        printf("Position is out of bounds\n");
        return;
    }
    
    prev->add = temp->add;
    free(temp);
}
