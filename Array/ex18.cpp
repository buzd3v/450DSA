//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> t;
            set<int> s1,s2,s3;
            int flag1 = 0; int flag2 = 0;
            for(int i = 0; i < n1; i++){
                s1.insert(A[i]);
            }
            for(int i = 0; i < n2; i++){
                s2.insert(B[i]);
            }
            for(int i = 0; i < n3; i++){
                s3.insert(C[i]);
            }
            for(int n : s1){
                if(s2.find(n)!=s2.end() && s3.find(n)!=s3.end())
                t.push_back(n);
            }
            return t;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends