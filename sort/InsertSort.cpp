/*
伪代码：
INSERTION-SORT(A)
for i=2 to A.length
	key=A[i]
	// 把 A[i] 插入到排序好的序列 A[1...i-1]中
	j=i-1
	while j>0 and A[j]>key
		A[j+1]=A[j]
		j=j-1
	A[j+1]=key
*/


#include<iostream>
#include<vector>
#define random(x) (rand()%x)
using namespace std;
vector<int> arr;
int arrLen = 20;
//init array
void initData(vector<int> &arr) {
	for (int i = 0; i<arrLen; ++i)
		arr.push_back(random(100));
}

void InsertSort(vector<int> &arr) {
	if (arr.size() <= 1)
		return;
	else {
		for (int i = 1; i < arr.size(); ++i) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
}
//print array
void print(vector<int>& array) {
	for (int i = 0; i<array.size(); ++i)
		cout << array[i] << " ";
	cout << endl;
}
int main() {
	initData(arr);
	cout << "before sort:" << endl;
	print(arr);
	InsertSort(arr);
	cout << "after sort:" << endl;
	print(arr);
	system("pause");
}