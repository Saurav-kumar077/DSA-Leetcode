class Solution {
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k,int days){
        int bouquetsMade = 0;
        int adjecentFlowers = 0;
        for(int day :bloomDay){
            if(day<=days){
                adjecentFlowers++;
            }
            else{
                adjecentFlowers = 0;
            }
            if(adjecentFlowers == k){
                bouquetsMade++;
                adjecentFlowers =0;
            }
        }
        return bouquetsMade>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long )m*k>n){
            return -1;
        }
        int st = *std::min_element(bloomDay.begin(),bloomDay.end());
        int end = *std:: max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(canMakeBouquets(bloomDay , m ,k,mid)){
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