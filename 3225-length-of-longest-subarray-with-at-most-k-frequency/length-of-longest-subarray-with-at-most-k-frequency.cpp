class Solution {
public:
   

    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int i = 0, ans = 0, j = 0;

        while ( j<n) {
          mp[nums[j]]++;
           
            while (mp[nums[j]]>k) {
                mp[nums[i]]--;
                i++;
            }
            j++;
            ans=max(ans,j-i);

        }
        return ans;
    }
};