#pragma once
#include<queue>

void Swap(int* _a, int* _b) {
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}

//Bubble Sort(버블 정렬)
void BubbleSort(int ary[], int begin, int end) {
	for (int i = begin; i < end; i++) {
		for (int j = begin; j < end; j++) {
			if (ary[j] > ary[j + 1])
				Swap(&ary[j], &ary[j + 1]);
		}
	}
	return;
}

//Selection Sort(선택 정렬)
void SelectionSort(int ary[], int begin, int end) {
	for (int i = begin; i <= end; i++) {
		int min = i;
		for (int j = i + 1; j <= end; j++) {
			if (min == -1 || ary[min] > ary[j])min = j;
		}
		Swap(&ary[min], &ary[i]);
	}
	return;
}

//Insertion Sort(삽입 정렬)
void InsertionSort(int ary[], int begin, int end) {
	for (int i = begin + 1; i <= end; i++) {
		int key = ary[i], j;
		for (j = i - 1; j >= begin && key < ary[j]; j--)
			ary[j + 1] = ary[j];
		ary[j + 1] = key;
	}
	return;
}

//Radix Sort(기수 정렬)
void RadixSort(int ary[], int begin, int end) {
	std::queue<int> que[10];
	int max = -1;
	for (int i = begin; i <= end; i++)
		max = max > ary[i] ? max : ary[i];
	for (int i = 1; max / i > 0; i *= 10) {
		for (int j = begin; j <= end; j++) {
			que[(ary[j] / i) % 10].push(ary[j]);
		}
		int count = 0;
		for (int j = 0; j < 10; j++) {
			for (int h = 0; h < que[j].size(); h++) {
				ary[count] = que[j].front();
				que[j].pop();
				count++;
				h--;
			}
		}
	}
	return;
}

//Quick Sort(퀵 정렬)
void QuickSort(int ary[], int begin, int end) {
	if (begin >= end) return;
	int piv = begin, low = begin + 1, high = end;
	while (low < high) {
		while (ary[low] < ary[piv] && low <= end)low++;
		while (ary[high] > ary[piv] && high > begin)high--;
		if (high >= low)
			Swap(&ary[high], &ary[low]);
	}
	if (ary[high] < ary[piv])
		Swap(&ary[high], &ary[piv]);
	QuickSort(ary, begin, high - 1);
	QuickSort(ary, high + 1, end);
	return;
}

//HeapSort (힙 정렬)
void Heapify(int ary[], int parent, int size) {
	if (parent >= size) return;
	int RightNode = parent * 2 + 2;
	int LeftNode = parent * 2 + 1;
	int MaxNode = parent;

	if (LeftNode < size && ary[LeftNode] > ary[MaxNode])
		MaxNode = LeftNode;
	if (RightNode < size && ary[RightNode] > ary[MaxNode])
		MaxNode = RightNode;

	if (MaxNode != parent) {
		Swap(&ary[MaxNode], &ary[parent]);
		Heapify(ary, MaxNode, size);
	}
	return;
}
void HeapSort(int ary[], int begin, int end) {
	int size = end + 1;
	for (int i = size / 2; i >= begin; i--)
		Heapify(ary, i, size);
	for (int i = end; i > begin; i--) {
		Swap(&ary[i], &ary[begin]);
		Heapify(ary, begin, --size);
	}
	return;
}

//Merge Sort(합병 정렬)
void Merge(int ary[], int begin,int mid, int end) {
	std::queue<int> mer;
	int l = begin;
	int r = mid;
	while (l < mid || r <= end) {
		if (l >= mid) {
			mer.push(ary[r++]);
			continue;
		}
		if (r > end) {
			mer.push(ary[l++]);
			continue;
		}
		if (ary[l] < ary[r]) 
			mer.push(ary[l++]);
		else
			mer.push(ary[r++]);
	}
	for (int i = 0; i <= end - begin; i++) {
		ary[begin + i] = mer.front();
		mer.pop();
	}
	return;
}

void MergeSort(int ary[], int begin, int end) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		MergeSort(ary, begin, mid);
		MergeSort(ary, mid + 1, end);
		Merge(ary, begin, mid + 1, end);
	}
	return;
}

