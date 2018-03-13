/*�������: "���� ����������� ����� n>=2. ����� ��� ������� �����, ������� �� ��������� n ��������� ������ ����������."*/
/*��� ��������� ������������� ��� ������� � ��������� ������ cmd*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int (*FunType)(int); /*���������� �������������� ��� FuncType*/
int CheckFun(int t)
{
    int count, i;
    count = 0;
    for (i = 2; i < t; i++)
    {   /*�������� ��������� t �� ������ �� ���������� ���e� >2.*/
        if ((t%i) != 0) count = count + 1;
        if ((t%i) == 0) { break; count = count + 0; }
    }
    return count;
}

int HelpFun(FunType CheckFun, int t)
{
    return CheckFun(t);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int n;
        n=atoi(argv[1]); /* Conversion string into int */
        /*if (scanf ("%d", &n)!=1) return 0;*/ /*��� ����� ������� �������� �� �����?*/
        fflush(stdin);
        if (n >= 2)
        {
            int t;
            t = 2;
            printf("Primes are:\n");
            do
            {
                if (HelpFun(CheckFun, t) == t - 2) printf("%d\n", t); /*���� ��� ���������� �� ������� �� t - ����������� ���.*/
                t++; /*��������� t.*/
            } while (t <= n); /*���� ����������� �� ��� ���, ���� t �� ������ n.*/
        }
        if (n<2) printf( "usage: %s filename.\nERROR: n must be > than 2.", argv[0] ); /*� ������ ������������� ����� ������ ������� ��������� �� ������.*/
        _getch();
        return 0;
    }
    else {printf( "usage: %s filename.\nERROR: enter one argument.", argv[0] ); _getch(); return 1;}


}

