//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends


/*Complete the functions below*/
int find(int A[],int X)
{
       if(X == A[X]) return X;
       
       return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
    X = find(A, X);
    Z = find(A, Z);
    
    A[X] = Z;

//  int n = sizeof(A);
// 	int rank[n+1] = {0};
	
	
// 	int ulp_X = find(A, X);
// 	int ulp_Z = find(A, Z);
	
	
	
// 	if(ulp_X == ulp_Z) return;
	
// 	if(rank[ulp_X] < rank[ulp_Z]){
// 	    A[ulp_X] = ulp_Z;
// 	}
// 	else if(rank[ulp_Z] < rank[ulp_X]){
// 	    A[ulp_Z] = ulp_X;
// 	}
	
// 	else{
// 	    A[ulp_X] = ulp_Z;
// 	    rank[ulp_Z]++;
// 	}
	
}