#include "hashtable.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define hash(valor,tamanho) (valor%tamanho)

typedef struct
{
    long matricula;
    char nome[100];
} Aluno;

#define Type Aluno
#define Key long
#define TYPE_NULL -99999999

// Uma definição abstrata da struct que representará a lista
typedef struct TAD_LIST list;

// Nó de lista
typedef struct _node {
    Type value;
    struct _node* next;
} node;

struct TAD_LIST {
    node* head;
};

// Aloca memória para um 'node' e define o endereço do próximo como NULL
node* new_node(Type valor) {
    node* n = malloc(sizeof(node));
    n->value = valor;
    n->next  = NULL;
    return n;
}

list* new_list() {

    list* v  = malloc(sizeof(list));
    v->head = NULL;
    return v;

}

int  list_size(list* v) {
    int cont=0;
    node* n = v->head;

    while(n != NULL)
    {
        n = n->next;
        cont++;
    }

    return cont;
}

node* list_iterate(list* v, int position)
{
    assert(position >0 && position <= list_size(v));

    node* n =v->head;

    for(int i=0;i<position-1;i++)
    {
        n = n->next;
    }

    return n;
}

void list_insert(list* v, Type value, int i){
    node* n = new_node(value);
    if(i==0)
    {
        n->next = v->head;
        v->head = n;
    }
    else
    {
        node* ptr = list_iterate(v, i);
        n->next = ptr->next;
        ptr->next = n;
    }
}

void list_push_back(list* v, Type value) {
    list_insert(v, value, list_size(v));
}

void list_push_front(list* v, Type value) {
    list_insert(v, value, 0);
}

Type list_erase(list* v, int i){

    Type value;

    if(i == 0)
    {
        node* n = v->head;
        v->head = n->next;
        value = n->value;
        free(n);

    }
    else
    {
        node* ptr = list_iterate(v,i);
        node* n = ptr->next;
        value = n->value;
        ptr->next = n->next;
        free(n);
    }

    return value;

}
typedef struct HASH_TABLE hasht;

struct HASH_TABLE
{
    list** table;
    long size;
    long nelem;
};

hasht* new_hasht(long capacity)
{
    hasht* t = malloc(sizeof(hasht));
    t->size = capacity;
    t->nelem = 0;
    t->table = malloc(sizeof(list*) * capacity);
    for (long i = 0; i < capacity; i++)
        t->table[i] = new_list();
    return t;
}

bool compare_by_key(Type objeto,Key chave)
{
  if(chave==objeto.matricula)
    return 1;
  else
    return 0;
}

Key get_key(Type objeto)
{
  return objeto.matricula;
}

void free_item(hasht* t)
{
}

void free_hasht(hasht* t)
{
    for (long i = 0; i < t->size; i++)
    {
        node* ptr = t->table[i]->head;
        while (ptr != NULL)
        {
            node* tmp = ptr;
            ptr = ptr->next;
            //free_item(tmp);
            free(tmp);
        }
        free(t->table[i]);
    }
    free(t->table);
    free(t);
}

long hasht_search(hasht* v, Key k)
{
    long i = hash(k, v->size);

    node* ptr = v->table[i]->head;

    while (ptr != NULL)
    {
        if ( compare_by_key( ptr->value, k )  )
            return ptr->value.matricula;
        ptr = ptr->next;
    }
    return TYPE_NULL;
}

void hasht_insert(hasht* t, Type obj)
{
    long r = hasht_search(t,  get_key(obj) );

    if ( r == TYPE_NULL )
    {
        long i = hash( get_key(obj)  , t->size);
        list_push_back( t->table[i], obj );
    }
}

Key hasht_remove(hasht* t,Key k)
{
    long i= hash(k,t->size);
    long x= hasht_search(t->table[i],k);
    long retorno;
    if(x!=TYPE_NULL)
      retorno=list_erase(t->table[i],k);
    return retorno;
}

void print_item(Type obj)
{
  printf("%s",obj.nome);
}

void hasht_print(hasht* t)
{
    for (long i = 0; i < t->size; i++)
    {
        node* ptr = t->table[i]->head;
        printf("%ld:", i );
        while ( ptr != NULL )
        {
            if(ptr!=t->table[i]->head)
                printf(", ");
            print_item( ptr->value );
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(void)
{
    long size;
    long insertions;
    int i;
    Type objeto;
    scanf("%li %li",&size,&insertions);
    hasht *t=new_hasht(size);
    for(i=0;i<insertions;i++)
    {
        scanf("%li %s",&objeto.matricula,&objeto.nome);
        hasht_insert(t,objeto);
    }
    hasht_print(t);
    free_hasht(t);
    return 0;
}
