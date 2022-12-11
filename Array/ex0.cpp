#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void reverseArray(int *a,int n){
    int l = 0;
    int r = n - 1;
    while(l < r){
        swap(a[l],a[r]);
        l++;
        r--;
        
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
	//code
	int t,n;
     
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin >> a[i]; //inputting elements of array
            
        reverseArray(a,n);
    }
	return 0;
}