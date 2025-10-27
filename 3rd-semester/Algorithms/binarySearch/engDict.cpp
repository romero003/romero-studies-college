#include <iostream>
#include <vector>
#include <string>

// aprender a declarar um array de tuplas
using namespace std;

int binarySearch(string element, vector<string> &vec){
    // Vai receber o elemento e retorja sua posição dentre os outros inteiros
    int l = 0;
    int r = vec.size() - 1;
    while (l <= r)
    {
        int m = (r+l)/2; // piso do elemento médio.
        if (vec[m] == element)
        {
            return 1;
        }
        else if (vec[m] < element) //Vou ter que mudar a lógica para encontrar as strings
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
        return 0;


    return l;
}

int main(){
    vector<string> vec;
    int wordAmount;
    cin>>wordAmount;
    string word;
    for(int i = 0; i<wordAmount; i++){
        cin>>word;
        vec.push_back(word);
    
    }
    int guessAmount;
    int guessedWord;
    int points = 0;
    for(int j = 0; j < guessAmount; j++){
        cin>>guessedWord;
        int found = binarySearch(word, vec);
        points = points + found;

    }
    
}
