

// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node* head, int index){
    int count = 1;
    struct node* temp = head;
    
    while(temp != NULL){
        if(count == index) 
            return (temp->data);
        count++;
        temp = temp->next;
    }
}
