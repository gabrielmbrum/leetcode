#include <stdlib.h>

#define MAX_NODES 5000

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void putInOrder (struct TreeNode* root, int *index, int **arr) {
    if (root != NULL) {
        putInOrder(root->left, index, &(*arr));       // Traverse left subtree
        (*arr)[(*index)++] = root->val;               // Store current node value
        putInOrder(root->right, index, &(*arr));      // Traverse right subtree
    }
}

void merge(int **sorted, int *root1, int root1Size, int *root2, int root2Size) {
    // index of each array
    int r1 = 0, r2 = 0, s = 0;

    while (r1 < root1Size && r2 < root2Size) {
        if (root1[r1] < root2[r2]) 
            (*sorted)[s++] = root1[r1++];
        else
            (*sorted)[s++] = root2[r2++];
    }

    // If any elements remain in root1
    while (r1 < root1Size)
        (*sorted)[s++] = root1[r1++];

    // If any elements remain in root2
    while (r2 < root2Size)
        (*sorted)[s++] = root2[r2++];
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int *sorted, *rootOne, *rootTwo;
    int rootOneSize = 0, rootTwoSize = 0;
    
    rootOne = (int*)malloc(sizeof(int) * MAX_NODES);
    rootTwo = (int*)malloc(sizeof(int) * MAX_NODES);

    // Fill rootOne and rootTwo with the in-order traversal of each tree
    putInOrder(root1, &rootOneSize, &rootOne);
    putInOrder(root2, &rootTwoSize, &rootTwo);

    *returnSize = rootOneSize + rootTwoSize;
    sorted = (int*)malloc(sizeof(int) * (*returnSize));

    // Merge the two sorted arrays
    merge(&sorted, rootOne, rootOneSize, rootTwo, rootTwoSize);

    // Free the temporary arrays
    free(rootOne);
    free(rootTwo);

    return sorted;
}