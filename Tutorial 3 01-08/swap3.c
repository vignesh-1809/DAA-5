#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    swap(&m, &n);
    printf("%d,%d\n",m,n);

    return 0;
}
