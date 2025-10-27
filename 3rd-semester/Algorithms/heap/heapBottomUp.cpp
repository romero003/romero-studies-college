#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapfy(vector<int> &vec, int n){

    int size_halved = n/2;
    for(int i = size_halved; i >= 1; i--){ //Começa do final das raízes e vai até a raiz principal
        
        int k = i; //Posição atual do nó i
        int v = vec[k]; //Valor desse nó
        bool heap = false; //Começa não sendo uma heap
        
        while(!heap && 2*k <= n){ //Enquanto não for uma heap e 2k <= n (ou seja, o nó k tiver filhos)
            int j = 2*k; // j vai fazer o papel do filho esquerdo de k
            if(j<n){ // Se o filho esquerdo tiver indice menor que o tamanho da heap (ou seja, tem nó direito)
                if(vec[j] > vec[j+1]){ //Se  o elemento j for menor que o seu no à direita, 
                    j++; //Consideremos o nó à direita
                }
            }
            if(v <= vec[j]){ //Se o valor do nó pai for maior que o valor do nó j (maior filho)
                heap = true; //É uma heap
            }else{//Se não for
                vec[k] = vec[j]; //Essas três últimas linhas realizam a troca
                k = j;
            }

        }
        vec[k] = v;
    } //O loop recomeça para a próxima raiz, até que todas as subárvores se tornem heaps
}


int heapSort(vector<int> &vec, int n){
    vector<int> repetitions;
    
    int d = n; //Define um diretor
    heapfy(vec, n); //Transforma em uma heap 

    while(d >= 1){ // Enquanto o meu tamanho do array reduzido não for nulo
        
        cout<<vec[1]<<endl; //Imprime o elemento maior ou menor
        swap(vec[1], vec[d]); //Troca com o último element (Tira do array)
        heapfy(vec, --d); //chama recursivamente a função com um tamanho a menos, eliminando o último do heapfy.
    }
 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; //size of the array
    cin>>n;

    vector<int> vec;
    vec.push_back(999);

    
    int e;//element of the array

    for(int i = 0; i<n; i++){
        cin>> e;
        vec.push_back(e);
    }

    int size = vec.size() - 1;

    heapSort(vec, size);

}