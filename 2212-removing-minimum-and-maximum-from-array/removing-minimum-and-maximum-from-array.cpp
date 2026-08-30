class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<vector<int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++) v.push_back({nums[i] , i});
        sort(v.begin(),v.end());
        int mn=v[0][1], mx = v[n-1][1];
        int x=min(mn,mx), y= max(mn,mx);
        int ans= x+1 + n-y;

        ans=min(ans, y+1);
        ans=min(ans, n-x);
        return ans;

    }
};