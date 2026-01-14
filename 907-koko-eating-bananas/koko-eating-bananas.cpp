class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        while(low<high){
            int mid = low+(high-low)/2;
            long long hour = 0;
            for(int i = 0;i<piles.size();i++){
                if(piles[i]% mid ==0){
                    hour += piles[i]/mid;
                }else{
                    hour += (piles[i]/mid)+1;
                }
            }
            if(hour <= h){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};