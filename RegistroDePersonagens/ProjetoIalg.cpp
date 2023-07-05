//Banco de dados de personagens de desenhos animados
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string.h>

using namespace std;



// NA ESTRUTURA STRUCT ESTAO OS CAMPOS QUE UTILIZAREMOS NESTRE PROJETO.

struct character{
    int identificador;
    string name;
    string creator;
    string tituloDesenho;
    float height;
    string bio;
};


// FUNÇAO PARA TRANSFORMAR TODAS AS LETRAS DE UMA STRING EM LETRAS MINUSCULAS:

string minusculo(string palavra) {
    for (char& c : palavra) {
        c = tolower(c);
    }

    return palavra;
}


//PROCEDIMENTO PARA IMPRIMIR TODOS OS PERSONAGENS DO NOSSO ARQUIVO CSV:

void imprimirLista(character personagens[], int tamanho) {
    cout << "\n\n\n" << endl;
    
    for (int i = 0; i < tamanho; i++){
        cout << "PERSONAGEM " << personagens[i].identificador << ": \n" << "Nome: " <<  personagens[i].name << "\n"  <<
        "Titulo do Desenho: " <<  personagens[i].tituloDesenho << "\n" << "Altura: "<< personagens[i].height << " metros " << 
        "\n" << "Criador: " << personagens[i].creator << "\n" << "Descricao: " << personagens[i].bio << "\n" << endl;
        cout << endl;
        cout << "======================================================================================================================="<< "\n" << endl;
    }
    
}


//PROCEDIMENTO PARA PESQUISAR ATRAVÉS DOS CAMPOS STRING, NOME, TITULO E CRADOR DE CADA PERSONAGEM.

void searchName(character personagens[], int tamanho){
    string nomeBusca;
    string nomeLista, nomeBuscado;
    int encontrados[tamanho];
    int select;
    int j = 0;
    char *ponteiro;
    char* charLista;
    char* charBuscado;

    cout << endl;
    cout << "Selecione a opcao que deseja buscar: \n" << endl;
    cout << "[1] - Buscar por nome do Personagem\n" << "[2] - Buscar por nome do Criador:\n" << "[3] - Buscar por titulo do desenho:\n" << endl;
    
    cin >> select;
    cin.ignore();

    switch (select) {
    case 1:
        fflush(stdin);
        cout << "\n\n\nDigite o nome do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);
        
        nomeBuscado = minusculo(nomeBusca);
        charBuscado = &nomeBuscado[0];
        
        
        // ESSA ESTRURA FOI UTILIZADA PARA PESQUISAR UMA STRING DENTRO DE UMA STRING, POR ISSO A UTILIZAÇAO DE strstr:
        for (int i = 0; i < tamanho; i++) {
            nomeLista = minusculo(personagens[i].name);
            charLista = &nomeLista[0];
            
            ponteiro = strstr(charLista, charBuscado);
            if (ponteiro) {
                encontrados[j] = i;
                j++;
            }           
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com o nome " << nomeBusca << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com o nome " << nomeBusca << ":" << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "   << 
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[encontrados[i]].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";               
            }
            cout << endl;            
        }     
        break;

    case 2:
        fflush(stdin);
        cout << "\n\n\nDigite o nome do criador do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);

        nomeBuscado = minusculo(nomeBusca);
        charBuscado = &nomeBuscado[0];

        for (int i = 0; i < tamanho; i++) {
            nomeLista = minusculo(personagens[i].creator);
            charLista = &nomeLista[0];
            ponteiro = strstr(charLista, charBuscado);

            if (ponteiro) {
                encontrados[j] = i;
                j++;
            }
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com o nome de criador " << nomeBusca << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com o nome do criador " << nomeBusca << ":" << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "  <<
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[encontrados[i]].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";
            }
            cout << endl;             
        }

        break;
    case 3:
        fflush(stdin);
        cout << "\n\n\nDigite o titulo do desenho do personagem que deseja encontrar: ";
        getline(cin, nomeBusca);

        nomeBuscado = minusculo(nomeBusca);
        charBuscado = &nomeBuscado[0];

        for (int i = 0; i < tamanho; i++) {
            nomeLista = minusculo(personagens[i].tituloDesenho);
            charLista = &nomeLista[0];
            ponteiro = strstr(charLista, charBuscado);

            if (ponteiro) {
                encontrados[j] = i;
                j++;
            }            
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com o titulo de desenho " << nomeBusca << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com o tiulo de desenho " << nomeBusca << ":" << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros "  <<
                "\n" << "Titulo do Desenho: " <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" << "Descricao: " << personagens[encontrados[i]].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";       
            }
            cout << endl;             
        }

        break;
    
    default:
        cout << "Opcao invalida!" << endl;
        break;
    }
    
    cout << "\n";               
}   


