#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000

unsigned char memoria[154], ir = 0x0, e = 0x0, l = 0x0, g = 0x0, lr = 0x0;

unsigned int mbr = 0x0, FlagEntrada = 1;

unsigned short int mar = 0x0, ibr = 0x0, imm = 0x0, pc = 0x0, a = 0x0, b = 0x0,
                   t = 0x0;

char *param1, *param2, *param3, *param4, *param5, *param6, *param7;
void split(char str[100], char delim[], char **param1, char **param2,
           char **param3, char **param4, char **param5, char **param6,
           char **param7) {
  str[strcspn(str, "\n")] = '\0';

  int i = 0;
  char *token = strtok(str, delim);

  while (token != NULL) {
    if (i == 0) {
      *param1 = token;
    } else if (i == 1) {
      *param2 = token;
    } else if (i == 2) {
      *param3 = token;
    } else if (i == 3) {
      *param4 = token;
    } else if (i == 4) {
      *param5 = token;
    } else if (i == 5) {
      *param6 = token;

    } else if (i == 6) {
      *param7 = token;
    }

    i++;
    token = strtok(NULL, delim);
  }

  if (i <= 3) {
    *param4 = "0";
  } else if (i <= 4) {
    *param5 = "10";
  } else if (i <= 5) {
    *param6 = "0";
  } else if (i <= 6) {
    *param7 = "0";
  }
  if (strcmp(*param2, "d") == 0) {

    *param7 = *param3;
    *param3 = "";
    *param4 = "";
    *param5 = "";
    *param6 = "";
  }
}

