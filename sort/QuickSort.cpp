/*
//basic algorithm
1、find a number,let number on its left lower than it,others bigger than it put on its right
2、sort it's left part & right part

QuickSort(array,begin,end)
	if begin < end:
		r = getPartition(array,begin,end)
		QuickSort(array,begin,r-1)
		QuickSort(array,r+1,end)
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define random(x) (rand()%x)
#define Iter	vector<int>::iterator
using namespace std;
vector<int> array;
int arrLen = 20;
//init array
void initData(vector<int>& array){
	for(int i=0;i<arrLen;++i)
		array.push_back(random(100));
}
//key part 
Iter getPartition(Iter begin,Iter end){
	Iter lowPos = begin;   //lowPos:position to put the endData(referance)
	for(Iter it = begin;it<=end-1;++it){
		if(*it < *end){
			int temp = *lowPos;
			*lowPos = *it;
			*it = temp;
			lowPos++;
		}
	}
	int temp = *lowPos;
	*lowPos = *end;
	*end = temp;
	return lowPos;
}
//QuickSort
void QuickSort(Iter begin,Iter end){
	if(begin<end){
		Iter mid = getPartition(begin,end);
		QuickSort(begin,mid-1);
		QuickSort(mid+1,end);
	}
}
//print array
void print(vector<int>& array){
	for(int i=0;i<array.size();++i)
		cout<<array[i]<<" ";
	cout<<endl;
}
int main(){
	initData(array);
	cout<<"before sort:"<<endl;
	print(array);
	QuickSort(array.begin(),array.end()-1);
	cout<<"after sort:"<<endl;
	print(array);
}
