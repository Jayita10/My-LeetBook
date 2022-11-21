//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    bool allocationIsPossible(int arr[], int barrier, int s, int n){
        int studentReq = 1, pages = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] > barrier) return false;
            if(arr[i] + pages > barrier){
                studentReq++;
                pages = arr[i];
            }
            else{
                pages += arr[i];
            }
        }
        
        if(studentReq > s) return false;
        else return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int n, int s) 
    {
        if(s > n) return -1;
        int low = A[0];
        int high = 0;
        
        for(int i=0;i<n;i++){
            low = min(low, A[i]);
            high += A[i];
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(allocationIsPossible(A, mid, s, n)){
                high = mid-1;
            }
            else low = mid + 1;
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends