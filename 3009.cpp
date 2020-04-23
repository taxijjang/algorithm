#include<iostream>
#include<map>

using namespace std;

map<int,int> x,y;

int main(void){
    for(int i = 0 ; i <3 ; i++){
        int xx,yy; cin >>xx>>yy;
        
        x[xx]++; y[yy]++;
    }
    
    for(auto tx : x){
        if(tx.second == 1)
            cout << tx.first <<" ";
    }
    
     for(auto ty: y){
        if(ty.second == 1)
            cout << ty.first;
    }
}