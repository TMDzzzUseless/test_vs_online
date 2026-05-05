#include <stdio.h>
#include <stdlib.h>

// 1. 先定義結構體
struct Node {
    int data;
    struct Node* left;  // 這裡可以寫，因為指標的大小是固定的
    struct Node* right;
};

// 2. 再定義使用該結構體的函式
// 中序遍歷印出樹（驗證用）
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* sortedArrayToBST(int A[], int start, int end) {
    // 終止條件：當起始索引大於結束索引時
    if (start > end) {
        return NULL;
    }

    // 取得中間索引，建立為根節點
    int mid = start + (end - start) / 2;
    struct Node* root = newNode(A[mid]);

    // 遞迴建立左子樹（使用中間值左邊的資料）
    root->left = sortedArrayToBST(A, start, mid - 1);

    // 遞迴建立右子樹（使用中間值右邊的資料）
    root->right = sortedArrayToBST(A, mid + 1, end);

    return root;
}

int main() {
    int A[] = {1, 3, 9, 12, 24, 25, 34, 55, 76, 77, 79, 92, 93, 95, 99};
    int n = sizeof(A) / sizeof(A[0]);

    // 建立二元搜尋樹
    struct Node* root = sortedArrayToBST(A, 0, n - 1);

    printf("二元樹建立完成！中序遍歷結果（應與原陣列相同）：\n");
    printInorder(root);
    printf("\n");

    return 0;
}