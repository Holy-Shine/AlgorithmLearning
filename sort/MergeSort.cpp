/*
MERGE-SORT(A, p, r)
if p<r
	q = [ p + r ] / 2
	MERGE-SORT(A, q, r)
	MERGE-SORT(A, p, q-1)
	MERGE(A, p, q, r)
*/
#include<iostream>
#include<vector>
#define random(x) (rand()%x)
#define  Iter	vector<int>::iterator
#define  INF	0x7fffffff
using namespace std;
vector<int> arr;
int arrLen = 20;
// init arr
void initData(vector<int>& arr) {
	for (int i = 0; i<arrLen; ++i)
		arr.push_back(random(100));
}

// key part
void merge(vector<int> &arr, int b, int m, int e) {
	vector<int> arr1(arr.begin() + b, arr.begin()+ m+1);
	vector<int> arr2(arr.begin() + m+1, arr.begin() + e+1);
	// insert a guard
	arr1.insert(arr1.end(), INF);
	arr2.insert(arr2.end(), INF);

	// merge two part
	int p1 = 0, p2 = 0;
	for (int i = b; i <= e; ++i) {
		if (arr1[p1] < arr2[p2]) {
			arr[i] = arr1[p1];
			p1++;
		}
		else {
			arr[i] = arr2[p2];
			p2++;
		}
	}

}

void mergesort(vector<int> &arr, int begin, int end) {
	if (begin<end) {
		int mid = begin + (end - begin) / 2;
		mergesort(arr, begin, mid);
		mergesort(arr, mid + 1, end);

		// after sort two part, merge them
		merge(arr, begin, mid, end);
	}
}

// MergeSort
void MergeSort(vector<int> &arr) {
	mergesort(arr, 0, arr.size()-1);
}
// print arr
void print(vector<int>& arr) {
	for (int i = 0; i<arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	initData(arr);
	cout << "before sort:" << endl;
	print(arr);
	MergeSort(arr);
	cout << "after sort:" << endl;
	print(arr);
	system("pause");
}
