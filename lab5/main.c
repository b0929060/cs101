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

char* ptr;
char* func(char a[], char b[]) {
    int alen=0,blen=0,i=0,j=0;
    while (a[i++]!='\0') {alen++;}
    while (b[j++]!='\0') {blen++;}
	ptr = (char*)calloc(alen+blen,sizeof(char));
	for(int i=0; i<alen;i++) {
		ptr[i]=a[i];
	}
	for(int i=0;i<blen;i++) {
		ptr[alen+i] = b[i];
	}
	ptr[alen+blen] = '\0';
	return ptr;
}

char* add_str_func(char a[], char b[], char* (*func_ptr)(char*, char*)) {
	return func_ptr(a,b);
}

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
    array_list.n=20;
    array_list.GET_INT_ARRAY=get_int_array;
    array_list.SET_VALUE=set_value;
    array_list.PRINT_ARRAY=print_array;
    int* ip2 = array_list.GET_INT_ARRAY(array_list.n);
    for (int i=0;i<array_list.n;i++) {
        array_list.SET_VALUE(ip2+i,i+1);
    }
    array_list.PRINT_ARRAY(ip2,array_list.n);
    free(ip2);
    ip2=NULL;
    printf("No.3 --------------------\n");
    char a[]="IU!IU!";
    char b[]="@CGU";
    printf("add_str_func = %s\n",add_str_func(a,b,func));
    free(ptr);
    ptr=NULL;
    return 0;
}
