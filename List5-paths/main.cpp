//#include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>
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
            aux.second = (aux.second*-1);
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

    void path(vector< vector< vector<pair<int,int>> > > table){
        int atual = table.size()-1;//pega o ultimo//ou seja, a chegada
        vector<int> way;//[num da possibilidade][vertices que formam o caminho]
        way.push_back(atual);//bota o finl em todos os caminho

        way = pathAux(table, way, atual);//aqui eu recebo um array bidimensional c todos os caminhos possiveis

        for(int i = (way.size()-1); i>=0; i--){
            cout << " " << way[i] ;
        }
    }

    vector<int> pathAux(vector< vector< vector<pair<int,int>> > > table, vector<int> way, int atual){
        if(atual == 0){
            return way;
        }else{//tenho que ajeitar isso aqui ainda
            int min = INF;
            int index;
            for(int i = 0; i<table[atual][1].size(); i++){//percorre todas as possibilidades
                if(table[atual][1][i].first<min){
                    min = table[atual][1][i].first;
                    index = i;
                }
            }
            atual = table[atual][1][index].first;
            way.push_back(atual);
            return pathAux(table, way, atual);

            //vou ter que botar o return aqui
            return way;
        }
    }

    void bellman_ford(){//eu quero sempre sair do 0 e sempre chegar no size()-1
        bool cicle = false;
        int tam = int(this->fase.size());
        //vou ter que fazer um vector [tam][2]
        vector< vector< vector< pair<int,int> > > > table;
        table.resize(tam);
        for(int i = 0; i<tam; i++){//comeca em 1 pq a distancia p o 0 vi ser sempre 0 já que eu começo por ele
            table[i].resize(2);
            if(i>0){//coloco infinito em todos menos no que eu estou
                pair<int,int> aux;
                aux.first = INF;
                table[i][0].push_back(aux);
                table[i][1].push_back(aux);
            }else{
                pair<int,int> aux;
                aux.first = 0;
                table[i][0].push_back(aux);
                table[i][1].push_back(aux);
            }
        }//até aqui é só p montar a tabela

        //[O vertice que eu estou olhando][se 0)distania min se2)de onde veio][só aparece quando o segundo é 1)possibilidade de vinda]/


        //agora só falta ajeitar p ele armazenar a quantidade de vertices
        //vertice que eu quero chegar//possibilidade

        for(int k = 1; k<tam;k++){//vai repetir n-1 vezes
            for(int i = 0; i<tam; i++){//vai percorrer todos os vertices// i é o vertice que eu to
                if(table[i][1][0].first!=INF){//se eu sei chegar nele de algum jeito
                    for(auto ptr: fase[i]->edges){//isso sai as arestas do vertice i//ptr é o vertice que eu vou
                        //eu vou fazer a distancia do que eu estou, mais a distancia do qual eu vou
                        if((table[i][0][0].first+ptr.second)<table[ptr.first->name][0][0].first){//se eu  consigo chegar no vertice com menos do que está na tabela, atualiza a tabela
                            table[ptr.first->name][0][0].first = (table[i][0][0].first+ptr.second);
                            table[ptr.first->name][1].clear();
                            pair<int,int> aux;
                            aux.first=i;
                            aux.second = table[i][1][0].second+1;//talvez isso esteja errdo
                            table[ptr.first->name][1].push_back(aux);
                        }else if(((table[i][0][0].first+ptr.second)==table[ptr.first->name][0][0].first)){
//                            if(count(table[ptr.first->name][1].begin(), table[ptr.first->name][1].end(), i)==0){//se esse i ainda n está contido no array//vou ter que ajeitar isso ainda
//                                //aqui ele vai ter que ver qual tem menos vertices
//                                if(){
//
//                                }
//                                table[ptr.first->name][1].push_back(i);
//                            }
                            if(table[ptr.first->name][1][0].second<(table[i][1][0].second+1)){//se o novo tem mais vertices
                                //faz nada
                            }else if(table[ptr.first->name][1][0].second==(table[i][1][0].second+1)){//se o novo tem a msm quantidade de vertices
                                //adiciona
                                pair <int,int> aux;
                                aux.first=i;
                                aux.second = table[ptr.first->name][1][0].second;
                                if(count(table[ptr.first->name][1].begin(), table[ptr.first->name][1].end(), aux)==0){
                                    table[ptr.first->name][1].push_back(aux);
                                }
                            }else{//se o novo tem menos vertices
                                //substitui
                                table[ptr.first->name][1].clear();
                                pair<int,int> aux;
                                aux.first=i;
                                aux.second = table[i][1][0].second+1;//talvez isso esteja errdo
                                table[ptr.first->name][1].push_back(aux);
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i<tam; i++){//vai percorrer todos os vertices// i é o vertice
            if(table[i][1][0].first!=INF){
                for(auto ptr: fase[i]->edges){//isso sai as arestas do vertice i
                    //eu vou fazer a distancia do que eu estou, mais a distancia do qual eu vou
                    if((table[i][0][0].first+ptr.second)<table[ptr.first->name][0][0].first){//se eu  consigo chegar no vertice com menos do que está na tabela, atualiza a tabela
                        cicle=true;
                    }
                }
            }
        }
        if(cicle){
            cout << "LOOP" << endl;
        }else{
            cout << table[this->fase.size()-1][0][0].first;
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
