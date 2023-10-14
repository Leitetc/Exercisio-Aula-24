#include <iostream>
#include <vector>
#include <string>

//atividade 01
using namespace std;

class Cidade {
private:
    string nomec;

public:
    Cidade(string nomec) : nomec(nomec) {}

    void setNome(string _nomec) {
        nomec = _nomec;
    }

    string getNomec() {
        return nomec;
    }
};

class Estado {
private:
    string nome;
    string sigla;
    vector<Cidade> cidades;

public:
    Estado(string no, string si) : nome(no), sigla(si) {}

    void setNome(string _no) {
        nome = _no;
    }

    string getNome() {
        return nome;
    }

    void setSigla(string _si) {
        sigla = _si;
    }

    string getSigla() {
        return sigla;
    }

    void adicionarCidade(const Cidade& cidade) {
        cidades.push_back(cidade);
    }

    vector<Cidade>& getCidades() {
        return cidades;
    }
};

void IncluirEstado(vector<Estado>& estados) {
    char sn;

    do {
        string nome, sigla;
        cout << "Informe o nome do estado: ";
        cin.ignore(); // Ignora caracteres pendentes no buffer, se houver
        getline(cin, nome);
        cout << "Informe a sigla do estado: ";
        cin >> sigla;
        Estado novoEstado(nome, sigla);

        string nomeCidade;
        cin.ignore(); // Ignora caracteres pendentes no buffer, se houver
        cout << "Informe o nome da cidade: ";
        getline(cin, nomeCidade);
        Cidade novaCidade(nomeCidade);

        novoEstado.adicionarCidade(novaCidade);

        estados.push_back(novoEstado);
        cout << "Estado incluído com sucesso!" << endl;

        cout << "Deseja inserir mais um ponto (s/n)? ";
        cin >> sn;
    } while (sn != 'n');
}

void ListarEstados(vector<Estado>& estados) {
    if (estados.empty()) {
        cout << "Nenhum estado cadastrado." << endl;
        return;
    }

    cout << endl << "Lista de Estados:" << endl;
    for (Estado& estado : estados) {
        cout << "Estado: " << estado.getNome() << " - " << estado.getSigla() << endl;
        cout << "Cidades: ";
        for (Cidade& cidade : estado.getCidades()) {
            cout << cidade.getNomec() << " ";
        }
        cout << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {
    vector<Estado> estados;
    int escolha;

    do {
        cout << endl << "Menu de Opcoes:" << endl;
        cout << "1. Incluir Estado" << endl;
        cout << "2. Listar estados cadastrados" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirEstado(estados);
                break;
            case 2:
                ListarEstados(estados);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (escolha != 0);

    return 0;
}
