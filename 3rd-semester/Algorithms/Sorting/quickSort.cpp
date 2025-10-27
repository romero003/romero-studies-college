#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int> &vec, int l, int r){
    int p = vec[l];
    int i =l;
    int j = r +1;
    do{
        do{
            i++;
        }while(!((vec[i]>= p)|| (i >= r)));
        do{
            j--;
        }while(!(vec[j]<=p));

        int change = vec[i];
        vec[i] = vec[j];
        vec[j] = change;
        
    }while(!(i>=j));


        int change = vec[i];
        vec[i] = vec[j];
        vec[j] = change;


        int change = vec[l];
        vec[l] = vec[j];
        vec[j] = change;

        return j;

}

vector<int> quickSort(vector<int> &vec, int l, int r){
    if(l < r){
        int s = partition(vec, l, r);
        quickSort(vec, l, s-1);
        quickSort(vec, s+1, r);
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
        quickSort(vec, 0, n - 1); // Chama a função mergesort passando como parâmetros um vetor e a posição inicial e final do vetor que vai ser sort
        for(int w: vec){
            cout<<w<<"\n";
        }
    }
}