// Arquivo list.h
#include <stdbool.h>
#define Type int
// Uma defini��o abstrata da struct que representar� a lista
typedef struct TAD_LIST list;

typedef struct _node {
	long value;
	char nome[100];
    struct _node* next;
}node;

struct TAD_LIST {
    node* head;
};
// Aloca mem�ria inicial para o vetor
list* new_list();

// Desaloca a mem�ria de v->data e do pr�prio v.
void free_list(list* v);

// Fun��es de remo��o de elementos
Type list_pop_back(list* v);
Type list_pop_front(list* v);
Type list_erase(list* v, int i);

// Fun��es de inser��o de elementos
void list_insert(list* v, Type value, int i);
void list_push_back(list* v, Type value);
void list_push_front(list* v, Type value);

// Fun��es de acesso aos dados
Type* list_at(list* v, int pos);
void list_set(list* v, int pos, Type value);
void list_print(list* v);
// Retorna a quantidade de elementos na lista
int  list_size(list* v);
// Retorna true se a lista est� vazia, false caso contr�rio.
bool list_empty(list* v);


