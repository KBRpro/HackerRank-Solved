#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include"hashtable.h"
#include"list.h"

long hash(char *str,int n)
{
    long hashval;
    for (hashval = 0; *str != '\0'; str++)
        hashval = *str + 31*hashval;
    return abs(hashval%n);
}

bool compare_by_key(Type objeto,Key chave)
{
  return strcmp( objeto -> palavra , chave ) == 0;
}

Key get_key(Type objeto)
{
  return objeto->palavra;
}

void free_item(Type objeto)
{
	free(objeto);
}

int lenght(char *p)
{
    int i = 0;
    while(p[i] != '\0' && p[i] != ' '){
        if(ispunct( p[i] )){
            p[i] = '\0';
            return i;
        }
        i++;
    }
    return i;
}

void printar_maior(hasht *t)
{
    int i=0;
    int maiorV=0;
    node *ptr;
    node *maior;
    while(i < t->size)
    {
        ptr=t->table[i++]->head;
        while( ptr != NULL )
        {
        	if(ptr->value->repeticoes > maiorV)
        	{
            	maior = ptr;
            	maiorV=ptr->value->repeticoes;
        	}
       	 ptr=ptr->next;
        }
    }
    puts(maior->value->palavra);
}

Type new_word(char *p)
{
    Type word=malloc(sizeof(palavra));
    strcpy(word->palavra, p);
    word->repeticoes=1;
    return word;
}

int main(void)
{
    long insertions;
    char palavra1[100];
    int tamanho;
    int i;
    scanf("%li",&insertions);
    hasht *t=new_hasht(51361);
    for(i=0;i<insertions;i++)
    {
        scanf("%s",palavra1);
        tamanho=lenght(palavra1);
        if(isupper(palavra1[0]) && tamanho>=5)
        {
            Type w = hasht_search(t,palavra1);
            if(w==TYPE_NULL)
                hasht_insert(t,new_word(palavra1));
            else
                w->repeticoes++;
        }
    }
    printar_maior(t);
    free_hasht(t);
    return 0;
}
