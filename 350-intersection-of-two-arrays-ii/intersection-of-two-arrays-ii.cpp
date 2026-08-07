class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        
        int n=nums1.size(), m=nums2.size();
        while(i<n && j<m){

            while(j<m && nums2[j] < nums1[i]) j++;
            if(j<m && nums2[j]==nums1[i]){
                ans.push_back(nums1[i]);
                j++;
            }
            i++;
        }
        return ans;
    }
};