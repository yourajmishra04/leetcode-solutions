class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        int mx=-1;
        for(int x:nums){
            mx=max(mx,x);
            mp[x]++;
        }
        if(k==n) return mx;
        if(k==1  ) {
            vector<int> temp=nums;
            sort(temp.rbegin(),temp.rend());
            for(int i=0;i<n;i++){
                if(mp[temp[i]]==1) return temp[i];
               
            }
             return -1;
        }
        
         mx=max(nums[0] , nums[n-1]);
        if(mp[mx]==1) return mx;
        mx= min(nums[0] , nums[n-1]);
        if(mp[mx]==1) return mx;
        return -1;

    }
};