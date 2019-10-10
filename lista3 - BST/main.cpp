#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


//H é o max de nos de uma arvore



class List{
    int element;
    List* next;

public:

    List(){
        this->element = 0;
        next = nullptr;
    }

    void inset(int id){
        if(this->next = nullptr){
            this->next->element = id;
        }else{
            this->next->inset(id);
        }
    }

    void remove(int id){
        if(this->next->element==id){
            this->next=this->next->next;
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

    Node(int element){
        this->element = element;
        this -> left = nullptr;
        this -> right = nullptr;
        this->funcionarios = new List();
    }

    void insertNode(int element){
        if(element>this->element){
            if(this->right==nullptr){
                this->right= new Node(element);
            }else{
                this->right->insertNode(element);
            }
        }else{
            if(this->left==nullptr){
                this->left= new Node(element);
            }else{
                this->left->insertNode(element);
            }
        }
    }

    void removeNode(int element){

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
           this->root = new Node(element);
       }else{
           this->root->insertNode(element);
       }
    }

    void remove(int element){
        
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
