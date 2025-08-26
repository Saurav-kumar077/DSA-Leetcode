class Solution {
    private:
    vector<int>mergerArray(vector<int>& nums1, vector<int>& nums2){
        int m=nums1.size();
        int n= nums2.size();
        
        vector<int>merged(m+n);
        int p1 = 0;
        int p2 = 0;
        int i =0;
        while(p1<m && p2<n){
            if(nums1[p1]<nums2[p2]){
                merged[i] = nums1[p1];
                p1++;
            }
            else{
                merged[i]=nums2[p2];
                p2++;
            }
            i++;
        }
        while(p1<m){
            merged[i]=nums1[p1];
            p1++;
            i++;
        }
        while(p2<n){
            merged[i]=nums2[p2];
            p2++;
            i++;
        }
        return merged;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged = mergerArray(nums1,nums2);
        int totalsize=merged.size();

        if(totalsize==0){
            return 0.0;
        }
        if(totalsize %2 ==1){
            //odd number of elements present in the given array
            return static_cast<double>(merged[totalsize/2]);
        }
        else{
            //even number of elements present in the array
            int mid1=merged[totalsize/2-1];
            int mid2 = merged[totalsize/2];
            return (static_cast<double>(mid1)+static_cast<double>(mid2))/2.0;
        }
    }
};