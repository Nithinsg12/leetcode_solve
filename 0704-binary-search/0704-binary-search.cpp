class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);
    }

    int search(vector<int>& nums, int target, int start, int end){

        if(start <= end){
            int mid = start + (end - start)/2;

            if(target > nums[mid])
                return search(nums,target,mid+1,end);
            else if(target < nums[mid])
                return search(nums,target,start,mid-1);
            else
                return mid;
        }
        return -1;
    }
};