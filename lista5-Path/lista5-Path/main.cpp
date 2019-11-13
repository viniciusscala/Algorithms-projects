#include "/usr/local/include/bits/stdc++.h"
//#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3fffffff

using namespace std;

class Vertice{
public:
    int name;
    pair<int, int> coord;
    list< pair<Vertice*, int> > edges;
    bool haveCoin;

    Vertice(int x, int y, int name){
        this->coord.first = x;
        this->coord.second = y;
        this->name = name;
        this-> haveCoin = false;
    }

    void coin(){
        this->haveCoin = true;
    }

    void point(Vertice* ver){
        pair<Vertice*, int> aux;
        aux.first = ver;
        aux.second = (((ver->coord.first-this->coord.first)*(ver->coord.first-this->coord.first))+((ver->coord.second-this->coord.second)*(ver->coord.second-this->coord.second)));
        if(ver->haveCoin){
            //aux.second = (aux.second-25);
            aux.second = -25;
        }
        this->edges.push_back(aux);
    }

};

class Game{
    vector<Vertice*> fase;

public:

    void clear(){
        this->fase.clear();
    }

    void insert(int x, int y){
        int nameAux = (int)this->fase.size();
        Vertice* aux = new Vertice(x,y,nameAux);
        fase.push_back(aux);
    }

    void coin(int index){
        this->fase[index]->coin();
    }

    void edge(int a, int b){
        this->fase[a]->point(this->fase[b]);
    }

    void path(vector< vector<int> > table){
        int atual = table.size()-1;
        vector< int > way;
        way.push_back(atual);
        way = pathAux(table, way, atual);
        for(int i = (way.size()-1); i>=0; i--){
            cout << way[i] << " ";
        }
    }

    vector<int> pathAux(vector< vector<int> > table, vector< int > way, int atual){
        if(atual == 0){
            return way;
        }else{
            atual = table[atual][1];
            way.push_back(atual);
            return pathAux(table, way, atual);
        }
    }

    void bellman_ford(){//eu quero sempre sair do 0 e sempre chegar no size()-1
        bool cicle = false;
        int tam = int(this->fase.size());
        //vou ter que fazer um vector [tam][2]
        vector< vector<int> > table;
        table.resize(tam);
        for(int i = 0; i<tam; i++){//comeca em 1 pq a distancia p o 0 vi ser sempre 0 já que eu começo por ele
            table[i].resize(2);
            if(i>0){//coloco infinito em todos menos no que eu estou
                table[i][0]=INF;
                table[i][1]=INF;
            }
        }

        for(int k = 1; k<tam;k++){//vai repetir n-1 vezes
            for(int i = 0; i<tam; i++){//vai percorrer todos os vertices// i é o vertice
                if(table[i][1]!=INF){
                    for(auto ptr: fase[i]->edges){//isso sai as arestas do vertice i
                        //eu vou fazer a distancia do que eu estou, mais a distancia do qual eu vou
                        if((table[i][0]+ptr.second)<table[ptr.first->name][0]){//se eu  consigo chegar no vertice com menos do que está na tabela, atualiza a tabela
                            table[ptr.first->name][0] = (table[i][0]+ptr.second);
                            table[ptr.first->name][1] = i;
                        }
                    }
                }
            }
        }
        for(int i = 0; i<tam; i++){//vai percorrer todos os vertices// i é o vertice
            if(table[i][1]!=INF){
                for(auto ptr: fase[i]->edges){//isso sai as arestas do vertice i
                    //eu vou fazer a distancia do que eu estou, mais a distancia do qual eu vou
                    if((table[i][0]+ptr.second)<table[ptr.first->name][0]){//se eu  consigo chegar no vertice com menos do que está na tabela, atualiza a tabela
                        cicle=true;
                    }
                }
            }
        }
        if(cicle){
            cout << "LOOP" << endl;
        }else{
            cout << table[this->fase.size()-1][0] << " ";
            path(table);
            cout << endl;
        }
    }

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lvl;
    cin >> lvl;

    for(int i = 0; i<lvl; i++){//para cara lvl
        Game game;
        game.clear();

        int places;
        cin>>places;
        for(int j = 0; j<places; j++){//p adicionar as casas
            int x;
            int y;
            cin >> x;
            cin >> y;
            game.insert(x, y);
        }

        int coins;
        cin>>coins;
        for(int j = 0; j<coins; j++){//moedas// ele vai dar o nome das casas que tem moeda
            int aux;
            cin >> aux;
            game.coin(aux);
        }

        int edges;
        for(int j = 0; j<places; j++){
            cin >> edges;
            for(int k = 0; k<edges; k++){
                int end;
                cin>>end;
                game.edge(j, end);
            }
        }//acabou a parte de pegar a entrada

        game.bellman_ford();

    }
    return 0;
}
