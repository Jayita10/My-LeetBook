class Solution {
public:
    int solve(ListNode* head, int k){
        ListNode* temp = head;
        ListNode* pre = NULL;
        
        while(head->next != head){
            for(int i=1;i<k;i++){
                pre = temp;
                temp = temp->next;
            }
            if(temp == head){
                head = head->next;
            }
            pre->next = temp->next;
            delete(temp);
            temp = pre->next;
        }
        return head->val;
    }
    
    int findTheWinner(int n, int k) {
        if(k == 1) return n;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int i=1;i<=n;i++){
            ListNode* node = new ListNode(i);
            if(head == NULL)
                head = tail = node;
            else{
                tail->next = node;
                tail = node;
            }
            tail->next = head;
        }
        return solve(head,k);
    }
};