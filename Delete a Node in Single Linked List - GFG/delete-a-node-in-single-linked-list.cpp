
/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    Node *temp = head;
    if(x == 1){
        temp = head->next;
        return temp;
    }
    int count = 1;
    while(temp != NULL && count < x-1){
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next; //value put
    temp = temp->next; //connect the node
    return head;
}
