//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to reverse every sub-array group of size k.

    void reverse(vector<long long> &a, int start, int end)
    {
        while (start <= end)
        {
            swap(a[start], a[end]);
            start++;
            end--;
        }
    }
    void reverseInGroups(vector<long long> &a, int n, int k)
    {
        // code here
        int offset = k;
        int i = 0;
        while (k <= n)
        {
            reverse(a, i, k - 1);
            i = k;
            k = i + offset;
        }
        reverse(a, i, n - 1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}