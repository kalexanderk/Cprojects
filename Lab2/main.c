/*Условие: "Дано натуральное число n>=2. Найти все простые числа, которые не превышают n используя решето Эратосфена."*/
/*Эта программа предназначена для запуска с командной строки cmd*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int (*FunType)(int); /*Определили функциональный тип FuncType*/
int CheckFun(int t)
{
    int count, i;
    count = 0;
    for (i = 2; i < t; i++)
    {   /*Проверяю делимость t на каждое из предыдущих чисeл >2.*/
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
        /*if (scanf ("%d", &n)!=1) return 0;*/ /*Как здесь сделать проверку на буквы?*/
        fflush(stdin);
        if (n >= 2)
        {
            int t;
            t = 2;
            printf("Primes are:\n");
            do
            {
                if (HelpFun(CheckFun, t) == t - 2) printf("%d\n", t); /*Если все предыдущие не делятся на t - выписываемм его.*/
                t++; /*Инкремент t.*/
            } while (t <= n); /*Цикл повторяется до тех пор, пока t не больше n.*/
        }
        if (n<2) printf( "usage: %s filename.\nERROR: n must be > than 2.", argv[0] ); /*В случае неправильного ввода данных выводим сообщение об ошибке.*/
        _getch();
        return 0;
    }
    else {printf( "usage: %s filename.\nERROR: enter one argument.", argv[0] ); _getch(); return 1;}


}

