#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int** new_matrix(int m, int n)
{
    int **matriz = (int**)malloc(m*sizeof(int*));
    int i,j;
    for (i=0;i<m;i++)
    {
       matriz[i]=(int*)malloc(n*sizeof(int));
       for(j=0;j<n;j++)
           matriz[i][j]=0;
    }
    return matriz;
}

void free_matrix(int** matrix, int m)
{
    int i;
     for (i= 0;i<m;i++)
        free(matrix[i]);
}

void print_matrix(int** matrix, int m, int n)
{
    int i,j;
    printf("%d %d\n",m,n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}


int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int** matrix = new_matrix(m, n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    print_matrix(matrix, m, n);
    free_matrix(matrix, m);
}
