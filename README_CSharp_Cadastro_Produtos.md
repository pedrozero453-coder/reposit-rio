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

## Código completo

```csharp
using System;
using System.Collections.Generic;

// Classe base
class Produto
{
    // Atributos privados
    private string nome;
    private double preco;
    private int quantidade;

    // Construtor
    public Produto(string nome, double preco, int quantidade)
    {
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    // Propriedades públicas (forma segura de acessar os privados)
    public string Nome
    {
        get { return nome; }
        set { nome = value; }
    }

    public double Preco
    {
        get { return preco; }
        set { preco = value; }
    }

    public int Quantidade
    {
        get { return quantidade; }
        set { quantidade = value; }
    }

    // Método virtual (pode ser sobrescrito)
    public virtual void Exibir()
    {
        Console.WriteLine($"Nome: {Nome}");
        Console.WriteLine($"Preço: R$ {Preco:F2}");
        Console.WriteLine($"Quantidade: {Quantidade}");
    }
}

// Classe filha (herança)
class ProdutoEletronico : Produto
{
    private int garantiaMeses;

    // Construtor da classe filha
    public ProdutoEletronico(string nome, double preco, int quantidade, int garantiaMeses)
        : base(nome, preco, quantidade) // chama o construtor da classe pai
    {
        this.garantiaMeses = garantiaMeses;
    }

    // Override (sobrescreve o método da classe pai)
    public override void Exibir()
    {
        base.Exibir(); // chama o método original da classe pai
        Console.WriteLine($"Garantia: {garantiaMeses} meses");
    }
}

class Program
{
    static void Main(string[] args)
    {
        List<Produto> lista = new List<Produto>();
        int opcao;

        do
        {
            Console.WriteLine("\n=== CADASTRO DE PRODUTOS ===");
            Console.WriteLine("1. Adicionar Produto Comum");
            Console.WriteLine("2. Adicionar Produto Eletrônico");
            Console.WriteLine("3. Listar Produtos");
            Console.WriteLine("4. Sair");
            Console.Write("Escolha uma opção: ");
            opcao = int.Parse(Console.ReadLine());

            switch (opcao)
            {
                case 1:
                    Console.Write("Nome do produto: ");
                    string nome1 = Console.ReadLine();

                    Console.Write("Preço: ");
                    double preco1 = double.Parse(Console.ReadLine().Replace('.', ','));

                    Console.Write("Quantidade: ");
                    int qtd1 = int.Parse(Console.ReadLine());

                    // Criando objeto da classe base
                    Produto p1 = new Produto(nome1, preco1, qtd1);
                    lista.Add(p1);

                    Console.WriteLine("\nProduto comum adicionado!");
                    break;

                case 2:
                    Console.Write("Nome do produto: ");
                    string nome2 = Console.ReadLine();

                    Console.Write("Preço: ");
                    double preco2 = double.Parse(Console.ReadLine().Replace('.', ','));

                    Console.Write("Quantidade: ");
                    int qtd2 = int.Parse(Console.ReadLine());

                    Console.Write("Garantia (em meses): ");
                    int garantia = int.Parse(Console.ReadLine());

                    // Criando objeto da classe filha
                    ProdutoEletronico p2 = new ProdutoEletronico(nome2, preco2, qtd2, garantia);
                    lista.Add(p2);

                    Console.WriteLine("\nProduto eletrônico adicionado!");
                    break;

                case 3:
                    if (lista.Count == 0)
                    {
                        Console.WriteLine("\nNenhum produto cadastrado.");
                    }
                    else
                    {
                        Console.WriteLine("\n=== LISTA DE PRODUTOS ===");

                        for (int i = 0; i < lista.Count; i++)
                        {
                            Console.WriteLine($"\nProduto {i + 1}:");
                            lista[i].Exibir(); // polimorfismo (chama o método certo)
                            Console.WriteLine("----------------------");
                        }
                    }

                    break;

                case 4:
                    Console.WriteLine("Saindo...");
                    break;

                default:
                    Console.WriteLine("Opção inválida!");
                    break;
            }

        } while (opcao != 4);
    }
}
```

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

### 2. Substituir o código

Abra o arquivo:

```text
Program.cs
```

Apague o conteúdo existente e coloque o código deste README dentro dele.

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
