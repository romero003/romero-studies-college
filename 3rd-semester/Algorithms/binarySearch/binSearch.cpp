#include <iostream>
#include <vector>

// aprender a declarar um array de tuplas
using namespace std;

int binarySearch(int element, vector<int> &vec){
    // Vai receber o elemento e retorja sua posição dentre os outros inteiros
    int l = 0;
    int r = vec.size() - 1;
    while (l <= r)
    {
        int m = (r+l)/2; // piso do elemento médio.
        if (vec[m] == element)
        {
            return m;
        }
        else if (vec[m] < element)
        {
            // atualiza o valor de l
            l = m + 1;
        }
        else
        {
            // atualiza o valor de r
            r = m - 1;
        }
    }
        return -1;


    return l;
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
    int position = binarySearch(chosenNum, vec);
    cout << position << endl;
}