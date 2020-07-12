#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int coeff;
    int exp;
}Term;

typedef struct{
    int num;
    Term* terms;
}Poly;

void create_poly(Poly* p)
{
    int i;
    printf("Num of terms:\n");
    scanf("%d",&p->num);
    p->terms = (Term*) malloc(p->num * sizeof(Term));
    printf("Scan terms:\n");
    for(i=0; i<p->num; i++){
      scanf("%d %d",&p->terms[i].coeff, &p->terms[i].exp);  
    }
}
Poly* add_poly(Poly *p1, Poly *p2)
{
    int i=0,j=0,k=0;
    Poly* sum;
    sum = (Poly*) malloc(sizeof(Poly));
    sum->terms =(Term*) malloc((p1->num + p2->num)*sizeof(Term));
    while(i < p1->num && j < p2->num){
        if(p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
                sum->terms[k] = p1->terms[i];
                sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff; 
        }
    }
    for(;i<p1->num;i++)
        sum->terms[k++] = p1->terms[i];
    for(;j<p2->num;j++)
        sum->terms[k++] = p2->terms[j];
    sum->num = k;
    return sum;
}
void display_poly(Poly p)
{
    int i;
    for(i = 0; i < p.num; i++)
        printf("%dx^%d+",p.terms[i].coeff,p.terms[i].exp);
    printf("\n");   
}
int main()
{
    Poly p1,p2,*p3;
    create_poly(&p1);
    create_poly(&p2);
    p3 = add_poly(&p1,&p2);
    printf("\n");
    display_poly(p1);
    printf("\n");
    display_poly(p2);
    printf("\n");
    display_poly(*p3);
    return 0;
}