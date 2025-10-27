// Existem n poções em linha 1 na esquerda e n na direita
//  Cada poção vai aumentar a vida em ai
// Pode decrescer a vida

// Começa com 0 e anda da esquerda para a direita
// Pode beber ou não beber
//  Se assegurar que a vida nã é negativa

// Qual o maior número de poções que eu posso beber?
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

void topDown(vector<int> &vec, int n, int a){

    bool heap = false;
    vec.push_back(a);
    int sz = vec.size() -1;
    int index = sz;
    while(heap == false){
        int rt = index/2;
        if(rt == 0){
            break;
        }
        if(vec[rt] > vec[index]){
            swap(vec[rt], vec[index]);
        }else{
            heap = true;
        }
        index = rt;
    }


    
    
}
//Mudar para top down
void bottomUp(vector<int> &vec, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        int k = i;
        int v = vec[k];
        bool heap = false;

        while (!heap && 2 * k <= n)
        {
            int j = 2 * k;
            if (j < n)
            {
                if (vec[j] >= vec[j + 1])
                {
                    j++;
                }
            }
            if (v < vec[j])
            {
                heap = true;
            }
            else
            {
                vec[k] = vec[j];
                k = j;
            }
        }
        vec[k] = v;
    }
}

void heapfy(vector<int> &vec, int n)
{
    int k = 1;
    int v = vec[k];
    bool heap = false;

    while (!heap && 2 * k <= n)
    {
        int j = 2 * k;
        if (j < n)
        {
            if (vec[j] >= vec[j + 1])
            {
                j++;
            }
        }
        if (v <vec[j])
        {
            heap = true;
        }
        else
        {
            vec[k] = vec[j];
            k = j;
        }
    }
    vec[k] = v;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int bottles = n;
    int poison = 0;
    long long life = 0;
    int d = poison;
    vector<int> heap;

    int totalPotions = 0;
    heap.push_back(999999);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        //Vai tentar beber a poção
        life = life + a;
        if (a < 0)
        {
            topDown(heap, d, a); 
            poison++;
            d++;
        }
        //Maybe its wrong

        if (life < 0 and poison >= 1)
        {
            life = life - heap[1];
            swap(heap[1], heap[d]);
            heap.pop_back();
            heapfy(heap, --d);
            bottles--;
        }
    }


    

    cout << bottles;
}