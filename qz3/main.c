#include <stdio.h>

void rec_dec(char* s) {
    if (*s=='0') {
        return 0;
    }
    printf("%c,",*s);
    return rec_dec(s+1);
}
void hanoi_tower(int n, char A, char C, char B) {
    FILE* fp;
    fp=fopen("hanoi.txt","a");
    if (n==0) {
        return;
    }
    hanoi_tower(n-1,A,B,C);
    fprintf(fp,"Move disk %d from %c to %c\n",n,A,C);
    hanoi_tower(n-1,B,C,A);
    fclose(fp);
}

int multiplication(int i,int j) {
    if (i < 10) {
        if (j < 10) {
            printf("%d*%d=%2d ", i, j, i*j);
            multiplication(i, j + 1);
        } else {
            printf("\n");
            i++;
            multiplication(i, 1);
        }
    }
    
}

int main() {
    char s[]="1234567890";
    int n = 16;
    rec_dec(s);
    printf("\n");
    hanoi_tower(n,'A','C','B');
    multiplication(1,1);
    return 0;
}
