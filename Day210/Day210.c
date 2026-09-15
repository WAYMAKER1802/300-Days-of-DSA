//Question : Given n items, each having a value and weight, and a knapsack with capacity W, maximize the total value you can put in the knapsack.
//You can take fractions of an item.
#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio =
            (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by value/weight ratio
    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (items[i].ratio < items[j].ratio) {

                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    float totalValue = 0;

    // Take items greedily
    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

            // Take complete item
            capacity -= items[i].weight;
            totalValue += items[i].value;

        } else {

            // Take fraction of item
            totalValue += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    printf("Maximum value = %.2f\n", totalValue);

    return 0;
}