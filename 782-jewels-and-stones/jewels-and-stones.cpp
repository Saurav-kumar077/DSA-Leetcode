class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>jewelsets;
        for(char ch:jewels){
            jewelsets.insert(ch);
        }
        int count;
        for(char ch:stones){
            if(jewelsets.count(ch)){
                count++;
            }
        }
        return count;
        
    }
};