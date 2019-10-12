//#include <bits/stdc++.h>
#include "/usr/local/include/bits/stdc++.h"
#define endl '\n'

using namespace std;


//H é o max de nos de uma arvore



class List{//ach que a lista esta pronta
    int element;
    int totalElementos;
    List* next;

public:
    List(){
        this->element = 0;
        next = nullptr;
        this->totalElementos = 0;
    }

    List(int id){
        this->element = id;
        next = nullptr;
        this->totalElementos = 0;
    }

    void inset1(int id, List* head){
        if(this->next == nullptr){
            this->next = new List(id);
            head->totalElementos = head->totalElementos + 1;
        }else{
            this->next->inset1(id, head);
        }
    }

    void inset(int id){
        inset1(id, this);
    }

    void remove1(int id, List* head){
        if(this->next->element==id){
            this->next=this->next->next;
            head->totalElementos = head->totalElementos - 1;
        }else{
            this->next->remove1(id, head);
        }
    }

    void remove(int id){
        remove1(id, this);
    }

    bool src(int id){
        if(this->next == nullptr){
            return false;
        }else if(this->next->element == id){
            return true;
        }else{
            return this->next->src(id);
        }
    }

    int getTotalElementos() {
        return totalElementos;
    }

};//fim da classe lista


class Node{//aka posto
public:
    int element;//aka casta
    Node* left;//aka subordinado
    Node* right;//aka subordinado
    List* funcionarios;

    Node(int element, int id){
        this->element = element;
        this -> left = nullptr;
        this -> right = nullptr;
        this->funcionarios = new List();
        this->funcionarios->inset(id);
    }

    Node(){
        this->element = 0;
        this -> left = nullptr;
        this -> right = nullptr;
        this->funcionarios = new List();
    }

    bool insertNode(int element, int id, int maxh, Node* root, int ramo){
        if(element>this->element){
            if(this->right==nullptr){//o problema daqui é que inserir nem sempre aumenta a altura
                int altura = root->altura(nullptr);
                if(ramo==altura&&(altura+1)>maxh){//aqui sempre aumenta
                    return false;
                }else{//aqui n aumenta
                    this->right= new Node(element, id);
                    return true;
                }
            }else{
                return this->right->insertNode(element, id, maxh, root, ramo +1);
            }
        }else if(element<this->element){
            if(this->left==nullptr){
                int altura = root->altura(nullptr);
                if(ramo==altura&&(altura+1)>maxh){//aqui sempre aumenta
                    return false;
                }else{
                    this->left= new Node(element, id);
                    return true;
                }
            }else{
                return this->left->insertNode(element, id, maxh, root, ramo +1);
            }
        }else{//aqui n aumenta a altura
            this->funcionarios->inset(id);
            return true;
        }
    }

    Node* menor(){
        if(this->left==nullptr){
            return this;
        }else{
            return this->left->menor();
        }
    }

    Node* change(Node* root, Node* folha){
        this->element = folha->element;
        this->funcionarios = folha ->funcionarios;
        return this;
    }

    Node* removeNode(Node* root, int element){// ////////////////////////////////////////////////////////////////////tava editando aqui
        if((element > this->element)){
            this->right = this->right->removeNode(this->right, element);
            return this;
        }else if((element < this->element)){
            this->left = this->left->removeNode(this->right, element);
            return this;
        }else{
            if(this->left==nullptr){//se só tiver o da direita (O elemento que eu quero deletar)
                return  this->right;
            }else if(this->right==nullptr){//se so tiver o da esquerda
                return  this->left;
            }else{//se tiver os dois
                Node* aux = this->right->menor();//o menor da direita
                root = change(root, aux);
                root->right = root->right->removeNode(root->right, aux->element);
                return  root;
            }
        }
    }

    int altura(Node* casta){
        if(this==casta){
            return -1;
        }else{
            int a = this->right->altura(casta);
            int b = this->left->altura(casta);
            int max;
            if(a>b){
                max = a;
            }else{
                max = b;
            }
            return 1 + max;
        }
    }

