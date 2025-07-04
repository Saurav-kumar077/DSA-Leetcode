class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        for(int i=0;i<arr.size();i++){
            count[arr[i]]++;
        }
        unordered_set<int>freqset;
        for(auto pair :count){
            if(freqset.count(pair.second)){
                return false;
            }
            freqset.insert(pair.second);
        }
        return true;
    }
};