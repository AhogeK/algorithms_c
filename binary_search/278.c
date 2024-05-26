//
// Created by Jonah Shi on 5/27/24.
//

#include <stdio.h>

int BAD_VERSION = 4;
int N = 5;

bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int res = firstBadVersion(N);
    if (res == BAD_VERSION) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}