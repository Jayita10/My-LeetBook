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
//     ListNode* middleNode(ListNode* head) {
//         vector<ListNode*> arr = {head};
        
//         while(arr.back()->next != NULL){
//             arr.push_back(arr.back()->next);
//         }
//         return arr[arr.size()/2];
//     }
    
    ListNode* middleNode(ListNode* head){
        ListNode* fast = head; 
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};