class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st,end;
        st=0;
        end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target)   return mid;

            if(nums[st]<=nums[mid]){
                //Means Left half is Sorted
                if(nums[st]<=target && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else{
                //Means Right Half is Sorted
                if(nums[mid]<=target && target<=nums[end]){
                    st=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};