// PRCEDIMENTO PARA PESQUISAR UM PERSONAGEM QEU ESTA DENTRO DE UMA ALTURA MÍNIMA DIGITADA ATÉ UMA ALTURA MÁXIMA DIGITADA:

void searchHeight(character personagens[], int tamanho){

    float heightMin, heightMax;
    int encontrados[tamanho], j = 0;
    
    cout << endl;
    cout << "Altura minima: ";
    cin >> heightMin;
    cout << "Altura maxima: ";
    cin >> heightMax;

    for (int i = 0; i < tamanho; i++) {
            if (personagens[i].height >= heightMin and personagens[i].height <= heightMax) {
                encontrados[j] = i;
                j++;
            }            
        }

        if (j == 0) {
            cout << "Nenhum personagem foi encontrado com a altura entre " << heightMin << " e " << heightMax << endl;
        }
        else {
            cout << "\nLista de personagens encontrados com a altura entre " << heightMin << " metros e " << heightMax << " metros : " << endl;

            for (int i = 0; i < j; i++) {
                cout << "\n" << endl; 
                cout << "PERSONAGEM " <<personagens[encontrados[i]].identificador << ": \n" << "Nome: " <<  personagens[encontrados[i]].name 
                    << "\n" << "Altura: "<< personagens[encontrados[i]].height << " metros " <<"\n" << "Titulo do Desenho: " 
                    <<  personagens[encontrados[i]].tituloDesenho << "\n" << "Criador: " << personagens[encontrados[i]].creator << "\n" 
                    << "Descricao: " << personagens[encontrados[i]].bio << "\n" << endl;
                cout << endl;
                cout << "=======================================================================================================================";                
            }            
        }
    
    cout << "\n";
    cout << endl;
}


//PROCEDIMNETO PARA ADICIONAR UM NOVO PERSONAGEM:

void addChar(character personagens[], int& tamanho, string cabecalho){
    string nomeAdd, tituloAdd, criadorAdd, bioAdd;
    float alturaAdd;
    
    tamanho++;

    personagens[tamanho-1].identificador = tamanho;
    
    fflush(stdin);
    cout << "\n\nInforme o nome do personagem que deseja adicionar: ";
    getline(cin, nomeAdd);
    personagens[tamanho-1].name = nomeAdd;

    fflush(stdin);
    cout << "Informe o titulo do desenho do personagem: ";
    getline(cin, tituloAdd);
    personagens[tamanho-1].tituloDesenho = tituloAdd;

    fflush(stdin);
    cout << "Informe o criador do personagem: ";
    getline(cin, criadorAdd);
    personagens[tamanho-1].creator = criadorAdd;

    fflush(stdin);
    cout << "Informe a altura do personagem: ";
    cin >> alturaAdd;
    cin.ignore();
    personagens[tamanho-1].height = alturaAdd;

    fflush(stdin);
    cout << "Informe a descricao do personagem: ";
    getline(cin, bioAdd);
    personagens[tamanho-1].bio = bioAdd;

    cout << endl;
    cout<< "Personagem adicionado com sucesso!\n\n" << endl;
    
    ofstream arquivoAdd ("personagens.csv");
    
    arquivoAdd << cabecalho << endl;
    for (int i = 0; i < tamanho; i++){
        arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].name << ";" <<  personagens[i].tituloDesenho <<
        ';'<<  personagens[i].creator << ';' << personagens[i].height << ';' << personagens[i].bio << "\n";
    }               
}


//PROCEDIMENTO PARA EDITAR OS CAMPOS DE UM PERSONAGEM:

