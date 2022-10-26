// from reverse_ll_recurrsive_method2.cpp 



/*         WHY POINTER VARIABLE OF FORM PAIR IS NOT CREATED?
Pair *reverse(Node *head)
{
    if(head==NULL || head->next==NULL){
        Pair *ans;
        ans->head=head;
        ans->tail=head;
        return ans;
    }
    Pair *smallans=reverse(head->next);
    (smallans->tail)->next=head;
    head->next=NULL;
    Pair *ans;
    ans->head=smallans->head;
    ans->tail=head;
    return ans;
}

Node *reverse_better(Node *head){
    return reverse(head)->head ;
}
*/