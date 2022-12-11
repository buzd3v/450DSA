#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> map;
        vector<int> vect;
        int n = nums.size();
        float times = n/3.0;
        for(int i = 0 ; i < n ; i++){
            if(map.find(nums[i]) != map.end()){
                map.find(nums[i])->second += 1;
            }
            else{
                map.insert(pair<int,int>(nums[i],1));
            }
        }
        for(std::pair<int,int> s : map){
            if(s.second > times) vect.push_back(s.first);
        }    
        return vect;   
    }
};