#include <iostream>
#include <vector>

using namespace std;



void mergesort(vector<int> &vec, int l, int r)
{ 
    if (l < r)
    {
        int m = (l + r) / 2;      
        mergesort(vec, l, m);     
        mergesort(vec, m + 1, r);

        vector<int> temp = vec;
        
        m = (l + r) / 2; 
        int i1 = l;      
        int i2 = m + 1;  
        for (int cur = l; cur <= r; cur++)
        {
            if (i1 == m + 1)
            {                          
                vec[cur] = temp[i2++]; 
            }
            else if (i2 > r)
            {
                vec[cur] = temp[i1++]; 
            }
            else if (temp[i1] <= temp[i2])
            {
                vec[cur] = temp[i1++]; 
            }
            else 
            {
                vec[cur] = temp[i2++];
            }
        }
        
    }
}


int bSearch(int element, vector<int> &vec){
    int l = 0;
    int size = vec.size();
    int r = size-1;

    //O tamanho do array é um ( se for menor, não conta, se for maior ou igual, conta)
    if(size == 1){
        if(vec[0]< element){
            return 0;
        }else{
            return 1;
        }
    }

    while(l <= r){
        //Encontrei o elemento. retorna o índice + 1 que corresponde a quantidade
        int m = (l+r)/2;
        if((m == size -1 && vec[m] == element) || (vec[m] == element && vec[m+1] > element)){//Se o elemento for o último do array e se o elemento for o último
            return m + 1;
        }else if(element < vec[m]){
            r = m - 1;
        }else if(element == vec[m+1]){ //Se o elemento for igual a m+1
            l = m + 1;
        }else{
            r = m -1;
        }
    }

    //Não encontrei o elemento. Devo encontrar o inteiro mais próximo menor do que elemento. Ele terá índice r ou índice l, a não ser que l e r sejam ambos maiores que o elemento
        if(abs(vec[l] - element) < abs(vec[r] - element)){ 
            return l;
        }
        return (r+1);

    return 0;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int price;
    vector<int> prices;
    for(int i = 0; i<n; i++){
        cin>>price;
        prices.push_back(price);
    }

    mergesort(prices, 0, (prices.size()-1));
    int q;
    cin>>q;
    int budget;
    int cheapShops;
    for(int j=0; j < q; j++){
        cin>>budget;
        cheapShops = bSearch(budget, prices);
        cout<<cheapShops<<endl;
    }
}