class Solution {
public:
    int maxProduct(int n) {
        int ans=1;
        priority_queue<int>pq;
        while(n>0){
          pq.push(n%10);
          n/=10;
        }
        ans*=pq.top();
        pq.pop();
        ans*=pq.top();
        return ans;
    }
};