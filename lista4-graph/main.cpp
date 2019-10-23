#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Vertice{
public:


    class Line{
    public:
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

        bool exist(Vertice* node){
            if(this->next == nullptr){
                return false;
            }else if(this->next->val->name == node->name){
                return true;
            }else{
                return this->next->exist(node);
            }
        }

        bool isFree(){
            if(this->next==nullptr){
                return true;
            }else{
                return false;
            }
        }

    };

    string name;
    Line* line;

    Vertice(string name){
        this->name = name;
        this->line = new Line();
    }
};

class SistemaOperacional{
    vector<Vertice> processos;//array de processos// um elemento desse array tem o nome do proceso e ua fila de recursos que ele está usando
    vector<Vertice> recursos;// array de recursos// um elemento desse assay tem o nome do recurso e a fila de processos que querem usar ele (ps: o primeiro é o que esta usando)
    map<string, int> map;

    void req(string p, string r){//processo solicita recurso
        if(map.count(p)&&map.count(r)){//se o processo e o recurso já existem
            Vertice* recurso = &this->recursos[this->map[r]];
            Vertice* processo = &this->processos[this->map[p]];
            if(recurso->line->isFree()){//recurso esta livre // o processo consegue o recurso
                recurso->line->in(processo);
                processo->line->in(recurso);
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                recurso->line->in(processo);
            }
        }else if(map.count(p)){//se o processo ja existe
            Vertice* recurso = new Vertice(r);
            Vertice* processo = &this->processos[this->map[p]];
            recursos.push_back(*recurso);
            map[r] = recursos.size()-1;

            recurso->line->in(processo);
            processo->line->in(recurso);

        }else if(map.count(r)){//se o recurso ja existe
            Vertice* recurso = &this->recursos[this->map[r]];
            Vertice* processo = new Vertice(p);
            processos.push_back(*processo);
            map[p] = processos.size()-1;

            if(recurso->line->isFree()){//recurso esta livre // o processo consegue o recurso
                recurso->line->in(processo);
                processo->line->in(recurso);
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                recurso->line->in(processo);
            }

        }else{//se nenhum dos 2 existem
            Vertice* recurso = new Vertice(r);
            Vertice* processo = new Vertice(p);
            recursos.push_back(*recurso);
            map[r] = recursos.size()-1;
            processos.push_back(*processo);
            map[p] = processos.size()-1;

            recurso->line->in(processo);
            processo->line->in(recurso);

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