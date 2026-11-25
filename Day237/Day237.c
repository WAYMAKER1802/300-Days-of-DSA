//Question- A thief has a knapsack with a maximum weight capacity of W. There are n items, each having a specific weight and
// profit.The thief can either take an entire item or leave it. An item cannot be divided.
//Using the Branch and Bound technique, find the maximum profit that can be obtained without exceeding the knapsack capacity.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int weight;
    int profit;
    double ratio;
} Item;

typedef struct {
    int level;
    int profit;
    int weight;
    double bound;
} Node;

Item items[MAX];
Node heap[10000];
int heapSize = 0;

int capacity, n;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node node) {
    int i = ++heapSize;
    heap[i] = node;

    while (i > 1 && heap[i].bound > heap[i / 2].bound) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;

    while (2 * i <= heapSize) {
        int child = 2 * i;

        if (child + 1 <= heapSize &&
            heap[child + 1].bound > heap[child].bound)
            child++;

        if (heap[i].bound >= heap[child].bound)
            break;

        swap(&heap[i], &heap[child]);
        i = child;
    }

    return top;
}

double bound(Node u) {
    if (u.weight >= capacity)
        return 0;

    double result = u.profit;
    int totalWeight = u.weight;
    int j = u.level + 1;

    while (j < n && totalWeight + items[j].weight <= capacity) {
        totalWeight += items[j].weight;
        result += items[j].profit;
        j++;
    }

    if (j < n) {
        result += (capacity - totalWeight) *
                  items[j].ratio;
    }

    return result;
}

int knapsack() {
    Node u, v;
    int maxProfit = 0;

    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u);

    push(u);

    while (heapSize > 0) {
        u = pop();

        if (u.bound <= maxProfit)
            continue;

        v.level = u.level + 1;

        // Include current item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= capacity &&
            v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v);

        if (v.bound > maxProfit)
            push(v);

        // Exclude current item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v);

        if (v.bound > maxProfit)
            push(v);
    }

    return maxProfit;
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].profit);
        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    // Sort items by profit/weight ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Maximum Profit = %d\n", knapsack());

    return 0;
}
