class Solution {
    vector<int>nextSmallerElement(vector<int>& arr){
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            else{
                ans[i]=n;
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>& arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            else{
                ans[i]=-1;
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0){
            return 0;
        }
        vector<int>next = nextSmallerElement(heights);
        vector<int>prev = prevSmallerElement(heights);

        int max_area = INT_MIN;
        for(int i=0;i<n;i++){
            int h = heights[i];
            int w = next[i]-prev[i]-1;

            int current_area = h*w;
            max_area = max(max_area , current_area);
        }
        return max_area;
    }
};