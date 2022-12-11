//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void printarr(int *a,int n){
        for(int i=0; i < n ; i++ ){
            cout << a[i] << " "; 
        }
        cout << endl;
}
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
        //the idea is put all smaller in arr1 and the bigger in arr2 without oder and then sorting them 
	    int i = 0;
	    int j = 0;
        int count  = 0;
        int k = n-1;
        while(i <= k && j < m  ){
            if(arr1[i] > arr2[j]) {      //if arr[i] > arr[j] then the last elemnt of arr1 still bigger than arr2[j]
                swap(arr1[k],arr2[j]);   //then swap them
                j++;                     //increase j and decrease k to skip the swapped elements
                k--;
            }
            else{
                i++;                     //if arr1[i] <= arr2[j] then arr1[i] <= arr2[j+1] so we increase i by one            
            }        
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m); 
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends