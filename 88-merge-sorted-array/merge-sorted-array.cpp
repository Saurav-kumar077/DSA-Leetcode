class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int write_idx = m+n-1;
        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[write_idx]=nums1[p1];
                p1--;
            }
            else{
                nums1[write_idx]=nums2[p2];
                p2--;
            }
            write_idx--;
        }
        while(p2>=0){
            nums1[write_idx]=nums2[p2];
            p2--;
            write_idx--;
        }
    }
};