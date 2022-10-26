////////////////////////////////////////////////////////////////////////////1ST
Node* merge(Node *head1, Node *head2) {
	if(head1 == NULL) {
		return head2;
	}
	if(head2 == NULL) {
		return head1;
	}
	Node *head = NULL, *tail = NULL;
	if(head1 -> data < head2 -> data) {
		head = head1;
		tail = head1;
		head1 = head1 -> next;
	}
	else {
		head = head2;
		tail = head2;
		head2 = head2 -> next;
	}

	while(head1 != NULL && head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			tail -> next = head1;
			tail = head1;
			head1 = head1 -> next;
		}
		else {
			tail -> next = head2;
			tail = head2;
			head2 = head2 -> next;
		}
	}
	if(head1 != NULL) {
		tail -> next = head1;
	}
	if(head2 != NULL) {
		tail -> next = head2;
	}
	return head;
}

////////////////////////////////////////////////////////////////////////2ND

Node *merge(Node *head1, Node *head2){
    Node *fhead=NULL ; 
    Node *ftail=NULL;
    Node *temp1=head1;
    Node *temp2=head2;
    if (head1==NULL){
        return head2;
    }
    else if(head2==NULL) {
        return head1;
    }
    while (temp1!=NULL && temp2!=NULL){
        if (temp1->data < temp2->data){
            if (fhead==NULL){
                fhead=temp1;
                ftail=temp1;
            }
            else {
                ftail->next=temp1;
                ftail=temp1;
            }
            temp1=temp1->next;
        }
        else if (temp1->data >= temp2->data){
            if (fhead==NULL){
                fhead=temp2;
                ftail=temp2;
            }
            else{
                ftail->next=temp2;
                ftail=temp2;
            }
            temp2=temp2->next;
        } 
    }
    while (temp2==NULL){
        ftail->next=temp1;
    }
    if (temp1==NULL){
        ftail->next=temp2;
    } 
    return fhead;
} 

//////////////////////////////////////////////////////////////////////////////// 

//WHY 1ST IS BETTER THAN 2ND ?