void editChar(character personagens[], int tamanho, string cabecalho){
    int identificadorBuscado;
    int select=0;
    cout << "\n\nDigite o identificador do personagem a ser editado :" <<  endl;
    cin >> identificadorBuscado;

    cout << "PERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].name << "\n" 
        << "Altura: "<< personagens[identificadorBuscado-1].height << " metros " << "\n" << "Titulo do Desenho: " 
        <<  personagens[identificadorBuscado-1].tituloDesenho << "\n" << "Criador: " << personagens[identificadorBuscado-1].creator 
        << "\n" << "Descricao: " << personagens[identificadorBuscado-1].bio << "\n" << endl;
    cout << endl;
    cout << "======================================================================================================================="<< "\n" << endl;
    

    cout << "Voce deseja alterar os dados desse identificador ? \n"<<
    "[1]- Sim " << endl << "[2]- Nao" << endl;

    cout << "\n\n";

    int numeroDigitado;
    cin >> numeroDigitado;

    cout << endl;

    if (numeroDigitado==1){

        do{
            string novoNome;
            float novaAltura;
            string novoTitulo;
            string novoCriador;
            string novaDescricao;

            switch (select)
            {
            case 0:
                cout<< "[1] - Editar nome do personagem \n"<<
                "[2] - Editar Altura \n"<<
                "[3] - Editar o Titulo \n"<< 
                "[4] - Editar o nome do criador \n"<<
                "[5] - Editar Descricao \n\n"<<
                "[-1] - Para sair da edicao\n" << endl;
                break;

            case 1:
                fflush (stdin);
                cout<< "Digite o novo nome do personagem : ";
                getline(cin, novoNome);
                personagens[identificadorBuscado-1].name= novoNome;
                cout << "\nNome do personagem alterado com sucesso!\n" << endl;
                
                break;

            case 2:
                fflush (stdin);
                cout<< "Digite a nova altura do personagem : ";
                cin>> novaAltura;
                cin.ignore();
                personagens[identificadorBuscado-1].height= novaAltura;
                cout << "\nAltura do personagem alterada com sucesso!\n" << endl;
                
                break;

            case 3:
                fflush (stdin);
                cout<< "Digite o novo titulo do desenho : ";
                getline(cin,novoTitulo);
                personagens[identificadorBuscado-1].tituloDesenho= novoTitulo;
                cout << "\nTítulo do desenho do personagem alterado com sucesso!\n" << endl;
                
                break;
            
            case 4:
                fflush (stdin);
                cout<< "Digite o novo criador do personagem : ";
                getline(cin,novoCriador);
                personagens[identificadorBuscado-1].creator= novoCriador;
                cout << "\nCriador do personagem alterado com sucesso!\n" << endl;
                
                break;

            case 5:
                fflush (stdin);
                cout<< "Digite a nova descriacao personagem : ";
                getline(cin,novaDescricao);
                personagens[identificadorBuscado-1].bio = novaDescricao;
                cout << "\nDescrição do personagem alterada com sucesso!\n" << endl;
                
                break;
            
            default:
                break;
            }
            if (select != -1 and select != 0) {
                cout << "[0] - Para voltar ao menu de edicao" << endl;
                cout << "[-1] - Para encerrar a edicao" << endl;
                cin >> select;
                cin.ignore();
            }
            else {
                cin >> select;
                cin.ignore();
            }
        }while(select!= -1);

        ofstream arquivoAdd ("personagens.csv");    
        arquivoAdd << cabecalho << endl;
        for (int i = 0; i < tamanho; i++){
            arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].name << ";" <<  personagens[i].tituloDesenho <<
            ';'<<  personagens[i].creator << ';' << personagens[i].height << ';' << personagens[i].bio << "\n";
        }            
    }
    cout << "\n" << endl;
}

//PROCEDIMENTO PARA DELETAR UM PERSONAGEM:

