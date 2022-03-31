#include <stdio.h>
int my_strlen(char* s) {
    int i=0,count=0;
    while (s[i++]!='\0') {count++;}
    return count;
}

int rec_strlen(char* s) {
    if (s[0]=='\0') {return 0;}
    else return rec_strlen(s+1)+1;
}

char* my_sort(char* s) {
    for (int i = 0; i < sizeof(s); i++) {
        for (int j = 0; j < sizeof(s); j++) {
            if (s[j] > s[i]) {
                int temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
    return s;
}

int main() {
    char s[]="IU is a girl!";
    printf("len = %d\n",my_strlen(s));
    printf("len = %d\n",rec_strlen(s));
    printf("sort = %s\n",my_sort(s));
    return 0;
}
