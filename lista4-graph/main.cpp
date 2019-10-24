#include <bits/stdc++.h>
#include <string>
#define endl '\n'

using namespace std;

class Vertice{
public:


    class Line{
    public:
        Vertice* val;
        Line* next;
        int size;

        Line(){
            this->val = nullptr;
            this->next = nullptr;
            this->size = -1;
        }

        Line(Vertice* node){
            this->val= node;
            this->next = nullptr;
            this->size = -1;
        }

        void in(Vertice* node, int* tam){//vou botar no final
            if(this->next==nullptr){
                this->next = new Line(node);
                *tam = *tam +1;
            }else{
                this->next->in(node, tam);
            }
        }

        Vertice* out(int* tam){//tir do comeco
            Vertice* aux = this->next->val;
            this->next = this->next->next;
            *tam = *tam -1;
            return aux;
        }

        void takeOff(Vertice* node, int* tam){
            if(this->next != nullptr && this->next->val->name == node->name){
                if(this->next->next!= nullptr){
                    this->next = this->next->next;
                }else{
                    this->next = nullptr;
                }
                *tam = *tam -1;
            }else{
                this->next->takeOff(node, tam);
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

        Vertice* getFirst(){
            return this->next->val;
        }

    };

    string name;
    Line* line;
    Line lineAux;
    string collor;

    Vertice(string name){
        this->name = name;
        this->line = new Line();
        this->collor = "white";
    }


    bool deadLockAux(stack<Vertice*> pilha, stack<Vertice*> limpar, Vertice* parametro, bool teste, map<Vertice*, bool> exist){
//        if(this->collor=="white"){
//
//        }else if(this->collor=="gray"){
//
//        }else if(this->collor=="black"){
//
//        }


        if(exist.count(this)&&exist[this]){//se eu achei um babado que ta na pilha
            return true;
        }else if(!this->lineAux.isFree()){//se ainda tem apontador
            Vertice* aux = this->lineAux.out(&this->lineAux.size);//pega o primeiro da fila
            pilha.push(aux);//bota o primeiro na fila
            exist[aux] = true;
            return pilha.top()->deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
        }else if(this->lineAux.isFree()){//se a fila ta vazia//n aponta mais p ngm
            if(teste&&this->name==parametro->name){
                return false;
            }else if(this->name==parametro->name){
                return false;
            }else{
                Vertice* aux1 = pilha.top();
                pilha.pop();
                exist[aux1] = false;
                return pilha.top()->deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
            }
        }


        //e se ele verifica um que ja n aponta p ngm?


        //se eu voltei p o primeiro e n achei ele// retorna false

    }


    bool deadlock(){
        stack<Vertice*> pilha;
        stack<Vertice*> limpar;
        this->lineAux = *this->line;
        map<Vertice*, bool> exist;
        this->deadLockAux(pilha, limpar, this, false, exist);

    }
};

class SistemaOperacional{
public:
    vector<Vertice> processos;//array de processos// um elemento desse array tem o nome do proceso e ua fila de recursos que ele está usando
    vector<Vertice> recursos;// array de recursos// um elemento desse assay tem o nome do recurso e a fila de processos que querem usar ele (ps: o primeiro é o que esta usando)
    map<string, int> m;

    SistemaOperacional(){
        this->processos;
        this->recursos;
        this->m;
    }

    void req(string p, string r){ //processo solicita recurso
        if(m.count(p)&&m.count(r)){//se o processo e o recurso já existem
            Vertice* recurso = &this->recursos[this->m[r]];
            Vertice* processo = &this->processos[this->m[p]];

            if(recurso->line->isFree()){//recurso esta livre // o processo consegue o recurso
                recurso->line->in(processo, &recurso->line->size);
                processo->line->in(recurso, &processo->line->size);
                cout << "AVAIL" << endl;
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                recurso->line->in(processo, &recurso->line->size);
                cout << "WAIT " << recurso->line->size << endl;
            }

        }else if(m.count(p)){//se o processo ja existe
            Vertice* recurso = new Vertice(r);
            Vertice* processo = &this->processos[this->m[p]];
            recursos.push_back(*recurso);/////////////////////////////////////////////////////////// talvez aqui de problema com o apontador e etc
            m[r] = recursos.size()-1;

            recurso->line->in(processo, &recurso->line->size);
            processo->line->in(recurso, &processo->line->size);

            cout << "AVAIL" << endl;

        }else if(m.count(r)){//se o recurso ja existe
            Vertice* recurso = &this->recursos[this->m[r]];
            Vertice* processo = new Vertice(p);
            processos.push_back(*processo);
            m[p] = processos.size()-1;

            if(recurso->line->isFree()){//recurso esta livre // o processo consegue o recurso
                recurso->line->in(processo, &recurso->line->size);
                processo->line->in(recurso, &processo->line->size);
                cout << "AVAIL" << endl;
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                recurso->line->in(processo, &recurso->line->size);
                cout << "WAIT " << recurso->line->size << endl;
            }

        }else{//se nenhum dos 2 existem
            Vertice* recurso = new Vertice(r);
            Vertice* processo = new Vertice(p);
            recursos.push_back(*recurso);
            m[r] = recursos.size()-1;
            processos.push_back(*processo);
            m[p] = processos.size()-1;

            recurso->line->in(processo, &recurso->line->size);
            processo->line->in(recurso, &processo->line->size);

            cout << "AVAIL" << endl;

        }
    }

    void fre(string p){
        if(m.count(p)){//se p existe
            int tamanho = processos[m[p]].line->size;
            int cont = 0;
            while(processos[m[p]].line->size!=-1){
                Vertice* recurso = processos[m[p]].line->out(&processos[m[p]].line->size);//se aqui só tira os que ele ja tem, o recurso sempre vai estar em uso
                //tenho que ver se o processo já estava com o recurso ou nao
                Vertice* processo = recurso->line->out(&recurso->line->size);
                if(!recurso->line->isFree()){
                    processo = recurso->line->getFirst();
                    processo->line->in(recurso, &processo->line->size);
                }
                cont++;
            }
            cout << "TERM " << cont << endl;
        }
    }

    void dlk(string p){
        if(processos[m[p]].deadlock()){//se tiver deadlock
            this->fre(p);//tem que mudar alguma coisinha
        }else{
            cout<< "NONE" <<endl;
        }
    }

};

//o recurso só aponta para um lugar, ou seja, o que está usando ele

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SistemaOperacional* so = new SistemaOperacional();//ta dando um erro aqui

    string func;
    string p;
    string r;

    cin >> func;

    while(func!="END"){

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
