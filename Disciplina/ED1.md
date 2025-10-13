# Ponteiros 

Ponteiros são **variáveis** que armazenam endereços na memória de outras variáveis. Dizemos que um ponteiro “aponta” para uma varíável quando contém o endereço da mesma.

## Sintaxe de declaração de ponteiro

tipo *nome_do_ponteiro

onde: 

* tipo : é o tipo de dado da variável cujo endereço o ponteiro armazena.
* *nome_ponteiro : O nome da variável ponteiro.

## Endereços de Variáveis

```cpp
#include <iostream>

using namespace std;

int main(){

int copos = 6;
double cafe = 4.5;

cout << "valor de copos = " << copos << endl;
cout << "endereco de copos = " << &copos << endl;

cout << "valor de cafe = " << cafe << endl;
cout << "endereco de cafe = " << &cafe << endl;

}

```

Saída:

```bash
valor de copos = 6
endereco de copos = 0x7fffccd17afc
valor de cafe = 4.5
endereco de cafe = 0x7fffccd17b00
```

---

# Structs (Registros)

Uma struct é uma variável especial que contém diversas outras variáveis normalmente de tipos diferentes. As variaveis internas contidas pela struct são denominadas membros da struct.

## Sintaxe da struct
```c
struct <identificador>
{
    <listagem dos tipos>
}

struct <identificador> <variavel>

```

Usando o **typedef** 

```c
typedef struct 
{
    <listagem dos tipos>
} <identificador>;

<identificador> <variavel>
```

Exemplo de declaração de uma struct:

```c
typedef struct 
{
    char nome[100];
    char cpf[20]; // deve conter 11 numeros
    char telefone[50]; // deve conter 12 numeros
} cliente;

cliente cliente1 = {"Fulano", 32383783728, 84999340933};
```

# Ponteiros X Registros

Um ponteiro pode apontar para tipos criados pelo
programador(registros, uniões e enumerações)

```cpp
#include <iostream>
using namespace std;

typedef struct{
    char nome[20];
    float salario;
    unsigned gols;
} jogador;

int main(){
    jogador j1;
    jogador *ptr = &j1;

    cout << "Digite o nome, salario e gols de um jogador: \n";
    cin >> j1.nome >> j1.salario >> j1.gols;

    cout << "Nome: " << j1.nome << " Salario: " << j1.salario << " Gols: " << j1.gols << endl;

    cout << "Nome: " << ptr->nome << " Salario: " << ptr->salario << " Gols: " << ptr->gols << endl;
}
```
---

# Alocação de Memória

### Tipos de Alocação
- **Automática:** ocorre na declaração da variável.
  ```c
  int total = 6;
  ```

- **Dinâmica:** ocorre em tempo de execução usando ponteiros.
  ```c
  int *pi = (int *)malloc(sizeof(int));
  free(pi);
  ```

### Passos da Alocação Dinâmica
1. Alocar memória com `malloc`.
2. Guardar o endereço em um ponteiro.
3. Usar o ponteiro para acessar/modificar dados.
4. Liberar memória com `free`.

### Observações
- `malloc` deve sempre ter um `free` correspondente.
- Evite vazamentos de memória.
- Liberar a memória não destrói o ponteiro.
- Em sistemas 64 bits, ponteiros têm 8 bytes.

---

## Vetores Dinâmicos

- Vetores **estáticos** exigem tamanho fixo na declaração.  
- Vetores **dinâmicos** podem ter tamanho definido em tempo de execução.  
- O tamanho não muda após a alocação.  
- O ponteiro pode ser manipulado como vetor.

```c
int *v = (int *)malloc(n * sizeof(int));
```

- Também é possível criar **matrizes alocadas dinamicamente**.

---

## Tipos Estruturados

### Registros (`struct`)
- Permitem armazenar múltiplos valores de tipos diferentes sob um único nome.
- Podem conter outras estruturas (aninhamento).
- É possível usar arrays de registros.
- Podem ser manipulados com ponteiros.

###  Uniões (`union`)
- Parecidas com registros.
- Compartilham a mesma área de memória entre os membros.
- Apenas um membro ativo por vez.

### Enumerações (`enum`)
- Definem valores inteiros nomeados.
- Tornam o código mais legível.

---

# Manipulação de Arquivos de Texto

- Sequência de bits em que cada grupo representa um caractere.
- Codificações comuns:
  - ASCII → 8 bits por caractere
  - Unicode → 8 a 32 bits por caractere (UTF-8, UTF-16, UTF-32)

###  Modos de Abertura de Arquivos de Texto

| Modo | Descrição |
|------|------------|
| `"r"`  | Abre para leitura. Retorna `NULL` se não existir. |
| `"w"`  | Cria para escrita. Se já existir, apaga. |
| `"a"`  | Abre para adicionar no final. Não altera dados existentes. |
| `"r+"` | Abre para leitura e escrita (arquivo deve existir). |
| `"w+"` | Cria para leitura e escrita (apaga se existir). |
| `"a+"` | Abre para leitura e escrita (mantém dados existentes). |

- Sem `+` → somente leitura ou escrita.  
- Com `+` → leitura e escrita simultânea.

### Escrita em Arquivos Texto

```c
FILE *arq = fopen("arquivo.txt", "w");
fprintf(arq, "Hello, world!");
fclose(arq);
```

### Leitura de Arquivos Texto

- `fgetc()` → lê caractere por caractere até `EOF`.
- `fgets()` → lê uma linha inteira.
- `fscanf()` → lê dados formatados.

```c
FILE *arq = fopen("arquivo.txt", "r");
char c;
while((c = fgetc(arq)) != EOF) {
    putchar(c);
}
fclose(arq);
```

---

# Manipulação de Arquivos Binários

- Conjunto de bits representando dados **na forma nativa** (inteiros, floats, etc.).

### Modos de Abertura de Arquivos Binários

| Modo | Descrição |
|------|------------|
| `"rb"`  | Leitura binária. |
| `"wb"`  | Escrita binária (apaga se existir). |
| `"ab"`  | Acrescenta dados binários ao final. |
| `"rb+"` | Leitura e escrita binária (arquivo deve existir). |
| `"wb+"` | Leitura e escrita binária (apaga se existir). |
| `"ab+"` | Leitura e escrita binária (mantém dados existentes). |

### Escrita em Arquivos Binários

```c
FILE *arq = fopen("dados.bin", "wb");
fwrite(&registro, sizeof(registro), 1, arq);
fclose(arq);
```

### Leitura em Arquivos Binários

```c
FILE *arq = fopen("dados.bin", "rb");
fread(&registro, sizeof(registro), 1, arq);
fclose(arq);
```

### 🧭 Movimentação no Arquivo Binário

- `fseek(arq, offset, origem)` → Move o ponteiro do arquivo.
  - `SEEK_SET` → início
  - `SEEK_CUR` → posição atual
  - `SEEK_END` → final
- `ftell(arq)` → Retorna posição atual.
- `rewind(arq)` → Volta ao início do arquivo.

---



