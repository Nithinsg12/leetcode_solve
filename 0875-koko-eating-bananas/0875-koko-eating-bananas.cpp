class Solution {
public:
    int findmax(vector<int> piles){
        int maxiMum= INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxiMum = max(maxiMum,piles[i]);
        }
        return maxiMum;
    }

    long long totalHours(vector <int> piles,int hourly){
        long long totalhours = 0;
        for(int i=0; i< piles.size(); i++){
            totalhours += (piles[i] + hourly -1)/hourly;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int start=1, end=findmax(piles);

        while(start <= end){
            int mid= start+(end-start)/2;
            long long hoursToGet = totalHours(piles,mid);
            if(hoursToGet <= k) end= mid-1;
            else start=mid+1;
        }
        return start;
    }
};