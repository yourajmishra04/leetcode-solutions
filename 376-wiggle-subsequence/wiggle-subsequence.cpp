class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
       vector<int>v;
       v.push_back(nums[0]);
       for(int i=1;i<n;i++){
        if(nums[i]!=v.back()) v.push_back(nums[i]);
       }
       n=v.size();
       if(n==1) return 1;

         vector<int>ans;
         for(int i=1;i<n;i++){
            if(v[i]>v[i-1]) ans.push_back(1);
            else ans.push_back(-1);
         }

         int fans=2;
         n=ans.size();
         for(int i=1;i<n;i++){
             if(ans[i]!=ans[i-1]) fans++;
         }

        return fans;
    }
};