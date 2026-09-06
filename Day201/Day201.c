//Given two singly linked lists headA and headB, find the node where they intersect. If they do not intersect, return NULL.
//The intersection is based on the same node, not just the same value.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                      struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;

    while (a != b) {
        if (a == NULL)
            a = headB;
        else
            a = a->next;

        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }

    return a;
}

int main() {
    // Common part
    struct ListNode *c1 = malloc(sizeof(struct ListNode));
    struct ListNode *c2 = malloc(sizeof(struct ListNode));
    struct ListNode *c3 = malloc(sizeof(struct ListNode));

    c1->val = 8;
    c2->val = 4;
    c3->val = 5;

    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    struct ListNode *a1 = malloc(sizeof(struct ListNode));
    struct ListNode *a2 = malloc(sizeof(struct ListNode));

    a1->val = 4;
    a2->val = 1;

    a1->next = a2;
    a2->next = c1;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    struct ListNode *b1 = malloc(sizeof(struct ListNode));
    struct ListNode *b2 = malloc(sizeof(struct ListNode));
    struct ListNode *b3 = malloc(sizeof(struct ListNode));

    b1->val = 5;
    b2->val = 6;
    b3->val = 1;

    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    struct ListNode *result = getIntersectionNode(a1, b1);

    if (result != NULL)
        printf("Intersection Node: %d\n", result->val);
    else
        printf("No intersection\n");

    return 0;
}