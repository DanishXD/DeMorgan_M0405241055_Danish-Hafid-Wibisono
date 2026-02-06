#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main() {
 int i;
 const int N = 100000000; // 100 juta elemen
 double *A, *B, *C;
 double start, end, time_par;
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
 // Penjumlahan PARALEL menggunakan OpenMP
 start = omp_get_wtime();
 #pragma omp parallel for
 for (i = 0; i < N; i++) {
 C[i] = A[i] + B[i];
 }
 end = omp_get_wtime();
 time_par = end - start;
 printf("Ukuran array: %d\n", N);
 printf("Jumlah thread digunakan: %d\n", omp_get_max_threads());
 printf("Waktu eksekusi paralel: %.6f detik\n", time_par);
 free(A);
 free(B);
 free(C);
 return 0;
}
