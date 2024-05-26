//
// 1095. 山脉数组中查找目标值
// Created by Jonah Shi on 5/27/24.
//

#include <stdio.h>

typedef struct {
    int* array;
    int size;
} MountainArray;

int get(MountainArray *mountainArr, int index) {
    return mountainArr->array[index];
}

int length(MountainArray *mountainArr) {
    return mountainArr->size;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int left = 0, right = length(mountainArr) - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int peak = left;
    left = 0, right = peak;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int num = get(mountainArr, mid);
        if (num == target) {
            return mid;
        } else if (num < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    left = peak, right = length(mountainArr) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int num = get(mountainArr, mid);
        if (num == target) {
            return mid;
        } else if (num < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    MountainArray mountainArr;
    int arr[] = {1, 2, 3, 4, 5, 3, 1};
    mountainArr.array = arr;
    mountainArr.size = 7;
    int target = 3;
    int res = findInMountainArray(target, &mountainArr);
    if (res == 2) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}