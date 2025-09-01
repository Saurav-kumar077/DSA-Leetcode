class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>anagramGroups;
        for(const string &s :strs){
            string key = s;
            sort(key.begin(),key.end());

            anagramGroups[key].push_back(s);
        }
        vector<vector<string>>result;
        for(auto const &[key,val]:anagramGroups){
            result.push_back(val);
        }
        return result;

    }
};