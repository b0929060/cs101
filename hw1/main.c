#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    FILE* fp;
    time_t curtime;
    curtime = time(NULL);
    int N;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩： ");
    scanf("%d",&N);
    printf("已為您購買的%d組樂透組合輸出至lotto.txt\n",N);
    
    fp=fopen("lotto.txt","w+");
    int i,n=6,num;
    srand((unsigned) time(NULL));
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp," %s",ctime(&curtime));

    for(int j=1;j<n;j++) {
        fprintf(fp,"[%d]: ",j);
        if (N) {
            for(i=0;i<n;i++) {
                num=(rand()%69)+1;
                if (num>=10) {
                    fprintf(fp,"%d ",num);   
                } else {
                    fprintf(fp,"0%d ",num);
                }
            }
            fprintf(fp,"0%d\n",rand()%10); 
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