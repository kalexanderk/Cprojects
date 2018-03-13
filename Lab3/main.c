#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void fill_matrix(int n, int **a)
{
    int i, j, natural;
    natural=1;
    for (i=0; i<=n-1; i++)
        for (j=MIN(i,n-i-1); j<=MAX(n-i-1, i); j++)
        {
            a[i][j]=natural*natural;
            natural++;
        }
}

void out_matrix(int n, int **a)
{
    int i, j;
    for(i=0; i<=n-1; i++)
        for (j=0; j<=n-1; j++)
        {
            if (j>0 && (j+n-1)%(n-1)==0) printf("%10d\n", a[i][j]);
            else printf("%10d", a[i][j]);
        }

}

main(int argc, char *argv[])
{
  int n;
  n=atoi(argv[1]); /*matrix size*/
  if (n>0)
  {   int i, j;
      int **a;
      /*The RHS of the second line returns a vector (of size N) of pointers to pointers.
       The third line allocates a block of memory large enough to contain all the elements of
       the array, and returns the starting address to a[0] i.e. the first element of the
       vector of pointers to pointers (the first-level pointers).  The final loop
       makes each of the remaining first-level pointers point to the first element of each 'row'
       of the 2D array by using pointer arithmetic.*/
      a=(int**)calloc(n, sizeof(int*));
      a[0]=(int*)calloc(n*n, sizeof (int));
      for (i=0; i<n; i++)
      {
         a[i]=a[0]+i*n;
      }

      if (a != NULL)
          {
              fill_matrix(n, a);
              out_matrix(n, a);
              for (i=0; i<n; i++)
                {
                    free(a[i]);
                }
              free(a);
          }
      _getch();
      return 0;
  }
  else
  {
    printf("usage: %s filename.\nERROR: enter int argument >0.", argv[0]);
    _getch();
    return 1;
  }

}
