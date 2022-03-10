**Brute force** 1. Put every node into an array A in order. Then the middle node is just A[A.length // 2], since we can retrieve each node by index.
TC : O(n) SC : O(n)
2. count no of nodes, iterate (count/2 + 1) and print the data TC: O(n) + O(n/2) SC : O(1)


**Optimal**
Two pointer approach - inc fast pointer by 2 & slow pointer by 1
***if(fast pointer reach last node or null, slow will be in middle/ 2nd middle(even)***
- if 1st middle ask for even n of nodes, we need to stop the fast before last node/ 2nd last node
- TC : as fast pointer inc by 2 & go till last **O(n/2)**
- SC : O(1)
