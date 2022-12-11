//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int left = 0;
        int right = n-1;
        int i = 0;
        int j = n-1;
        while(left<= n-1){
            if(a[left] == 0){
                swap(a[left],a[i]);
                i++;
            }
            left++;
        }
        while(right >= 0){
            if(a[right] == 2){
                swap(a[right],a[j]);
                j--;
            }
            right--;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
