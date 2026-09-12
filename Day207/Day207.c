//Question : Given a linked list, swap every two adjacent nodes without changing their values.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* first = head;
    struct ListNode* second = head->next;

    // Swap the two nodes
    first->next = swapPairs(second->next);
    second->next = first;

    return second;
}

struct ListNode* createList(int n) {

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(struct ListNode* head) {

    while (head != NULL) {
        printf("%d", head->val);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main() {

    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    struct ListNode* head = createList(n);

    head = swapPairs(head);

    printf("After swapping pairs: ");
    printList(head);

    return 0;
}