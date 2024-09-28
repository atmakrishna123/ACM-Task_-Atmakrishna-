#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
struct Node*createNode(int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertAtBeginning(struct Node**head,int data){
    struct Node*newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}
void insertAtEnd(struct Node**head,int data){
    struct Node*newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAtPosition(struct Node**head,int data,int pos){
    if(pos==1){
        insertAtBeginning(head,data);
        return;
    }
    struct Node*newNode=createNode(data);
    struct Node*temp=*head;
    for(int i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        insertAtEnd(head,data);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
}
void deleteFromBeginning(struct Node**head){
    if(*head==NULL)return;
    struct Node*temp=*head;
    *head=(*head)->next;
    if(*head!=NULL){
        (*head)->prev=NULL;
    }
    free(temp);
}
void deleteFromEnd(struct Node**head){
    if(*head==NULL)return;
    struct Node*temp=*head;
    if(temp->next==NULL){
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void deleteFromPosition(struct Node**head,int pos){
    if(*head==NULL)return;
    if(pos==1){
        deleteFromBeginning(head);
        return;
    }
    struct Node*temp=*head;
    for(int i=1;i<pos&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        deleteFromEnd(head);
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void traverseForward(struct Node*head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void traverseBackward(struct Node*head){
    if(head==NULL)return;
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main(){
    struct Node*head=NULL;
    insertAtBeginning(&head,5);
    insertAtEnd(&head,10);
    insertAtPosition(&head,7,2);
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head,2);
    traverseForward(head);
    traverseBackward(head);
    return 0;
}