class Solution {
public:

    int findDays(vector<int> &weights,int cap){
        int day = 0, load = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i] + load > cap){
                day +=1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end= accumulate(weights.begin(),weights.end(),0);
        while(start <= end){
            int mid = start + (end-start)/2;

            int numOfdays = findDays(weights,mid);
            if(numOfdays >= days){
                start = mid+1;
            }else{
                end=mid -1 ;
            }
        }
        return start;
    }
};