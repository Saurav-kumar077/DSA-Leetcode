class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;//min heap
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(auto &it:freq){
            pq.push({it.first,it.second});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};