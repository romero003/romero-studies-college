#include <iostream>
#include <vector>
using namespace std;

void mergesort(vector<int> &vec, int l, int r)
{ // recebe como parâmetros o vetor,
    if (l < r)
    {
        int m = (l + r) / 2;      // Divide os índices do vetor em duas partes
        mergesort(vec, l, m);     // Coloca para o mergesort a primeira parte do vetor, que corresponde a de l até m
        mergesort(vec, m + 1, r); // Coloca para o mergesort a segunda parte do vetor, que vai de m+1 até r

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

int main(){                                     // função principal
    ios_base::sync_with_stdio(false); // linhas que otimizam a recepção de input
    cin.tie(nullptr);

    int c;
    cin >> c; // quantidade de vezes que o código vai ser executado
    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n; // Recebe o tamanho do vetor
        vector<int> vec;
        int x;
        for (int j = 0; j < n; j++)
        {
            cin >> x;// Cria o vetor de acordo com a entrada
            vec.push_back(x);
        }
        mergesort(vec, 0, n - 1); // Chama a função mergesort passando como parâmetros um vetor e a posição inicial e final do vetor que vai ser sort
        for(int w: vec){
            cout<<w<<"\n";
        }
    }
}