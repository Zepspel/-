#include <stdio.h>

fract_integer2(float noint);

int main()
{
    fract_integer2(3.78);


    return 0;
}

int fract_integer2(float noint) //передаем сюда дробь
{
    int sum = 0;
    int rank = 1;
    int frac2;
    int divider = 1000000;
    int integer = (int)noint;
    int frac = (int)(noint * 1000000);
    frac = frac % divider;

    printf("%d, %d\n", integer, frac);

   int a;
   for (int i=0; i<6; ++i)
   {
        a = frac % 10;
        frac = frac / 10;
        sum += a * rank;
        if (a != 0)
        {
            rank *= 10;
        }

   }

    printf("%d", sum);
}