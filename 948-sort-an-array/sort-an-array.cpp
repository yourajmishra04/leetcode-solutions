class Solution {
public:
    vector<int> solve(vector<int>& nums, int i, int j) {

        if (i == j)
            return  {nums[i]}; 
        int mid = (i + j) / 2;

        vector<int> lft = solve(nums, i, mid);
        vector<int> rght = solve(nums, mid + 1, j);

        vector<int> ans;
        int l = lft.size(), r = rght.size();
        int ll = 0, rr = 0;
        while (ll < l && rr < r) {
            if (lft[ll] < rght[rr]) {
                ans.push_back(lft[ll]);
                ll++;
            } else {
                ans.push_back(rght[rr]);
                rr++;
            }
        }

        while (ll < l) {
            ans.push_back(lft[ll]);
            ll++;
        }
        while (rr < r) {
            ans.push_back(rght[rr]);
            rr++;
        }
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};