// Program contoh struktur data Mahasiswa dengan array, pointer, dan vector
#include <stdio.h>   // printf
#include <string.h>  // strcpy
#include <vector>    // vector

using namespace std;

struct Mahasiswa {   // Struktur data untuk menyimpan info 1 mahasiswa
    char nama[50];   // Nama mahasiswa (array char)
    int nim;         // NIM mahasiswa
    float ipk;       // IPK mahasiswa
};

// [2] Fungsi cetak semua mahasiswa via pointer
void cetakSemuaMahasiswa(const Mahasiswa *ptr, int n) {
    printf("=== DAFTAR MAHASISWA (ARRAY + POINTER) ===\n"); // Judul output
    for (int i = 0; i < n; ++i) {                        // Loop setiap mahasiswa
        printf("Mahasiswa #%d\n", i + 1);                // Nomor urut
        printf("Nama : %s\n", (ptr + i)->nama);          // Akses via pointer arithmetic
        printf("NIM  : %d\n", (ptr + i)->nim);
        printf("IPK  : %.2f\n", (ptr + i)->ipk);
        printf("-----------------------------------------\n");
    }
    printf("\n");                                         // Baris kosong pemisah
}

// [3] Fungsi cetak semua mahasiswa dari vector
void cetakSemuaMahasiswaVector(const vector<Mahasiswa> &v) {
    printf("=== DAFTAR MAHASISWA (VECTOR) ===\n");        // Judul output
    for (int i = 0; i < (int)v.size(); ++i) {            // Loop berdasarkan ukuran vector
        printf("Mahasiswa #%d\n", i + 1);
        printf("Nama : %s\n", v[i].nama);                // Akses via indeks vector
        printf("NIM  : %d\n", v[i].nim);
        printf("IPK  : %.2f\n", v[i].ipk);
        printf("---------------------------------\n");
    }
    printf("\n");                                         // Baris kosong pemisah
}

// [5] Fungsi cari mahasiswa berdasarkan NIM
int cariMahasiswaByNim(const vector<Mahasiswa> &v, int nimCari) {
    for (int i = 0; i < (int)v.size(); ++i) {            // Periksa satu per satu
        if (v[i].nim == nimCari) {                       // Jika NIM cocok
            return i;                                    // Kembalikan indeks
        }
    }
    return -1;                                           // -1 berarti tidak ditemukan
}

int main() {
    // [1] Array of struct Mahasiswa (menyimpan > 1 mahasiswa)
    Mahasiswa mhsArray[2];                               // Array berisi 2 mahasiswa

    strcpy(mhsArray[0].nama, "John Doe");                // Isi nama mahasiswa ke-1
    mhsArray[0].nim = 12345;                             // Isi NIM mahasiswa ke-1
    mhsArray[0].ipk = 3.75f;                             // Isi IPK mahasiswa ke-1

    strcpy(mhsArray[1].nama, "Jane Smith");              // Isi nama mahasiswa ke-2
    mhsArray[1].nim = 67890;                             // Isi NIM mahasiswa ke-2
    mhsArray[1].ipk = 3.85f;                             // Isi IPK mahasiswa ke-2

    // [2] Cetak semua mahasiswa dengan pointer
    cetakSemuaMahasiswa(mhsArray, 2);                    // Kirim alamat array + jumlah data

    // [3] Ganti penyimpanan ke vector<Mahasiswa>
    vector<Mahasiswa> daftar;                            // Vector kosong
    daftar.push_back(mhsArray[0]);                       // Tambah mahasiswa 1
    daftar.push_back(mhsArray[1]);                       // Tambah mahasiswa 2

    // [4] Tambah dua mahasiswa baru ke vector memakai fungsi STL (push_back)
    Mahasiswa mhsBaru1;                                  // Mahasiswa baru #1
    strcpy(mhsBaru1.nama, "Andi Putra");
    mhsBaru1.nim = 11223;
    mhsBaru1.ipk = 3.60f;
    daftar.push_back(mhsBaru1);                          // push_back menambah di akhir

    Mahasiswa mhsBaru2;                                  // Mahasiswa baru #2
    strcpy(mhsBaru2.nama, "Siti Rahma");
    mhsBaru2.nim = 44556;
    mhsBaru2.ipk = 3.92f;
    daftar.push_back(mhsBaru2);                          // push_back menambah di akhir

    // [3] Cetak isi vector
    cetakSemuaMahasiswaVector(daftar);                   // Tampilkan semua data di vector

    // [5] Cari dan tampilkan mahasiswa berdasarkan NIM
    int nimCari = 67890;                                 // NIM yang ingin dicari
    int idx = cariMahasiswaByNim(daftar, nimCari);       // Dapatkan indeks hasil
    if (idx != -1) {                                     // Jika ditemukan
        printf("=== HASIL PENCARIAN NIM ===\n");
        printf("NIM  : %d\n", nimCari);
        printf("Nama : %s\n", daftar[idx].nama);
        printf("IPK  : %.2f\n", daftar[idx].ipk);
        printf("===========================\n");
    } else {                                             // Jika tidak ditemukan
        printf("=== HASIL PENCARIAN NIM ===\n");
        printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", nimCari);
        printf("===========================\n");
    }

    return 0;
}
