class Solution {
    vector<vector<int>>InsertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>>res;
        bool inserted = false;
        for(int i=0;i<intervals.size();i++){
            if(inserted==false && newInterval[0]<=intervals[i][0]){
                res.push_back(newInterval);
                inserted=true;
            }
            res.push_back(intervals[i]);
        }
        if(inserted==false){
            res.push_back(newInterval);
        }
        return res;
    }
    vector<vector<int>>Merge(vector<vector<int>>& intervals){
        vector<vector<int>>result;
        int st1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int st2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1>=st2){//overlapping condition
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

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>withNewInterval = InsertInterval(intervals , newInterval);
        return Merge(withNewInterval);
    }
};