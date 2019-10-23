#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Vertice{

    class Line{
        Vertice* val;
        Line* next;

        Line(){
            this->val = nullptr;
            this->next = nullptr;
        }

        Line(Vertice* node){
            this->val= node;
            this->next = nullptr;
        }

        void in(Vertice* node){//vou botar no final
            if(this->next==nullptr){
                this->next = new Line(node);
            }else{
                this->next->in(node);
            }
        }

        Vertice* out(){//tir do comeco
            Vertice* aux = this->next->val;
            this->next = this->next->next;
            return aux;
        }

        void takeOff(Vertice* node){
            if(this->next != nullptr && this->next->val->name == node->name){
                this->next = this->next->next;
            }else{
                this->next->takeOff(node);
            }
        }

    };

    string name;
    Line* ptr;

    Vertice(string name, Line* ptr){
        this->name = name;
        this->ptr = ptr;
    }
};

class SistemaOperacional{
    vector<Vertice> processos;//array de processos// um elemento desse array tem o nome do proceso e ua fila de recursos que ele está usando
    vector<Vertice> recursos;// array de recursos// um elemento desse assay tem o nome do recurso e a fila de processos que querem usar ele (ps: o primeiro é o que esta usando)
    map<string, int> map;

    void req(string p, string r){//processo solicita recurso
        if(map.count(p)&&map.count(r)){//se o processoe o recurso já existem
            processos[p]
        }else if(map.count(p)){//se o processo ja existe

        }else if(map.count(r)){//se o recurso ja existe

        }else{//se nenhum dos 2 existem

        }
    }

    void fre(){

    }

    void dlk(){

    }

};

//o recurso só aponta para um lugar, ou seja, o que está usando ele

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SistemaOperacional oi;

    return 0;
}