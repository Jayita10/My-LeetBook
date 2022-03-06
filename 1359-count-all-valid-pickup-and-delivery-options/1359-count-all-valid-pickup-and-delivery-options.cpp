class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, m = 1000000007;
        for (int i=1; i<n+1; ++i) ans = ans * i % m;
        for (int i=1; i<2*n; i+=2) ans = ans * i % m;
        return ans;
    }
};