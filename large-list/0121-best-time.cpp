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


// in C:
//#include <stdlib.h>
//int maxProfit(int* prices, int pricesSize) {
//    // Only move the left ptr if you lose money on the next day
//    int current = 0;
//    int next = 1;
//    int max_profit = 0;
//    while(next < pricesSize){
//        int curr_profit = prices[next]-prices[current];
//        if(curr_profit < 0){
//            ++current;
//            next = current+1;
//        }else{
//            if(max_profit < curr_profit){
//                max_profit = curr_profit;
//            }
//            ++next;
//        }
//    }
//    return max_profit;
//}
