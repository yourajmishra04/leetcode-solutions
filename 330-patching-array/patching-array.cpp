class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        priority_queue<int , vector<int> , greater<int>>st;
        for(int x : nums) st.push(x);

       long long k=0;
        int ans=0;

        while(k<n){

            while(!st.empty() && st.top() <= k+1) {
                k+=st.top();
                st.pop();

            }

            if(k<n){
                ans++;
                k+=k+1;
            }



        }
        return ans;


    }
};