class ProductOfNumbers {
public:
stack<int>st;
vector<long long>v;
int z=-1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push(num);
        int n=v.size();
        if(num==0) z=n;
        if(n==0) v.push_back(num);
        else {
            if(v[n-1]==0) v.push_back(num);
            
           else v.push_back(num*v[n-1]);}
    }
    
    int getProduct(int k) {
        int n=v.size();
        long long ans=v[n-1];
        int idx=n-k-1;
        if(idx>= 0 && v[idx]>0) ans/=v[idx];
        if(idx < z) return 0;
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */