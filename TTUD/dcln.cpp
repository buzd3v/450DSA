#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int>& a, int n){
        
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
int main()
{
    vector<int> a  = {-2,11,-4, 13,-5, 2};
    int n = 6;
    cout << maxSubarraySum(a,n);
}