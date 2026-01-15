class Solution {
    bool possible(vector<int>& position , int n , int m, int guess ){
        int ball = 1;
        int pos = position[0];

        for(int i =1;i<n;i++){
            int MF = position[i]-pos;
            if(MF <guess){
                continue;
            }else{
                ball++;
                pos = position[i];
            }
        }
        if(ball>=m){
            return true;
        }else{
            return false;
        }
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1]-position[0];
        int ans = -1;
        while(low<=high){
            int guess = low+(high-low)/2;
            if(possible(position , n , m , guess)){
                ans = guess;
                low= guess+1;
            }else{
                high = guess-1;
            }
        }
        return ans;
    }
};