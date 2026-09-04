class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>st;
        int n=nums.size();
        for(int i=k;i>0;i--) st.insert(i);
          for(int i=n-1;i>=0;i--){
              if(st.find(nums[i])!= st.end()) st.erase(nums[i]);

              if(st.empty()) return n-i;
          }
          return n
          ;
         
    }
};