    int src(Node* root, int id, int casta, int h){
        if(casta == this->element){
            if(this->funcionarios->src(id)){
                return h;
            }else{
                return -1;
            }
        }else{//cada evz que entra aqui, a altura soma 1
            if(casta>this->element){
                if(this->right==nullptr){
                    return -1;
                }else{
                    return this->right->src(root, id, casta, h+1);
                }
            }else{
                if(this->left==nullptr){
                    return -1;
                }else{
                    return this->left->src(root, id, casta, h+1);
                }

            }
        }
    }

    Node* src(Node* root,int casta){
        if(root!=nullptr){
            if(casta>this->element){
                return this->right->src(this->right,casta);
            }else if(casta<this->element){
                return this->left->src(this->left,casta);
            }else{
                return this;
            }
        }else{
            return nullptr;
        }
    }

};

class Bst{//aka base
private:
    Node* root;

    bool insert(int element, int id, Node* root, int maxh){
        if(this->root==nullptr){//nesse caso nunca vai aumentar a altura
            this->root = new Node(element, id);
            return true;
        }else{
            return this->root->insertNode(element, id, maxh, root, 0);
        }
    }

    void remove(int element){
        this->root = this->root->removeNode(this->root, element);
    }

    int src(int id, int casta){
        return this->root->src(this->root, id, casta, 0);
    }



public:

    int altura(){
        return this->root->altura(nullptr);
    }

    Node *getRoot() const {
        return root;
    }

    Bst(){
        this->root = nullptr;
    }

    bool adm(int id, int casta, int maxh, Node* root){
        int teste = this->altura();
        if(teste<=maxh){// nem sempre inserir aumenta o tamanho da arvore
            return this->insert(casta, id, root, maxh);
        }else{
            return false;
        }
    }

    bool inf(int id, int casta, int maxh, Node* root){
        int teste = this->altura();
        if(teste<=maxh){// nem sempre inserir aumenta o tamanho da arvore
            return this->insert(casta, id, root, maxh);
        }else{
            return false;
        }
    }

    void ext(int id, int casta){
        Node* posto= this->root->src(this->root, casta);
        if(posto!=nullptr){
             posto->funcionarios->remove(id);
             if(posto->funcionarios->getTotalElementos()==0){
                 this->remove(posto->element);
             }
         }
    }

    int sch(int id, int casta){
        return src(id, casta);
    }

};

void debugger(Bst arrayBase[5]){
    for(int i = 0; i<5; i++){
        cout << arrayBase[i].altura() << endl;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numBases;
    int hLimite;
    int totalInicialAgentes;

    cin >> numBases;
    cin >> hLimite;
    cin >> totalInicialAgentes;

    hLimite = hLimite-1;

    Bst arrayBase[5];

    //for(int i = 0; i<numBases; i++){
    //    arrayBase[i] = *new Bst();
    //}

    int casta;
    int id;
    int base;

    string comando;



    for(int i = 0; i<totalInicialAgentes; i++){
        cin >> comando;
        cin >> casta;
        cin >> id;
        cin >> base;

        bool teste = false;

        for(int j = 0; j<numBases && !teste; j++){
            int baseAux = ((base+j) % numBases);
            teste = arrayBase[baseAux].adm(id, casta, hLimite, arrayBase[baseAux].getRoot());
        }

        //cout << "id" << id << endl;
        //debugger(arrayBase);
        //cout << endl;

    }

    cin >> comando;
    while(comando!="END"){

        cin >> casta;
        cin >> id;
        cin >> base;

        //cout << comando << " " << casta << " " << id << " " << base << " " << endl;

        if(comando == "INF"){//inserir

            bool teste = false;

            for(int j = 0; j<numBases && !teste; j++){
                int baseAux = ((base+j) % numBases);
                teste = arrayBase[baseAux].inf(id, casta, hLimite, arrayBase[baseAux].getRoot());
                if(teste){
                    cout << ((base+j) % numBases) << endl;
                }
            }
            if(!teste){
                cout << -1 << endl;
            }

        }else if(comando == "EXT"){//remover

            arrayBase[base].ext(id, casta);

        }else if(comando == "SCH"){//procurar

            cout << arrayBase[base].sch(id, casta) << endl;

        }

        cin >> comando;
    }


    return 0;
}