void preencherMemoria(char comando[100]) {

  split(comando, ";/ ", &param1, &param2, &param3, &param4, &param5, &param6,
        &param7);

  if (strcmp(param3, "hlt") == 0 || strcmp(param3, "nop") == 0 ||
      strcmp(param3, "add") == 0 || strcmp(param3, "sub") == 0 ||
      strcmp(param3, "mul") == 0 || strcmp(param3, "div") == 0 ||
      strcmp(param3, "cmp") == 0 || strcmp(param3, "xchg") == 0 ||
      strcmp(param3, "and") == 0 || strcmp(param3, "or") == 0 ||
      strcmp(param3, "xor") == 0 || strcmp(param3, "not") == 0 ||
      strcmp(param3, "ldrb") == 0) {

    param6 = param5;
    param5 = param4;
    param4 = "0";
  }

  if (strcmp(param3, "hlt") == 0 || strcmp(param3, "nop") == 0 ||
      strcmp(param3, "add") == 0 || strcmp(param3, "sub") == 0 ||
      strcmp(param3, "mul") == 0 || strcmp(param3, "div") == 0 ||
      strcmp(param3, "cmp") == 0 || strcmp(param3, "xchg") == 0 ||
      strcmp(param3, "and") == 0 || strcmp(param3, "or") == 0 ||
      strcmp(param3, "xor") == 0 || strcmp(param3, "not") == 0 ||
      strcmp(param3, "ldrb") == 0 || strcmp(param3, "je") == 0 ||
      strcmp(param3, "jne") == 0 || strcmp(param3, "jl") == 0 ||
      strcmp(param3, "jle") == 0 || strcmp(param3, "jg") == 0 ||
      strcmp(param3, "jge") == 0 || strcmp(param3, "jmp") == 0 ||
      strcmp(param3, "sta") == 0 || strcmp(param3, "stb") == 0 ||
      strcmp(param3, "movial") == 0 || strcmp(param3, "moviah") == 0 ||
      strcmp(param3, "addia") == 0 || strcmp(param3, "subia") == 0 ||
      strcmp(param3, "mulia") == 0 || strcmp(param3, "divia") == 0 ||
      strcmp(param3, "lsh") == 0 || strcmp(param3, "rsh") == 0 ||
      strcmp(param3, "lda") == 0 || strcmp(param3, "ldb") == 0) {
    if (strcmp(param3, "hlt") == 0) {
      mbr = 0x00;
    } else if (strcmp(param3, "nop") == 0) {
      mbr = 0x08;
    } else if (strcmp(param3, "add") == 0) {
      mbr = 0x10;
    } else if (strcmp(param3, "sub") == 0) {
      mbr = 0x18;
    } else if (strcmp(param3, "mul") == 0) {
      mbr = 0x20;
    } else if (strcmp(param3, "div") == 0) {
      mbr = 0x28;
    } else if (strcmp(param3, "cmp") == 0) {
      mbr = 0x30;
    } else if (strcmp(param3, "xchg") == 0) {
      mbr = 0x38;
    } else if (strcmp(param3, "and") == 0) {
      mbr = 0x40;
    } else if (strcmp(param3, "or") == 0) {
      mbr = 0x48;
    } else if (strcmp(param3, "xor") == 0) {
      mbr = 0x50;
    } else if (strcmp(param3, "not") == 0) {
      mbr = 0x58;
    } else if (strcmp(param3, "ldrb") == 0) {
      mbr = 0xB8;
    } else if (strcmp(param3, "je") == 0) {
      mbr = 0x60;
    } else if (strcmp(param3, "jne") == 0) {
      mbr = 0x68;
    } else if (strcmp(param3, "jl") == 0) {
      mbr = 0x70;
    } else if (strcmp(param3, "jle") == 0) {
      mbr = 0x78;
    } else if (strcmp(param3, "jg") == 0) {
      mbr = 0x80;
    } else if (strcmp(param3, "jge") == 0) {
      mbr = 0x88;
    } else if (strcmp(param3, "jmp") == 0) {
      mbr = 0x90;
    } else if (strcmp(param3, "sta") == 0) {
      mbr = 0xA8;
    } else if (strcmp(param3, "stb") == 0) {
      mbr = 0xB0;
    } else if (strcmp(param3, "movial") == 0) {
      mbr = 0xC0;
    } else if (strcmp(param3, "moviah") == 0) {
      mbr = 0xC8;
    } else if (strcmp(param3, "addia") == 0) {
      mbr = 0xD0;
    } else if (strcmp(param3, "subia") == 0) {
      mbr = 0xD8;
    } else if (strcmp(param3, "mulia") == 0) {
      mbr = 0xE0;
    } else if (strcmp(param3, "divia") == 0) {
      mbr = 0xE8;
    } else if (strcmp(param3, "lsh") == 0) {
      mbr = 0xF0;
    } else if (strcmp(param3, "rsh") == 0) {
      mbr = 0xFC;
    } else if (strcmp(param3, "lda") == 0) {
      mbr = 0x98;
    } else if (strcmp(param3, "ldb") == 0) {
      mbr = 0xA0;
    }
  }
  unsigned int outro_valor = strtoul(
      param4, NULL, 16); // converte a string em um valor numérico hexadecimal

  mbr = ((mbr & 0x00FFFFFF) << 8) | (outro_valor & 0xFF);

  if (strcmp(param5, "hlt") == 0 || strcmp(param5, "nop") == 0 ||
      strcmp(param5, "add") == 0 || strcmp(param5, "sub") == 0 ||
      strcmp(param5, "mul") == 0 || strcmp(param5, "div") == 0 ||
      strcmp(param5, "cmp") == 0 || strcmp(param5, "xchg") == 0 ||
      strcmp(param5, "and") == 0 || strcmp(param5, "or") == 0 ||
      strcmp(param5, "xor") == 0 || strcmp(param5, "not") == 0 ||
      strcmp(param5, "ldrb") == 0 || strcmp(param5, "je") == 0 ||
      strcmp(param5, "jne") == 0 || strcmp(param5, "jl") == 0 ||
      strcmp(param5, "jle") == 0 || strcmp(param5, "jg") == 0 ||
      strcmp(param5, "jge") == 0 || strcmp(param5, "jmp") == 0 ||
      strcmp(param5, "sta") == 0 || strcmp(param5, "stb") == 0 ||
      strcmp(param5, "movial") == 0 || strcmp(param5, "moviah") == 0 ||
      strcmp(param5, "addia") == 0 || strcmp(param5, "subia") == 0 ||
      strcmp(param5, "mulia") == 0 || strcmp(param5, "divia") == 0 ||
      strcmp(param5, "lsh") == 0 || strcmp(param5, "rsh") == 0 ||
      strcmp(param5, "lda") == 0 || strcmp(param5, "ldb") == 0) {
    if (strcmp(param5, "hlt") == 0) {
      mbr = (mbr << 8) | 0x00;
    } else if (strcmp(param5, "nop") == 0) {
      mbr = (mbr << 8) | 0x08;
    } else if (strcmp(param5, "add") == 0) {
      mbr = (mbr << 8) | 0x10;
    } else if (strcmp(param5, "sub") == 0) {
      mbr = (mbr << 8) | 0x18;
    } else if (strcmp(param5, "mul") == 0) {
      mbr = (mbr << 8) | 0x20;
    } else if (strcmp(param5, "div") == 0) {
      mbr = (mbr << 8) | 0x28;
    } else if (strcmp(param5, "cmp") == 0) {
      mbr = (mbr << 8) | 0x30;
    } else if (strcmp(param5, "xchg") == 0) {
      mbr = (mbr << 8) | 0x38;
    } else if (strcmp(param5, "and") == 0) {
      mbr = (mbr << 8) | 0x40;
    } else if (strcmp(param5, "or") == 0) {
      mbr = (mbr << 8) | 0x48;
    } else if (strcmp(param5, "xor") == 0) {
      mbr = (mbr << 8) | 0x50;
    } else if (strcmp(param5, "not") == 0) {
      mbr = (mbr << 8) | 0x58;
    } else if (strcmp(param5, "ldrb") == 0) {
      mbr = (mbr << 8) | 0xB8;
    } else if (strcmp(param5, "je") == 0) {
      mbr = (mbr << 8) | 0x60;
    } else if (strcmp(param5, "jne") == 0) {
      mbr = (mbr << 8) | 0x68;
    } else if (strcmp(param5, "jl") == 0) {
      mbr = (mbr << 8) | 0x70;
    } else if (strcmp(param5, "jle") == 0) {
      mbr = (mbr << 8) | 0x78;
    } else if (strcmp(param5, "jg") == 0) {
      mbr = (mbr << 8) | 0x80;
    } else if (strcmp(param5, "jge") == 0) {
      mbr = (mbr << 8) | 0x88;
    } else if (strcmp(param5, "jmp") == 0) {
      mbr = (mbr << 8) | 0x90;
    } else if (strcmp(param5, "sta") == 0) {
      mbr = (mbr << 8) | 0xA8;
    } else if (strcmp(param5, "stb") == 0) {
      mbr = (mbr << 8) | 0xB0;
    } else if (strcmp(param5, "movial") == 0) {
      mbr = (mbr << 8) | 0xC0;
    } else if (strcmp(param5, "moviah") == 0) {
      mbr = (mbr << 8) | 0xC8;
    } else if (strcmp(param5, "addia") == 0) {
      mbr = (mbr << 8) | 0xD0;
    } else if (strcmp(param5, "subia") == 0) {
      mbr = (mbr << 8) | 0xD8;
    } else if (strcmp(param5, "mulia") == 0) {
      mbr = (mbr << 8) | 0xE0;
    } else if (strcmp(param5, "divia") == 0) {
      mbr = (mbr << 8) | 0xE8;
    } else if (strcmp(param5, "lsh") == 0) {
      mbr = (mbr << 8) | 0xF0;
    } else if (strcmp(param5, "rsh") == 0) {
      mbr = (mbr << 8) | 0xFC;
    } else if (strcmp(param5, "lda") == 0) {
      mbr = (mbr << 8) | 0x98;
    } else if (strcmp(param5, "ldb") == 0) {
      mbr = (mbr << 8) | 0xA0;
    }
    unsigned int outro_valor2 = strtoul(param6, NULL, 16);
    mbr = (mbr << 8) | (outro_valor2 & 0xFF);
  }
  if (strcmp(param2, "d") == 0) {
    unsigned int pos = strtoul(param1, NULL, 16);
    unsigned int dado = strtoul(param7, NULL, 16);
    mbr = dado;

    memoria[pos++] = (mbr >> 8) & 0xFF;
    memoria[pos++] = mbr & 0xFF;
  }

  memoria[mar++] = (mbr >> 24) & 0xFF;
  memoria[mar++] = (mbr >> 16) & 0xFF;
  memoria[mar++] = (mbr >> 8) & 0xFF;
  memoria[mar++] = mbr & 0xFF;
}

