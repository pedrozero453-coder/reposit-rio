# Gerenciador de Tarefas em C++

Um programa de console desenvolvido em **C++** para praticar conceitos fundamentais de **Programação Orientada a Objetos (POO)**, ponteiros e gerenciamento manual de memória.

O sistema permite adicionar tarefas, listar tarefas, concluí-las e verificar o estado do armazenamento disponível.

## Conceitos utilizados

O projeto foi desenvolvido para demonstrar os seguintes conceitos:

- **Classes e objetos** — `Tarefa` e `GerenciadorTarefas`.
- **Encapsulamento** — os atributos das classes são privados e acessados através de métodos públicos.
- **Ponteiros** — utilizados para armazenar e acessar objetos dinamicamente.
- **Alocação dinâmica de memória** — utilização de `new`.
- **Ponteiro para ponteiro (`Tarefa**`)** — utilizado para criar uma lista dinâmica de ponteiros para tarefas.
- **Operador `->`** — utilizado para acessar métodos de objetos através de ponteiros.
- **Construtores** — utilizados para inicializar as classes.
- **`do while`** — utilizado para manter o menu funcionando até o usuário escolher sair.
- **`switch case`** — utilizado para controlar as opções do menu.
- **`for`** — utilizado para percorrer e listar as tarefas.
- **`if / else if / else`** — utilizado para verificar o estado do armazenamento.
- **`while`** — utilizado no processo de encerramento do programa.

## Funcionalidades

O programa possui cinco opções:

1. **Adicionar Tarefa**
   - Permite cadastrar uma nova tarefa.
   - O sistema possui capacidade para até 5 tarefas.

2. **Listar Tarefas**
   - Exibe todas as tarefas cadastradas.
   - Uma tarefa pendente aparece como `[ ]`.
   - Uma tarefa concluída aparece como `[X]`.

3. **Concluir Tarefa**
   - Permite selecionar uma tarefa pelo número.
   - Altera seu estado para concluída.

4. **Ver Status de Armazenamento**
   - Informa quantos espaços estão sendo utilizados.
   - Informa quando a lista está vazia.
   - Informa quando a capacidade máxima foi atingida.

5. **Sair**
   - Encerra o menu principal e inicia o processo de fechamento.

## Estrutura das classes

### `Tarefa`

Representa uma única tarefa.

Possui os atributos privados:

- `descricao`
- `concluida`

E os métodos:

```cpp
Tarefa(std::string desc);
void concluir();
void exibir();
```

O método `concluir()` altera o estado da tarefa para concluída.

O método `exibir()` mostra a tarefa utilizando:

```text
[ ] Tarefa pendente
[X] Tarefa concluída
```

### `GerenciadorTarefas`

É responsável por gerenciar várias tarefas.

Possui:

- `lista` — ponteiro para os ponteiros das tarefas.
- `capacidade` — quantidade máxima de tarefas.
- `quantidade` — quantidade atual de tarefas cadastradas.

Principais métodos:

```cpp
bool adicionarTarefa(std::string desc);
void concluirTarefa(int indice);
void listarTarefas();
int getQuantidade();
int getCapacidade();
```

A lista é criada dinamicamente através de:

```cpp
lista = new Tarefa*[capacidade];
```

E cada tarefa também é criada dinamicamente:

```cpp
lista[quantidade] = new Tarefa(desc);
```

## Ponteiros utilizados no projeto

Um dos principais objetivos deste código é praticar ponteiros.

### Ponteiro para objeto

No `main`, o gerenciador é criado desta forma:

```cpp
GerenciadorTarefas* gerenciador = new GerenciadorTarefas(5);
```

A variável `gerenciador` não armazena diretamente o objeto. Ela armazena o **endereço de memória** do objeto.

Por isso, para acessar seus métodos é utilizado o operador:

```cpp
gerenciador->adicionarTarefa(novaDescricao);
```

### Ponteiro para ponteiro

A classe `GerenciadorTarefas` utiliza:

```cpp
Tarefa** lista;
```

Isso significa que `lista` é um ponteiro para ponteiros de `Tarefa`.

A estrutura permite armazenar vários endereços de objetos `Tarefa`:

```text
lista
  |
  +----> Tarefa 1
  |
  +----> Tarefa 2
  |
  +----> Tarefa 3
  |
  +----> Tarefa 4
  |
  +----> Tarefa 5
```

## Estruturas de controle

### `do while`

O menu principal utiliza `do while` para garantir que o menu seja executado pelo menos uma vez:

```cpp
do
{
    // menu
} while (opcao != 5);
```

### `switch case`

O `switch` direciona o programa para a ação correspondente à opção escolhida:

