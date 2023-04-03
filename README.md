# Maquina_Von_Neumann

Este projeto é um simulador de CPU baseado na arquitetura de Von Neumann, desenvolvido como parte de um trabalho de faculdade pelos alunos Fabricia Silva Machado e Gênesis Brito.

## Funcionamento
O simulador permite a execução de instruções básicas de um processador, como leitura e escrita em memória, operações aritméticas e lógicas, desvio condicional e incondicional, entre outras. O usuário pode definir um programa em linguagem de montagem para ser executado no simulador, podendo acompanhar a execução passo a passo.

Como usar
1. Baixe o código fonte do simulador;
2. Crie um arquivo de texto com as instruções em linguagem de montagem que deseja executar e salve-o como TXT dentro da pasta do projeto com o nome "comando.txt";
3. Execute o projeto em um ambiente de Linguagem C;
4. Esse simulador deve mostrar o conteúdo
dos registradores no fim de cada ciclo de máquina, quando haverá uma pausa até apertar uma tecla para iniciar o próximo
ciclo.
5. O simulador irá ler as instruções do arquivo "comando.txt" seguindo o padrão abaixo:
Endereço da instrução/dado; Local da instrução na memória (usando "i" para indicar instrução e "d" para dado); Mneumônico da instrução, tendo ou não em seguida o seu endereço, separando-as por "/". Exemplo:

```
0;i;lda 96/ldb 98
4;i;sub/xchg
8;i;lda 94/div
c;i;ldb 92/mul
10;i;ldb 90/add
14;i;sta 8e/hlt
90;d;20
92;d;3
94;d;4
96;d;5
98;d;3
```
## Funções

A seguir os comandos executados pelo simulador:

* **hlt** : o processador não faz nada. Em outras palavras, nenhum registrador tem o seu valor alterado durante a execução de hlt. Deve-se colocar no fim do programa.
* **nop** :  Se 𝐿𝑅 = 1, o PC é incrementado, mas nenhum outro registrador tem seu valor alterado durante a execução de nop, com exceção de LR, que segue o funcionamento apresentado acima. Caso 𝐿𝑅 = 0, nenhum registrador, com exceção de LR, tem seu valor alterado.
* **add** : ADD REGISTER: A = A + B
* **sub** : SUBTRACT REGISTER: A = A − B
* **mul** : MULTIPLY REGISTER: A = A × B
* **div** : DIVIDE REGISTER: A = A ÷ B
* **cmp** : COMPARE REGISTER: compara a palavra no registrador A com a palavra no registrador B e preenche os registradores internos E, L e G os valores fazendo sequencialmente os seguintes testes:
1. Se A = B, então E = 1; senão E = 0;
2. Se A < B, então L = 1; senão L = 0;
3. Se A > B, então G = 1; senão G = 0.
* **xchg** : EXCHANGE: alterna o conteúdo entre os registradores A e B usando o registrador interno T como espaço temporário.
* **and** : LOGICAL-AND ON REGISTER: A = A & B
* **or** : LOGICAL-OR ON REGISTER: A = A | B
* **xor** : LOGICAL-XOR ON REGISTER: A = A ^ B
* **not** : LOGICAL-NOT ON REGISTER: A = ! A
* **je M[X]** : JUMP IF EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1.
* **jne M[X]** : JUMP IF NOT EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 0.
* **jl M[X]** : JUMP IF LOWER THAN: muda o registrador PC para o endereço de memória X caso L = 1.
* **jle M[X]** : JUMP IF LOWER THAN OR EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1 ou L = 1.
* **jg M[X]** : 0 JUMP IF GREATER THAN: muda o registrador PC para o endereço de memória X caso G = 1.
* **jge M[X]** : JUMP IF GREATER THAN OR EQUAL TO: muda o registrador PC para o endereço de memória X caso E = 1 ou G = 1.
* **jmp M[X]** : JUMP: muda o registrador PC para o endereço de memória X.
* **lda M[X]** : LOAD A: carrega o registrador A com uma palavra de 16 bits da memória que se inicia no endereço X.
* **ldb M[X]** : LOAD B: carrega o registrador B com uma palavra de 16 bits da memória que se inicia no endereço X.
* **sta M[X]** : STORE A: armazena em uma palavra de 16 bits que começa a partir do endereço de memória X o conteúdo do registrador A.
* **stb M[X]** : STORE B: armazena em uma palavra de 16 bits que começa a partir do endereço de memória X o conteúdo do registrador B.
* **ldrb** : LOAD A WITH WORD POINTED BY B: carrega o registrador A com uma palavra de 16 bits da memória que se inicia no endereço contido no registrador B.
* **movial imm** : MOVE IMMEDIATE TO LOWER A: zera o registrador A e move os oito bits menos significativos (0:7) do imediato para a parte inferior (0:7) do registrador A.
* **moviah imm** : MOVE IMMEDIATE TO HIGHER A: move os oito bits menos significativos (0:7) do imediato para a parte superior(8:15) do registrador A, enquanto os bits menos significativos do registrador A são mantidos intactos.
* **addia imm** : ADD A WITH IMMEDIATE: A = A + IMM
* **subia imm** : SUBTRACT A WITH IMMEDIATE: A = A − IMM
* **mulia imm** : MULTIPLY A WITH IMMEDIATE: A = A × IMM
* **divia imm** : DIVIDE A WITH IMMEDIATE: A = A÷ IMM.
* **lsh imm** : LEFT SHIFT: desloca a palavra no registrador A em IMM bits à esquerda.
* **rsh imm** : RIGHT SHIFT: desloca a palavra no registrador A em IMM bits à direita.

## Contribuindo

Este projeto é resultado de um trabalho acadêmico e, portanto, não está aberto a contribuições externas.


