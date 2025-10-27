using namespace std;
#include <vector>
#include <iostream>

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



int count(vector<int>& vec, int n, int c){
    int d = n;
    int currentOrbit = 1;
    int counter = 0;
    int totalPrice = 0;


    bottomUp(vec, n);

    

    while(d>=1){

        if(vec[1] != currentOrbit){
            if(counter >= c){
                totalPrice = totalPrice + c;
            }else{
                totalPrice = totalPrice + counter;
            }
            counter = 0;
        }

        while(currentOrbit != vec[1]){
            currentOrbit++;
        }
        
        counter++;

        swap(vec[1], vec[d]);
        heapfy(vec, --d);
    }
    if(counter > 0){
        if(counter >= c){
                totalPrice = totalPrice + c;
            }else{
                totalPrice = totalPrice + counter;
            }
    }
    
    return totalPrice;
}



int main(){
    int t;
    cin>>t;

    for(int i = 0; i<t; i++){
        //cout<<i+1<< "° caso!"<<endl;
        int n;
        cin>>n;
        int c;
        cin>>c;

        vector<int> vec;
        vec.push_back(-1);
        for(int j=0; j<n; j++){
            
            int a;
            cin>>a;
            vec.push_back(a);
        }
        int price = count(vec, n, c);
        cout<<price<<endl;
    }
}