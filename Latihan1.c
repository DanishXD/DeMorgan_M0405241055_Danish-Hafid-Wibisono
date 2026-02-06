#include <stdio.h>

int main() {
    int N, i, Q, L, R, j, total;
    int suhu[1000];

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &suhu[i]);
    }

    scanf("%d", &Q);

    for (i = 0; i < Q; i++) {
        scanf("%d %d", &L, &R);
        total = 0;
        for (j = L - 1; j < R; j++) {
            total = total + suhu[j];
        }
        printf("%d\n",  total);
    }

    return 0;
}