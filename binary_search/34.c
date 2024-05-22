//
// Created by Jonah Shi on 5/22/24.
//

#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            int l = mid;
            int r = mid;
            while (l >= 0 && nums[l] == target) {
                l--;
            }
            while (r < numsSize && nums[r] == target) {
                r++;
            }
            result[0] = l + 1;
            result[1] = r - 1;
            return result;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    int* result = searchRange(nums, 6, target, &returnSize);
    if (result[0] == 3 && result[1] == 4) {
        printf("The algorithm is correct\n");
    } else {
        printf("The algorithm is wrong\n");
    }

    free(result);
    return 0;
}