class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(auto&entry:freq){
            minHeap.push({entry.second,entry.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

            vector<int>result(k);
            for(int i=k-1;i>=0;i--){
                result[i]=minHeap.top().second;
                minHeap.pop();
            }
        
        return result;  
    }
};