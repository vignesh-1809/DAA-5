#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    swap(&m, &n);
    printf("%d,%d\n",m,n);

    return 0;
}
