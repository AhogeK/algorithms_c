//
// 4. 寻找两个正序数组的中位数
// Created by Jonah Shi on 5/27/24.
//

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int m = nums1Size;
    int n = nums2Size;
    int left = 0;
    int right = m;
    int halfLen = (m + n + 1) / 2;
    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = halfLen - i;
        if (i < m && nums2[j - 1] > nums1[i]) {
            left = i + 1;
        } else if (i > 0 && nums1[i - 1] > nums2[j]) {
            right = i - 1;
        } else {
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                maxLeft = nums1[i - 1];
            } else {
                maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
            }
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }

            int minRight = 0;
            if (i == m) {
                minRight = nums2[j];
            } else if (j == n) {
                minRight = nums1[i];
            } else {
                minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            }
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}

int main() {
    int nums1[] = {1, 3, 5, 7, 9, 11};
    int nums1Size = 6;
    int nums2[] = {2, 4, 6, 8, 10};
    int nums2Size = 5;
    double res = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    if (res == 6.0) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
    return 0;
}