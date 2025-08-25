class Solution {
    bool canShip(vector<int>& weights, int days,int capacity){
        int dayNeeded = 1;
        int currentWeight = 0;
        for(int weight:weights){
            currentWeight += weight;
            if(currentWeight>capacity){
                dayNeeded++;
                currentWeight = weight ; 
            }

        }
        return dayNeeded  <=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=-1;
        int n = weights.size();
        long long totalWeight = 0;
        int maxWeight = 0;
        for(int weight:weights){
            totalWeight += weight;
            maxWeight = max(maxWeight , weight);
        }

        int st = maxWeight ;
        int end = totalWeight;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(canShip(weights , days,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};