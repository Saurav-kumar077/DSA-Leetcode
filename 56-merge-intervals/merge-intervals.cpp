class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int st1 = intervals[0][0];
        int end1 = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int st2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end1>=st2){//overlapping
                st1 = st1;
                end1 = max(end1,end2);
                continue;
            }
            result.push_back({st1,end1});
            st1 = st2;
            end1=end2;
        }
        result.push_back({st1,end1});
        return result;
    }
};