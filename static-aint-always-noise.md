# Static ain't always noise

| Campo | Valor |
| --- | --- |
| Plataforma | CyLab Security Academy (ex-picoCTF) |
| Categoria oficial | General Skills |
| Ênfase deste writeup | Engenharia reversa estática básica  |
| Dificuldade | Fácil (Easy) |
| Autor | SYREAL |
| Origem | picoCTF 2021 — Challenge Library |

## Objetivo

O desafio entrega dois arquivos prontos:

- `static` — binário compilado
- `ltdis.sh` — script auxiliar do próprio desafio

A tarefa é achar a flag olhando o conteúdo do binário, sem precisar executá-lo.

## Resolução

### 1. Ver o que é o arquivo `static`

```bash
file static
```

O `file` lê a assinatura do arquivo e diz o tipo. O retorno mostrou que `static` é um executável ELF 64-bit para Linux (x86-64), dinamicamente linkado e *not stripped*.

Isso só confirma que é um programa Linux, não um texto ou um compactado. Não executa o binário.

### 2. Liberar o script do desafio

O `ltdis.sh` veio junto no download. Sem o bit de execução o terminal não roda ele direto:

```bash
chmod +x ltdis.sh
```

### 3. Rodar o script no binário

```bash
./ltdis.sh static
```

O próprio script avisou que gerou dois arquivos no mesmo diretório:

- `static.ltdis.x86_64.txt` — dump em Assembly
- `static.ltdis.strings.txt` — textos legíveis extraídos do binário

### 4. Olhar o Assembly

Abri `static.ltdis.x86_64.txt`. Reconheci trechos isolados (instruções básicas). Não li o arquivo inteiro e não reconstruí a lógica do programa. A flag não estava óbvia nesse dump.

### 5. Ler as strings e achar a flag

```bash
cat static.ltdis.strings.txt
```

`cat` imprime o arquivo no terminal. O dump era pequeno. Percorri a listagem e localizei a flag visualmente pelo prefixo `academy{`.

Writeups antigos do picoCTF mostram `picoCTF{` no mesmo desafio. Nesta instância o prefixo era `academy{`.

## Flag

```text
academy{...}
```

*(valor da instância omitido no portfólio)*

## O que isso mostra

A flag estava escrita em claro dentro do binário. Por isso apareceu no arquivo de strings. Segredo hardcoded em executável dá para ler sem rodar o programa.
