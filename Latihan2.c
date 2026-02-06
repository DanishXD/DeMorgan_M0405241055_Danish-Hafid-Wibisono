#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int A[10000];
    for (int i = 0; i < X; i++) {
        scanf("%d", &A[i]);
    }

    int M[10000];
    int maxLIS = 1;

    for (int i = 0; i < X; i++) {
        M[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && M[j] + 1 > M[i]) {
                M[i] = M[j] + 1;
            }
        }
        if (M[i] > maxLIS) {
            maxLIS = M[i];
        }
    }

    int langkah = X - maxLIS;
    printf("%d\n", langkah);

    return 0;
}