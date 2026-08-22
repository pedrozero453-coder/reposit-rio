# Cadastro de Produtos em C#

Um programa de console desenvolvido em **C#** para praticar conceitos fundamentais de **Programação Orientada a Objetos (POO)**.

O sistema permite cadastrar produtos comuns e produtos eletrônicos, armazená-los em uma lista e exibir suas informações através de um menu interativo.

## Conceitos de POO utilizados

O projeto foi desenvolvido para demonstrar os seguintes conceitos:

- **Encapsulamento** — os atributos da classe `Produto` são privados e acessados através de propriedades públicas.
- **Herança** — `ProdutoEletronico` herda de `Produto`.
- **Polimorfismo** — o método `Exibir()` é `virtual` na classe base e sobrescrito com `override` na classe filha.
- **Construtores** — utilizados para inicializar os objetos.
- **Listas** — os produtos são armazenados em uma `List<Produto>`.
- **Override** — permite que produtos eletrônicos exibam informações adicionais.
- **Base** — permite chamar o construtor e o método da classe pai.

## Funcionalidades

O programa possui quatro opções:

1. **Adicionar Produto Comum**
   - Nome
   - Preço
   - Quantidade

2. **Adicionar Produto Eletrônico**
   - Nome
   - Preço
   - Quantidade
   - Garantia em meses

3. **Listar Produtos**
   - Exibe todos os produtos cadastrados.
   - O programa utiliza polimorfismo para chamar o `Exibir()` correto de cada objeto.

4. **Sair**
   - Encerra o programa.

## Estrutura das classes

### `Produto`

É a classe base do projeto e possui:

- `nome`
- `preco`
- `quantidade`

Também possui o método:

```csharp
public virtual void Exibir()
```

### `ProdutoEletronico`

Herda da classe `Produto` e adiciona:

- `garantiaMeses`

O método `Exibir()` é sobrescrito:

```csharp
public override void Exibir()
```

Dessa forma, além das informações básicas do produto, a garantia também é exibida.



## Como executar

### Pré-requisito

É necessário ter o **.NET SDK** instalado.

Para verificar se o .NET está instalado, abra o terminal e execute:

```bash
dotnet --version
```

Se aparecer uma versão, o SDK está instalado.

### 1. Criar o projeto

Abra o terminal e execute:

```bash
dotnet new console -n CadastroProdutos
```

Entre na pasta:

```bash
cd CadastroProdutos
```

### 2. Inserir o codigo

Abra o arquivo:

```text
Program.cs
```
Cole o codigo do arquivo Program.cs


### 3. Executar

No terminal, dentro da pasta do projeto, execute:

```bash
dotnet run
```

O programa será iniciado e o menu aparecerá no terminal.

## Exemplo de uso

```text
=== CADASTRO DE PRODUTOS ===
1. Adicionar Produto Comum
2. Adicionar Produto Eletrônico
3. Listar Produtos
4. Sair
Escolha uma opção: 2

Nome do produto: Notebook
Preço: 3500
Quantidade: 2
Garantia (em meses): 12

Produto eletrônico adicionado!
```

Ao listar:

```text
=== LISTA DE PRODUTOS ===

Produto 1:
Nome: Notebook
Preço: R$ 3500,00
Quantidade: 2
Garantia: 12 meses
----------------------
```

## Objetivo do projeto

Este projeto tem como objetivo praticar os fundamentos de **C# e Programação Orientada a Objetos**, principalmente:

`Encapsulamento → Herança → Polimorfismo → Classes → Objetos → Construtores`

---

## Licença

Projeto criado para fins de estudo.
