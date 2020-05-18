//#include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Cube{
    int lx;
    int ly;
    int lz;
    int xf;
    int yf;
    int zf;
    vector<vector<vector<pair<int,int>>>> cube;//.first é o da casa//.second é o max do caminho
public:

    Cube(int x, int y, int z, int fx, int fy, int fz){
        this->lx = x;
        this->ly = y;
        this->lz = z;
        this->xf = fx;
        this->yf = fy;
        this->zf = fz;
        this->cube.resize(x,vector<vector<pair<int,int>>>(y, vector<pair<int,int>>(z)));
    }

    void setPt(int x, int y, int z, int pt){
        cube[x][y][z].first = pt;
    }

    int function(int x, int y, int z){
        if(this->cube[x][y][z].second==0){//se eu ainda n calculei
            if(x==this->xf&&y==this->yf&&z==this->zf){//se eu já cheguei onde eu queria
                this->cube[x][y][z].second = this->cube[x][y][z].first;
            }else{
                int move[3];
                if((x-1)>=this->xf){
                    move[0] = function((x-1),y,z);
                }else{
                    move[0] = -1;
                }

                if((y+1)<=this->yf){
                    move[1] = function(x,(y+1),z);
                }else{
                    move[1] = -1;
                }

                if((z+1)<=this->zf){
                    move[2] = function(x,y,(z+1));
                }else{
                    move[2] = -1;
                }

                int resp = 0;

                for(int i = 0; i<3; i++){
                    if(resp<move[i]){
                        resp = move[i];
                    }
                }

                this->cube[x][y][z].second = this->cube[x][y][z].first + resp;
            }
            return this->cube[x][y][z].second;
        }else{//se eu já calculei
            return this->cube[x][y][z].second;
        }
    }

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    int y;
    int z;
    cin >> x;
    cin >> y;
    cin >> z;

    int xf;
    int yf;
    int zf;
    cin >> xf;
    cin >> yf;
    cin >> zf;

    Cube* map = new Cube(x,y,z, xf, yf, zf);

    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            for(int k = 0; k<z; k++){
                int aux;
                cin >> aux;
                map->setPt(i,j,k,aux);
            }
        }
    }

    int nPlayers;
    cin>>nPlayers;

    for(int i=0; i<nPlayers;i++){
        int xAux;
        int yAux;
        int zAux;

        cin >> xAux;
        cin >> yAux;
        cin >> zAux;
        cout << map->function(xAux, yAux, zAux) << endl;
    }

    return 0;
}
