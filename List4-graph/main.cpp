//#include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>
#include <string>
#define endl '\n'

using namespace std;

class Vertice{
public:

    string name;
    list<Vertice*> in;
    list<Vertice*> out;


    Vertice(string name){
        this->name = name;
    }

    void point(Vertice* s){
        this->out.push_back(s);//o primeiro aponta
        s->in.push_back(this);//o segundo recebe
        if(this->name[0]=='R'){//se for um recurso apontando p um processo
            s->out.remove(this);//tira esse recurso da lista de coisas que o processo quer
        }
    }

    void cut(Vertice* s){
        this->out.remove(s);//o primeiro para de apontar p o segundo
        s->in.remove(this);//o segundo para de receber o primeiro
        if(this->name[0]=='R'){//se for um recurso parando de apontar p um processo eu tenho que verificar se tem outro processo querendo esse recurso
            if(this->in.size()>0){//se tiver processos na fila de espera do recurso
                Vertice* novoProcesso = this->in.front();//pega o primeiro processo da fila
                this->in.pop_front();//tira ele da fila de espera
                this->point(novoProcesso);//e da o recurso p ele
            }
        }
    }

    bool dlk(){
        stack<Vertice*> pilha;
        unordered_map<string, string> cor;

        pilha.push(this);
        cor[this->name]="grey";

        return dlkAux(pilha, cor);
    }

    bool dlkAux(stack<Vertice*> pilha, unordered_map<string, string> cor){

        for(auto ptr: pilha.top()->out){
            if(cor[ptr->name]=="grey"){//se o prox for cinza, retorna true
                return true;
            }else if(cor[ptr->name]==""){//se o prox for branco, entra nele
                pilha.push(ptr);
                cor[ptr->name]="grey";
                return ptr->dlkAux(pilha, cor);
                break;
            }
//            string teste = cor[ptr];
//            cout << teste << endl;
        }//se chegar aqui, é pq só tem preto

        cor[this->name]="black";
        pilha.pop();
        if(pilha.size()>0){
            return pilha.top()->dlkAux(pilha, cor);
        }else{
            return false;
        }


    }

};


class SistemaOperacional{
    unordered_map<string, Vertice*> recurso;
    unordered_map<string, Vertice*> processo;

public:

    void req(string p, string r){
        if(!processo.count(p)){//se o processo ainda nexiste
            processo[p] = new Vertice(p);
        }
        if(!recurso.count(r)){//se o recurso ainda n existe
            recurso[r] = new Vertice(r);
        }
        if(this->recurso[r]->out.empty()){//se o recurso está livre// o processo consegue o recurso
            this->recurso[r]->point(processo[p]);
            cout << "AVAIL" << endl;
        }else{//se o recurso já está em uso
            this->processo[p]->point(recurso[r]);
            cout << "WAIT " << this->recurso[r]->in.size() << endl;
        }
    }

    void fre(string p){
        if(processo.count(p)){//se o processo exxiste
            int cont = processo[p]->in.size() + processo[p]->out.size();
            while(processo[p]->in.size()>0){//enquanto ainda tiver recurso apontando p o recurso
                Vertice* recurso = processo[p]->in.front();//pega o recurso que ele estava usando
                recurso->cut(processo[p]);
            }
            while(processo[p]->out.size()>0){//enquanto ele ainda quiser recursos
                Vertice* recurso = processo[p]->out.front();
                processo[p]->cut(recurso);
            }
            cout << "TERM " << cont << endl;
        }
    }

    void dlk(string p){
        if(processo[p]->dlk()){
            if(processo.count(p)){//se o processo exxiste
                int cont = processo[p]->in.size();
                int contR = processo[p]->out.size();
                while(processo[p]->in.size()>0){//enquanto ainda tiver recurso apontando p o recurso
                    Vertice* recurso = processo[p]->in.front();//pega o recurso que ele estava usando
                    recurso->cut(processo[p]);
                }
                while(processo[p]->out.size()>0){//enquanto ele ainda quiser recursos
                    Vertice* recurso = processo[p]->out.front();
                    processo[p]->cut(recurso);
                }
                cout << "KILL " << cont << " " << contR << endl;
            }
        }else{
            cout<< "NONE" <<endl;
        }
    }
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SistemaOperacional* so = new SistemaOperacional();//ta dando um erro aqui

    string func;
    string p;
    string r;

    cin >> func;

    int cont = 0;

    while(func!="END"){
        cont++;
        //cout << cont << endl;
        if(func == "REQ"){
            cin >> p;
            cin >> r;
            so->req(p, r);
        }else if(func == "FRE"){
            cin >> p;
            so->fre(p);
        }else if(func == "DLK"){
            cin >> p;
            so->dlk(p);
        }
        cout.flush();
        cin >> func;
    }

    return 0;
}
