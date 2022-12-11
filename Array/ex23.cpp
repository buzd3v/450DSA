//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        set<int> a;
        for (int i = 0; i < N; i++)
        {
            a.insert(arr[i]);
        }
        
        int count = 0 ;
        int max = 0;
        vector<int> vect;
        for(set<int>::iterator it = a.begin(); it!= a.end(); it++){
            vect.push_back(*it);
        }
        for(int i = 0;i < vect.size(); i++ ){
            if(i>0 && (vect[i] - vect[i-1] == 1)){
                count++;
            }
            else {
                count = 1;
            }
            max = std::max(max,count);
        }
        return max;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends