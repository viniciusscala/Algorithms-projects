#include "/usr/local/include/bits/stdc++.h"
//#include <bits/stdc++.h>
#define endl '\n'

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
        
        
        
    }
    return 0;
}
