#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    FILE* fp;
    time_t curtime;
    struct tm *info;
    char buffer[80];
    time(&curtime);
    info = localtime(&curtime);
    strftime(buffer,80,"%c",info);
    int N,i,n=6,num,a[6];;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩： ");
    scanf("%d",&N);
    printf("已為您購買的%d組樂透組合輸出至lotto.txt\n",N);
    fp=fopen("lotto.txt","w+");
    srand((unsigned) time(NULL));
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp,"=%s=\n",buffer);
    for(int j=1;j<n;j++) {
        fprintf(fp,"[%d]: ",j);
        if (N>0) {
            for (i=0;i<6;i++) {
                a[i]=rand()%69+1;
            }
            for (int r=0;r<n; ++r) {
                for (int s=0;s<r; ++s) {
                    if (a[s] > a[r]) {
                        int temp = a[s];
                        a[s] = a[r];
                        a[r] = temp;
                    }
                }
                for(int s=0;s<r;s++){
                    if(a[s]==a[r]){
                        r--;
                    }
                }
            }
            for(i=0;i<n;i++) {
                if (a[i]>=10) {
                    fprintf(fp,"%d ",a[i]);   
                } else {
                    fprintf(fp,"0%d ",a[i]);
                }
            }
            fprintf(fp,"0%d\n",rand()%9+1); 
            N--;
        } else {
            for(i=0;i<n+1;i++) {
                fprintf(fp,"-- ");   
            }
            fprintf(fp,"\n");
        }
    }
    fprintf(fp,"======== csie@CGU ========");
    fclose(fp);
    return 0;
}