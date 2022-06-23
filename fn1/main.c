#include <stdio.h>
int setMyBit(int x, int y) {
    x=x |(1<<y);
    return x;
}
int clearMyBit(int x, int y) {
    x=x &((1<<y)-1);
    return x;
}
int inverseMyBit(int x, int y) {
    x=x ^(1<<y);
    return x;
}
int main() {
    int a = 1;
    int b = 3;
    int t = a;
    printf("setMyBit(%d, %d) = %d\n", t, b, setMyBit(a,b));
    t = a;
    printf("clearMyBit(%d, %d) = %d\n", t, b, clearMyBit(a,b));
    t = a;
    printf("inverseMyBit(%d, %d) = %d\n", t, b, inverseMyBit(a,b));
    return 0;
}
