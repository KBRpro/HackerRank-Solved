
#include <stdbool.h>
// Se Type e Key não foram definidos de antemão, serão aqui definidos como inteiros
#ifndef Type
 #define Type palavra*
#endif

#ifndef Key
 #define Key char*
#endif

#ifndef TYPE_NULL
 #define TYPE_NULL NULL
#endif

#ifndef TYPE_REMOVED
 #define TYPE_REMOVED -99999998
#endif

// Define o tipo abstrato de dados hasht
typedef struct HASH_TABLE hasht;
// Gerenciamento de memória
hasht* new_hasht(long capacity);
void free_hasht(hasht* ht);
// Manipulação da estrutura de dados
void hasht_insert(hasht* ht, Type obj);
Type hasht_search(hasht* ht, Key k);

// Funções a serem definidas em main.c
Key get_key(Type obj);/
bool compare_by_key(Type obj, Key k);/
void print_item(Type obj);/
void free_item(Type obj);/
long hash(long *str, int n);
