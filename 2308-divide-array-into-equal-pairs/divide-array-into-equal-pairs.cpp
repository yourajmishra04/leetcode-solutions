class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        for(int x : nums) mp[x]++;

        for(auto it : mp) if(it.second % 2==1) return 0;

        return 1;
    }
};