void lerArquivo(char *arquivo) {
  FILE *arq;
  char Linha[100];
  char *result;
  int i;

  arq = fopen(arquivo, "rt");
  if (arq == NULL) {
    printf("Problemas na abertura do arquivo\n");
    return;
  }
  i = 1;
  while (!feof(arq)) {
    result = fgets(Linha, 100, arq);
    if (result) {
      preencherMemoria(Linha);
    }
    i++;
  }
  fclose(arq);
}

void Busca() {

  if (lr == 0) {
    mar = pc;
    // transferindo a palavra para mbr

    mbr = memoria[mar];
    mbr = memoria[mar++] << 8;
    mbr = (mbr | memoria[mar++]) << 8;
    mbr = (mbr | memoria[mar++]) << 8;
    mbr = mbr | memoria[mar++];
  }
}

void Decodifica() {

  if (lr == 0) {

    ibr = mbr & 0x0000ffff;

    ir = mbr >> 27;
    mbr = (mbr & 0xffff0000) >> 16;

    if (ir == 0x00 || ir == 0x01 || ir == 0x02 || ir == 0x03 || ir == 0x04 ||
        ir == 0x05 || ir == 0x06 || ir == 0x07 || ir == 0x08 || ir == 0x09 ||
        ir == 0x0a || ir == 0x0b || ir == 0x17) {

      mar = 0x0;
    } else if (ir == 0x0c || ir == 0x0d || ir == 0x0e || ir == 0x0f ||
               ir == 0x10 || ir == 0x11 || ir == 0x12 || ir == 0x13 ||
               ir == 0x14 || ir == 0x15 || ir == 0x16) {

      mar = mbr & 0x000007ff;
    } else if (ir == 0x18 || ir == 0x19 || ir == 0x1a || ir == 0x1b ||
               ir == 0x1c || ir == 0x1d || ir == 0x1e || ir == 0x1f) {

      mar = 0x0;
      imm = mbr & 0x000007ff;
    }
    lr++;
  } else {

    mbr = ibr;
    ibr = 0x00;
    ir = mbr >> 11;
    if (ir == 0x00 || ir == 0x01 || ir == 0x02 || ir == 0x03 || ir == 0x04 ||
        ir == 0x05 || ir == 0x06 || ir == 0x07 || ir == 0x08 || ir == 0x09 ||
        ir == 0x0a || ir == 0x0b || ir == 0x17) {

      mar = 0x0;
    } else if (ir == 0x0c || ir == 0x0d || ir == 0x0e || ir == 0x0f ||
               ir == 0x10 || ir == 0x11 || ir == 0x12 || ir == 0x13 ||
               ir == 0x14 || ir == 0x15 || ir == 0x16) {

      mar = mbr & 0x000007ff;
    } else if (ir == 0x18 || ir == 0x19 || ir == 0x1a || ir == 0x1b ||
               ir == 0x1c || ir == 0x1d || ir == 0x1e || ir == 0x1f) {

      mar = 0x0;
      imm = mbr & 0x000007ff;
    }
    lr = 0;
  }
}

