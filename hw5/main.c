#include <stdio.h>
int g_mem[10];
typedef struct my_mm {
    int used[10];       //有無被占用
    int ptr[10];        //被哪個pointer占用
} my_mm_t;
my_mm_t mms;
int num=0;
int* my_calloc(int n,int size) {
    if (num==0) {
        num=n;    
    } else {
        num=num+n;
    }
    int flag=0,spc=0,indx=0;
    for (int i=0;i<10;i++) {
        if (mms.used[i]==0&spc==0) {
            spc++;
            indx=i;
        } else if (mms.used[i]==0) {
            spc++;
        }
    }
    if (spc>=size) {
        for (int i=indx;i<indx+size;i++) {
            mms.used[i]=1;
            mms.ptr[i]=num;
        }
        printf("mms->");    //印出mms
        for (int i=0;i<10;i++) {
            printf("%d",mms.used[i]);
        }
        printf("\n");
        return mms.used+indx; //(有空的第一個位置?);
    } else {  
        printf("mms->");    //印出mms
        for (int i=0;i<10;i++) {
            printf("%d",mms.used[i]);
        }
        printf(" <— Out of space\n");
        return NULL;    //沒空間,回傳NULL給np 
    }
}
void my_free(int* p) {
    *p=0;
    p=NULL;
    for (int i=0;i<10;i++) {
        if (mms.ptr[i]==num) {
            mms.ptr[i]=0;
        }
    }
    printf("mms->");    //印出mms
    for (int i=0;i<10;i++) {
        printf("%d",mms.used[i]);
    }
    printf("\n");
}
int main() {
    int* np1 = my_calloc(1,1);
    int* np2 = my_calloc(1,2);
    int* np3 = my_calloc(1,3);
    int* np4 = my_calloc(1,4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1,3);
    return 0;
}
