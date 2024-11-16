#include <stdio.h>
#include <stdlib.h>

void initialisation(int size, float *p);
void show(int size, float *p);
void paste(int *size, float *p, float elem, int index);
void removed(int *size, float *p, int index);
void special(int *size, float *p);
void fraction(float digit, int *z, float *f);
int fract_integer(float f);

int main()
{
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    float *p = (float*)malloc(size);

    initialisation(size, p);
    //show(size, p);

    //paste(&size, p, 0, 1);
    //show(size, p);

    //removed(&size, p, 2);
    //show(size, p);

    special(&size, p);

    return 0;
}

void initialisation(int size, float *p)
{
    float elem;
    for (int i = 0; i < size; ++i)
    {
        scanf("%f", &elem);
        p[i] = elem;
    }
}

void show(int size, float *p)
{
    for (int i = 0; i < size; ++i)
    {
        printf("\np[%d] = %f ", i, p[i]);
    }
    printf("\n");
}

void paste(int *size, float *p, float elem, int index)
{
    //if (index < size)
    (*size)++;
    p = realloc(p, (*size) * sizeof(float)); //увеличили размер массива на 1

    for (int i = ((*size)-2); i >= index; --i) //cдвигаем элементы после индекса вставляемого на 1 вправо
    {
        p[i+1] = p[i];
    }
    p[index] = elem;
}

void removed(int *size, float *p, int index)
{
    (*size)--;
    for (int i = index; i <= ((*size)-1); ++i)
    {
        p[i] = p[i+1];
    }
    p = realloc(p, (*size) * sizeof(float));
}

void special(int *size, float *p)
{
    int z, f_z;
    float f;
    for (int i = 0; i < (*size); ++i)
    {
        z = (int)p[i]; //целая часть
        printf("z = %d\n", z);
        f = p[i] - z; //дробная часть
        f_z = fract_integer(f);
        if (z < f_z)
        {
            printf("for i=%d %d<%d", i, z, f_z);
        }
    }

}

void fraction(float digit, int *z, float *f) //выделяет из числа целую и дробную части
{
    printf("%f\n", digit);
    int a = (int)digit;
    *z = a;
    float b = digit - (*z);
    *f = b;
}

int fract_integer(float f) //передаем сюда дробную часть числа
{
    int z, integer = 0, rank = 1;
    /*while (f != 0)
    {
        f *= 10;
        fraction(f, &z, &f);
        integer += z * rank;
        rank *= 10;
    }*/

    for (int i = 0; i < 2; ++i)
    {
        if (f == 0){break;}
        f *= 10;
        fraction(f, &z, &f);
        integer += z * rank;
        rank *= 10;
    }

    return integer;
}

int fract_integer2(float noint) //передаем сюда дробь
{
    a = (int)
}