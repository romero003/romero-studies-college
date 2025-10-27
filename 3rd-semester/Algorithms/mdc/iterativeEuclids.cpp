#include <iostream>
using namespace std;
int MDC(int n,int m){
    while(!n){
            int r = n %m;
            n=m;
            m=r;
        }
        return m;
}


int main(){
    int nIterations;
    cin>>nIterations;

    for(int i = 0; i< nIterations;i++){
        int n;
        cin>> n;
        int m;
        cin>>m;
        while(!n){
            int r = n %m;
            n=m;
            m=r;
        }
        
    }
}