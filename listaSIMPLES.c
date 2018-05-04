#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Type int

// Nó de lista
typedef struct _node {
    Type valor;
    struct _node* next;
} node;


typedef struct TAD_LIST {
    node* no;
    int size;
}list;

// Aloca memória para um 'node' e define o endereço do próximo como NULL
node* new_node(Type valor) {
    node* n = malloc(sizeof(node));
    n->valor = valor;
    n->next  = NULL;
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
   node *ptr=lista->no;
   if(lista->size==1)
   {
       retorno=lista->no->valor;
       lista->no=NULL;
       lista->size=0;
   }
    else
    {
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
        retorno=ptr->next->valor;
        ptr->next=NULL;
        lista->size--;
    }
    return retorno;
}

Type list_pop_front(list* lista) {
    Type valor;
    valor=lista->no->valor;
    lista->no=lista->no->next;
    lista->size--;
    return valor;
}

Type list_erase(list* lista, int i){
    Type retorno;
    int pos=0;
    node *ptr=lista->no;
    node *ptr1=lista->no;
    if(i==0)
        retorno=list_pop_front(lista);
    else if(i==lista->size)
        retorno=list_pop_back(lista);
    else
    {
        while(pos<i-1)
        {
           ptr=ptr->next;
           ptr1=ptr1->next;
           pos++;
        }
        ptr1=ptr1->next;
        retorno=ptr1->valor;
        ptr1=ptr1->next;
        ptr->next=ptr1;
        lista->size--;
    }
    return retorno;
}

// Funções de inserção de elementos
void list_insert(list* lista, Type value, int i)
{
    node *ptr=lista->no;
    node *ptr1=lista->no;
    node *pusher=new_node(value);
    int pos=0;
    if(i==0)
    {
        pusher->next=lista->no;
        lista->no=pusher;
    }
    else if(i==lista->size && i!=0)
    {
       while(ptr->next!=NULL)
            ptr=ptr->next;
       ptr->next=pusher;
    }
    else
    {
       while(pos<i-1)
        {
           ptr=ptr->next;
           ptr1=ptr1->next;
           pos++;
        }
        ptr1=ptr1->next;
        pusher->next=ptr1;
        ptr->next=pusher;
    }
    lista->size++;
}

void list_push_back(list* lista, Type value) {
  node *aux=new_node(value);
  if(lista->size==0)
    lista->no=aux;
  else
  {
    node *ptr=lista->no;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=aux;
  }
  lista->size++;
}

void list_push_front(list* lista, Type value) { //erro
    node *aux=new_node(value);
    aux->next=lista->no;
    lista->no=aux;
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
