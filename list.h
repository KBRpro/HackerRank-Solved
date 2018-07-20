// Arquivo list.h
#include <stdbool.h>
#define Type int
// Uma definição abstrata da struct que representará a lista
typedef struct TAD_LIST list;

typedef struct _node {
	long value;
	char nome[100];
    struct _node* next;
}node;

struct TAD_LIST {
    node* head;
};
// Aloca memória inicial para o vetor
list* new_list();

// Desaloca a memória de v->data e do próprio v.
void free_list(list* v);

// Funções de remoção de elementos
Type list_pop_back(list* v);
Type list_pop_front(list* v);
Type list_erase(list* v, int i);

// Funções de inserção de elementos
void list_insert(list* v, Type value, int i);
void list_push_back(list* v, Type value);
void list_push_front(list* v, Type value);

// Funções de acesso aos dados
Type* list_at(list* v, int pos);
void list_set(list* v, int pos, Type value);
void list_print(list* v);
// Retorna a quantidade de elementos na lista
int  list_size(list* v);
// Retorna true se a lista está vazia, false caso contrário.
bool list_empty(list* v);


