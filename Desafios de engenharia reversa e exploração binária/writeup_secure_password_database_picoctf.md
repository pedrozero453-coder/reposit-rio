**Write-up — Secure Password Database**

picoCTF 2026 • Reverse Engineering • Ghidra + GDB

**Desafio identificado:** Secure Password Database, da picoCTF 2026.

# 1. Entendendo o fluxo do programa

Depois de ler o código com mais atenção, identifiquei que o desafio era o **Secure Password Database**, da picoCTF 2026. Comecei pela função \`main\`, observando como o programa recebia a senha, perguntava seu tamanho em bytes e, em seguida, solicitava um valor de hash para liberar o acesso.

Na primeira parte, a senha é lida com \`fgets\`. Depois, o programa lê o tamanho informado e usa \`atoi\` para converter essa entrada textual em um número. Esse número controla quantos bytes do buffer são impressos. Essa lógica chamou minha atenção, mas meu caminho principal foi seguir a comparação que decide se o programa abre o arquivo da flag.

Ao continuar a leitura, percebi que a senha escolhida não era comparada diretamente com o valor final. O programa chama \`make_secret\`, que reconstrói dados internos do binário e devolve o resultado de uma função de hash. Esse retorno é comparado com o número que eu forneço no último prompt.

# 2. Localizando a comparação no Ghidra

No código decompilado pelo Ghidra, foquei neste trecho de \`main\`. Mantive os nomes das variáveis locais que o próprio Ghidra mostrou, porque eles ajudaram a relacionar o pseudocódigo com o assembly.

```
local_100 = strtoul(entrada, &local_120, 10);

local_f8 = make_secret(local_e5);
if (local_f8 == local_100) {
    /* abre flag.txt */
}
```

O que entendi dessa parte foi: \`local_100\` guarda o valor numérico que digitei no prompt do hash, enquanto \`local_f8\` recebe o retorno de \`make_secret\`. Portanto, o objetivo era descobrir o valor produzido durante a execução e informar esse número no formato aceito pelo programa.

Depois, procurei no assembly do Ghidra a instrução correspondente à condição \`if (local_f8 == local_100)\`. O trecho relevante é a comparação de dois valores de 64 bits:

```
call make_secret
mov QWORD PTR [rbp-0xf8], rax
mov rax, QWORD PTR [rbp-0xf8]
cmp rax, QWORD PTR [rbp-0x100]
jne caminho_de_falha
```

Esse trecho confirma o vínculo entre as duas representações. O retorno de \`make_secret\` chega em \`RAX\` e é guardado em \`local_f8\`, localizado em \`\[rbp-0xf8\]\`. Já \`local_100\`, localizado em \`\[rbp-0x100\]\`, contém o valor digitado e convertido por \`strtoul\`. A instrução \`cmp\` compara esses dois valores; se forem diferentes, o fluxo segue pelo salto condicional.

# 3. O equivalente em C

Para deixar a lógica mais clara, reescrevi a parte relevante em C simplificado. Este trecho representa o fluxo da comparação, não o programa inteiro:

```
char *fim = NULL;
unsigned long valor_informado = strtoul(entrada_hash, &fim, 10);
unsigned long valor_calculado = make_secret(buffer_secreto);

if (fim != entrada_hash && valor_calculado == valor_informado) {
    /* o programa tenta abrir e ler flag.txt */
}
```

Também resumi o papel de \`make_secret\`. Os bytes que alimentam essa função estão definidos dentro do binário; não preciso reproduzi-los aqui para explicar meu método. A função aplica XOR aos bytes, termina o buffer e passa o resultado para \`hash\`.

```
unsigned long make_secret(unsigned char *destino) {
    size_t i = 0;

    while (obf_bytes[i] != '\0') {
        destino[i] = obf_bytes[i] ^ 0xAA;
        ++i;
    }

    destino[i] = '\0';
    return hash(destino);
}
```

Essa leitura me ajudou a entender que eu não precisava adivinhar uma senha especial nem reimplementar toda a transformação. Bastava observar o valor calculado pelo próprio programa quando a execução chegasse ao ponto certo.

# 4. Conferindo o valor no GDB

Abri o executável no GDB e usei \`break main\` como ponto de parada inicial. Não espalhei breakpoints por toda a função: acompanhei a execução a partir de \`main\` até \`make_secret\` ter retornado e o valor estar disponível para a comparação.

```
(gdb) break main
(gdb) run
# Informo os dados solicitados e avanço a execução até o trecho relevante.
(gdb) x/gx $rbp-0xf8
```

Usei o exame de memória para observar o conteúdo associado a \`local_f8\`. No meu rascunho, anotei o comando como \`x/x\`; para explicitar a leitura de 8 bytes em hexadecimal, que corresponde a um valor de 64 bits, a forma mais clara no GDB é \`x/gx\`. O importante foi ler o conteúdo da variável no momento em que ela já havia sido calculada, e não o conteúdo antes da chamada de \`make_secret\`.

O GDB mostrou o valor em hexadecimal. Como o programa converte a entrada com \`strtoul(..., 10)\`, a entrada seguinte precisa ser escrita como número decimal. Por isso, converti o conteúdo observado de hexadecimal para decimal e usei o resultado no prompt do hash. Mantive a interpretação de 64 bits para não truncar o valor.

Na primeira tentativa, informei o valor convertido e funcionou. Não precisei criar breakpoints em todas as instruções de \`main\`; o essencial foi acompanhar a execução até o retorno de \`make_secret\` estar disponível e ler a variável certa.

# 5. Observação sobre endereços e valores

Durante a revisão, percebi que é importante separar três coisas: o endereço da instrução, o deslocamento de uma variável em relação a \`RBP\` e o dado armazenado nessa variável. Por exemplo, \`0x00101685\` é o endereço da instrução \`cmp\` mostrado no trecho do Ghidra; em decimal, esse endereço é **1.054.341**. Se a anotação for apenas \`0x1685\`, esse número corresponde a **5.765** em decimal. Nenhum desses números, por si só, é o hash calculado.

Da mesma forma, \`\[rbp-0xf8\]\` não é um endereço absoluto: é a posição relativa à base da pilha em que o programa guarda \`local_f8\`. Para recuperar o resultado correto, é preciso examinar o conteúdo dessa posição durante a execução, depois que a função tiver calculado o valor.

# Conclusão

Meu caminho foi partir da leitura do código no Ghidra, localizar o \`if (local_f8 == local_100)\`, reconhecer a comparação correspondente no assembly e conferir no GDB o conteúdo da variável que recebe o retorno de \`make_secret\`. Em seguida, converti o valor observado de hexadecimal para decimal, pois a entrada é interpretada na base 10. Com o valor completo de 64 bits informado no prompt, consegui passar pela comparação.

O principal aprendizado foi relacionar o pseudocódigo do Ghidra às instruções do assembly e, depois, usar o GDB para observar o estado real da execução. Isso foi mais direto para mim do que inserir breakpoints em vários pontos ou tentar reproduzir manualmente todo o cálculo.

# Referências

Identificação do desafio e referência de estudo: [Página do desafio — CyLab Security Academy](https://learn.cylabacademy.org/library/767)

Material geral de apoio sobre ferramentas e fundamentos de CTF: [The CTF Primer — picoCTF](https://primer.picoctf.org/)