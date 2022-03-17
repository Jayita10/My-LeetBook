class Solution {
public:
    int tribonacci(int n) {
        //bottom up space  optimaization
        if(n<=1)
            return n;
        if(n == 2)
            return 1;
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        
        for(int i=3;i<=n;i++){
            int curr_i = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr_i;
        }
        return prev1;
    }
};