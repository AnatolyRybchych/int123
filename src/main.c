#include <stdio.h>

#include <int123.h>

int main(void){
    unsigned char first[1024];
    unsigned char second[1024];
    unsigned char result[1024];

    char buffer[10000];

    printf("first:");
    scanf("%10000s", buffer);
    intn_parse_hex(1024, first, buffer);

    printf("second:");
    scanf("%10000s", buffer);
    intn_parse_hex(1024, second, buffer);

    intn_and(1024, result, first, second);

    intn_shl(1024, result, result, 1);

    printf("result:");
    intn_print_hex(1024, result);
    printf("\n");

    return 0;
}

