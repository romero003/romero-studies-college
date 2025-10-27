#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeSort(vector<int> &vec, int l, int r)
{ // recebe como parâmetros o vetor,
    if (l < r)
    {
        int m = (l + r) / 2;      // Divide os índices do vetor em duas partes
        mergeSort(vec, l, m);     // Coloca para o mergesort a primeira parte do vetor, que corresponde a de l até m
        mergeSort(vec, m + 1, r); // Coloca para o mergesort a segunda parte do vetor, que vai de m+1 até r

        vector<int> temp = vec;// cria um vetor temporário com tamanho r+1
        
        m = (l + r) / 2; // Cria uma referência de índice m
        int i1 = l;      // O primeiro índice vai ser o índice da esquerda
        int i2 = m + 1;  // O segundo [indice vai ser o índice da metade mais 1]
        for (int cur = l; cur <= r; cur++)
        {
            if (i1 == m + 1) //1. Já se copiou todos os elementos do fragmento à esquerda
            {                          
                vec[cur] = temp[i2++]; // 2. Copio todos os elementos à direita
            }
            else if (i2 > r)//1. Ja se copiou todos os valores do segundo fragmento 
            {
                vec[cur] = temp[i1++]; //2.Agora vamos inserir o que falta do primeiro
            }
            else if (temp[i1] <= temp[i2])//1. Se o valor da esquerda for menor que o da direita
            {
                vec[cur] = temp[i1++]; //2. Copia direto pra o vetor principal
            }
            else //3. Se não for,
            {
                vec[cur] = temp[i2++];//4. copia o da direita
            }
        }
        
    }
}


int main(){
    int score = 0;
    int testCases;
    cin>>testCases;
    int halvedNumbers;
    int number;
    int minimum;

    vector<int> vec;


    for(int i = 0;i < testCases; i++){
        cin>>halvedNumbers;
        for(int j = 0;j < 2* halvedNumbers; j++){
            cin >> number;
            vec.push_back(number);
        }
        mergeSort(vec, 0, vec.size() -1);
        for(int k = 0; k < halvedNumbers * 2; k = k +2){
            minimum = min(vec[k], vec[k+1]);
            score = score + minimum;
        }
        vec.clear();
        cout<<score<<endl;
        score = 0;

    }
}