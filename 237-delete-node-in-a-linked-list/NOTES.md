Linked list basic node structure: {value, address of next node}
​
So, linked list is something similar to this
​
(head_value, addr_2)---->(val_2, addr_3)---->(val_3, addr_4)---->(val_4, addr_5)---->NULL
Let's say Node to be deleted is 2nd node pointed by a pointer *node = (val_2, addr_3)
​
Now, we take another pointer to point to next node
​
ListNode* nextNode = node->next;
Then we copy the next node to current node
```
here, we are deferecing pointers
so we are copying the next node content to current node i.e. (node_value, address_of_next_node)
now current node has nextNode's value and it has address of (node->next->next) node
so we updated current node next pointer, by pointing it to (node->next->next) node
*node = *nextNode;
​
after copying node it looks something like this
- (head_value, addr_2)---->(val_3, addr_4)        (val_3, addr_4)---->(val_4, addr_5)---->NULL
|___________________________________________^
​
​
second node has node_value of 3rd node
also second node has address of 4th node so, 2nd node next pointer point to 4th node
```
​
and finally delete the node pointed by temp pointer because we have already copy it's content to current node
Time and Space: O(1)