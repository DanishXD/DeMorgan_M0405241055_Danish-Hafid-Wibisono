#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main() {
 int i, j, k;
 const int N = 800; // ukuran matriks NxN
 double **A, **B, **C;
 double start, end, time_par;
 // Alokasi matriks 2D
 A = (double**) malloc(N * sizeof(double*));
 B = (double**) malloc(N * sizeof(double*));
 C = (double**) malloc(N * sizeof(double*));
 for (i = 0; i < N; i++) {
 A[i] = (double*) malloc(N * sizeof(double));
 B[i] = (double*) malloc(N * sizeof(double));
 C[i] = (double*) malloc(N * sizeof(double));
 }
 // Inisialisasi matriks
 for (i = 0; i < N; i++)
 for (j = 0; j < N; j++) {
 A[i][j] = i + j;
 B[i][j] = i - j;
 C[i][j] = 0.0; }
 // Perkalian matriks menggunakan OpenMP
 start = omp_get_wtime();
 #pragma omp parallel for private(j, k) shared(A, B, C)
 for (i = 0; i < N; i++) {
 for (j = 0; j < N; j++) {
 double sum = 0.0;
 for (k = 0; k < N; k++) {
 sum += A[i][k] * B[k][j];
 }
 C[i][j] = sum;
 }
 }
 end = omp_get_wtime();
 time_par = end - start;
 printf("Ukuran matriks: %d x %d\n", N, N);
 printf("Jumlah thread digunakan: %d\n", omp_get_max_threads());
 printf("Waktu eksekusi (paralel): %.6f detik\n", time_par);
 // Bebaskan memori
 for (i = 0; i < N; i++) {
 free(A[i]);
 free(B[i]);
 free(C[i]);
 }
 free(A);
 free(B);
 free(C);
 return 0;
}
