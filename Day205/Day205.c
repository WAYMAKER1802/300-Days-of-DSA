//Question -  Rearrange a linked list so that odd-positioned nodes come first, followed by even-positioned nodes, while keeping their original order.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* oddEvenList(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenHead = even;

    while (even != NULL && even->next != NULL) {

        // Connect odd nodes
        odd->next = even->next;
        odd = odd->next;

        // Connect even nodes
        even->next = odd->next;
        even = even->next;
    }

    // Join odd list and even list
    odd->next = evenHead;

    return head;
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

    head = oddEvenList(head);

    printf("After rearranging: ");
    printList(head);

    return 0;
}