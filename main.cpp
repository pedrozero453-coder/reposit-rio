#include <iostream>
#include <string>

// Classe que representa uma única tarefa
class Tarefa {
private:
    std::string descricao;
    bool concluida;

public:
    Tarefa(std::string desc) {
        descricao = desc;
        concluida = false;
    }

    void concluir() {
        concluida = true;
    }

    void exibir() {
        std::cout << "[" << (concluida ? "X" : " ") << "] " << descricao << std::endl;
    }
};

// Classe que gerencia a lista de tarefas usando ponteiros manuais
class GerenciadorTarefas {
private:
    Tarefa** lista;
    int capacidade;
    int quantidade;

public:
    GerenciadorTarefas(int cap) {
        capacidade = cap;
        quantidade = 0;
        lista = new Tarefa * [capacidade];
    }

   
    ~GerenciadorTarefas() {
        for (int i = 0; i < quantidade; i++) {
            delete lista[i]; // Deleta cada tarefa criada com 'new'
        }
        delete[] lista; // Deleta o array de ponteiros criado com 'new[]'
    }

    bool adicionarTarefa(std::string desc) {
        if (quantidade >= capacidade) {
            std::cout << "\n[Erro] Lista cheia!" << std::endl;
            return false;
        }

        lista[quantidade] = new Tarefa(desc);
        quantidade++;
        std::cout << "\nTarefa adicionada com sucesso!" << std::endl;
        return true;
    }

    void concluirTarefa(int indice) {
        if (indice >= 0 && indice < quantidade) {
            lista[indice]->concluir();
            std::cout << "\nTarefa " << indice + 1 << " concluida!" << std::endl;
        }
        else {
            std::cout << "\n[Erro] Indice invalido!" << std::endl;
        }
    }

    void listarTarefas() {
        if (quantidade == 0) {
            std::cout << "\nNenhuma tarefa cadastrada." << std::endl;
            return;
        }

        std::cout << "\n=== MINHAS TAREFAS ===" << std::endl;
        for (int i = 0; i < quantidade; i++) {
            std::cout << i + 1 << ". ";
            lista[i]->exibir();
        }
        std::cout << "======================\n" << std::endl;
    }

    int getQuantidade() { return quantidade; }
    int getCapacidade() { return capacidade; }
};

int main() {
    GerenciadorTarefas* gerenciador = new GerenciadorTarefas(5);
    int opcao = 0;

    do {
        std::cout << "1. Adicionar Tarefa" << std::endl;
        std::cout << "2. Listar Tarefas" << std::endl;
        std::cout << "3. Concluir Tarefa" << std::endl;
        std::cout << "4. Ver Status de Armazenamento" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        std::cin.ignore(); 

        switch (opcao) {
        case 1: {
            std::string novaDescricao;
            std::cout << "Digite a descricao da tarefa: ";
            std::getline(std::cin, novaDescricao);
            gerenciador->adicionarTarefa(novaDescricao);
            break;
        }
        case 2:
            gerenciador->listarTarefas();
            break;

        case 3: {
            int indice;
            std::cout << "Digite o numero da tarefa que concluiu: ";
            std::cin >> indice;
            gerenciador->concluirTarefa(indice - 1);
            break;
        }
        case 4: {
            int qtd = gerenciador->getQuantidade();
            int cap = gerenciador->getCapacidade();

            if (qtd == 0) {
                std::cout << "\nStatus: O sistema esta totalmente vazio.\n" << std::endl;
            }
            else if (qtd == cap) {
                std::cout << "\nStatus: Memoria cheia! Libere espaco ou reinicie.\n" << std::endl;
            }
            else {
                std::cout << "\nStatus: " << qtd << " de " << cap << " slots usados.\n" << std::endl;
            }
            break;
        }
        case 5:
            std::cout << "Saindo do programa..." << std::endl;
            break;

        default:
            std::cout << "Opcao invalida! Tente novamente.\n" << std::endl;
            break;
        }

    } while (opcao != 5);

    std::cout << "\nFechando aplicacao de forma segura..." << std::endl;
    int contador_fechamento = 3;
    while (contador_fechamento > 0) {
        std::cout << "Desconectando em " << contador_fechamento << "..." << std::endl;
        contador_fechamento--;
    }


    delete gerenciador; 
    return 0;
}

