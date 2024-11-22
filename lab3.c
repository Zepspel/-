#include <stdio.h>
#include <stdlib.h>

void initialisation(int size, float *p);
void show(int size, float *p);
void paste(int *size, float *p, float elem, int index);
void removed(int *size, float *p, int index);
void special(int *size, float *p, int *newsize, float **pp);
int fract_integer2(float noint);

int main()
{
    int size, newsize;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    float *p = (float*)malloc(size*sizeof(float));

    initialisation(size, p);
    show(size, p);

    //paste(&size, p, 0, 1);
    //show(size, p);

    //removed(&size, p, 2);
    ///show(size, p);

    float **pp;

   

    special(&size, p, &newsize, pp);

    //printf("size=%d\n", newsize);
    //printf("pp=%s\n", *pp);
    show(newsize, *pp);

    free(p);
    free(*pp);
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

void special(int *size, float *p, int *newsize, float **pp)
{
    int z, f_z, k=0;
    float f;
    for (int i = 0; i < (*size); ++i) //счетаем количество нужных нам чисел
    {
        z = (int)p[i]; //целая часть
        f_z = fract_integer2(p[i]);
        if (z < f_z)
        {
            //printf("for i=%d %d<%d\n", i, z, f_z);
            k++; //счетчик количества нужных нам чисел
        }
    }

    *newsize = k;
    printf("k=%d\n", k);


    float* pp1 = (float*)malloc(k*sizeof(float));
    int r = 0; //итератор по новому массиву
    for (int i = 0; i < (*size); ++i)
    {
        z = (int)p[i]; //целая часть
        f_z = fract_integer2(p[i]);
        if (z < f_z)
        {   
            *((pp1) + r) = p[i];
            //printf("pp1=%f\n", *(pp1+r));
            r++;
            removed(size, p, i);
            i--;
        }
    }
    *pp = pp1;

}

int fract_integer2(float noint) //передаем сюда дробь
{
    int sum = 0;
    int rank = 1;
    //int integer = (int)noint;
    int frac = (int)(noint * 1000000);
    frac = frac % 1000000;
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
    return sum;
}
