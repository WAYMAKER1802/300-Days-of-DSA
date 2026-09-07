//Question : Given two lists of restaurant names, find the common restaurant(s) having the smallest sum of their indices in the two lists.
#include <stdio.h>
#include <string.h>

int main() {

    char *list1[] = {
        "Shogun",
        "Tapioca Express",
        "Burger King",
        "KFC"
    };

    char *list2[] = {
        "Piatti",
        "The Grill at Torrey Pines",
        "Hungry Hunter Steakhouse",
        "Shogun"
    };

    int n = 4;
    int m = 4;

    int minSum = 100000;

    printf("Common restaurant(s) with minimum index sum:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (strcmp(list1[i], list2[j]) == 0) {

                int sum = i + j;

                if (sum < minSum) {
                    minSum = sum;

                    printf("%s\n", list1[i]);
                }
            }
        }
    }

    return 0;
}