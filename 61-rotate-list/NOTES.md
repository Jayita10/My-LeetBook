**Brute force**
put the last node and rotate k times,
TC :  O(k * n) , n -> for last node, k -> times to put in front
SC : O(1)
​
**Optimal**
find the length, if k>length, then %
make the ll circular, rotate till count <= length-k
TC : O(n)[length] + O(n- n%k)
SC : O(1)