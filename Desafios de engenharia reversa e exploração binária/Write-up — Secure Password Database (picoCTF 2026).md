# Secure Password Database — picoCTF 2026

*picoCTF 2026 · Reverse Engineering · 200 pts*

O desafio entrega um binário que pede uma senha, depois o tamanho dessa senha e, por fim, um "hash" para liberar a conta. Se o hash estiver certo, o programa imprime a flag. Meu objetivo era descobrir que hash era esse.

## 1. Lendo a main

Comecei abrindo a `main` no Ghidra e lendo o que eu conseguia entender, pesquisando o que eu não conhecia e sem me prender em cada detalhe. Logo na primeira entrada de dados, a da senha, o `fgets` usa o limite `0x32`, ou seja, 50 bytes. Como o destino é um array de `char` e cada `char` ocupa 1 byte, a senha aceita até 50 caracteres.

```c
pcVar2 = fgets(acStack_b9 + 1,0x32,stdin);
```

Mais abaixo, o programa pergunta o tamanho da senha, guarda a resposta em `local_d8` (outro array de `char`) e usa o `atoi` para transformar o que eu digitei em número.

```c
pcVar2 = fgets(local_d8,0x14,stdin);
...
uVar1 = atoi(local_d8);
```

Nessa primeira passada eu nem li o `for` que vem logo depois do `atoi`. Ainda estava um pouco confuso com o código e preferi focar no que realmente parecia importante.

## 2. A função make\_secret

Foi então que fui ler a `make_secret`. Percebi que ela não fazia nada além de uma espécie de descriptografia: pega uma sequência de bytes guardada no programa e aplica um XOR com uma chave fixa em cada byte. No fim, ela ainda passa o resultado pela função `hash` e devolve o valor. Mais tarde isso se revelou o valor principal que eu precisava para pegar a flag.

```c
void make_secret(long param_1)
{
  long local_10;

  for (local_10 = 0; obf_bytes[local_10] != '\0'; local_10 = local_10 + 1) {
    *(byte *)(local_10 + param_1) = obf_bytes[local_10] ^ /* chave oculta */;
  }
  *(undefined1 *)(param_1 + 0xc) = 0;
  hash(param_1);
  return;
}
```

## 3. A comparação que decide tudo

Voltando para a `main`, vi que a flag só é lida (`fopen("flag.txt", ...)`) se uma comparação for verdadeira:

```c
local_100 = strtoul(acStack_b9 + 1,&local_120,10);
...
local_f8 = make_secret(local_e5);
if (local_f8 == local_100) {
  local_f0 = fopen("flag.txt","r");
```

Ou seja: `local_100` é o número que eu digito no prompt do hash (o `strtoul` converte o texto para número) e `local_f8` é o que a `make_secret` retornou. A senha que eu digitei no começo nem entra nessa conta. Bastava eu descobrir o valor de `local_f8` e digitar exatamente ele.

O problema é que, por ser uma variável local, o decompilador não me dava um endereço fixo para ela. Então fui olhar o assembly dessa parte e escolhi trabalhar com esta instrução, que é a comparação em si:

```asm
CALL       make_secret
MOV        qword ptr [RBP + local_f8],RAX
MOV        RAX,qword ptr [RBP + local_f8]
CMP        RAX,qword ptr [RBP + local_100]
```

Na lista de variáveis da função, o Ghidra mostra `local_f8` em `Stack[-0xf8]`, o que no GDB vira `[rbp-0xf8]`. Ou seja, o retorno da `make_secret` fica guardado ali, e era exatamente ali que eu precisava olhar.

## 4. Olhando a memória no GDB

Abri o binário no GDB, coloquei um breakpoint na `main` e segui a execução até a comparação. Quando cheguei nela, a instrução que eu via era `MOV RAX, QWORD PTR [rbp-0xf8]`. Só precisei mandar o GDB mostrar o que estava nesse endereço, em 64 bits (8 bytes, o tamanho de um `ulong`):

```
(gdb) break main
(gdb) run
# segui a execução até passar pela make_secret
(gdb) x/gx $rbp-0xf8
<endereço>:    0x[valor oculto]
```

O GDB me devolveu o valor em hexadecimal, já com os 64 bits preenchidos: `0x[valor oculto]`.

## 5. De hexadecimal para decimal

O `strtoul` da `main` recebe o número `10` como último argumento, e isso quer dizer que ele espera a entrada na **base 10**, em decimal. Se eu digitasse o hexadecimal do jeito que o GDB mostrou, não ia funcionar. Como de cabeça eu não faço essa conversão, usei uma ferramenta para fazer isso por mim:

- Hexadecimal: `0x[valor oculto]`
- Decimal: `[valor oculto]`

## 6. Testando

Rodei o programa de novo, informei uma senha qualquer e, quando chegou no prompt `Enter your hash to access your account!`, digitei o número decimal que eu tinha calculado. A validação `if (local_f8 == local_100)` foi satisfeita e o programa abriu o `flag.txt` e imprimiu a flag.

**Flag:** `picoCTF{[oculta]}`
