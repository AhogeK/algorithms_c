//
// Created by Jonah Shi on 5/8/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pick;

// 初始化猜数字游戏
void initGame() {
    srand(time(NULL)); // 设置随机数种子
    pick = rand() % 100 + 1; // 生成一个1-100的随机数
}

int guess(int num) {
    if (num == pick) {
        return 0;
    } else if (num < pick) {
        return 1;
    } else {
        return -1;
    }
}

// 猜数字游戏的核心逻辑
int guessNumber(int n) {
    int left = 1;
    int right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);
        if (result == 0) {
            return mid;
        } else if (result < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    initGame();
    int result = guessNumber(100);
    if (result == pick) {
        printf("The algorithm is correct\n");
    } else {
        printf("The algorithm is wrong\n");
    }
    return 0;
}