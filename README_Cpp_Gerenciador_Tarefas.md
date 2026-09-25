### Gerenciador de Tarefas em C++

Um programa de console desenvolvido em C++ para praticar conceitos fundamentais de Programação Orientada a Objetos (POO), ponteiros e gerenciamento manual de memória de forma segura. 

O sistema permite adicionar tarefas, listar tarefas, concluí-las e verificar o estado do armazenamento disponível. 

### Conceitos utilizados

O projeto foi desenvolvido para demonstrar os seguintes conceitos: 

* **Classes e objetos** — Tarefa e GerenciadorTarefas.
* **Encapsulamento** — os atributos das classes são privados e acessados através de métodos públicos.
* **Ponteiros** — utilizados para armazenar e acessar objetos dinamicamente.
* **Alocação dinâmica de memória** — utilização de new e liberação manual com delete / delete[].
* **Destrutores** — implementados para limpar a memória alocada dinamicamente e evitar vazamentos de memória (*memory leaks*).
* **Ponteiro para ponteiro (Tarefa**)** — utilizado para criar uma lista dinâmica de ponteiros para tarefas.
* **Operador ->** — utilizado para acessar métodos de objetos através de ponteiros.
* **Construtores** — utilizados para inicializar as classes.
* **do while** — utilizado para manter o menu funcionando até o usuário escolher sair.
* **switch case** — utilizado para controlar as opções do menu.
* **for** — utilizado para percorrer e listar as tarefas.
* **if / else if / else** — utilizado para verificar o estado do armazenamento.
* **while** — utilizado no processo de encerramento do programa.

### Funcionalidades

O programa possui cinco opções: 

1. **Adicionar Tarefa** 

  * Permite cadastrar uma nova tarefa.
  * O sistema possui capacidade inicial para até 5 tarefas.
2. **Listar Tarefas** 

  * Exibe todas as tarefas cadastradas.
  * Uma tarefa pendente aparece como [ ].
  * Uma tarefa concluída aparece como [X].
3. **Concluir Tarefa** 

  * Permite selecionar uma tarefa pelo número.
  * Altera seu estado para concluída.
4. **Ver Status de Armazenamento** 

  * Informa quantos espaços estão sendo utilizados.
  * Informa quando a lista está vazia.
  * Informa quando a capacidade máxima foi atingida.
5. **Sair** 

  * Encerra o menu principal, libera as alocações da memória e inicia o processo de fechamento.

### Estrutura das classes

### Tarefa

Representa uma única tarefa. 

* **Atributos privados:** descricao, concluida.
* **Métodos públicos:** Tarefa(std::string desc), void concluir(), void exibir().

### GerenciadorTarefas

É responsável por gerenciar e limpar a lista de tarefas. 

* **Atributos privados:** lista (ponteiro para ponteiros), capacidade, quantidade.
* **Métodos públicos:** GerenciadorTarefas(int cap), ~GerenciadorTarefas() (Destrutor), bool adicionarTarefa(std::string desc), void concluirTarefa(int indice), void listarTarefas(), int getQuantidade(), int getCapacidade().

### Gerenciamento Seguro de Memória

Embora este projeto utilize alocação manual com new para fins didáticos, o código foi estruturado para evitar desperdício de recursos através de gerenciamento manual estrito: 

cpp

~GerenciadorTarefas() {
    for (int i = 0; i < quantidade; i++) {
        delete lista[i]; // Libera cada tarefa individual da memória
    }
    delete[] lista; // Libera o array de ponteiros principal
}

Use o código com cuidado.

### Como executar

### Pré-requisito

É necessário ter um compilador C++ instalado. Verifique rodando no terminal: 

bash

g++ --version

Use o código com cuidado.

### 1. Compilar

Abra o terminal na pasta do projeto e execute: 

bash

g++ main.cpp -o gerenciador -std=c++17

Use o código com cuidado.

### 2. Executar

* **Windows:** gerenciador.exe
* **Linux/macOS:** ./gerenciador

### Exemplo de uso

text

1. Adicionar Tarefa
2. Listar Tarefas
3. Concluir Tarefa
4. Ver Status de Armazenamento
5. Sair
Escolha uma opcao: 1

Digite a descricao da tarefa: Estudar C++
Tarefa adicionada com sucesso!

Use o código com cuidado.

### Licença

Projeto criado estritamente para fins de estudo e fixação de conceitos de ponteiros.
