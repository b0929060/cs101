#include <stdlib.h>
#include <stdio.h>
int* find_num(int* p,int* n,int target) {
    int adr=0;
    for (int i=0;i<10;i++) {
        if (*n == target) {
           adr = i;
           printf("&n[%d]->%p, n[%d]=%d; ",adr,&n,adr,*n);
           break;
        }
        n++;
    }
    return n;
}

int main() {
    int n[]={6,4,7,2,0,9,8,1,5,3};
    int* p;
    printf("No.1 --------------------\n");
    p=find_num(p,n,9);
    printf("p->%p, *p=%d\n",p,*p);
    printf("No.2 --------------------\n");
    int* ap[10];
    int indx[10],m[10];
    for (int i=0;i<10;i++) {
        m[i]=n[i];
    }
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
	for (int i=0;i<10;i++) {
	    for (int j=0;j<10;j++) {
	        if (n[i]==m[j]) {
	            indx[i]=j;
	            break;
	        }
	    }
	} 
    for (int i=0;i<10;i++) {
        ap[i]=&(m[indx[i]]);
    }
    for (int i=0;i<10;i++) {
        printf("&n[%i]->%p, n[%i]=%d; ",indx[i],&m[indx[i]],indx[i],m[indx[i]]);
        printf("ap[%i]->%p, *ap[%i]=%i\n",i,ap[i],i,*ap[i]);
    }

    return 0;
}
