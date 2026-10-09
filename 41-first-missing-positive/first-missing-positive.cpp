class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st;
        for(int x : nums)st.insert(x);
        int ans=1;
        while(st.find(ans)!=st.end()) ans++;
        return ans;
    }
};