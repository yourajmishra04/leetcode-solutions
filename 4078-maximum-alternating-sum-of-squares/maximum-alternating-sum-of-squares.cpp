class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(abs(nums[i]));
        }
        sort(v.rbegin(),v.rend());
        long long ans=0;
        int k=(n+1)/2;
        for(int i=0;i<k;i++){
            long long l=v[i]*v[i];
            ans+=l;
        }
        for(int i=k;i<n;i++){
            long long l=v[i]*v[i];
            ans-=l;
        }
        return ans;
    }
};