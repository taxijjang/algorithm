#include<iostream>
#define SIZE 1000
using namespace std;


struct Tree{
	Tree *node[SIZE];
	bool finish,child_node;
	
	Tree(){
		fill(node,node+SIZE,nullptr);
		finish = child_node= false;
	}

	~Tree(){
		for(int i =0 ; i < SIZE ;i++){
			if(node[i]){
				delete node[i];
			}
		}
	}
}
int main(void){
	
}