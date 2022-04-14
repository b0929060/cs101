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
    int indx[10];
    //排序大小
	for (int i = 0; i < 10; ++i) {          
		for (int j = 0; j < 9 - i; ++j) { 
			if (n[j] > n[j + 1]) {
				int temp = n[j];
				indx[j] = n[j + 1];
				indx[j + 1] = temp;
			}
		}
	}
// 	for (int i=0;i<10;i++) {
//         printf("%d,",indx[i]);
//     }
    for (int i=0;i<10;i++) {
        ap[i]=&n[i];
    }
    for (int i=0;i<10;i++) {
        printf("&n[%i]->%p, n[%i]=%d; ",indx[i],&n[indx[i]],i,n[indx[i]]);
        printf("ap[%i]->%p, *ap[%i]=%i\n",i,ap[i],i,*ap[i]);
    }

    return 0;
}
