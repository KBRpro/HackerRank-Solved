#include "hashtable.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct HASH_TABLE
{
    Type* table;
    long size;
    long nelem;
};


hasht* new_hasht(long capacity)
{
    hasht* t = malloc(sizeof(hasht));
    t->size = capacity;
    t->nelem = 0;
    t->table = malloc(sizeof(Type) * capacity);
    for (long i = 0; i < t->size; i++)
        t->table[i] = TYPE_NULL;
    return t;
}

void free_hasht(hasht* t)
{
    for (long i = 0; i < t->size; i++)
        free_item(t->table[i]);
    free(t->table);
    free(t);
}

long rehash(long hash, int j, long N)
{
    return (hash + j) % N;
}

Type hasht_search(hasht* t, Key k)
{
    long khash = hash(k, t->size);
    int j = 1;
    long reps = t->size;
    long i = khash;
    while ( t->table[i] != TYPE_NULL && reps-- > 0)
    {
        if ( compare_by_key( t->table[i], k )  )
            return t->table[i];
        i = rehash(khash, j++, t->size);
    }
    return TYPE_NULL;
}

void hasht_insert(hasht* t, Type obj)
{
    Type r = hasht_search(t,  get_key(obj) );
    if ( r == TYPE_NULL )
    {
      long i = hash( get_key(obj)  , t->size);
      list_push_front( t->table[i], obj );
    }
}


void hasht_print(hasht* t)
{
  for (long i = 0; i < t->size; i++)
  {
      node* ptr = t->table[i]->head;
      printf("%ld: ", i );
      while ( ptr != NULL )
      {
          print_item( ptr->value );
          ptr = ptr->next;
      }
      printf("\n");
  }
}
