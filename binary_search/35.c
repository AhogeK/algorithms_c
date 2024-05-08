//
// https://leetcode.cn/problems/search-insert-position
// Created by Jonah Shi on 5/8/24.
//

#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
    int left  = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int result = searchInsert(nums, 4, target);
    if (result == 2) {
        printf("The algorithm is correct\n");
    } else {
        printf("The algorithm is wrong\n");
    }
    return 0;
}