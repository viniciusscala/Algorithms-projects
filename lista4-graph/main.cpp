#include "/usr/local/include/bits/stdc++.h"
//#include <bits/stdc++.h>
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
            if(this->next==nullptr){
                return nullptr;
            }else{
                return this->next->val;
            }

        }

        void clear(){
            this->next = nullptr;
        }

        void clear1(){
            if(this->next!=nullptr){
                this->next->next = nullptr;//quando ele cria uma copia, ele so cria a copia da cabeca, como o resto é apontador, ele usa o apontador do aux e do normal
            }
        }

        Line clone(Line* aux){

            //a fila sempre tem o primeiro mas ele n importa

            if(this->next==nullptr){//clona o atual e para

            }else{//clona o atual e da o passo recursivo
                aux->val = this->val;
                aux->next = this->next;//isso n vai dar certo, ele só vai copar o apontador

                //eu tenho que sair dando new

                this->next->clone(aux->next);
            }

        }//ele vai retornar a cabeça p a nova lista

    };

    string name;
    Line* line;
    Line* want;
    Line* wantAux;
    Line* lineAux;
    string collor;

    Vertice(string name){
        this->name = name;
        this->line = new Line();
        this->collor = "white";
        this->want = new Line();
    }


//    bool deadLockAux(stack<Vertice*> pilha, stack<Vertice*> limpar, Vertice* parametro, bool teste, map<Vertice*, string> exist){
//
//        //processo -> usa o want
//        //eu posso criar um vector de apontador de fila//ou talvez uma pilha
//
//        Line* apontador;
//
//        if(this->name[0]=='P'){//se for processo
//            apontador = this->want;
//            if(!apontador->isFree()){//se ainda tem apontador
//                Vertice* aux = apontador->getFirst();//pega o primeiro da fila//tenho que parr de usar esse out
//                apontador = apontador->next;
//                pilha.push(aux);//bota o primeiro na fila
//                exist[aux] = "grey";
//                Vertice proxR = *pilha.top();
//               proxR.lineAux = *proxR.line;//tenho que mudar isso aqui
//                proxR.lineAux.clear1();//deixa so o 1
//                if(!proxR.line->isFree()&&exist.count(proxR.line->getFirst())&&exist[proxR.line->getFirst()]=="grey"){
//                    return true;
//                }else{
//                    return proxR.deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
//                }
//            }else{//se n aponta p mais ngm
//                Vertice* aux1 = pilha.top();
//                pilha.pop();
//                exist[aux1] = "black";
//                if(pilha.size()==0){//se a pilha acabou, retorna falso
//                    return false;
//                }else{
//                    return pilha.top()->deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
//                }
//            }
//
//            //recurso -> usa o line.getfirst
//        }else{//se for recurso
//            apontador = this->line;
//            if(!apontador->isFree()){//se ainda tem apontador
//                Vertice* aux = this->lineAux.out(&this->lineAux.size);//pega o primeiro da fila
//                pilha.push(aux);//bota o primeiro na pilha
//                exist[aux] = true;
//                Vertice* proxP = pilha.top();
//                proxP->wantAux = *proxP->want;
//                if(!proxP->wantAux.isFree()&&exist.count(proxP->wantAux.getFirst())&&exist[proxP->wantAux.getFirst()]){
//                    return true;
//                }else{
//                    return proxP->deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
//                }
//            }else{//se n aponta p mais ngm
//                Vertice* aux1 = pilha.top();
//                pilha.pop();
//                exist[aux1] = false;
//                if(pilha.size()==0){
//                    return false;
//                }else{
//                    return pilha.top()->deadLockAux(pilha, limpar, parametro, true, exist);//faz recursivamente com o ultimo da pilha
//                }
//            }
//        }
//
//
//
//    }

    //(exist.count(proxR)&&exist[proxR]=="grey")

    //o prox é r6

    bool deadlockAux1(stack<Line*> pilha, Vertice* parametro, map<Vertice*, string> exist){//eu to adicionando o primeiro recurso sem verificar
        if(this->name[0]=='P'){//se for processo
            if(!pilha.top()->isFree()){//se ainda tem coisa apontando
                Vertice* proxR = pilha.top()->getFirst();//pega o primeiro da fila//tenho que parr de usar esse out
                if(exist[proxR]=="grey"){
                    return true;
                }else{
                    pilha.push(proxR->line);//bota o primeiro na fila
                    exist[proxR] = "grey";
                    return proxR->deadlockAux1(pilha,parametro,exist);//faz recursivamente com o ultimo da pilha
                }
//                pilha.push(proxR->line);//bota o primeiro na fila
//                exist[proxR] = "grey";
//                bool test1 = !(exist.count(proxR)&&exist[proxR]=="grey");
//                bool test2 = exist.count(proxR);
//                bool test3 = exist[proxR]=="grey";
//                if(test2&&test3){//is free n funciona p recurso
//                    return true;
//                }else{
//                    return proxR->deadlockAux1(pilha,parametro,exist);//faz recursivamente com o ultimo da pilha
//                }
            }else{
                pilha.pop();
                exist[this] = "black";
                if(pilha.size()==0){//se a pilha acabou, retorna falso
                    return false;
                }else{//aqui tem que fazer a funcao recursova p que o ngm nunca retorne nullptr
                    while(pilha.size()>0&&pilha.top()->next==nullptr){
                        pilha.pop();
                    }
                    if(pilha.size()==0){//se a pilha acabou, retorna falso
                        return false;
                    }else{
                        Line* auxx = pilha.top();
                        pilha.pop();
                        auxx = auxx->next;
                        pilha.push(auxx);
                        return pilha.top()->val->deadlockAux1(pilha, parametro, exist);//faz recursivamente com o ultimo da pilha
                    }
                }
            }
        }else{//se for recurso//nesse caso, ou ele aponta p um ou ele n aponta p ngm

            if(exist[this->line->getFirst()]=="grey"){//se a fila já acabou
                pilha.pop();
                exist[this] = "black";
//                Vertice* aux1 = pilha.top()->val;
//                pilha.pop();
//                exist[aux1] = "black";
                if(pilha.size()==0){//se a pilha acabou, retorna falso
                    return false;
                }else{
                    while(pilha.size()>0&&pilha.top()->next==nullptr){
                        pilha.pop();
                    }
                    if(pilha.size()==0){//se a pilha acabou, retorna falso
                        return false;
                    }else{
                        Line* auxx = pilha.top();
                        pilha.pop();
                        auxx = auxx->next;
                        pilha.push(auxx);
                        return pilha.top()->val->deadlockAux1(pilha, parametro, exist);//faz recursivamente com o ultimo da pilha
                    }
                }
            }else{//se tem prox
                Vertice* proxP = pilha.top()->getFirst();//pega o primeiro da fila//tenho que parr de usar esse out
                if(exist[proxP]=="grey"){
                    return true;
                }else{
                    pilha.push(proxP->want);//bota o primeiro na fila
                    exist[proxP] = "grey";
                    return proxP->deadlockAux1(pilha,parametro,exist);//faz recursivamente com o ultimo da pilha
                }
//                exist[aux] = "grey";
//                pilha.push(aux->want);//bota o primeiro na fila
//                Vertice* proxP = pilha.top()->getFirst();
//                if(!proxP->want->isFree()&&exist.count(proxP->want->getFirst())&&exist[proxP->want->getFirst()]=="grey"){
//                    return true;
//                }else{
//                    return proxP->deadlockAux1(pilha,parametro,exist);//faz recursivamente com o ultimo da pilha
//                }
            }
        }
    }

    bool deadlock(){

        //tenho que lembrar
        //processor usa want
        //recurso usa o primeiro do line

        stack<Line*> pilha;
        map<Vertice*, string> exist;
        exist.clear();
        pilha.push(this->want);
        exist[this] = "grey";

        //e se essa pilha for de apontador de fila?//nesse caso, ele acabaria quando o da base chegasse em null, pq eu iria dando next nele

        //braco = nem entrou na pilha ainda // se eu achar um branco, ele entr na pilha
        //cinza = está na pilha // se eu tentar botar um cinza, achei um cilco
        //preto = já saiu da pilha // se achar um preto, pula p o prox

        //vou criar um metodo p clonar a fila

        return this->deadlockAux1(pilha, this, exist);

    }
};