void Imprimir() {
  printf("---------------------------------MAQUINA DE VON "
         "NEUMANN---------------------------------\n\n");
  printf("MBR: %08x", mbr);
  printf("\tMAR: %08x", mar);
  printf("\tIR:%02x", ir);
  printf("\tE:% 02x\n", e);
  printf("IBR:%08x\t", ibr);
  printf("PC:%02x\t", pc);
  printf("A:%08x\t", a);
  printf("L:%02x\n", l);
  printf("B:%08x\t", b);
  printf("T:%08x", t);
  printf("\tIMM:%02x", imm);
  printf("\tLR:%02x", lr);
  printf("\tG:%02x\n\n", g);
  printf("MEMORIA:\n\n");

  for (int i = 1; i <= 154; i++) {
    printf("%02x: %02x|\t", i - 1, memoria[i - 1]);
    if (i % 11 == 0) {
      printf("\n---------------------------------------------------------------"
             "------------------------");
      printf("\n");
    }
  }
  getchar();
  system("clear");
}
void Executa() {

  // entra o ir com o opcode e executa a fun��o desejada
  if (ir == 0x00) { // htl C
    FlagEntrada = 0;
    printf("Fim do Programa\n");
    printf("%d", FlagEntrada);
    getchar();
    system("clear");
    lr = 1;
  } else if (ir == 0x01) { // nop 

    if (lr == 1) {
      pc = pc + 4;
    } else {
      lr = 1;
    }
  } else if (ir == 0x02) { // add C

    a = a + b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x03) { // sub C
    a = a - b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x04) { // mul C
    a = a * b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x05) { // div C
    a = a / b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x06) { // cmp C
    if (a == b) {
      e = 1;
      l = 0;
      g = 0;
    } else if (a > b) {
      e = 0;
      l = 0;
      g = 1;
    } else {
      e = 0;
      l = 1;
      g = 0;
    }
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x07) { // xchg C
    t = a;
    a = b;
    b = t;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x08) { // and 
    a = a & b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x09) { // or 
    a = a | b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x0a) { // xor 
    a = a ^ b;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x0b) { // not 
    a = !a;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x0c) { // je M[X] 

    if (e == 1) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x0d) { // jne M[X] 

    if (e == 0) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x0e) { // jl M[X] 

    if (l == 1) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x0f) { // jle M[X] C

    if (e == 1 || l == 1) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x10) { // jg M[X] 

    if (g == 1) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x11) { // jge M[X] 

    if (e == 1 || g == 1) {
      pc = mar;
    } else {
      if (lr == 0) {
        pc = pc + 4;
      }
    }
  } else if (ir == 0x12) { // jmp M[X] 
    pc = mar;
  } else if (ir == 0x13) { // lda M[X] C

    mbr = mbr & 0x00000000;
    mbr = (mbr | memoria[mar++]) << 8;
    mbr = mbr | memoria[mar];
    a = mbr;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x14) { // ldb M[X] C

    mbr = mbr & 0x00000000;
    mbr = (mbr | memoria[mar++]) << 8;
    mbr = mbr | memoria[mar];
    b = mbr;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x15) { // sta M[X] C

    // 0000 0000 0000 0000 0000 0000 0010 0110
    mbr = mbr & 0x00000000;
    mbr = mbr | a;
    memoria[mar++] = (mbr & 0x0000ff00) >> 8;
    memoria[mar] = mbr & 0x000000ff;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x16) { // stb M[X] C

    // 0000 0000 0000 0000 0000 0000 0010 0110
    mbr = mbr & 0x00000000;
    mbr = mbr | b;
    memoria[mar++] = (mbr & 0x0000ff00) >> 8;
    memoria[mar] = mbr & 0x000000ff;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x17) { // ldrb 

    mbr = mbr & 0x00000000;
    mar = b;
    mbr = (mbr | memoria[mar++]) << 8;
    mbr = mbr | memoria[mar];
    a = mbr;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x18) { // movial imm 

    a = a & 0x0000;
    a = imm & 0x00ff;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x19) { // moviah imm 

    imm = (imm & 0x00ff) << 8;
    a = a | imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1a) { // addia imm C
    a = a + imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1b) { // subia imm C

    a = a - imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1c) { // mulia imm C

    a = a * imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1d) { // divia imm C

    a = a / imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1e) { // lsh imm

    a = a << imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  } else if (ir == 0x1f) { // rsh imm

    a = a >> imm;
    if (lr == 0) {
      pc = pc + 4;
    }
  }
}

int main() {

  lerArquivo("./comandos.txt");

  while (FlagEntrada == 1) {

    Busca();
    //Imprimir();
    Decodifica();
    //Imprimir();
    Executa();
    Imprimir();
  }
}
