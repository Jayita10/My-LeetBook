//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int num) {
        int cnt = 0;
        
        // logn
        // while(num){
        //     cnt += num & 1;
        //     num >>= 1;
        // }
        
        // another method
        // loop == no of set bits == TC
        while(num){
            cnt++;
            num = num & (num-1);
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends