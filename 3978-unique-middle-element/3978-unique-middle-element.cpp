class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid=nums[(nums.size()-1)/2];
        int count=0;
        for(int val:nums){
            if(val==mid)    count++; 
        }
        if(count>1) return false;
        return true;
    }
};