/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        vector<int> arr;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
    
    
            int n = arr.size();
            int i = 0;
            int l = n-1;

            while(i <= l){
                if(arr[i++] != arr[l--])
                    return false;
            }
            return true;
    }
    */
    
    ListNode* reverse(ListNode* root){
        ListNode* newnode = NULL;
        
        while(root != NULL){
            ListNode* next = root->next;
            root->next = newnode;
            newnode = root;
            root = next;
        }
        
        return newnode;
    }
    
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        while(slow != NULL){
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};



