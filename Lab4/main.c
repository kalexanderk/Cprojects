#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//функция ввода строчек
char** inp(int *n)
{
	int i=0, j=0;
	char **arr, **temp, *temptemp;
	printf("Enter strings. To stop, enter empty string:\n");
	arr=NULL;
	do
    {
		temp=(char**)malloc((i+1)*sizeof(char*));
		j=0;
		temp[i]=NULL;
		do
		{
			temptemp=(char*)malloc((j+1)*sizeof(char));
			if ((temptemp[j]=getche())==13) temptemp[j]='\0';
			if (temp[i]!=NULL)
			{
				memcpy(temptemp,temp[i],j);
				free(temp[i]);
			}
			temp[i]=temptemp;
			j++;
        } while (temp[i][j-1]!='\0');
		if (arr!=NULL)
		{
			memcpy(temp,arr,i*sizeof(char*));
			free(arr);
		}
		arr=(char**)temp;
		i++;
		printf("\n");
	} while (arr[i-1][0]!='\0');
	*n=i-1;
    return arr;
}

//функция поиска наименьшей длины строчки среди введенных
int searchMin(char **arr, int n, long int *number)
{
	int i, min;
	*number=0;
	if (n!=0) {
		min=*number=strlen(arr[0]);
		for (i=1;i<n;i++) if (*number-(*number+=strlen(arr[i])) && min>strlen(arr[i])) min=strlen(arr[i]);
	} else min=0;
	return min;
}


//функция установки выбранных элементов массива в указанное значение
int inst(int sizeMin, long int numberOfSymbols, char** arrout)
{
  int ret=0;
  bool marker = 1;
  int numb_arr;
  char *arr;
  do
  {
      puts("\nDo you want to change any element of the array? (Input Y/N):  \n");
      char decision;
      decision=getche();
      if (decision == 'N') marker=0;
      double substitution;
      if (decision =='Y')
      {
      if (numberOfSymbols%sizeMin == 0) substitution = roundf(numberOfSymbols/sizeMin);
      else substitution = roundf(numberOfSymbols/sizeMin + 0.5);
      printf("\nInput number of element of the array (from 1 to %.0f):  ", substitution);
      int res; //проверим на число
      res=scanf( " %d" , &numb_arr); //scanf возвращает количество нормально отконвертированнных значений
      fflush(stdin);
      if ((numb_arr>0) & (numb_arr<=substitution) & (res==1))
      {
          printf("Enter new string value of element number %d:\n", numb_arr);
///////////////////////////////////////////////////////////////////////// читает новую 1 строчку, результат arr
        int i=0, j=0;
        char *temp, *temptemp;
        arr=NULL;
        do
        {
            temp=(char*)malloc((i+1)*sizeof(char));
            j=0;
            temp=NULL;
            do
            {
                temptemp=(char*)malloc((j+1)*sizeof(char));
                if ((temptemp[j]=getche())==13) temptemp[j]='\0';
                if (temp!=NULL)
                {

                    memcpy(temptemp,temp,j);
                    free(temp);
                }
                temp=temptemp;
                j++;
            } while (temp[j-1]!='\0');
            if (arr!=NULL)
            {
                memcpy(temp,arr,i*sizeof(char*));
                free(arr);
            }
            arr=(char*)temp;
            i++;
        } while (arr[j-1]!='\0');
/////////////////////////////////////////////////////////////////////////
      arrout[numb_arr-1]=arr;
      ret=100;
      }
     }
  }while (marker==1);

  return ret;
}


//функция определения идентичных строчек
int** ident(int sizeOfArrO, char** arrout)
{
    int i1, i2;
    int** ret_ar = (int**) malloc(sizeOfArrO*sizeof(int*));
    for (i1=0; i1<sizeOfArrO-1; i1++)
        for (i2=i1+1; i2<sizeOfArrO; i2++)
        {
            if (arrout[i1]=arrout[i2])
            {
                ret_ar[i1][i2]=1;
                ret_ar[i2][i1]=1;
            }
        }
return ret_ar;
}


int main() {
	int sizeOfArrI, i1, i2, j1, j2, sizeMin, sizeOfArrO, ch, j;
	long int numberOfSymbols;
	char **arrinp, **arrout;

	arrinp=inp(&sizeOfArrI);
	sizeMin=searchMin(arrinp, sizeOfArrI, &numberOfSymbols);

	printf("Minimal string length = %d. Number of symbols = %d.\n", sizeMin, numberOfSymbols);
	if (sizeMin==0) return 0;
	arrout=(char**)malloc((sizeOfArrO=(numberOfSymbols%sizeMin?1+numberOfSymbols/sizeMin:numberOfSymbols/sizeMin))*sizeof(char*));

	i1=i2=j1=j2=0;
	for (i1=0; i1<sizeOfArrO; i1++) {
		arrout[i1]=(char*)malloc((sizeMin+1)*sizeof(char));
		for (j1=0; j1<sizeMin; j1++, j2++) {
			if (j2==strlen(arrinp[i2])) {
				i2++;
				j2=0;
			}
			arrout[i1][j1]=arrinp[i2][j2];
		}
		arrout[i1][sizeMin]='\0';
	}
	printf("\n");
	for (i1=0; i1<sizeOfArrO; i1++) printf("a[%d] = %s\n", i1+1, arrout[i1]);

	int check;
	check = inst(sizeMin, numberOfSymbols, arrout);
	if (check > 0)
    {
      puts("\nDo you want to display the renewed sequence of array elements? (Input Y/N):\n");
      char decision;
      decision=getche();
      printf("\n \n");
      if (decision =='Y') for (i1=0; i1<sizeOfArrO; i1++) printf("a[%d]' = %s\n", i1+1, arrout[i1]);;
    }
    printf("\n");

    puts("\nDo you want to check which elements of array are the same? (Input Y/N):\n");
    char decision;
    decision=getche();
    printf("\n");
    if (decision =='Y')
    {
        int count;
        int id_arr[sizeOfArrO-1][sizeOfArrO-1];
        for (i1=0; i1<sizeOfArrO-1; i1++)
            for (i2=i1+1; i2<sizeOfArrO; i2++)
            {
                check=0;
                for (count=0; count<sizeMin; count++)
                if (arrout[i1][count]==arrout[i2][count])  check++;
                if (check==sizeMin) printf("\n(Aligned) lines %d and %d are the same.", i1+1, i2+1);
            }
    }

	getchar();
	return 0;
}


