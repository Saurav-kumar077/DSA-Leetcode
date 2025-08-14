class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
            return;
        }
        k=k%n;
        if(k==0){
            return;
        }
        int s=0;
        int e = n-1;
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
        s=0;
        e=k-1;
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
        s=k;
        e=n-1;
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
};