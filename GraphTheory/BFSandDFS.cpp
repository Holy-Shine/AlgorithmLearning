/*
tree like this:
		1
	  /   \
	 2     5
	/ \    /
   6   3  4
   		   \
   		   	7
*/ 

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define NODE int
#define MAX 10

NODE neighborMat[MAX][MAX]={0};
bool visited[MAX] = {0};  	// we need a bool array to indicate wheather we have visited one node

// initial neighbor mat
void initialNeighborMat(){
	neighborMat[1][2]=neighborMat[2][1]=1;
	neighborMat[1][5]=neighborMat[5][1]=1;
	neighborMat[2][6]=neighborMat[6][2]=1;
	neighborMat[3][2]=neighborMat[2][3]=1;
	neighborMat[5][4]=neighborMat[4][5]=1;
	neighborMat[4][7]=neighborMat[7][4]=1;
}


// BFS use a queue to go through all nodes
void BFS(NODE head){
	queue<NODE> q;
	q.push(head);
	while(!q.empty()){
		// visit queue's head node
		NODE node = q.front();
		cout<<node<<" ";
		visited[node] = true;
		// get node next to it put into queue
		for(int i = 0; i<MAX; ++i){
			if(!visited[i]&&neighborMat[node][i]==1)
				q.push(i);
		}
		q.pop();
	}
}

// DFS is a recurrant way to go through graph
void DFS(NODE node){
	if(visited[node])
		return;
	cout<<node<<" ";
	visited[node]=true;
	for(int i =0; i<MAX; ++i){
		if(neighborMat[node][i]==1)
			DFS(i);
	}
}
int main(){
	initialNeighborMat();
	cout<<"----------------------BFS-------------------------"<<endl;
	cout<<"BFS order: ";
	BFS(1);
	cout<<endl;
	memset(visited,0,sizeof(visited));
	cout<<"----------------------DFS-------------------------"<<endl;
	cout<<"DFS order: ";
	DFS(1);
	return 0;
}
