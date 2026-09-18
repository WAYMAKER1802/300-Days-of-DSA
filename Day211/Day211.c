//Question : You have children with different greed factors and cookies with different sizes.
//A child can get a cookie only if: cookie size >= child's greed
//Find the maximum number of children who can be satisfied.
#include <stdio.h>

// Sort array in ascending order
void sort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (arr[i] > arr[j]) {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {

    int n, m;

    printf("Enter number of children: ");
    scanf("%d", &n);

    int greed[n];

    printf("Enter greed factors: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &greed[i]);
    }

    printf("Enter number of cookies: ");
    scanf("%d", &m);

    int cookies[m];

    printf("Enter cookie sizes: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &cookies[i]);
    }

    // Sort both arrays
    sort(greed, n);
    sort(cookies, m);

    int child = 0;
    int cookie = 0;
    int satisfied = 0;

    // Greedy approach
    while (child < n && cookie < m) {

        if (cookies[cookie] >= greed[child]) {

            // This cookie satisfies this child
            satisfied++;
            child++;
            cookie++;

        } else {

            // Cookie is too small
            cookie++;
        }
    }

    printf("Maximum satisfied children = %d\n", satisfied);

    return 0;
}