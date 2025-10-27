#include <iostream>
using namespace std;

int commonDivisor(int n, int m){
    int r = n % m;
        n = m;
        m = r;

    if(!m){
        return n;
    }
    return commonDivisor(n, m);   
}
int main(){
    
    int nIterations;
    cin>>nIterations;
    for(int i = 0; i < nIterations; i++){

        int firstInteger;
        int secondInteger;

        cin>>firstInteger;
        cin>>secondInteger;

        
        int awnser = commonDivisor(firstInteger, secondInteger);
        cout<<awnser<<"\n";
    }
}