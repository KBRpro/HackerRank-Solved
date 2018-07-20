#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Type int

// Nó de lista
typedef struct _node {
    Type valor;
    struct _node* next;
    struct _node* previous;
} node;


typedef struct TAD_LIST {
    node* no;
    node* final;
    int size;
}list;

// Aloca memória para um 'node' e define o endereço do próximo como NULL
node* new_node(Type valor) {
    node* n = malloc(sizeof(node));
    n->valor = valor;
    n->next  = NULL;
    n->previous = NULL;
    return n;
}

/* * * * * * * * * * * * * * * * * * * * * * *
 * Complete a implementação das funções abaixo
 * * * * * * * * * * * * * * * * * * * * * * */

// Aloca memória inicial para o vetor
list* new_list()
{
    list *lista=malloc(sizeof(list));
    lista->size=0;
    lista->no=NULL;
    lista->final=NULL;
    return lista;
}

// Desaloca a memória de v->data e do próprio v.
void free_list(list* v)
{
    free(v);
}

// Funções de remoção de elementos
Type list_pop_back(list* lista)
{
   Type retorno;
   node *ptr=lista->final;
   retorno=ptr->valor;
   if(lista->size==1)
   {
     lista->no=NULL;
     lista->final=NULL;
   }
   else
   {
     ptr=ptr->previous;
     lista->final=ptr;
     ptr->next=NULL;
   }
   lista->size--;
   return retorno;
}

Type list_pop_front(list* lista) {
    Type retorno;
    node *ptr=lista->no;
    retorno=ptr->valor;
    if(lista->size==1)
    {
      lista->no=NULL;
      lista->final=NULL;
    }
    else
    {
      lista->no=ptr->next;
      ptr->previous=NULL;
    }
    lista->size--;
    return retorno;
}

Type list_erase(list* lista, int i){
    Type retorno;
    int pos=0;
    node *ptr=lista->no;
    node *ptr1;
    if(i==0)
        retorno=list_pop_front(lista);
    else if(i==lista->size-1)
        retorno=list_pop_back(lista);
    else
    {
        while(pos<i)
        {
           ptr=ptr->next;
           pos++;
        }
        retorno=ptr->valor;
        ptr->previous->next=ptr->next;
        ptr->next->previous=ptr->previous;
        lista->size--;
    }
    return retorno;
}

// Funções de inserção de elementos
void list_insert(list* lista, Type value, int i)
{
    node *ptr=lista->no;
    node *ptr1;
    node *pusher=new_node(value);
    int pos=0;
    if(i==0)
      list_push_front(lista,value);
    else if(i==lista->size && i!=0)
      list_push_back(lista,value);
    else
    {
       while(pos<i-1)
        {
           ptr=ptr->next;
           pos++;
        }
        ptr1=ptr->next;
        pusher->previous=ptr;
        pusher->next=ptr1;
        ptr->next=pusher;
        ptr1->previous=pusher;
        lista->size++;
    }
}

void list_push_back(list* lista, Type value) {
  node *aux=new_node(value);
  node *ptr=lista->final;
  if(lista->size==0)
  {
    lista->no=aux;
    lista->final=aux;
  }
  else
  {
    ptr->next=aux;
    aux->previous=ptr;
    lista->final=aux;
  }
  lista->size++;
}

void list_push_front(list* lista, Type value) {
    node *aux=new_node(value);
    node *ptr=lista->no;
    if(lista->size==0)
    {
      lista->no=aux;
      lista->final=aux;
    }
    else
    {
      ptr->previous=aux;
      aux->next=ptr;
      lista->no=aux;
    }
    lista->size++;
}

// Funções de acesso aos dados
Type* list_at(list* lista, int pos) {
    int i;
    i=0;
    node *ptr=lista->no;
    Type valor;
    while(i<pos)
    {
        ptr=ptr->next;
        i++;
    }
    return ptr->valor;
}

void list_set(list* lista, int pos, Type value) {
    int i;
    i=0;
    node *ptr=lista->no;
    while(i<pos)
    {
        ptr=ptr->next;
        i++;
    }
    ptr->valor=value;
}

void list_print(list* lista) {
  node* ptr=lista->no;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->valor);
    ptr=ptr->next;
  }
  printf("\n");
}

// Retorna a quantidade de elementos na lista
int  list_size(list* lista) {
    int i;
    i=0;
    node *ptr=lista->no;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        i++;
    }
    return i;
}

// Retorna true se a lista está vazia, false caso contrário.
bool list_empty(list* lista) {
    if(lista->no==NULL)
        return true;
    else
        return false;
}

int main()
{
    int capacidade = 0;
    scanf("%d", &capacidade);

    list* v = new_list();

    int ncmds = 0;
    scanf("%d", &ncmds);

    char cmd[20];
    int  indice;
    int  valor;

    while (ncmds-- > 0)
    {
        scanf("%s", cmd);

        if (strcmp(cmd, "push_back") == 0)
        {
            scanf("%d", &valor);
            list_push_back(v, valor);
        } else if (strcmp(cmd, "push_front") == 0)
        {
            scanf("%d", &valor);
            list_push_front(v, valor);
        } else if (strcmp(cmd, "insert") == 0)
        {
            scanf("%d", &valor);
            scanf("%d", &indice);
            list_insert(v, valor, indice);
        } else if (strcmp(cmd, "pop_back") == 0)
        {
            list_pop_back(v);
        } else if (strcmp(cmd, "pop_front") == 0)
        {
            list_pop_front(v);
        } else if (strcmp(cmd, "erase") == 0)
        {
            scanf("%d", &indice);
            list_erase(v, indice);
        } else if (strcmp(cmd, "set") == 0)
        {
            scanf("%d", &indice);
            scanf("%d", &valor);
            list_set(v, indice, valor);
        }
        printf("[%d] ",v->size);
        list_print(v);
    }

    free_list(v);
}
