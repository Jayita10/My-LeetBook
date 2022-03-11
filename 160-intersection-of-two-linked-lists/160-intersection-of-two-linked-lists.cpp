/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /** Brute Force1 : TC: O(n^2), SC: O(1)
        
        ListNode* temp;
        while(headA != NULL){
            temp = headB;
            while(temp != NULL){
                if(temp == headA)
                    return temp;
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
        
        Brute Force2 : TC: O(n), SC: O(n)
        
        unordered_map<ListNode*, int> m;
        while(headA != NULL){
            m[headA]++;
            headA = headA->next;
        }
        
        while(headB != NULL){
            if(m[headB] > 0) // ?
                return headB;
            headB = headB->next;
        }
        return NULL;
        **/
        
        if(!headA || !headB) return NULL;
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1 != ptr2){
            ptr1 = ptr1 == NULL? headB : ptr1->next;
            ptr2 = ptr2 == NULL? headA : ptr2->next;
        }
        return ptr2;
    }
};