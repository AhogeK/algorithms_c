//
// 852. 山脉数组的峰顶索引
// Created by Jonah Shi on 5/27/24.
//

#include <stdio.h>

int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 0, right = arrSize - 2;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int arr[] = {0, 1, 0};
    int arrSize = 3;
    int res = peakIndexInMountainArray(arr, arrSize);
    if (res == 1) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}
