#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


class SistemaOperacional{
    vector<vector<int>> processos(1);//arestas que saem de processos
    vector<int>recursos(1);//arestas que saem de recursos (Só pode ter 1 por recurso)


    void req(int p, int r){

    }

    void fre(){

    }


};

//o recurso só aponta para um lugar, ou seja, o que está usando ele

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SistemaOperacional oi;


    vector<int> teste(1, -1);
    teste.push_back(6);
    teste.push_back(5);
    teste.push_back(4);
    cout<< teste[2];
    cout.flush();
    return 0;
}