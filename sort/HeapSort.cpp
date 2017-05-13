/*
regard array as a heap,we should adjust heap;
Than we sort array with two step:
	1.get heap-top element out;
	2.adjust heap
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
// init array
void initData(vector<int>& array){
	for(int i=0;i<arrLen;++i)
		array.push_back(random(100));
}



// adjust heap to minHeap/or maxHeap if downsort
void minHeapAdjust(vector<int>& array,int i,int arrLen){
	int temp = array[i];
	int lc = 2*i+1;  // left child
	int len=arrLen;
	while(lc<len){
		if(lc+1<len && array[lc+1]<array[lc])
			lc++;  // find the smaller one
		// change 
		if(array[lc]>temp)  // adjust finished
			break;
		array[i]=array[lc];
		i=lc;
		lc = 2*i+1;
	}
	array[i]=temp;
	
}

// delete element from heap
vector<int> deleteHeapNumber(vector<int>& array){
	vector<int> vec;
	for (int i = array.size() - 1; i >= 0; i--)  
    {  
        vec.push_back(array[0]);
		array[0]= array[i];
		minHeapAdjust(array,0,i);
    }
	return vec;  
} 
void HeapSort(vector<int>& array){
	// leaf node neednt adjust
	for(int i=array.size()/2;i>=0;i--){
		minHeapAdjust(array,i,array.size());
	}	
	array = deleteHeapNumber(array);
	
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
	HeapSort(array);
	cout<<"after sort:"<<endl;
	print(array);
}
