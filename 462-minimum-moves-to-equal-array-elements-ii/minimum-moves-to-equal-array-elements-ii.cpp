class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long tot=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++ ) tot+=abs(nums[0]-nums[i]);
        long long ans=tot;
        for(int i=1;i<n;i++){

            long long temp=ans;
            int m=nums[i]-nums[i-1];
            temp-=m;
            temp+=(m*(i));
            temp-=(m*(n-i-1));
            ans=min(ans,temp);
        }

        return ans;
    }
};