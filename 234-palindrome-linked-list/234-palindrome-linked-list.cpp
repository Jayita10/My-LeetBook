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
    bool check(vector<int> &arr, int n){
        int i = 0;
        int l = n-1;
        
        while(i <= l){
            if(arr[i++] != arr[l--])
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        vector<int> arr;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        if(check(arr,n)) return true;
        return false;
    }
};