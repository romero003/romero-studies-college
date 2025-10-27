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

        vector<int> temp = vec; //Refatorar mergesort
        
        m = (l + r) / 2; 
        int i1 = l;      
        int i2 = m + 1;  
        for (int cur = l; cur <= r; cur++)
        {
            if (i1 == m + 1){                          
                vec[cur] = temp[i2++]; 
            }
            else if (i2 > r){
                vec[cur] = temp[i1++]; 
            }
            else if (temp[i1] <= temp[i2]){
                vec[cur] = temp[i1++]; 
            }
            else {
                vec[cur] = temp[i2++];
            }
        }
        
    }
    //for(int i: vec){
        //cout<<i<<endl;
    //}
}



int bSearch(int element, vector<int> &vec){
    // Vai receber o elemento e retorja sua posição dentre os outros inteiros
    int l = 0;
    int r = vec.size() - 1;
    int upperBoundIndex = -1;
    while (l <= r) // Enquanto l e r não tiverem se ultrapassado
    {
        int m = (r+l)/2; 
        if (vec[m] <= element) //Se o item for menor ou igual ao elemento: quer dizer que não foi encontrado um item maior. É necessário procurá-lo do lado direito de vec
        {
            l = m +1;
        }
        else{ // O item é maior, mas agora preciso ver se existe algum outro menor do que ele do lado esquerdo do array
            r = m -1; //Se o item procurado for maior que o elemento
            upperBoundIndex = m;
        }
        
        

    }
        
    //Se eu não achei um upper bound, quer dizer que todos os elementos são menores ou iguais que o elemento
    if(upperBoundIndex == -1){
        return vec.size();
    }

    //Se eu achei, quer dizer que o elemento é anterior a upperBound
    return (upperBoundIndex);
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
        cout<<cheapShops<<"\n";
    }
}