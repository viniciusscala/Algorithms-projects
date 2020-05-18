#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

    void printarArray(string* estacionamentoAux, int totalGaragens){
        //area de teste
        //for(int j = 0; j< totalGaragens; j++){
        //    string tesste = estacionamentoAux[j];
        //    if(tesste!=""){
        //        cout <<j<<":"<< tesste << " ";
        //        cout.flush();
        //    }
//
        //}
        //cout << endl;
        //fim area de teste
    }

    string* abrirGaragem(string* estacionamento,int totalGaragens,int totalGaragensAntes, int efetivo){
        string* estacionamentoAux = new string[totalGaragens];
        int cont = 0;
        bool continua = true;
        for(int i = 0; i< totalGaragensAntes&&continua; i++){
            string placa = estacionamento[i];
            if(placa!=""&&placa!="indisponivel"){
                cont++;
                if(cont>efetivo){
                    continua=false;
                }
                int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                if (estacionamentoAux[placaChave1%totalGaragens]=="") {
                    estacionamentoAux[placaChave1%totalGaragens] = placa;
                } else {
                    while (estacionamentoAux[placaChave1%totalGaragens]!="") {
                        placaChave1++;
                    }
                    estacionamentoAux[placaChave1%totalGaragens] = placa;
                }
            }
        }
        return estacionamentoAux;
    }

    static int distancia(string placa, int tamanho, int posicao){
        int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
        int d = (tamanho + posicao - (placaChave1%tamanho))%tamanho;

        return d;
    }

    string* estacionamento22(string* estacionamento, int chave, string placa, int distancia1, int totalGaragens){

        while(estacionamento[chave%totalGaragens]!=""&&(estacionamento[chave%totalGaragens]=="indisponivel"||distancia(estacionamento[chave%totalGaragens], totalGaragens, chave%totalGaragens)>=distancia1)){
            distancia1++;
            chave++;
        }
        if(estacionamento[chave%totalGaragens]==""){
            estacionamento[chave%totalGaragens]=placa;
        }else{
            string placaAux=estacionamento[chave%totalGaragens];
            estacionamento[chave%totalGaragens]=placa;
            int placaChave1 = (placaAux[0]-'A')*1+(placaAux[1]-'A')*26 + (placaAux[2]-'A')*26*26+(placaAux[3]-'A')*26*26*26 + (placaAux[4]-'A')*26*26*26*26+(placaAux[5]-'A')*26*26*26*26*26;

            return estacionamento22(estacionamento, placaChave1, placaAux, 0, totalGaragens);
        }
        printarArray(estacionamento, totalGaragens);
        return estacionamento;
    }

    string* abrirGaragem2(string* estacionamento,int totalGaragens,int totalGaragensAntes, int efetivo){
        string* estacionamentoAux = new string[totalGaragens];
        int cont = 0;
        bool continua = true;
        for(int i = 0; i< totalGaragensAntes&&continua; i++){
            string placa = estacionamento[i];
            if(placa!=""&&placa!="indisponivel") {
                cont++;
                if(cont>efetivo){
                    continua=false;
                }
                int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                estacionamentoAux = estacionamento22(estacionamentoAux, placaChave1, placa, 0, totalGaragens);
                printarArray(estacionamentoAux, totalGaragens);
            }
        }
        return estacionamentoAux;
    }

    static int posicao22(string placa, string* estacionamento2, int totalGaragens){
        int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
        if((estacionamento2[placaChave1%totalGaragens]!="")&&estacionamento2[placaChave1%totalGaragens]==placa){
            return placaChave1%totalGaragens;
        }else if(estacionamento2[placaChave1%totalGaragens]==""){
            return -1;
        }else{
            bool continua = true;
            int contador=0;
            int distanciaTeste = distancia(estacionamento2[placaChave1%totalGaragens],  totalGaragens, placaChave1%totalGaragens);
            while((estacionamento2[placaChave1%totalGaragens]!=""&&(estacionamento2[placaChave1%totalGaragens]=="indisponivel"))||((estacionamento2[placaChave1%totalGaragens]!="")&&estacionamento2[placaChave1%totalGaragens]!=placa&&(distanciaTeste>=contador)&&contador<=totalGaragens&&continua)){
                contador++;
                placaChave1++;
                if(estacionamento2[placaChave1%totalGaragens]!=""){
                    distanciaTeste = distancia(estacionamento2[placaChave1%totalGaragens],  totalGaragens, placaChave1%totalGaragens);
                }else{
                    continua=false;
                }
            }
            if(estacionamento2[placaChave1%totalGaragens]!=""&&estacionamento2[placaChave1%totalGaragens]==placa){
                return placaChave1%totalGaragens;
            }else{
                return -1;
            }
        }

    }

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int minGaragens ;
        int ocupacaoMin ;
        int ocupacaoMax;
        string comando;
        string placa;
        int posicao1;
        int distancia1;
        int posicao2;
        int distancia2;
        int vagasOcupadas = 0;
        int vagasRealmenteOcupadas = 0;
        int totalGaragens;
        double taxaDeOcupacao;
        double taxaDeOcupacaoEfetiva;
        int totalGaragensAntes;
        int dMax1 = 0;
        int dMax2 = 0;
        int breakPoint = 0;

        cin >> minGaragens;
        cin >> ocupacaoMin;
        cin >> ocupacaoMax;
        cin >> comando;

        totalGaragens = minGaragens;
        taxaDeOcupacao = vagasOcupadas/totalGaragens;
        taxaDeOcupacaoEfetiva = vagasRealmenteOcupadas/totalGaragens;

        string* estacionamento = new string[totalGaragens];
        string* estacionamento2 = new string[totalGaragens];

        while(comando!="END"){

            cin >> placa;

            if(comando=="IN"){
                taxaDeOcupacao = vagasOcupadas/totalGaragens;

                if(100*vagasOcupadas <= totalGaragens*ocupacaoMax) {//se n precisar abrir mais vagas

                    int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;


                    if (estacionamento[placaChave1%totalGaragens]=="") {//se n tiver colisao
                        estacionamento[placaChave1%totalGaragens] = placa;
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = 0;
                    } else {//se tiver colisao
                        int contador = 0;
                        while (estacionamento[placaChave1%totalGaragens]!="") {//editei alguma coisa aqui
                            placaChave1++;
                            contador++;
                        }
                        estacionamento[placaChave1%totalGaragens] = placa;
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = contador;
                    }

                    //estacionamento2
                    placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                    estacionamento2 = estacionamento22(estacionamento2, placaChave1, placa, 0, totalGaragens);
                }else{//se precisar abrir mais vagas

                    int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                    totalGaragensAntes = totalGaragens;
                    totalGaragens = 2*totalGaragens;


                    estacionamento = abrirGaragem(estacionamento, totalGaragens, totalGaragensAntes, vagasRealmenteOcupadas);
                    if (estacionamento[placaChave1%totalGaragens]=="") {
                        estacionamento[placaChave1%totalGaragens] = placa;
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = 0;
                    } else {
                        int contador = 0;
                        while (estacionamento[placaChave1%totalGaragens]!="") {
                            placaChave1++;
                            contador++;
                        }
                        estacionamento[placaChave1%totalGaragens] = placa;
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = contador;
                    }

                    //estacionamento2
                    placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                    estacionamento2 = abrirGaragem2(estacionamento2, totalGaragens, totalGaragensAntes, vagasRealmenteOcupadas);
                    estacionamento2 = estacionamento22(estacionamento2, placaChave1, placa, 0, totalGaragens);

                    vagasOcupadas = vagasRealmenteOcupadas;

                    printarArray(estacionamento2, totalGaragens);

                }


                vagasOcupadas++;
                vagasRealmenteOcupadas++;
                posicao2 = posicao22(placa, estacionamento2, totalGaragens);
                distancia2 = distancia(placa, totalGaragens, posicao2);
                breakPoint++;
                cout << posicao1<<" "<<distancia1<<" "<<posicao2<<" "<<distancia2<<endl;
            }else if(comando=="OUT"){

                //fim estacionamento 1
                int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;
                    posicao2 = posicao22(placa, estacionamento2, totalGaragens);
                    if(posicao2==-1){
                        distancia2=-1;
                    }else{
                        estacionamento2[posicao2]="indisponivel";
                        distancia2 = distancia(placa, totalGaragens, posicao2);
                    }

                if(posicao2!=-1){
                    placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;

                    if (estacionamento[placaChave1%totalGaragens]!=""&&estacionamento[placaChave1%totalGaragens]==placa) {//se n der colisao
                        estacionamento[placaChave1%totalGaragens] = "indisponivel";
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = 0;
                        vagasRealmenteOcupadas--;
                    } else {//se der colisao
                        int contador = 0;
                        while ((estacionamento[placaChave1%totalGaragens]!="")&&(estacionamento[placaChave1%totalGaragens]!=placa)&&(contador<=totalGaragens)) {
                            placaChave1++;
                            contador++;
                        }
                        if((contador>totalGaragens)||(estacionamento[placaChave1%totalGaragens]=="")){
                            posicao1 = -1;
                            distancia1 = -1;
                        }else{
                            estacionamento[placaChave1%totalGaragens] = "indisponivel";
                            posicao1 = placaChave1%totalGaragens;
                            distancia1 = contador;
                            vagasRealmenteOcupadas--;
                        }
                    }
                }else{
                    posicao1 = -1;
                    distancia1 = -1;
                }

                breakPoint++;
                cout << posicao1<<" "<<distancia1<<" "<<posicao2<<" "<<distancia2<<endl;

                taxaDeOcupacaoEfetiva = vagasRealmenteOcupadas/totalGaragens;
                if(100*vagasRealmenteOcupadas < totalGaragens*ocupacaoMin && distancia1!=-1){
                    totalGaragensAntes = totalGaragens;
                    if((totalGaragens/2)>minGaragens){
                        totalGaragens = totalGaragens/2;
                    }else{
                        totalGaragens = minGaragens;
                    }
                    estacionamento = abrirGaragem(estacionamento, totalGaragens, totalGaragensAntes, vagasRealmenteOcupadas);
                    estacionamento2 = abrirGaragem2(estacionamento2, totalGaragens, totalGaragensAntes, vagasRealmenteOcupadas);
                    vagasOcupadas = vagasRealmenteOcupadas;
                }
            }else if(comando=="SCH"){
                int placaChave1 = (placa[0]-'A')*1+(placa[1]-'A')*26 + (placa[2]-'A')*26*26+(placa[3]-'A')*26*26*26 + (placa[4]-'A')*26*26*26*26+(placa[5]-'A')*26*26*26*26*26;

                    posicao2 = posicao22(placa, estacionamento2, totalGaragens);
                    if(posicao2==-1){
                        distancia2=-1;
                    }else{
                        distancia2 = distancia(placa, totalGaragens, posicao2);
                    }
                if(distancia2!=-1){
                    if (estacionamento[placaChave1%totalGaragens]!=""&&estacionamento[placaChave1%totalGaragens]==placa) {//se n der colisao
                        posicao1 = placaChave1%totalGaragens;
                        distancia1 = 0;
                    } else {//se der colisao
                        int contador = 0;
                        while ((estacionamento[placaChave1%totalGaragens]!="")&&(estacionamento[placaChave1%totalGaragens]!=placa)&&(contador<=totalGaragens)) {
                            placaChave1++;
                            contador++;
                        }
                        if((contador>totalGaragens)||(estacionamento[placaChave1%totalGaragens]=="")){
                            posicao1 = -1;
                            distancia1 = -1;
                        }else{
                            posicao1 = placaChave1%totalGaragens;
                            distancia1 = contador;
                        }
                    }
                }else{
                    distancia1=-1;
                    posicao1=-1;
                }


                if(dMax1<distancia1){
                    dMax1 = distancia1;
                }
                if(dMax2<distancia2){
                    dMax2=distancia2;
                }

                cout << posicao1<<" "<<distancia1<<" "<<posicao2<<" "<<distancia2<<endl;
                breakPoint++;
            }

            cout.flush();
            cin >> comando;
        }

        cout << dMax1<<" "<<dMax2<<endl;

    return 0;
}
