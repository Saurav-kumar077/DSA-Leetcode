class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>result(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int prevIdx = st.top();
                st.pop();
                result[prevIdx] = i- prevIdx;
            }
            st.push(i);
        }
        return result;
    }
};