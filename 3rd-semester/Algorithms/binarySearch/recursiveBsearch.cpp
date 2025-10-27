#include <iostream>
#include <vector>
using namespace std;


int binarySearch(int element, vector<int> &vec, int l, int r){
    if(r >= l){
        int m = (l+r)/2;
        if(element == vec[m]){
            return m;
        }else if(element < vec[m]){
            return binarySearch(element, vec, l, m-1);
        }else{
            return binarySearch(element, vec, m+1, r);
        }
    }else{
        return -1;
    }
}



int main()
{
    vector<int> vec;
    for (int i = 0; i < 100; i++){
        vec.push_back((i +100));
    }
    // Ao ser implementada a busca binária, o valor a ser retornado deve corresponder ao valor do item - 100
    int chosenNum;
    cout << "Escolha um número a ser encontrado utilizando busca binária" << endl;
    cin >> chosenNum;
    int position = binarySearch(chosenNum, vec, 0, vec.size() - 1);
    cout << position << endl;
}
