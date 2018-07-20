#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <stdbool.h>

#define Type char

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
  printf("[%d] ",lista->size);
  while(ptr!=NULL)
  {
    printf("%c",ptr->valor);
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

void list_reverse(list* lista)
{
    list* lista1= new_list();
    while(lista->size!=0)
        list_push_front(lista1,list_pop_back(lista));
    while(lista1->size!=0)
        list_push_back(lista,list_pop_back(lista1));
}

void list_splice(list *lista,list *lista1,int pos)
{
    while(lista1->size!=0)
        list_insert(lista,list_pop_back(lista1),pos);
    list_print(lista);
}

void set_insert(list *lista,Type valor)
{
    node *ptr=lista->no;
    int boleia=0;
    while(ptr!=NULL)
    {
        if(valor==ptr->valor)
           boleia=1;
        ptr=ptr->next;
    }
    if(boleia==0)
       list_push_back(lista,valor);
}

list* set_union(list *lista,list *lista1)
{
    list *lista2=new_list();
    while(lista->size!=0)
        set_insert(lista2,list_pop_front(lista));
    while(lista1->size!=0)
        set_insert(lista2,list_pop_front(lista1));
    return lista2;
}

void crossover(list *lista1,list *lista2,int ponto)
{
    int i;
    i=ponto;
    char valor1,valor2;
    while(i<lista1->size)
    {
        valor1=list_erase(lista1,i);
        valor2=list_erase(lista2,i);
        list_insert(lista1,valor2,i);
        list_insert(lista2,valor1,i);
        i++;
    }
}

int main()
{
    int i,pontos,ponto;
    Type valor;
    int tamanho1,tamanho2;
    i=0;
    list* lista = new_list();
    list* lista1 = new_list();
    char str1[10000],str2[10000];
    scanf("%s",str1);
    scanf("%s",str2);
    tamanho1=strlen(str1);
    tamanho2=strlen(str2);
    while(i<tamanho1)
    {
        list_push_back(lista,str1[i]);
        i++;
    }
    i=0;
    while(i<tamanho2)
    {
        list_push_back(lista1,str2[i]);
        i++;
    }
    i=0;
    scanf("%d",&pontos);
    while(i<pontos)
    {
        scanf("%d",&ponto);
        crossover(lista,lista1,ponto);
        i++;
    }
    list_print(lista);
    list_print(lista1);
    return 0;
}
