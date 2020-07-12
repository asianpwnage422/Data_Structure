#include <stdio.h>
#include <stdlib.h>

struct Array{
    int length;
    int A[5];
};

void insertion_sort(struct Array* b)
{
    int i,j,key;
    for(i = 1; i < b->length; i++){
        key = b->A[i];
        j = i-1;
        while(j >= 0 && b->A[j] > key){
            b->A[j+1] = b->A[j];
            j = j-1;
        }
        b->A[j+1] = key;
    }
}
void Display(struct Array b){
    int i;
    for(i = 0; i < b.length; i++)
        printf("%d ",b.A[i]);
    printf("\n");
}
int main()
{
    int i,j=1;
    struct Array b;
    b.length = 5;
    for(i = b.length-1; i >= 0; i--){
        b.A[i] = j;
        j++;
    }
    insertion_sort(&b);
    Display(b);
    return 0;
}