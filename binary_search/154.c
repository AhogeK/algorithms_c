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
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    return nums[left];
}

int main() {
    int nums[] = {2, 2, 2, 0, 1};
    int numsSize = 5;
    int res = findMin(nums, numsSize);
    if (res == 0) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}