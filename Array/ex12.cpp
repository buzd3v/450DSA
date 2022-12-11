//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        //kadane's algo
        // this algo works if only there's at least one positive number in the array
        int max_so_far = INT32_MIN;
        int max_ending_here = 0;
        for(int i = 0 ; i < n ; i++){
            max_ending_here += a[i];
            //this max_ending_here is the max sum end from a[0] to a[i]
            max_so_far = max(max_ending_here,max_so_far);
            if(max_ending_here < a[i]) max_ending_here = a[i];
        } 
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
     
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends