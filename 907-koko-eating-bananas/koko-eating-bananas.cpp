class Solution {
    long long hoursNeeded(vector<int>&piles, int speed){
        long long hour = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            hour += + piles[i]/speed;
            if(piles[i]%speed !=0){
                hour++;
            }
        }
        return hour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = -1;

        while(low<=high){
            int mid = low+(high-low)/2;
            long long totalHours = hoursNeeded(piles , mid);

            if(totalHours <= h ){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};