void delChar(character personagens[], int& tamanho, string cabecalho){

    int identificadorBuscado,  numeroDigitado;

    fflush(stdin);
    cout << "Digite o identificador do peronagem que deseja retirar: ";
    cin >> identificadorBuscado;

    cout << "PERSONAGEM " << personagens[identificadorBuscado-1].identificador << ": \n" << "Nome: " <<  personagens[identificadorBuscado-1].name << "\n" 
        << "Altura: "<< personagens[identificadorBuscado-1].height << " metros " << "\n" << "Titulo do Desenho: " 
        <<  personagens[identificadorBuscado-1].tituloDesenho << "\n" << "Criador: " << personagens[identificadorBuscado-1].creator 
        << "\n" << "Descricao: " << personagens[identificadorBuscado-1].bio << "\n" << endl;

    cout << "Voce deseja remover os dados desse identificador ? \n"<<
    "[1]- Sim " << endl << "[2]- Nao" << endl;

    cin >> numeroDigitado;

    if (numeroDigitado == 1){
        for (int i = identificadorBuscado; i < tamanho; i++){
            personagens[i-1].name = personagens[i].name;
            personagens[i-1].tituloDesenho  = personagens[i].tituloDesenho;
            personagens[i-1].height = personagens[i].height;
            personagens[i-1].creator = personagens[i].creator;
            personagens[i-1].bio = personagens[i].bio;
        }
    }

    ofstream arquivoAdd ("personagens.csv");    
    arquivoAdd << cabecalho << endl;
    tamanho--;
    for (int i = 0; i < tamanho; i++){
        arquivoAdd << personagens[i].identificador << ';' <<  personagens[i].name << ";" <<  personagens[i].tituloDesenho <<
        ';'<<  personagens[i].creator << ';' << personagens[i].height << ';' << personagens[i].bio << "\n";
    }            

    cout << "Personagem removido com sucesso!\n";
}

int main(){
    int capacidade = 50;
    character* personagens = new character[capacidade];

    string cabecalho;
    char lixo;
    int tamanho = 0;

    ifstream arqPersonagens("personagens.csv");
    if (not arqPersonagens){
        cout<< "Arquivo nao encontrado!"<< endl;
    }
    else {
    
        getline(arqPersonagens, cabecalho);

        while (arqPersonagens >> personagens[tamanho].identificador) {
            if (tamanho >= capacidade - 1) {
                character* temp = new character[capacidade+30];
                for (int i = 0; i < capacidade; i++) {
                    temp[i] = personagens[i];
                }
                delete[] personagens;
                personagens = temp;
                capacidade+=30;
            }

            arqPersonagens >> lixo;
            getline(arqPersonagens, personagens[tamanho].name, ';');
            getline(arqPersonagens, personagens[tamanho].tituloDesenho, ';');
            getline(arqPersonagens, personagens[tamanho].creator, ';');
            arqPersonagens >> personagens[tamanho].height;
            arqPersonagens >> lixo;
            getline(arqPersonagens, personagens[tamanho].bio);
            tamanho++;
            fflush(stdin);
        }

        int select = 0;
        
        do {
            switch(select){
                case 0:
                    cout << "\n\n\nMetodos de Pesquisa: \n\n" 
                        << "[1] - Mostrar lista completa \n"
                        << "[2] - Pesquisar por nome \n" 
                        << "[3] - Pesquisar por altura \n" 
                        << "[4] - Adicionar personagem \n"
                        << "[5] - Editar personagem \n"
                        << "[6] - Retirar personagem \n\n" 
                        << "[-1] - Para encerrar o programa\n" << endl;
                    break;
                case 1:
                    imprimirLista(personagens, tamanho);
                    break;

                case 2:
                    searchName(personagens, tamanho);
                    break;

                case 3:
                    searchHeight(personagens, tamanho);
                    break;

                case 4:
                    addChar(personagens, tamanho, cabecalho);
                    break;

                case 5:
                    editChar(personagens, tamanho, cabecalho);
                    break;

                case 6:
                    delChar(personagens, tamanho, cabecalho);
                    break;

                default:
                    cout << "Programa encerrado";
                    break;
            }

            if (select != -1 and select != 0) {
                cout << "[0] - Para voltar ao menu principal" << endl;
                cout << "[-1] - Para encerrar o programa" << endl;
                cin >> select;
                cin.ignore();
            }
            else {
                cin >> select;
                cin.ignore();
            }

        } while (select != -1);

        cout << "\n\nPrograma Encerrado!" << endl;
    }

    return 0;
} 