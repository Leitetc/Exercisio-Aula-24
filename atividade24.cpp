#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estado {
public:
    string nome;
    string sigla;

    Estado(string nome, string sigla) : nome(nome), sigla(sigla) {}
};

class Cidade {
public:
    string nome;
    Estado* estado;

    Cidade(string nome, Estado* estado) : nome(nome), estado(estado) {}
};

int main() {
    vector<Estado> estados;
    vector<Cidade> cidades;

    // Lê informações dos estados
    int numEstados = 0;
    cout << "Quantos estados deseja cadastrar? ";
    cin >> numEstados;
    cin.ignore(); // Limpa o buffer

    for (int i = 0; i < numEstados; i++) {
        string nome, sigla;
        cout << "Nome do estado " << i + 1 << ": ";
        getline(cin, nome);
        cout << "Sigla do estado " << i + 1 << ": ";
        cin >> sigla;
        cin.ignore(); // Limpa o buffer

        Estado estado(nome, sigla);
        estados.push_back(estado);
    }

    // Lê informações das cidades
    int numCidades = 0;
    cout << "Quantas cidades deseja cadastrar? ";
    cin >> numCidades;
    cin.ignore(); // Limpa o buffer

    for (int i = 0; i < numCidades; i++) {
        string nome;
        int estadoIndex;
        cout << "Nome da cidade " << i + 1 << ": ";
        getline(cin, nome);

        cout << "Selecione o estado da cidade " << i + 1 << ":" << endl;
        for (int j = 0; j < numEstados; j++) {
            cout << j + 1 << ". " << estados[j].nome << " (" << estados[j].sigla << ")" << endl;
        }
        cin >> estadoIndex;
        cin.ignore(); // Limpa o buffer

        if (estadoIndex >= 1 && estadoIndex <= numEstados) {
            Cidade cidade(nome, &estados[estadoIndex - 1]);
            cidades.push_back(cidade);
        } else {
            cout << "Opção inválida. Cidade não cadastrada." << endl;
        }
    }

    // Exibe os estados e cidades cadastrados
    cout << "Estados cadastrados:" << endl;
    for (int i = 0; i < numEstados; i++) {
        cout << estados[i].nome << " (" << estados[i].sigla << ")" << endl;
    }

    cout << "Cidades cadastradas:" << endl;
    for (int i = 0; i < numCidades; i++) {
        cout << cidades[i].nome << " - " << cidades[i].estado->nome << " (" << cidades[i].estado->sigla << ")" << endl;
    }

    return 0;
}
