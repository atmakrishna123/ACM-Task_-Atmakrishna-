SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }
    SinglyLinkedListNode* mergedHead=NULL;
    if (head1->data<=head2->data){
        mergedHead=head1;
        mergedHead->next=mergeLists(head1->next,head2);
    }else{
        mergedHead=head2;
        mergedHead->next=mergeLists(head1,head2->next);
    }
    return(mergedHead);
}