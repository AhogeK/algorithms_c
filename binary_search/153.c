//
// Created by Jonah Shi on 5/22/24.
//

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

int main() {
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = 5;
    int res = findMin(nums, numsSize);
    if (res == 1) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}