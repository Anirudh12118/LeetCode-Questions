class Solution {
public:
    void reverse(vector<int>&nums,int st,int end){
        while(st<=end){
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()-1) k=k%nums.size();
        if(k==0)    return;
        //First reverse the while Array
        reverse(nums,0,nums.size()-1);
        //Reverse the first k element
        reverse(nums,0,k-1);
        //Reverse the remaining element
        reverse(nums,k,nums.size()-1);
    }
};