class SistemaOperacional{
public:
    vector<Vertice*> processos;//array de processos// um elemento desse array tem o nome do proceso e ua fila de recursos que ele está usando
    vector<Vertice*> recursos;// array de recursos// um elemento desse assay tem o nome do recurso e a fila de processos que querem usar ele (ps: o primeiro é o que esta usando)
    map<string, int> m;


    void req(string p, string r){ //processo solicita recurso
        if(m.count(p)&&m.count(r)){//se o processo e o recurso já existem
//            Vertice** recurso = &this->recursos[this->m[r]];
//            Vertice** processo = &this->processos[this->m[p]];

            if(this->recursos[this->m[r]]->line->isFree()){//recurso esta livre // o processo consegue o recurso
                this->recursos[this->m[r]]->line->in(this->processos[this->m[p]], &this->recursos[this->m[r]]->line->size);
                this->processos[this->m[p]]->line->in(this->recursos[this->m[r]], &this->processos[this->m[p]]->line->size);
                cout << "AVAIL" << endl;
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                this->recursos[this->m[r]]->line->in(this->processos[this->m[p]], &this->recursos[this->m[r]]->line->size);
                this->processos[this->m[p]]->want->in(this->recursos[this->m[r]], &this->processos[this->m[p]]->want->size);
                cout << "WAIT " << this->recursos[this->m[r]]->line->size << endl;
            }

        }else if(m.count(p)){//se o processo ja existe
            Vertice* recurso = new Vertice(r);
            Vertice** processo = &this->processos[this->m[p]];
            recursos.push_back(recurso);/////////////////////////////////////////////////////////// talvez aqui de problema com o apontador e etc// quando o vector aumenta de tamanho, a memoria das coisas mudam de lugar
            m[r] = recursos.size()-1;

            recurso->line->in(this->processos[this->m[p]], &recurso->line->size);
            this->processos[this->m[p]]->line->in(recurso, &this->processos[this->m[p]]->line->size);

            cout << "AVAIL" << endl;

        }else if(m.count(r)){//se o recurso ja existe
            Vertice** recurso = &this->recursos[this->m[r]];
            Vertice* processo = new Vertice(p);
            processos.push_back(processo);
            m[p] = processos.size()-1;

            if(this->recursos[this->m[r]]->line->isFree()){//recurso esta livre // o processo consegue o recurso
                this->recursos[this->m[r]]->line->in(processo, &this->recursos[this->m[r]]->line->size);
                processo->line->in(this->recursos[this->m[r]], &processo->line->size);
                cout << "AVAIL" << endl;
            }else{//se o recurso esta sendo usado // o processo entra na fila do recurso
                this->recursos[this->m[r]]->line->in(processo, &this->recursos[this->m[r]]->line->size);
                processo->want->in(this->recursos[this->m[r]], &processo->want->size);
                cout << "WAIT " << this->recursos[this->m[r]]->line->size << endl;
            }

        }else{//se nenhum dos 2 existem
            Vertice* recurso = new Vertice(r);
            Vertice* processo = new Vertice(p);
            recursos.push_back(recurso);
            m[r] = recursos.size()-1;
            processos.push_back(processo);
            m[p] = processos.size()-1;

            recurso->line->in(processo, &recurso->line->size);
            processo->line->in(recurso, &processo->line->size);

            cout << "AVAIL" << endl;

        }
    }

