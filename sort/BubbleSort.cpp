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

void BubbleSort(Iter begin,Iter end){
	for(Iter it=begin;it<end;++it){
		for(Iter nit=it+1;nit<=end;++nit)
			if(*nit<*it){
				int temp = *it;
				*it = *nit;
				*nit = temp;
			}
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
	BubbleSort(array.begin(),array.end()-1);
	cout<<"after sort:"<<endl;
	print(array);
}