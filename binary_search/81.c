//
// 81. 搜索旋转数组 II
// Created by Jonah Shi on 5/26/24.
//
#include <stdio.h>

bool search(int *nums, int numsSize, int target) {
    int left  = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
            left++;
            right--;
        } else if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    int numsSize = 7;
    bool res = search(nums, numsSize, target);
    if (res) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}