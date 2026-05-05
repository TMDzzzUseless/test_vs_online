#include <stdio.h>

/**
 * 二元搜尋法 (Binary Search)
 * 參數:
 * A[]: 已排序的整數陣列
 * size: 陣列的大小（長度）
 * target: 要搜尋的目標值
 * 回傳值:
 * 找到時回傳其在陣列中的索引值 (0 ~ size-1)
 * 找不到時回傳 -1
 */
int binarySearch(int A[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // 取得中間索引（在 C 語言中，整數相除會自動無條件捨去）
        int mid = low + (high - low) / 2; 

        if (A[mid] == target) {
            return mid;      // 找到目標，回傳索引值
        } 
        else if (A[mid] < target) {
            low = mid + 1;   // 目標在右半邊，調整左邊界
        } 
        else {
            high = mid - 1;  // 目標在左半邊，調整右邊界
        }
    }

    return -1; // 搜尋失敗，回傳 -1
}

int main() {
    // 宣告並初始化已排序陣列
    int A[] = {1, 3, 9, 12, 24, 25, 34, 55, 76, 77, 79, 92, 93, 95, 99};
    
    // 自動計算陣列的長度 (這裡算出來會是 15)
    int size = sizeof(A) / sizeof(A[0]); 
    
    int target;
    printf("請輸入你想搜尋的目標值：");
    
    // 安全地讀取使用者輸入，並確認輸入的是數字
    if (scanf("%d", &target) != 1) {
        printf("錯誤：請輸入整數數字！\n");
        return 1;
    }

    // 呼叫二元搜尋
    int result = binarySearch(A, size, target);

    // 輸出結果
    if (result != -1) {
        printf("找到目標！數值 %d 在陣列中的索引值為: %d\n", target, result);
    } else {
        printf("在陣列中找不到數值 %d，回傳值為: %d\n", target, result);
    }

    return 0;
}