#include <bits/stdc++.h>
#define endl '\n'

using namespace std;


//H é o max de nos de uma arvore

class List{
    int element;
    List* next;

    List(int element){
        if(this->elemt){
            this
        }
    }
};


class Node{//aka posto
    //ps: acho que eu ainda voi precisar colocar uma lista de funcionarios aqui
public:
    int element;//aka casta
    Node* left;//aka subordinado
    Node* right;//aka subordinado
    List* funcionarios;

    Node(int element){
        this->element = element;
        this -> left = nullptr;
        this -> right = nullptr;
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

};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numBases;
    int limitePostos;
    int totalInicialAgentes;

    cin >> numBases;
    cin >> limitePostos;
    cin >> totalInicialAgentes;

    Bst* arrayBase = new Bst[numBases];

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
