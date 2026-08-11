class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st;
        for (auto x : nums)
            st.insert(x);
        int n = nums.size();
        int i = 0;
        int j=1, ans = 0;
        int range = 0;
      
            while (j < n && nums[j] == nums[j - 1] + 1)
                j++;

           int sum=0;
           for(int k=i;k<j;k++) sum+=nums[k];
           while(st.find(sum)!=st.end())sum++;
      
        return sum;
    }
};