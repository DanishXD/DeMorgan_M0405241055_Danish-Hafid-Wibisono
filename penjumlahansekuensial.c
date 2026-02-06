#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // hanya digunakan untuk omp_get_wtime()
int main() {
 int i;
 const int N = 100000000; // 100 juta elemen
 double *A, *B, *C;
 double start, end, time_seq;
 // Alokasi memori
 A = (double*) malloc(N * sizeof(double));
 B = (double*) malloc(N * sizeof(double));
 C = (double*) malloc(N * sizeof(double));
 if (A == NULL || B == NULL || C == NULL) {
 printf("Gagal mengalokasikan memori!\n");
 return -1;
 }
 // Inisialisasi array
 for (i = 0; i < N; i++) {
 A[i] = i * 0.5;
 B[i] = i * 2.0;
 }
 // Penjumlahan SEKUENSIAL
 start = omp_get_wtime();
 for (i = 0; i < N; i++) {
 C[i] = A[i] + B[i];
 }
 end = omp_get_wtime();
 time_seq = end - start;
 printf("Ukuran array: %d\n", N);
 printf("Waktu eksekusi sekuensial: %.6f detik\n", time_seq);
 free(A);
 free(B);
 free(C);
 return 0;
}