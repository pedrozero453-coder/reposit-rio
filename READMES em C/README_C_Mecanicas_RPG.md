# Sistema de Inventário e Mapa em C

Projeto desenvolvido em linguagem C como exercício de fundamentos de programação, trabalhando principalmente com funções, matrizes, vetores, strings, ponteiros, entrada de dados e estruturas de controle.

O programa simula uma pequena estrutura de jogo em terminal, contendo um menu principal, um inventário editável e um mapa 5x5.

## Funcionalidades

- Exibição de uma mensagem inicial de boas-vindas.
- Menu principal com opções para:
  - Abrir o inventário.
  - Sair do menu e exibir o mapa.
- Inventário com 8 espaços.
- Alteração do nome dos itens do inventário.
- Utilização de `fgets()` para receber nomes de itens.
- Mapa representado por uma matriz `5x5`.
- Exibição do mapa no terminal.
- Organização do código em funções independentes.

## Conceitos de C utilizados

Este projeto foi desenvolvido para praticar conceitos fundamentais da linguagem C, incluindo:

- `#include <stdio.h>`
- Funções.
- Matrizes bidimensionais.
- Arrays de caracteres (strings).
- Ponteiros.
- Vetores de ponteiros.
- Estruturas `while` e `do while`.
- Estrutura `switch`.
- Estruturas condicionais `if`.
- Laços `for`.
- Entrada de dados com `scanf()`.
- Entrada de strings com `fgets()`.
- Manipulação básica do buffer de entrada.
- `#define` para configuração de compilação.

## Estrutura do programa

O código possui quatro funções principais:

### `mapa()`

Cria e exibe uma matriz de caracteres de 5x5.

Cada posição do mapa é inicialmente preenchida com um espaço:

```c
char mostrarMapa[5][5] = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};
```

Depois, dois loops `for` percorrem a matriz e exibem cada posição no terminal.

### `inventario(int alterarEspaco)`

Controla o inventário do jogador.

Inicialmente existem oito itens:

1. Espada
2. Pocao
3. Escudo
4. Chave
5. Arco
6. Flechas
7. Tochas
8. Vazio

Os itens são armazenados em arrays de caracteres e posteriormente reunidos em um vetor de ponteiros:

```c
char* inventarioJogador[8] = {
    item1, item2, item3, item4,
    item5, item6, item7, item8
};
```

O jogador pode selecionar uma posição de 1 a 8 e substituir o nome do item.

As opções 9 e 10 fazem o programa sair da tela do inventário.

### `Menu(int selecionar)`

Responsável pelo menu principal.

O jogador pode:

```text
1 - Abrir Inventario
2 - Sair e exibir mapa
```

A função utiliza `switch` para identificar a opção escolhida e executar a operação correspondente.

### `main()`

É o ponto de entrada do programa.

A execução começa mostrando:

```text
Bem-vindo, Jogador!
```

Em seguida, o menu principal é iniciado. Quando o jogador sai do menu, o mapa é exibido.

## Como executar

Você precisa de um compilador C instalado no computador.

Algumas opções são:

- GCC / MinGW
- Clang
- Visual Studio
- Visual Studio Code com um compilador C configurado

### Opção 1 — GCC / MinGW no Windows

Salve o código em um arquivo chamado:

```text
main.c
```

Abra o terminal na pasta onde o arquivo está localizado e execute:

```bash
gcc main.c -o jogo.exe
```

Se a compilação for concluída sem erros, execute:

```bash
jogo.exe
```

No PowerShell, também pode ser necessário utilizar:

```powershell
.\jogo.exe
```

### Opção 2 — GCC no Linux

Compile com:

```bash
gcc main.c -o jogo
```

Depois execute:

```bash
./jogo
```

### Opção 3 — Visual Studio

O código contém:

```c
#define _CRT_SECURE_NO_WARNINGS
```

Essa diretiva permite evitar alguns avisos relacionados às funções de entrada consideradas inseguras pelo compilador da Microsoft.

No Visual Studio:

1. Crie um projeto de C/C++.
2. Adicione um arquivo `main.c`.
3. Cole o código do projeto.
4. Compile o projeto.
5. Execute pelo Visual Studio.

## Exemplo de execução

Ao iniciar o programa:

```text
Bem-vindo, Jogador!

=== MENU PRINCIPAL ===
1 - Abrir Inventario
2 - Sair e exibir mapa
Escolha uma opcao:
```

Ao escolher o inventário:

```text
=== SEU INVENTARIO ===
[1] Espada
[2] Pocao
[3] Escudo
[4] Chave
[5] Arco
[6] Flechas
[7] Tochas
[8] Vazio

Digite de 1 a 8 para alterar um item.
Digite 9 ou 10 para voltar ao menu:
```

Ao sair do menu, o mapa é exibido:

```text
=== MAPA DO JOGO ===
[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]
```

## Observações

Este projeto é um exercício de programação em C e representa uma implementação inicial de sistemas que poderiam fazer parte de um jogo maior.

O projeto pode ser expandido futuramente com funcionalidades como:

- Movimentação do jogador pelo mapa.
- Sistema de posição.
- Colisão com obstáculos.
- Itens consumíveis.
- Sistema de vida.
- Inimigos.
- Salvar e carregar o estado do jogador.
- Múltiplos mapas.
- Sistema de combate.
- Interface de terminal mais completa.



## Objetivo do projeto

O objetivo principal deste projeto é praticar fundamentos da linguagem C através da criação de uma estrutura simples de jogo em terminal.

O projeto também serve como base para implementar sistemas mais complexos de jogos utilizando C.

##Licença
Projeto criado para fins de estudo.

## Link para o projeto
https://github.com/pedrozero453-coder/reposit-rio/blob/main/main.c
