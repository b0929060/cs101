#include <stdlib.h>
#include <stdio.h>
int* find_num(int* p,int* n,int target) {
    int adr=0;
    for (int i=0;i<10;i++) {
        if (*n == target) {
           adr = i;
           break;
        }
        n++;
    }
    printf("&n[%d]->%p, n[%d]=%d; ",adr,&n,adr,*n);
    printf("p->%p, *p=%d\n",p,*p);
}

int main() {
    int n[]={6,4,7,2,0,9,8,1,5,3};
    int* p=n;
    printf("No.1 --------------------\n");
    find_num(p,n,9);
    printf("No.2 --------------------\n");
    int* ap[10];
    //排序大小
	for (int i = 0; i < 10; ++i) {          
		for (int j = 0; j < 9 - i; ++j) { 
			if (n[j] > n[j + 1]) {
				int temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}
// 	for (int i=0;i<10;i++) {
//         printf("%d,",n[i]);
//     }
    for (int i=0;i<10;i++) {
        ap[i]=&n[i];
    }
    for (int i=0;i<10;i++) {
        printf("&n[%d]->%p, n[%d]=%d; ",i,&n[i],i,n[i]);
        printf("ap[%d]->%p, *ap[%d]=%d\n",i,ap[i],i,*ap[i]);
    }

    return 0;
}
