#include <stdio.h>
// 中序遍歷印出樹（驗證用）
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
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