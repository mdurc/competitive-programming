 // returned array must be malloced, assume caller frees the memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct node{
	int key;
	int val;
	struct node* next;
};

int hash(int a){
	return abs(a % MAX);
}

int find(struct node* v[], int h){
	struct node* p = v[hash(h)];
	while(p){
		if(p->key == h) return p->val;
		p = p->next;
	}
	return -1;
}

void insert(struct node* v[], int h, int a){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = h;
    new_node->val = a;
    new_node->next = v[hash(h)]; // insert it at the front of linked list
    v[hash(h)] = new_node;
}

int* twoSum(int* nums, int size, int target, int* ret_size){
	int* ret = (int*)malloc(2 * sizeof(int));
	ret[0] = -1;
	ret[1] = -1;
    *ret_size = 2;

    struct node* vals[MAX] = { NULL };

    int i;
	for(i = 0; i < size ; ++i){
		int r = find(vals, target-nums[i]);
		if(r!=-1 && r!=i){
			ret[0] = i;
			ret[1] = r;
            break;
		}
        insert(vals, nums[i], i);
	}
    for(i = 0; i < MAX ; ++i){
        struct node* t = vals[i];
        while(t){
            struct node* temp = t;
            t = t->next;
            free(temp);
        }
    }
	return ret;
}


int main(){
    // [2,7,11,15]
    // size = 4
    // target: 9
    int target = 9;
    int size = 4;
    int* nums = (int*) malloc(size * sizeof(int));
    nums[0] = 2;
    nums[1] = 2;
    nums[2] = 7;
    nums[3] = 15;

    int rsize = 0;
    int* result = twoSum(nums, size, target, &rsize);
    for(int i=0;i<rsize;++i){
        printf("Index %d: %d\n", i, result[i]);
        printf("Value at index: %d\n", nums[result[i]]);
    }
    free(nums);
    free(result);
}
