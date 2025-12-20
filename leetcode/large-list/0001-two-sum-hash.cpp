#include <iostream>
#include <vector>

#define TABLE_SIZE 1024

class Node {
public:
    int number;
    int index;
    Node* next;
};


class Solution {
public:
    
    Solution() {
        std::vector<int> nums = {0,4,3,0};
        std::vector<int> t = twoSum(nums, 0);

        for (int v: t){
            std::cout<<v<<'\n';
        }
    }

    int hash_func(int num){ return abs(num%TABLE_SIZE); }

    void add(Node** table, int num, int index){
        int hash_index = hash_func(num);
        table[hash_index]=new Node{num,index,table[hash_index]};
    }

    int get_index_of_value(Node** table, int value){
        Node* start = table[hash_func(value)];
        while(start){
            if(start->number==value){ return start->index; }
            start=start->next;
        }
        return -1;
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        Node* table[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;++i){ table[i]=nullptr; }


        for(int i=0;i<nums.size();++i){
            int other_index = get_index_of_value(table, target-nums[i]);
            if(other_index!=-1 && other_index != i){
                return {i, other_index};
            }
            // Only add if it is not a solution. 
            // Maybe it is a pair to another future value.
            add(table, nums[i], i);
            // we could add it at the start, but my implementation of add will
            // add the node to the start of the linked list, and the get_index_of_value
            // will return the index of the first occurence of the value.
        }
        return {-1,-1};
    }
};

int main() { Solution(); }




