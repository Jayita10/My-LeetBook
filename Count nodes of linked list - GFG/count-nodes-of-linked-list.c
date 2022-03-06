
// Driver Code Ends


//User function Template for C
// iterative
int getCount(struct Node* head){
    if(head == NULL) return 0;
    return 1 + getCount(head->next);
}

//recursive
int getCount(struct Node* head){
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
