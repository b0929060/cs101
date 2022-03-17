#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
    FILE* fp2;
    int N,i,n=6,num,a[6],arr_write[5],arr_read[5],count[]={1};
    int operator_id[6]={0,1,2,3,4,5},operator;
    time_t curtime;
    struct tm *info;
    char buffer[80];
    time(&curtime);
    info = localtime(&curtime);
    strftime(buffer,80,"%c",info);
    if ((fp2 = fopen("count.bin","rb"))!=NULL) {
        fp2 = fopen("count.bin", "rb");
	    fread(count, sizeof(int), 1, fp2);
	    fclose(fp2);
    }
    FILE* fp_op;
    if ((fp_op = fopen("operator.bin","r"))!=NULL) {
        fp_op = fopen("operator.bin", "wb");
	    fclose(fp_op);
    }
    FILE* fp_rec;
    if ((fp_rec = fopen("records.bin","r"))==NULL) {
        fp_rec = fopen("records.bin", "wb");
	    fclose(fp_rec);
    }

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請輸入操作人員ID：(0~5)：");
    scanf("%d",&operator);
    printf("請問您要買幾組樂透彩： ");
    scanf("%d",&N);
    printf("已為您購買的%d組樂透組合輸出至lotto[%05d].txt\n",N,count[0]);

    char s1[32];
    snprintf(s1,sizeof(char)*32,"lotto[%05d].txt",count[0]);
    FILE* fp;
    fp=fopen(s1,"w+");
    srand((unsigned) time(NULL));
    fprintf(fp,"======== lotto649 ========\n");
    fprintf(fp,"=======+ No.%05d +=======\n",count[0]);
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
    fprintf(fp,"=======* Op.%05d *=======\n",operator_id[operator]);
    fprintf(fp,"======== csie@CGU ========");
    fclose(fp);

    char szbuff[32],szbuff2[32];
    strftime(szbuff,100,"%x",info);
    strftime(szbuff2,100,"%X",info);

    typedef struct lotto_record_t {
        int lotto_no;
        int lotto_receipt;
        int emp_id;
        char lotto_date[32];
        char lotto_time[32];
    } lotto_record_t;

    struct lotto_record_t record_t;
    record_t.lotto_no=count;
    record_t.lotto_receipt=N*50*1.1;
    record_t.emp_id=operator;
    strcpy(record_t.lotto_date,szbuff);
    strcpy(record_t.lotto_time,szbuff2);

    count[0]++;
    fp2=fopen("count.bin","wb+");
    fwrite(count,sizeof(count),1,fp2);
    fclose(fp2);
    fp_op = fopen("operator.bin", "wb");
    fwrite(&operator,sizeof(int),1,fp_op);
    fclose(fp_op);
    fp_rec =fopen("recoeds.bin","ab");
    fwrite(&record_t,sizeof(record_t),1,fp_rec);
    fclose(fp_rec);
    return 0;
}