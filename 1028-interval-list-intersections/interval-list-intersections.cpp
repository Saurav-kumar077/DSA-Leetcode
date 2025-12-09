class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>result;
        int i = 0;
        int j=0;
        while(i<firstList.size() && j<secondList.size()){
            int st1 = firstList[i][0];
            int end1 = firstList[i][1];
            
            int st2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(st1<=st2){
                if(end1>=st2){
                    int s = max(st1,st2);
                    int e = min(end1,end2);
                    result.push_back({s,e});
                }
            }else{
                if(end2>=st1){
                    int s = max(st1,st2);
                    int e = min(end1 , end2);
                    result.push_back({s,e});
                }
            }
            if(end1>=end2){
                j++;
            }else{
                i++;
            }
        }
        return result;
    }
};