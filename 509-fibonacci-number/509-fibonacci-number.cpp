class Solution {
public:
    int fib(int n) {
        //bottom-up space optimization
        if(n <= 1)
            return n;
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=2;i<=n;i++){
            int curr_i = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr_i;
        }
        return prev1;
    }
};