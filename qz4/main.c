#include <stdio.h>
#include <stdlib.h>
int swap(int* i,int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}
int swapArray(int source[10],int dest[10],int size) {
    for (int i=0;i<10;i++) {
        swap(&source[i],&dest[i]);
    }
}
int printArray(int array[10],int size) {
    for (int i=0;i<10;i++) {
        if (i==9) {
            printf("%d",array[i]);
        } else {
            printf("%d, ",array[i]);
        }
    }
    printf("]\n");
}
char* copy_string(char* s) {
    int len=0;
    while (*s++!='\0') {len++;}
    char* ptr[len];
    for (int i=0;i<len;i++) {
        ptr[i] = (char*)calloc(10,sizeof(char));
        s--;
    } s--;
    for (int i=0;i<len;i++) {
        ptr[i]=s++;
        return ptr[i];
    }
    free(ptr[len]); ptr[len]=NULL;
}

int main() {
    printf("No.1 -------------------\n");
    int n,m;
    n=1;
    m=2;
    swap(&n,&m);
    printf("after swap, n = %d, m = %d\n",n,m);
    printf("No.2 -------------------\n");
    int size = 10;
    int source[10] = {0,9,8,7,6,5,4,3,2,1};
    int dest[10] =  {10,20,30,40,50,60,70,80,90,100};
    swapArray(source,dest,size);
    printf("after swap array, source array = [");
    printArray(source,size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    printf("No.3 -------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n",cp_str);
    return 0;
}
