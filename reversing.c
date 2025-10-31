#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
    
};

struct Node*head=NULL;

void insertAtEnd(int data){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    if (head==NULL){
        head=new_node;
        return;
    }
    struct Node*last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    
    
}
void reverseList(){
    struct Node*prev=NULL;
    struct Node*current=head;
    struct Node*next=NULL;
    
    while (current !=NULL){
        next=current->next;
        
        current->next=prev;
        
        prev=current;
        current=next;
        
    }
    head=prev;
    
}
void printList(){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main() {
    
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    printf("Initial list:");
    printList();
    
    reverseList();
    printf("Reversed list:");
    printList();
    
    return 0;
}