#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struktur untuk menyimpan elemen dan indeks asli
struct Element {
    int value;
    size_t index;
};

// Fungsi untuk melakukan Quick Sort
void quickSort(vector<Element>& array, int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2].value;
    while (i <= j) {
        while (array[i].value < pivot) i++;
        while (array[j].value > pivot) j--;
        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

// Fungsi untuk melakukan Binary Search
vector<size_t> binarySearch(const vector<Element>& array, int target) {
    int left = 0, right = static_cast<int>(array.size()) - 1;
    vector<size_t> foundIndices;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid].value == target) {
            foundIndices.push_back(array[mid].index); // Simpan indeks asli
            // Cari duplikat di kedua sisi
            int temp = mid;
            while (--temp >= left && array[temp].value == target) {
                foundIndices.push_back(array[temp].index);
            }
            temp = mid;
            while (++temp <= right && array[temp].value == target) {
                foundIndices.push_back(array[temp].index);
            }
            break;
        }
        if (array[mid].value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return foundIndices;
}

// Fungsi untuk mencetak hasil pencarian
void printResult(const vector<size_t>& indices, int target) {
    if (indices.empty()) {
        cout << "Angka " << target << " tidak ada dalam array\n";
    } else {
        cout << "Angka " << target << " ada di indeks ke ";
        for (size_t i = 0; i < indices.size(); ++i) {
            cout << indices[i] + 1; // Tambah +1 untuk mengubah ke indeks 1-based
            if (i < indices.size() - 1) cout << " dan ";
        }
        cout << endl;
    }
}

int main() {
    // Inisialisasi array
    vector<int> inputArray = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<Element> dataArray(inputArray.size());

    // Isi dataArray dengan nilai dan indeks asli
    for (size_t i = 0; i < inputArray.size(); ++i) {
        dataArray[i] = {inputArray[i], i};
    }

    // Urutkan array menggunakan Quick Sort
    quickSort(dataArray, 0, static_cast<int>(dataArray.size()) - 1);

    // Input dari pengguna
    int searchValue;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> searchValue;

    vector<size_t> resultIndices = binarySearch(dataArray, searchValue);
    printResult(resultIndices, searchValue);

    return 0;
}

