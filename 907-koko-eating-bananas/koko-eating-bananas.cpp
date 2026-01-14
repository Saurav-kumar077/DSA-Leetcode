class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<high){
            int mid = low+(high-low)/2;
            long long hour = 0;
            for(int p:piles){
                if(p % mid ==0){
                    hour += p/mid;
                }else{
                    hour += (p/mid)+1;
                }
            }
            if(hour<= h ){
                    high=mid;
                }
                else{
                    low = mid+1;
                }
        }
        return low;

    }
};