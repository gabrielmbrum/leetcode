#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5000

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

void putInOrder (struct TreeNode* root, int index, int **arr) {
    if (root != NULL) {
        putInOrder(root->left, index, &(*arr));
        *arr[index++] = root->val;
        putInOrder(root->right, index, &(*arr));
    }
}

void merge(int **sorted, int *root1, int *root2) {
    //index of each array
    int r1, r2, s;
    r1 = r2 = s = 0;

    while (r1 < MAX_NODES && r2 < MAX_NODES) {
        if (root1[r1] < root2[r2]) 
            *sorted[s++] = root1[r1++];
        else
            *sorted[s++] = root2[r2++];
    }

    // if already inserted all values of root1
    if (r1 == MAX_NODES) {
        while (r2 < MAX_NODES)
            *sorted[s++] = root2[r2++];
    } else {
        while (r1 < MAX_NODES)
            *sorted[s++] = root1[r1++];
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int *sorted, *rootOne, *rootTwo;
    sorted = (int*)malloc(sizeof(int) * MAX_NODES * 2);
    rootOne = (int*)malloc(sizeof(int) * MAX_NODES);
    rootTwo = (int*)malloc(sizeof(int) * MAX_NODES);
    
    putInOrder(root1, 0, &rootOne);
    putInOrder(root2, 0, &rootTwo);

    merge(&sorted, rootOne, rootTwo);

    return sorted;
}

/*
possível solução
1 - percorrer in order e adicionar em 2 vetores distintos e depois agrupar eles

2 - percorrer pelas duas ao mesmo tempo, comparando qual é menor (problema: n sei como)
    -> 
*/

/*
sol 1

sol 2
inOrder(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 != null && root2 != null) {
        if (root1->val < root2->val) {
            inOrder(root1->left, root2);
            add(arr1, root1->val);
            inOrder(root1, root2->left)
        } else {
            inOder(root1, root2->left);
            add(arr2, root2->val);
        }
    }
}
*/

