#include <stdio.h>

int _sum(int x,int y) {
    return x+y;
}
int _sub(int x,int y) {
    return x-y;
}
int _mult(int x,int y) {
    return x*y;
}
int _div(int x,int y) {
    return x/y;
}
// int _power(int x,int y) {
//     int ans=x;
//     for(int i=1;i<y;i++) {
//         ans*=x;
//     }
//     return ans;
// }
int _power(int x,int y) {
    if(y==1) return x;
    else return x*_power(x,y-1);
}

int main() {
    int x,y,choice;
    int(*ope[5])(int,int);
    ope[0]=_sum;
    ope[1]=_sub;
    ope[2]=_mult;
    ope[3]=_div;
    ope[4]=_power;
    
    printf("Enter two integer: ");
    scanf("%d%d",&x,&y);
    
    printf("Enter 0:+, 1:-, 2:*,3:/, 4:^ ");
    scanf("%d",&choice);
    
    printf("%d",ope[choice](x,y));
    return 0;
}
