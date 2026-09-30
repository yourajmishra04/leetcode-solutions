class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> st;
        int n = seq.size();
        vector<int>ans(n);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                st.push(i);
                continue;
            }
            else{
                int k=st.size();
                int t=0;
                if(k%2 == 0) t=1;
                ans[i]=t;
                ans[st.top()]=t;
                st.pop();
            }
        }
        return ans;
    }
};