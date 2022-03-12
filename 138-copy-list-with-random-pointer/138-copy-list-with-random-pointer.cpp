/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* iter = head;
        Node* front = head;
        
        while(iter != NULL){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        Node* psudo_head = new Node(0);
        Node* copy = psudo_head;
        while(iter != NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return psudo_head->next;
    }
};


/*  Brute Force!
unorddered_map<Node*, Node*> m;
        Node* temp = head;
        while(temp != NULL){
            m.insert(temp, new node(temp->val));
            temp = temp->next;
        }
        https://leetcode.com/problems/copy-list-with-random-    pointer/discuss/249256/C%2B%2B-iterative-recursive-and-O(1)-space
        */ 