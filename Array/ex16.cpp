#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_so_far = 0;
        int max_ending_here = 0;
        int minprice = prices[0];
        for(int price : prices){
            //finding the minimum price till the day i;
            if(minprice >= price) minprice = price;
            //find max profit till the day i
            max_ending_here = price - minprice;
            //update maxprice a.k.a max_so_far 
            max_so_far = max(max_ending_here,max_so_far);
        }
        return max_so_far;
    }
};