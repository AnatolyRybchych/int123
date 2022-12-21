#include <stdio.h>

#include <int123.h>

int main(void){
    unsigned char first[1024];
    unsigned char second[1024];
    unsigned char result[1024];

    char buffer[10000];

    printf("first:");
    scanf("%10000s", buffer);
    parse_hex(first, 1024, buffer);

    printf("second:");
    scanf("%10000s", buffer);
    parse_hex(second, 1024, buffer);

    intn_nor(result, first, second, 1024);

    intn_shr(result, result, 1, 1024);

    printf("result:");
    print_hex(result, 1024);
    printf("\n");

    return 0;
}
