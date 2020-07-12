#include <stdio.h>

typedef struct
{
    int length;
    int A[10];
}array;

void Display(array a){
    int i;
    for(i = 0; i < a.length; i++)
        printf("%d ",a.A[i]);
}

void reverse(array* a)
{
    int i,j;
    int B[a->length];
    for(i = a->length-1, j = 0; i >= 0; i--, j++)
        B[j] = a->A[i];
    for(i = 0; i < a->length; i++)
        a->A[i] = B[i];
}
void swap(int *a, int *b)
{
    int temo;
    temo = *a;
    *a = *b;
    *b = temo;
}
void s_reverse(array *a)
{
    int i,j;
    for(i = 0,j = a->length-1; i <= j; i++, j--)
        swap(&a->A[i],&a->A[j]);
}
void merge(array *a, array *b)
{
    int i = 0,j = 0,k = 0;
    int C[a->length + b->length];
    while(i < a->length && j < b->length){
        if(a->A[i] <= b->A[j]){
            C[k] = a->A[i];
            i++,k++;
        }
        else{
            C[k] = b->A[j];
            j++,k++;
        }
    }
    for(;i<a->length;i++){
            C[k] = a->A[i];
            k++;
        }
    for(;j<b->length;j++){
            C[k] = b->A[j];
            k++;
        }
    for(i=0; i<a->length + b->length; i++)
        printf("%d ",C[i]);
}
void missing_ele(array a)
{
    int i;
    int diff = a.A[0];
    for(i = 0; i < a.length; i++){
        if(a.A[i] - i != diff){
            while(a.A[i] - i > diff){
                printf("%d ",i + diff);
                diff++;
            }
        }
    }
}
int max(array a)
{
    int i;
    int max = 0;
    for(i = 0; i < a.length; i++){
        if(a.A[i] > max)
            max = a.A[i];
    }
    return max;
}
int min(array a)
{
    int i;
    int min = 1000000;
    for(i = 0; i < a.length; i++){
        if(a.A[i] < min)
            min = a.A[i];
    }
    return min;
}
void hash(array  a)
{
    int i;
    int B[max(a)];
    for(i = 0; i < max(a); i++)
        B[i] = 0;
    for(i = 0; i < a.length; i++){
        B[a.A[i]]++;
    }
    for(i = min(a); i < max(a); i++)
        if(B[i] == 0)
            printf("%d ", i);
}
void duplicate(array a)
{
    int i;
    int j;
    for(i = 0; i < a.length - 1; i++){
        if(a.A[i] == a.A[i+1]){
            j = i+1;
            while(a.A[j] == a.A[i])
                j++;
            printf("dup %d for %d times\n",a.A[i],j-i);
            i = j - 1;
        }
    }
}
void dup_hash(array a)
{
    int i;
    int B[max(a)];
    for(i = 0; i < max(a); i++)
        B[i] = 0;
    for(i = 0; i < a.length; i++)
        B[a.A[i]]++;
    for(i = 0; i < max(a); i++){
        if(B[i] > 0){
            printf("dup %d for %d times\n",i,B[i]);
        }
    }
}
int main()
{
    int i;
    array a;
    a.length = 4;
    array b = {7,{5,5,6,7,7,7,8}};
    for(i = 0; i < a.length; i++)
        a.A[i] = i;
    dup_hash(b);
    return 0;
}