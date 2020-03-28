#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node* forwards;
    int value;
};

struct node* new(int val){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->value = val;
    return new_node;
}

void append (struct node* head, int val){
    struct node* new_node = new(val);

    struct node* current;
    for (current=head; current->forwards!= NULL; current=current->forwards) {
    }
    
    current->forwards = new_node;
}

struct node*  push_front(struct node* head, int val){
    struct node* new_node = new(val);
    new_node->forwards = head;
    return new_node;
}

void print_list(struct node* head){
    struct node* current;
    for (current=head; current!= NULL; current=current->forwards) {
        printf("%d -> ", current->value);
    }
    printf("\n");
}

struct node* reverse(struct node* head){
    struct node* new_head = NULL;

    struct node* current;
    for(current=head; current!=NULL;current=current->forwards){
        new_head = push_front(new_head, current->value);
    }

    return new_head;
}

void insert(struct node* head, int val){
  struct node* current;
  for(current=head; current->forwards != NULL && current->forwards->value < val; current=current->forwards){
  }
  struct node* new_node = new(val);
  new_node->forwards = current->forwards;
  current->forwards = new_node;
}

int main(){

    struct node* head = new(1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 6);
    append(head, 7);
    append(head, 8);
    append(head, 9);
    print_list(head);
    printf("\n");

    struct node* head2 = new(9);
    head2 = push_front(head2, 8);
    head2 = push_front(head2, 7);
    head2 = push_front(head2, 6);
    head2 = push_front(head2, 5);
    head2 = push_front(head2, 4);
    head2 = push_front(head2, 3);
    head2 = push_front(head2, 2);
    head2 = push_front(head2, 1);
    print_list(head2);
    printf("\n");

    struct node* reversed = reverse(head2);
    print_list(reversed);

    insert(head, 5);
    print_list(head);
    
    return 0;
}
