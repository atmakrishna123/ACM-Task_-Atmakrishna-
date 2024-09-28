struct SinglyLinkedListNode* removeDuplicates(struct SinglyLinkedListNode* head) {
    struct SinglyLinkedListNode* current=head;
    while(current!=NULL && current->next!=NULL){
        if (current->data==current->next->data){
            struct SinglyLinkedListNode* duplicate=current->next;
            current->next=current->next->next;
            free(duplicate);
        }else{
            current=current->next;
        }
    }
    return(head);
}