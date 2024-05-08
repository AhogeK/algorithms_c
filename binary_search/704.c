//
// Created by Jonah Shi on 4/25/24.
//

#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    int left = 0;
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
    return -1;
}

// 递归的方式完成
int search2(int* nums, int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return search2(nums, mid + 1, right, target);
    } else {
        return search2(nums, left, mid - 1, target);
    }
}

// 排除法写二分 while(left < right) 结果后处理
int search3(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (nums[left] == target) {
        return left;
    }
    return -1;
}


int main(void) {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = search(nums, numsSize, target);
    if (result != 4) {
        printf("The algorithm is wrong\n");
        exit(1);
    }
    // test search3
    result = search3(nums, numsSize, target);
    if (result != 4) {
        printf("The algorithm is wrong\n");
        exit(1);
    }
    printf("The algorithm is correct\n");
    return 0;
}