//Question : Given activities with a start time and finish time, select the maximum number of non-overlapping activities that one person can perform.
#include <stdio.h>

int main() {

    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int n = 6;
    int count = 1;
    int lastFinish = finish[0];

    printf("Selected activities:\n");
    printf("(%d, %d)\n", start[0], finish[0]);

    for (int i = 1; i < n; i++) {

        if (start[i] >= lastFinish) {
            printf("(%d, %d)\n", start[i], finish[i]);

            count++;
            lastFinish = finish[i];
        }
    }

    printf("Maximum activities = %d\n", count);

    return 0;
}