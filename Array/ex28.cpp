//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
    long long trappingWater(int a[], int n){
        // code here
        int maxLeft = a[0];
        int maxRight = a[n-1];
        int Min;
        int res = 0;
        int i = 0;
        int j = n-1;
        //the idea is find the maxLeft and maxRight of an element
        // if maxLeft < maxRight then the maxLeft is smaller than any maxRight
        // and we want min of maxLeft anf maxRight so ...
        while(i <= j ){
            Min = min(maxLeft,maxRight);
            if(maxLeft <= maxRight){
                res += (a[i] < Min ? Min - a[i] : 0);
                maxLeft = max(a[i],maxLeft);
                i++;
            }
            else{
                res += (a[j] < Min ? Min - a[j] : 0);
                maxRight = max(a[j],maxRight);
                j--;
            }

        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends