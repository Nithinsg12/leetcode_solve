class Solution {
public:

    int sumOfDivisor(vector<int> &nums,int div){
        int sum =0;
        for(int i=0; i<nums.size();i++){
            sum += ceil((double)nums[i]/(double)div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1, end=*max_element(nums.begin(),nums.end());

        while(start <= end){
            int mid = start + (end- start)/2;
            if(sumOfDivisor(nums,mid) <= threshold){
                end = mid-1;
            } else{
                start=mid+1;
            }
        }
        return start;
    }
};