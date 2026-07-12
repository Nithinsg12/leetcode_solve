class Solution {
public:

    bool possible(vector<int>&bloomDay,int day,int k,int m){
        int count = 0, noOfm = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                 count++;
            }
            else{
                noOfm += count/k;
                count =0;
            }
        }
        noOfm += count/k;
        return noOfm >=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini =  INT_MAX;
        int maxi = INT_MIN;

        long long val = 1LL*k*m;
        if(val > bloomDay.size()) return -1;
        for(int i=0; i< bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int start = mini, end = maxi;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(possible(bloomDay,mid,k,m)){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};