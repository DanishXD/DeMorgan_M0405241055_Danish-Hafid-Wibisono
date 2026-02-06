#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // hanya untuk fungsi waktu
int main() {
 int i, j, k;
 const int N = 800; // ukuran matriks NxN
 double **A, **B, **C;
 double start, end, time_seq;
 // Alokasi matriks 2D secara dinamis
 A = (double**) malloc(N * sizeof(double*));
 B = (double**) malloc(N * sizeof(double*));
 C = (double**) malloc(N * sizeof(double*));
 for (i = 0; i < N; i++) {
 A[i] = (double*) malloc(N * sizeof(double));
 B[i] = (double*) malloc(N * sizeof(double));
 C[i] = (double*) malloc(N * sizeof(double));
 }
 // Inisialisasi matriks A dan B
 for (i = 0; i < N; i++)
 for (j = 0; j < N; j++) {
 A[i][j] = i + j;
 B[i][j] = i - j;
 C[i][j] = 0.0;
 }
 // Perkalian matriks (sekuensial)
 start = omp_get_wtime();
 for (i = 0; i < N; i++) {
 for (j = 0; j < N; j++) {
 for (k = 0; k < N; k++) {
 C[i][j] += A[i][k] * B[k][j];
 }
 }
 }
 end = omp_get_wtime();
 time_seq = end - start;
 printf("Ukuran matriks: %d x %d\n", N, N);
 printf("Waktu eksekusi (sekuensial): %.6f detik\n", time_seq);
 // Bebaskan memori
 for (i = 0; i < N; i++) {free(A[i]);
 free(B[i]);
 free(C[i]);
 }
 free(A);
 free(B);
 free(C);
 return 0;
}
