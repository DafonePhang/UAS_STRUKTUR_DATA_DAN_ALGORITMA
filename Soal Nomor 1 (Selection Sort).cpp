#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menukar dua elemen
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan array menggunakan Selection Sort
void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Temukan elemen terkecil dalam array yang belum diurutkan
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pertama dari array yang belum diurutkan
        swap(arr[minIndex], arr[i]);
    }
}

// Fungsi untuk mencetak array
void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah orang : ";
    cin >> n;
    cin.ignore();

    string names[n];
    cout << "Masukkan nama dan alamat setiap orang : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama dan alamat " << i + 1 << " : ";
        getline(cin, names[i]);
    }

    selectionSort(names, n);

    cout << "Data setelah diurutkan (Selection Sort): " << endl;
    printArray(names, n);
    return 0;
}

