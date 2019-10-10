#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


//H é o max de nos de uma arvore



class List{//ach que a lista esta pronta
    int element;
    List* next;
    int totalElementos;

public:

    List(){
        this->element = 0;
        next = nullptr;
        this->totalElementos = 0;
    }

    void inset(int id){
        if(this->next = nullptr){
            this->next->element = id;
            this->totalElementos = this->totalElementos + 1;
        }else{
            this->next->inset(id);
        }
    }

    void remove(int id){
        if(this->next->element==id){
            this->next=this->next->next;
            this->totalElementos = this->totalElementos - 1;
        }else{
            this->next->remove(id);
        }
    }

    bool src(int id){
        if(this->next->element == id){
            return true;
        }else if(this->next == nullptr){
            return false;
        }else{
            return src(id);
        }
    }
};


class Node{//aka posto
public:
    int element;//aka casta
    Node* left;//aka subordinado
    Node* right;//aka subordinado
    List* funcionarios;
    Node* pai;

    Node(Node* pai, int element){
        this->element = element;
        this -> left = nullptr;
        this -> right = nullptr;
        this->funcionarios = new List();
        this-> pai = pai;
    }

    Node(){
        this->element = 0;
        this -> left = nullptr;
        this -> right = nullptr;
        this->funcionarios = new List();
        this-> pai = nullptr;
    }

    void insertNode(Node* pai, int element){
        if(element>this->element){
            if(this->right==nullptr){
                this->right= new Node(pai, element);
            }else{
                this->right->insertNode(this->right, element);
            }
        }else{
            if(this->left==nullptr){
                this->left= new Node(pai, element);
            }else{
                this->left->insertNode(this->left, element);
            }
        }
    }

    void removeReal(int element){
        if(this->left==nullptr && this->right == nullptr){//sem filho
            this = null;
        }else if(this->left != nullptr){//filho a esquerda

        }else if(this -> right != nullptr){//filho a direita

        }else{//2 filhos

        }
    }

    void removeNode(int element){
        if(element = this->right->element){
            this->removeReal(element);
        }else if(element > this->right->element){
            this->right->removeNode(element);
        }else{
            this->left->removeNode(element);
        }
    }

};

class Bst{//aka base
private:
    Node* root;

public:

    Bst(){
        this->root = nullptr;
    }

    void insert(int element){
       if(this->root==nullptr){
           this->root = new Node(nullptr, element);
       }else{
           this->root->insertNode(this->root, element);
       }
    }

    void remove(int element){
        this->root->removeNode(element);
    }

};

class ArrayBases{
    Bst* arrayBase;
public:

    ArrayBases(int numBases){
        this->arrayBase = new Bst[numBases];
    }

    void insert(){

    }

    void remove(){

    }
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numBases;
    int hLimite;
    int totalInicialAgentes;

    cin >> numBases;
    cin >> hLimite;
    cin >> totalInicialAgentes;

    ArrayBases* array = new ArrayBases(numBases);

    int casta;
    int id;
    int base;

    string comando;



    for(int i = 0; i<totalInicialAgentes; i++){
        cin >> comando;
        cin >> casta;
        cin >> id;
        cin >> base;



        //inserir os funcionarios
    }

    cin >> comando;
    while(comando!="END"){

        if(comando == "INF"){//inserir
            cin >> casta;
            cin >> id;
            cin >> base;

        }else if(comando == "EXT"){//remover
            cin >> casta;
            cin >> id;
            cin >> base;

        }else if(comando == "SCH"){//procurar
            cin >> casta;
            cin >> id;
            cin >> base;

        }

        cin >> comando;
    }


    return 0;
}
