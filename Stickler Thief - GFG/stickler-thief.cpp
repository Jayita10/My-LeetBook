//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
	   if(n == 2) return max(arr[1], arr[0]);
	   
	   int prev1 = max(arr[1], arr[0]);
	   int prev2 = arr[0];
	   
	   for(int i=2;i<n;i++){
	       int op1 = arr[i] + prev2;
	       int op2 = prev1;
	       
	       int curri = max(op1, op2);
	       prev2 = prev1;
	       prev1 = curri;
	   }
	   return prev1;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends