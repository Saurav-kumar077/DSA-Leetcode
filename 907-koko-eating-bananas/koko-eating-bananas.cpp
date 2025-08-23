class Solution {
    int maxElement(vector<int>&piles){
        int maxi = INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calculateTotalHours(vector<int>& piles, int hourlyRate){
        long long totalH = 0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalH += (long long)(piles[i] + hourlyRate - 1) / hourlyRate;
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int st=1;
        int end=maxElement(piles);
        int ans=end;
        while(st<=end){
            int mid = st+(end-st)/2;
            long long totalHours = calculateTotalHours(piles ,mid);
            if(totalHours<=h){
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