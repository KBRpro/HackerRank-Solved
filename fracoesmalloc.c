1#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction* new_fraction(int a, int b)
{
 Fraction *aux;
 aux=malloc(sizeof(Fraction));
 aux->numerator=a;
 aux->denominator=b;
 return aux;
}

Fraction* add(Fraction* a,Fraction* b)
{
    Fraction* c;
    c=new_fraction(((a->numerator*b->denominator)+(b->numerator*a->denominator)),(a->denominator*b->denominator));
    return c;
}

Fraction* sub(Fraction* a, Fraction* b)
{
    Fraction* c;
    c=new_fraction(((a->numerator*b->denominator)-(b->numerator*a->denominator)),(a->denominator*b->denominator));
    return c;
}

Fraction* multiply(Fraction* a, Fraction* b)
{
    Fraction* c;
    c=new_fraction((a->numerator*b->numerator),(a->denominator*b->denominator));
    return c;

}

Fraction* divide(Fraction* a, Fraction* b)
{
    Fraction* c;
    c=new_fraction((a->numerator*b->denominator),(a->denominator*b->numerator));
    return c;
}

void print(Fraction* f)
{
    int num,dem;
    num=f->numerator;
    dem=f->denominator;
    printf("%d/%d\n",f->numerator,f->denominator);
}


int main()
{
    int nops; // Número de operações a serem efetuadas
    char op;  // Caractere indicando a operação: +, -, *, /

    Fraction* a = new_fraction(0,0);
    Fraction* b = new_fraction(0,0);

    scanf("%d", &nops);

    Fraction* result;
    while (nops-- > 0)
    {
        // Lê o numerador e denominador da primeira fração
        scanf("%d %d", &a->numerator, &a->denominator);
        // Lê um espaço e lê o caractere do operador
        scanf("%c%c", &op, &op);
        // Lê o numerador e denominador da segunda fração
        scanf("%d %d", &b->numerator, &b->denominator);

        // Efetua a operação indicada pelo caractere op
        switch(op) {
            case '+': result = add(a, b); break;
            case '-': result = sub(a, b); break;
            case '*': result = multiply(a, b); break;
            case '/': result = divide(a,b);    break;
        }
        print(result);
        free(result);
    }
}
