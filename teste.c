#include<math.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

long ntrocas = 0;
long ncomps = 0;

#define MAX 10000

//Função Swap
void swap(int*v, int a, int b)
{
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
    ntrocas++;
}
// Fim da função Swap

// Cria��o de vetores
void random_sequence(int* v, int n)
{
    for(int i=0; i<n; i++)
    {
        v[i] = rand() % MAX;
    }
}

void random_cres_sequence(int* v, int n)
{
    v[0] = rand() % MAX;
    for(int i = 1; i < n; i++)
    {
        v[i] = v[i-1]+rand() % MAX;
    }
}

void quick_sortD(int lista[],int tamanho)
{
    quick(lista,0,tamanho-1);
}
void quick(int lista[],int esquerdo,int direito)
{
  register int i,j;
       int x,y;
       i = esquerdo;
       j = direito;
       x = lista[(esquerdo+direito)/2];
       do{
           while(lista[i]>x && i<direito) i++;
           while(x>lista[j] && j>esquerdo) j--;
           if(i<=j){
              y = lista[i];
              lista[i] = lista[j];
              lista[j] = y;
              i++;
              j--;
                       }
              }while(i<=j);
              if(esquerdo<j) quick(lista,esquerdo,j);
              if(i<direito) quick(lista,i,direito);
}

int* random_decr_sequence(int *vet, int n)
{
    random_cres_sequence(vet,n);
    quick_sortD(vet,n);
}

void random_semi_sequence(int* v, int n)
{
   random_cres_sequence(v, n);
    int j = (n*0.15)+1;
    for(int i = j; i > 0; i--){
        int a = rand()%n;
        int b = rand()%n;
        swap(v, a, b);
    }
}
/*
void random_cres_sequence(int* vet, int n)
{
    random_sequence(vet, n);
    heapsort(vet, n);

}*/
//Fim da criação de vetores



//Função BubbleSort
void bolha(int vetor[], int tam)
{
    int i, j;

    for(i=tam-1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                //ncomps++;
                swap(vetor, j, j+1);
            }
        }
    }
}
// Fim do BubbleSort

//Função HeapSort
void heapsort(int* v, int n)
{
    int i = n, p, f, aux; //p = pai; f = filho.
    while(1)
    {
        if(i > 0)
        {
            ncomps++;
            i--;
            aux = v[i];
        }
        else
        {
            n--;
            if(n==0)
                return;
            aux = v[n];
            v[n] = v[0];
        }
        p = i;
        f = (i * 2) + 1;
        while(f < n)
        {
            if((f + 1 < n)&&(v[f + 1] > v[f] ))
            {
                ncomps++;
                f++;
            }
            if(v[f] > aux)
            {
                ncomps++;
                v[p] = v[f];
                p = f;
                f = p * 2 + 1;
            }
            else
            {
                break;
            }
        }
        v[p] = aux;
    }
}
//Fim da Função Heapsort

//Função QuickSort
int partition(int* v, int ini, int f)
{
    int pivo = v[f];
    int i = (ini-1);

    for(int j = ini; j<=f-1; j++)
    {
        if(v[j]<=pivo)
        {
            ncomps++;
            i++;
            swap(v,j,i);
        }

    }
    swap(v,i+1,f);
    return (i+1);
}


void quick_sort(int* v, int i, int f)
{
    if (i < f)
    {
        ncomps++;
        int p = partition(v, i, f);
        quick_sort(v, i,   p-1);
        quick_sort(v, p+1, f);
    }
}
// Fim do quickSort

//Função MergeSort
void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
// Fim do mergeSort

//int argc, char** argv
int main()
{
    //int tam = atoi(argv[1]);

    //int opt = atoi(argv[2]);
    int i, tam;
    scanf("%d", &tam);
    int vetor1[tam];
    int vetor2[tam];
    int vetor3[tam];
    int vetor4[tam];

    printf("\n Semi: ");
    random_semi_sequence(vetor1, tam);
    for(i=0; i < tam; i++)
    {
        printf("%d ", vetor1[i]);
    }
    printf("\n Cres: ");
    random_cres_sequence(vetor2, tam);

    for(i=0; i < tam; i++)
    {
        printf("%d ", vetor2[i]);
    }
    printf("\n Decr: ");
    random_decr_sequence(vetor3, tam);

    for(i=0; i < tam; i++)
    {
        printf("%d ", vetor3[i]);
    }
     printf("\n Rand: ");
      random_sequence(vetor4, tam);

    for(i=0; i < tam; i++)
    {
        printf("%d ", vetor4[i]);
    }
    /*for(int exp = 0 ; exp < 30; exp++)
    {
        switch(opt)
        {
        case 0:
            random_sequence(vetor,tam);  //Gerar vetores ramdomicos
            clock_t inicio = clock();
            quick_sort(vetor,0,tam);
            clock_t fim = clock();
            double diff = (double) (fim-inicio);
            diff = diff/CLOCKS_PER_SEC;
            printf("%lf\t%ld\t%ld\n",diff, ntrocas, ncomps);
            ntrocas = 0;
            ncomps = 0;
            break;
        case 1:
            random_cres_sequence(vetor,n);
            clock_t inicio = clock();
            quick_sort(vetor,0,tam);
            clock_t fim = clock();
            double diff = (double) (fim-inicio);
            diff = diff/CLOCKS_PER_SEC;
            printf("%lf\t%ld\t%ld\n",diff, ntrocas, ncomps);
            ntrocas = 0;
            ncomps = 0;
            break;
            case 2:
            random_decr_sequence(vetor,n);
            clock_t inicio = clock();
            quick_sort(vetor,0,tam);
            clock_t fim = clock();
            double diff = (double) (fim-inicio);
            diff = diff/CLOCKS_PER_SEC;
            printf("%lf\t%ld\t%ld\n",diff, ntrocas, ncomps);
            ntrocas = 0;
            ncomps = 0;
            break;
                case 2:
            random_cres_sequence(vetor,n);
            clock_t inicio = clock();
            quick_sort(vetor,0,tam);
            clock_t fim = clock();
            double diff = (double) (fim-inicio);
            diff = diff/CLOCKS_PER_SEC;
            printf("%lf\t%ld\t%ld\n",diff, ntrocas, ncomps);
            ntrocas = 0;
            ncomps = 0;
            break;
        }

    }*/



    return 0;
}
