//There are n people in a party. You are given a matrix M where:
//M[i][j] = 1 → person i knows person j
//M[i][j] = 0 → person i does not know person j
//A celebrity is a person who:
//Everyone knows
//Knows nobody
//Find the celebrity. If there is no celebrity, return -1.
#include <stdio.h>

int findCelebrity(int M[][4], int n) {

    int candidate = 0;

    // Step 1: Find a possible celebrity
    for (int i = 1; i < n; i++) {

        if (M[candidate][i] == 1) {
            // Candidate knows i,
            // so candidate cannot be celebrity
            candidate = i;
        }
    }

    // Step 2: Verify the candidate

    for (int i = 0; i < n; i++) {

        if (i == candidate)
            continue;

        // Celebrity should know nobody
        // Everyone else should know celebrity
        if (M[candidate][i] == 1 || M[i][candidate] == 0) {
            return -1;
        }
    }

    return candidate;
}

int main() {

    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int M[4][4];

    printf("Enter the matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    int result = findCelebrity(M, n);

    if (result == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", result);

    return 0;
}