#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* get_int_array(int n) {
    return (int*)calloc(n,sizeof(int));
}

void set_value(int* p,int v) {
    int* t=p;
    *t=v;
}

void print_array(int* p, int n) {
    printf("[");
    for (int i=0;i<n;i++) {
        (i!=(n-1))? printf("%d, ",*p++):printf("%d]\n",*p++);
    }
}

typedef struct array_list {
    int n;
    int* (*GET_INT_ARRAY)(int);
    void (*SET_VALUE)(int*,int);
    void (*PRINT_ARRAY)(int*,int);
} array_list_t;

// int func(char a[], char b[]) {
//     strcpy(a,b);
//     return a;
// }

// int add_func(char a[], char b[], char (*func_ptr)(char, char)) {
//     return func_ptr(a,b);
// }

int main() {
    int n = 10;
    int* ip = get_int_array(n);
    for (int i=0;i<n;i++) {
        set_value(ip+i,i+1);
    }
    printf("No.1 --------------------\n");
    print_array(ip,n);
    free(ip);
    ip=NULL;
    printf("No.2 --------------------\n");
    array_list_t array_list;
    array_list.n=15;
    array_list.GET_INT_ARRAY=get_int_array;
    array_list.SET_VALUE=set_value;
    array_list.PRINT_ARRAY=print_array;
    ip = GET_INT_ARRAY(array_list.n);
    for (int i=0;i<n;i++) {
        SET_VALUE(ip+i,i+1);
    }
    PRINT_ARRAY(ip,array_list.n);
    free(ip);
    ip=NULL;
    printf("No.3 --------------------\n");
    char a[]="IU!IU!";
    char b[]="@CGU";
    int alen=0,blen=0,i=0,j=0;
    while (a[i++]!='\0') {alen++;}
    while (b[j++]!='\0') {blen++;}
    //printf("alen:%d blen:%d",alen,blen);
    //printf("add_str_func = %s\n",add_str_func(a,b,func));
    return 0;
}