    void fre(string p){
        if(m.count(p)){//se p existe
            int cont = 0;
            while(processos[m[p]]->line->size!=-1){//enquanto ainda tiver coisa na fila de recursos que o processo tem
                Vertice* recurso = processos[m[p]]->line->out(&processos[m[p]]->line->size);//tira um recurso da fila de recursos que o processo tem
                Vertice* processo = recurso->line->out(&recurso->line->size);//faz o recurso parar de apontar para o processo
                if(!recurso->line->isFree()){//se tem coisa na fila do recurso
                    processo = recurso->line->getFirst();//pega que coisa é essa
                    processo->line->in(recurso, &processo->line->size);//e da ao processo
                    processo->want->takeOff(recurso, &processo->want->size);
                }
                cont++;
            }
            processos[m[p]]->want->clear();
            cout << "TERM " << cont << endl;
        }
    }

    void dlk(string p){
        if(processos[m[p]]->deadlock()){//se tiver deadlock
            if(m.count(p)){//se p existe
                int cont = 0;
                int contR = 0;
                while(processos[m[p]]->line->size!=-1){
                    Vertice* recurso = processos[m[p]]->line->out(&processos[m[p]]->line->size);//se aqui só tira os que ele ja tem, o recurso sempre vai estar em uso
                    //tenho que ver se o processo já estava com o recurso ou nao
                    Vertice* processo = recurso->line->out(&recurso->line->size);
                    if(!recurso->line->isFree()){
                        processo = recurso->line->getFirst();
                        processo->line->in(recurso, &processo->line->size);
                    }
                    cont++;
                }
                contR = processos[m[p]]->want->size;
                cout << "KILL " << cont << " " << contR << endl;
            }
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
