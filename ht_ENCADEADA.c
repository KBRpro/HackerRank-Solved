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

void free_hasht(hasht* t)
{
    for (long i = 0; i < t->size; i++)
    {
        node* ptr = t->table[i]->head;
        while (ptr != NULL)
        {
            node* tmp = ptr;
            ptr = ptr->next;
            free_item(tmp->value);
        }
        free(t->table[i]);
    }
    free(t->table);
    free(t);
}

Type hasht_search(hasht* v, Key k)
{
    long i = hash(k, v->size);

    node* ptr = v->table[i]->head;

    while (ptr != NULL)
    {
        if ( compare_by_key( ptr->value, k )  )
            return ptr->value;
        ptr = ptr->next;
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

/*void hasht_print(hasht* t)
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
}*/
//foi utilizado o printar_maior para printar.
