class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i: nums) s.insert(i);
        int mul=1;
        while(1){
            if(s.find(mul*k)==s.end()) return mul*k;
            mul++;
        }
        return 0;
    }
};