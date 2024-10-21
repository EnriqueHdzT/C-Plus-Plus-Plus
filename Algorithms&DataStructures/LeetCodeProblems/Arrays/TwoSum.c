/*
**  LeetCode Problem 1 - Two Sum
**  https://leetcode.com/problems/two-sum
**  
*/

#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}