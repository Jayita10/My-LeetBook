**Brute Force**
1.  store all the linkedList value in vector
2.  check the vector is palindrome or not
3.  TC : O(n)+O(n) , SC : O(n)
​
**Optimal**
1. find middle, which has slow pointer
2. reverse the next(right) half of slow pointer
3. shift the slow by 1(odd & even) and then compare temp and slow(left and right compare), slow null -> palindrome
4. TC: O(n/2) + O(n/2) + O(n/2) + {O(n/2) + O(n/2)}
middle + reverse + compare + find mid + back to original ll
5. SC : O(1)