//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int a[], int n , int x )
{
    // code here

    int left = 0;
    int right = n-1;
    int res = -1;
    vector<int> result(2,-1);
    while(left <= right){
        int mid = left + (right - left) /2;
        if(a[mid] == x ) res = mid;
        if(a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid -1 ;
        }
    }
    if (res == -1) return result;
    else {
        int l = res,r = res;
        while(1){
            if(a[l-1] == x) l--;
            if(a[r+1] == x) r++;
            if((a[l-1] != x || l-1 == -1) && (a[r+1]!=x || r+1 == n)) break; 
        }
        result[0] = l;
        result[1] = r;
        return result;
    }
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
       
    }
    return 0;
}



// } Driver Code Ends