```cpp
switch (opcao)
{
    case 1:
        // adicionar tarefa
        break;

    case 2:
        // listar tarefas
        break;

    // ...
}
```

### `for`

O `for` percorre todas as tarefas cadastradas:

```cpp
for (int i = 0; i < quantidade; i++)
{
    lista[i]->exibir();
}
```

### `if / else if / else`

Utilizado para verificar o estado do armazenamento:

```cpp
if (qtd == 0)
{
    // vazio
}
else if (qtd == cap)
{
    // cheio
}
else
{
    // parcialmente utilizado
}
```

### `while`

Um `while` é utilizado no encerramento para realizar uma pequena contagem regressiva:

```cpp
while (contador_fechamento > 0)
{
    std::cout << "Desconectando em "
              << contador_fechamento << "..." << std::endl;

    contador_fechamento--;
}
```

## Código completo

```cpp
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

        // O comando 'new' tem o trabalho de criar um novo espaço na memória para a lista (ou, em outros casos, para variáveis, objetos, entre outros).
        lista = new Tarefa * [capacidade];
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

    // Uso do FOR para percorrer os ponteiros
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

    // 1. Uso do DO WHILE para o menu principal
    do {
        std::cout << "1. Adicionar Tarefa" << std::endl;
        std::cout << "2. Listar Tarefas" << std::endl;
        std::cout << "3. Concluir Tarefa" << std::endl;
        std::cout << "4. Ver Status de Armazenamento" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        std::cin.ignore(); // Limpa o buffer do cin

        // 2. Uso do SWITCH CASE para o roteamento das opções principais
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

            // 3. Uso do ELSE IF para verificar o estado do armazenamento
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

    // 4. Uso do WHILE demonstrando uma busca ou processamento secundário antes de fechar
    std::cout << "\nFechando aplicacao de forma segura..." << std::endl;
    int contador_fechamento = 3;
    while (contador_fechamento > 0) {
        std::cout << "Desconectando em " << contador_fechamento << "..." << std::endl;
        contador_fechamento--;
    }

    // O comando '->' serve para acessar membros (funções ou variáveis) de um objeto através de seu ponteiro.
    return 0;
}
```

## Como executar

### Pré-requisito

É necessário ter um compilador C++ instalado.

Você pode verificar se o **g++** está instalado executando no terminal:

```bash
g++ --version
```

Se aparecer a versão do compilador, ele está pronto para ser utilizado.

## 1. Criar o arquivo

Crie um arquivo chamado:

```text
main.cpp
```

Cole o código completo deste README dentro dele.

## 2. Compilar

Abra o terminal na pasta onde está o arquivo `main.cpp` e execute:

```bash
g++ main.cpp -o gerenciador
```

Para utilizar um padrão moderno do C++, também pode executar:

```bash
g++ main.cpp -o gerenciador -std=c++17
```

## 3. Executar

No Windows:

```bash
gerenciador.exe
```

No Linux/macOS:

```bash
./gerenciador
```

## Exemplo de uso

Ao iniciar o programa:

```text
1. Adicionar Tarefa
2. Listar Tarefas
3. Concluir Tarefa
4. Ver Status de Armazenamento
5. Sair
Escolha uma opcao:
```

Ao adicionar uma tarefa:

```text
Digite a descricao da tarefa: Estudar C++

Tarefa adicionada com sucesso!
```

Ao listar:

```text
=== MINHAS TAREFAS ===
1. [ ] Estudar C++
======================
```

Depois de concluir:

```text
Digite o numero da tarefa que concluiu: 1

Tarefa 1 concluida!
```

A lista passa a mostrar:

```text
=== MINHAS TAREFAS ===
1. [X] Estudar C++
======================
```

## Objetivo do projeto

Este projeto tem como objetivo praticar fundamentos de **C++**, principalmente:

`Classes → Objetos → Encapsulamento → Ponteiros → new → Operador -> → Estruturas de controle → Gerenciamento de memória`

Além disso, o projeto serve como exercício para entender como objetos podem ser criados dinamicamente e acessados através de ponteiros.

## Observação sobre gerenciamento de memória

Este código utiliza `new` para alocar memória manualmente. Em um projeto real, seria necessário liberar essa memória utilizando `delete`/`delete[]` ou, preferencialmente, utilizar recursos modernos do C++, como **RAII**, `std::vector` e **smart pointers** (`std::unique_ptr` e `std::shared_ptr`).

Neste projeto, a alocação manual foi mantida propositalmente para praticar o funcionamento de ponteiros e memória dinâmica.

---

## Licença

Projeto criado para fins de estudo.
