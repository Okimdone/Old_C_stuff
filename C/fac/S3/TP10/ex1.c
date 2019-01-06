#include <stdio.h>

int main()
{
    int A[]={12,23,34,45,56,67,78,89,90},*P=A;

    printf("a) *P+2\t\t\t-->%d\n",*P+2);
    printf("b) *(P+2)\t\t-->%d\n",*(P+2));
    printf("c) &P+1\t\t\t-->%p\n",&P+1);
    printf("d) &A[4]-3\t\t-->%p\n",&A[4]-3);
    printf("e) A+3\t\t\t-->%p\n",A+3);
    printf("f) &A[7]-P\t\t-->%ld\n",&A[7]-P);
    printf("g) P+(*P-10)\t\t-->%p\n",P+(*P-10));
    printf("h) *(P+*(P+8)-A[7])\t-->%i\n",*(P+*(P+8)-A[7]));

}