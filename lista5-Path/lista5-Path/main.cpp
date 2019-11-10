#include "/usr/local/include/bits/stdc++.h"
//#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Vertice{
    int name;
    pair<int, int> coord;
    list< pair<Vertice, int> > edges;
public:
    Vertice(int x, int y, int name){
        this->coord.first = x;
        this->coord.second = y;
        this->name = name;
    }
};

class Game{
    vector<Vertice*> fase;
    
    void insert(int x, int y){
        int nameAux = 6;
        Vertice* aux = new Vertice(x,y,nameAux);
        fase.push_back(aux);
    }
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lvl;
    cin >> lvl;
    
    for(int i = 0; i<lvl; i++){//para cara lvl
        int places;
        for(int j = 0; j<places; j++){
            int x;
            int y;
            cin >> x;
            cin >> y;
            
        }
    }
//no final de cada fase eu uso um vector .clear
    return 0;
}
