#include<bits/stdc++.h>
using namespace std;

bool isTrue(int *a,int n, int c,int mid){
    int count = 1;
    int pivot = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] - a[pivot] >= mid) {
            count++;
            pivot = i;
        }
        if(count == c) return true;
    }
    return false;
}

int findDistance(int *a,int n, int c){
    int res = 0;
    int low = 1;
    int high = (a[n-1] - a[0]) /(c-1);
    //the result will be between low and high, if res = mid so we continue find res between mid=1 and high,
    // else res != mid we find res between mid-1 and low
    while(low <= high){
        int mid = (high + low) /2;
        if(isTrue(a,n,c,mid)){
            low = mid+1;
            res = mid;
        }
        else{
            high = mid - 1;
        }
    } 
    return res;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        int a[n];
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        cout << findDistance(a,n,c) << endl;
    }
}