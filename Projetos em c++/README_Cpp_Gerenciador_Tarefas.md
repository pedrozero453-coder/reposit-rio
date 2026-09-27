Gerenciador de Tarefas em C++

Um gerenciador de tarefas simples desenvolvido em C++, com foco no estudo de Programação Orientada a Objetos (POO) e gerenciamento manual de memória.

O programa permite adicionar, listar e concluir tarefas, além de verificar a capacidade atual de armazenamento.

Funcionalidades
Adicionar tarefas.
Listar tarefas cadastradas.
Marcar tarefas como concluídas.
Verificar o status de armazenamento.
Limitar a quantidade de tarefas pela capacidade definida.
Liberar corretamente a memória utilizada ao encerrar o programa.
Conceitos utilizados

O projeto utiliza conceitos fundamentais de C++, incluindo:

Classes e objetos
Encapsulamento
Construtores
Destrutor
Métodos
Ponteiros
Ponteiro para ponteiro (Tarefa**)
Alocação dinâmica com new
Liberação de memória com delete
Liberação de arrays com delete[]
std::string
std::cin e std::cout
Condicionais
Laços de repetição
switch / case
Estrutura do projeto

O programa possui duas classes principais.

Tarefa

Representa uma tarefa individual.

Cada tarefa possui uma descrição e um estado de conclusão:

std::string descricao;
bool concluida;

A classe possui métodos para concluir e exibir a tarefa.

Exemplo:

[ ] Estudar C++
[X] Fazer exercícios
GerenciadorTarefas

Responsável por armazenar e gerenciar as tarefas.

O armazenamento utiliza um array dinâmico de ponteiros:

Tarefa** lista;

A capacidade é definida na criação do gerenciador:

GerenciadorTarefas* gerenciador = new GerenciadorTarefas(5);

Cada tarefa é criada dinamicamente utilizando new:

lista[quantidade] = new Tarefa(desc);

Ao finalizar o programa, o destrutor libera a memória das tarefas e posteriormente o array de ponteiros:

for (int i = 0; i < quantidade; i++) {
    delete lista[i];
}

delete[] lista;
Menu

O programa apresenta as seguintes opções:

1. Adicionar Tarefa
2. Listar Tarefas
3. Concluir Tarefa
4. Ver Status de Armazenamento
5. Sair
Exemplo

Ao adicionar uma tarefa:

Escolha uma opcao: 1
Digite a descricao da tarefa: Estudar ponteiros

Tarefa adicionada com sucesso!

Ao listar:

=== MINHAS TAREFAS ===
1. [ ] Estudar ponteiros
======================

Após concluir:

Escolha uma opcao: 3
Digite o numero da tarefa que concluiu: 1

Tarefa 1 concluida!

Resultado:

=== MINHAS TAREFAS ===
1. [X] Estudar ponteiros
======================
Compilação

Com G++:

g++ main.cpp -o tarefas
Linux / macOS
./tarefas
Windows
tarefas.exe
Estrutura
gerenciador-tarefas/
│
├── main.cpp
└── README.md
Objetivo

Este projeto foi desenvolvido para praticar C++, Programação Orientada a Objetos, ponteiros e gerenciamento manual de memória por meio de uma aplicação simples e funcional.
