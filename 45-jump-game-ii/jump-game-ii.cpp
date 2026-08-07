class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dis =0 , curr= 0 , ans=0;
        for(int i=0;i<n-1;i++){
            dis=max(dis, i+nums[i]);
            if(i== curr){
                curr= dis;
                ans++;
            }

        }
        return ans;

    }
};