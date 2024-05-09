#include <iostream>
#include <vector>

class Solution {
public:
    Solution(){
        std::vector<int> prices{7,1,5,3,6,10};
        std::cout<<"Max profit of: "<<std::endl;
        for (int p: prices){
            std::cout<<p<<' ';
        }
        std::cout<<" is: \n"<<maxProfit(prices);
    }
    int maxProfit(std::vector<int>& prices) {

        int overall{};
        int start{};
        for (int i{}; i < prices.size()-1;i++){
            if (prices[i+1]<prices[i]){
                if (prices[i]-prices[start]>overall){
                    overall = prices[i]-prices[start];
                }
                if (prices[i+1]<prices[start]){
                    start = i+1;
                }
            }
        }
        return (prices.back()-prices[start] > overall ? prices.back()-prices[start] : overall);
    }
};


int main(){
    Solution();
    return 0;
}
