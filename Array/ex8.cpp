//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>


using namespace std;

// } Driver Code Ends
// User function template for C++
//Cause there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K), 
//the first one is on the left of the current point (A[i] + K is the last element of the first segment), 
//the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment). 
//For the first segment, the smallest element is left, the largest is A[i] + K; 
//For the second segment, A[i + 1] - K is the smallest element, the largest is right. 
//Thus, for each point, the largest element should be either A[i] + K or right, 
//the smallest element should be either left or A[i + 1] - K.
//check if mini < 0 continue because the height of tower can not a negative number 
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int res = arr[n-1] - arr[0];
        int left = arr[0] + k;
        int right = arr[n-1] - k;
        for(int i = 0 ; i< n ;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if(j<=i) cout << arr[j]+k << " ";
                else cout<< arr[j] - k << " "; 
            }
            cout <<endl;
            int mini = min(left,arr[i+1]-k);
            int maxi = max(arr[i]+k,right);
            if(mini < 0 ) continue;
            res = min(res, maxi-mini);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends