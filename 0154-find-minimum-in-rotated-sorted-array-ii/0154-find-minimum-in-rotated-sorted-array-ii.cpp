class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0, end=arr.size()-1, ans=INT_MAX;
        
        while(start <= end){
            int mid = start +(end-start)/2;

            if(arr[start] ==arr[mid] && arr[mid]==arr[end]){
                if(arr[mid] < ans){
                    ans=arr[mid];
                }
                start++;
                end--;
                continue;
            }
            if(arr[start] < arr[end]){
                if(arr[start] < ans){
                    ans = arr[start];
                }break;  
            }
            if(arr[start] <= arr[mid]){
                if(arr[start] < ans){
                    ans=arr[start];
                }
                start= mid+1;
            }else{
                end=mid-1;
                if(arr[mid] < ans){
                    ans=arr[mid];
                }
            }
        }return ans;
    }
};