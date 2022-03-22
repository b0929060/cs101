#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    typedef struct lotto_record_t {
        int lotto_no;
        int lotto_receipt;
        int emp_id;
        char lotto_date[32];
        char lotto_time[32];
    } lotto_record_t;
    lotto_record_t record_t;
    int money=0,a,b,money_sum,a_sum,b_sum;
    char str_date[16];
    FILE* fp_rec;
    fp_rec=fopen("record.bin","rb");
    fread(money,sizeof(struct lotto_record_t),record_t.lotto_receipt,fp_rec);
    FILE* fp;
    time_t curtime;
    struct tm *info;
    char buffer[80];
    time(&curtime);
    info = localtime(&curtime);
    strftime(buffer,80,"%Y%m%d",info);
    int i=0;
    char line_ch;
    while ((line_ch=fgetc(fp_rec)) != EOF) {
        if (line_ch !='\n') {
            str_date[i]=line_ch;
            i++;
        } else {
            break;
        }
    }
    fclose(fp_rec);
    fp=fopen("report.txt","w+");
    fprintf(fp,"========= lotto649 Report =========\n");
    fprintf(fp,"- Date ------ Num. ------ Receipt -\n");
    fprintf(fp,"%s     %.02d/%.02d           %.04d\n",str_date,a,money/55,money);
    fprintf(fp,"-----------------------------------\n");
    fprintf(fp,"======== %s Printed =========\n",buffer);
    fclose(fp);
    
    return 0;
}