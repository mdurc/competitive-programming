class Solution {
public:
    template <int F>
    void reduceFactor(int& n){
        while(n%F==0){ n/=F; }
    }
    bool isUgly(int n){
        if(n<=0)return 0;
        reduceFactor<2>(n);
        reduceFactor<3>(n);
        reduceFactor<5>(n);
        return n==1;
    }
};
