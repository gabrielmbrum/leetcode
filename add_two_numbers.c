/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode dummyHead = {0, NULL};
    struct ListNode* current = &dummyHead;

    while (carry || l1 || l2) {
        int sum = carry; // 
        if (l1) {
            sum += l1->val; 
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val; 
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }

    return dummyHead.next; // Return the head of the resulting list
}

// Function to print the linked list.
void printList(struct ListNode* node) {
  while (node != NULL) {
      printf("%d", node->val);
      if (node->next != NULL) printf(" -> ");
      node = node->next;
  }
  printf("\n");
}