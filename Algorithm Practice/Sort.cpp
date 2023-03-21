#include<iostream>
#include<random>
#include"Sort.h"
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 999);
	int ary[20] = { 0, };
	for (int i = 0; i < 20; i++) {
		int rn = dis(gen);
		bool check = true;
		for (int j = 0; j < 20; j++) {
			if (ary[j] == rn) {
				i--;
				check = false;
				break;
			}
		}
		if (check)ary[i] = rn;
	}
	//Bubble Sort
	int ary1[20];
	memcpy(&ary1, &ary, sizeof(ary));
	BubbleSort(ary1, 0, 19);
	for (int ele : ary1)
		cout << ele << " ";
	cout << endl;
	//Selection Sort
	int ary2[20];
	memcpy(&ary2, &ary, sizeof(ary));
	SelectionSort(ary2, 0, 19);
	for (int ele : ary2)
		cout << ele << " ";
	cout << endl;
	//Insertion Sort
	int ary3[20];
	memcpy(&ary3, &ary, sizeof(ary));
	InsertionSort(ary3, 0, 19);
	for (int ele : ary3)
		cout << ele << " ";
	cout << endl;
	//Radix Sort
	int ary4[20];
	memcpy(&ary4, &ary, sizeof(ary));
	RadixSort(ary4, 0, 19);
	for (int ele : ary4)
		cout << ele << " ";
	cout << endl;
	//Quick Sort
	int ary5[20];
	memcpy(&ary5, &ary, sizeof(ary));
	QuickSort(ary5, 0, 19);
	for (int ele : ary5)
		cout << ele << " ";
	cout << endl;
	//Heap Sort
	int ary6[20];
	memcpy(&ary6, &ary, sizeof(ary));
	HeapSort(ary6, 0, 19);
	for (int ele : ary6)
		cout << ele << " ";
	cout << endl;
	//Merge Sort
	int ary7[20];
	memcpy(&ary7, &ary, sizeof(ary));
	
	for (int ele : ary7)
		cout << ele << " ";
	cout << endl;

	return 0;
}