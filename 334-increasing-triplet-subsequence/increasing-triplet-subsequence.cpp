class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX, c=INT_MAX , n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>b) return 1;

            if(nums[i]<=a) a=nums[i];

            else if(nums[i]<=b) b=nums[i];

        }
        return 0;
    }
};