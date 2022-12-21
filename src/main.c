#include <stdio.h>

#include <int123.h>

int main(void){
    unsigned char num[1024];

    char buffer[10000];
    scanf("%10000s", buffer);

    parse_hex(num, 1024, buffer);
    print_hex(num, 1024);
    

    return 0;
}
