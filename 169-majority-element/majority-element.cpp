class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto x : freq){
            if(x.second > nums.size()/2){
                return x.first;
            }
        }
        return -1;
        
    }
};