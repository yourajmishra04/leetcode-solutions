class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
          vector<int>pos,neg;
          for(int x : nums) {
            if(x<0) neg.push_back(x);
            else pos.push_back(x);
          }
          vector<int>ans;
          int n=pos.size(),i=0;
          while(i<n){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
          }
          return ans;
    }
};