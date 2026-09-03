class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e=0, o=0;

        for(int x : nums1) {
            if(x%2==0) e++;
            else o++;
        }
           if(e==0 || o==0) return 1;
        sort(nums1.begin() , nums1.end());

        if(nums1[0]%2==1) return 1;
        return 0;

    }
};