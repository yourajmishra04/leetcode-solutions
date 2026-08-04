class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        for(int x : nums) st.insert(x);
        int mi=nums[0], ma=nums[n-1];
        while(mi<ma){
            mi++;
            if(st.find(mi)==st.end()) ans.push_back(mi);
        }
        return ans;
    }
};