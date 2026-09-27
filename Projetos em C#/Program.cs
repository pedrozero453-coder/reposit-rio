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
