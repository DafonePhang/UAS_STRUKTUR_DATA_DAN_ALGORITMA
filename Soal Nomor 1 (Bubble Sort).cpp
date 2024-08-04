#include <iostream>
#include <string>
using namespace std;

//Fungsi untuk menukar dua elemen
void swap(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
}

//Fungsi untuk mengurutkan array mengunakan Bubble Sort
void bubbleSort(string arr[], int n){
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr [j + 1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

// Fungsi untuk mencetak array
void printArray(string arr[],  int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
	cout << endl;
}

int main (){
	int n;
	cout << "Masukkan jumlah orang : ";
	cin >> n;
	cin.ignore();
	
	string names[n];
	cout << "Masukkan nama dan alamat setiap orang : "<< endl;
	for (int i = 0; i < n; i++) {
		cout << "Nama dan alamat " << i + 1 << " : ";
		getline(cin, names[i]);
	}
	
	bubbleSort(names, n);
	
	cout << "Data setelah diurutkan (Bubble Sort): " << endl;
	printArray(names, n);
	return 0;
	}
