#include <int123.h>

#define IMPL_BIT_OPERATION(NAME, FIRST_OP, OPERATOR, SECOND_OP)\
void intn_##NAME(void *result, const void *first, const void *second, size_t n){\
    size_t long_size = n / sizeof(long);\
    for (size_t i = 0; i < long_size; i++){\
        ((unsigned long*)result)[i] =\
            (FIRST_OP((const unsigned long*)first)[i]) OPERATOR (SECOND_OP((const unsigned long*)second)[i]);\
    }\
    for (size_t i = long_size * sizeof(long); i < n; i++){\
        ((unsigned char*)result)[i] =\
            (FIRST_OP ((const unsigned char *)first)[i]) OPERATOR (SECOND_OP((const unsigned char *)second)[i]);\
    }\
}

static const char *end_of_hexadecimal(const char *str);
static bool is_dec(char ch);
static bool is_hex_lower(char ch);
static bool is_hex_upper(char ch);
static bool is_hexadecimal(char ch);
static unsigned char from_dec(char ch);
static unsigned char from_hexadecimal(char ch);

IMPL_BIT_OPERATION(and, ,&,)
IMPL_BIT_OPERATION(nand, ~,&,)
IMPL_BIT_OPERATION(andn, ,&,~)
IMPL_BIT_OPERATION(nandn, ~,&,~)
IMPL_BIT_OPERATION(or, , |, )
IMPL_BIT_OPERATION(nor, ~, |, )
IMPL_BIT_OPERATION(orn, , |, ~)
IMPL_BIT_OPERATION(norn, ~, |, ~)
IMPL_BIT_OPERATION(xor, , ^, )
IMPL_BIT_OPERATION(nxor, ~, ^, )
IMPL_BIT_OPERATION(xorn, , ^, ~)
IMPL_BIT_OPERATION(nxorn, ~, ^, ~)

bool parse_hex(void *num, size_t n, const char *str){
    assert(n < 0x0fffffffffffffff);

    unsigned char *num_bytes = num;

    memset(num, 0, n);

    size_t curr_semibyte = (n - 1) * 2 + 1;
    const char *num_end = end_of_hexadecimal(str);
    
    while (--num_end >= str){
        unsigned char digit = from_hexadecimal(*num_end);

        num_bytes[curr_semibyte >> 1] |= digit << (curr_semibyte & 1 ? 0: 4);

        if(curr_semibyte == 0) return false;
        else curr_semibyte--;
    }
    return true;
}

bool intn_mul(void *restrict result, const void *restrict first, const void *restrict second, size_t n){
    assert(n < 0x0fffffffffffffff);

    unsigned char *result_bytes = result;
    const unsigned char *first_bytes = first;
    const unsigned char *second_bytes = second;

    memset(result_bytes, 0, n);

    bool ret = true;

    for (size_t i = 0 ; i < n ; i++){
        unsigned int curr = 0;
        for (long int j = n - 1; j >= (long int)i; j--){
            curr += result_bytes[j - i] + first_bytes[j] * second_bytes[n - i - 1];

            result_bytes[j - i] = curr & 0xff;
            curr >>= 8;
        }
        if(curr){
            ret = false;
            continue;
        }
    }
    return ret;
}

bool intn_add(void *restrict result, const void *restrict first, const void *restrict second, size_t n){
    unsigned char *result_bytes = result;
    const unsigned char *first_bytes = first;
    const unsigned char *second_bytes = second;

    memset(result_bytes, 0, n);

    unsigned short int curr = 0;
    for (size_t i = n - 1; i < n ; i--){
        curr = curr + first_bytes[i] + second_bytes[i];
        result_bytes[i] = curr & 0xff;
        curr >>= 8;
    }
    return curr != 0;
}


void print_hex(const void *num, size_t n){
    const unsigned char *num_bytes = num;

    size_t i = 0;

    for (; i < n; i++){
        if(num_bytes[i]){
             break;
        }
    }

    if(i == n){
        putchar('0');
        return;
    }
    
    for (; i < n; i++){
        printf("%02X", (int)num_bytes[i]);
    }
}

static const char *end_of_hexadecimal(const char *str){
    while (*str){
        if(!is_hexadecimal(*str)){
            return str;
        }
        str++;
    }
    return str;
}

static bool is_dec(char ch){
    return ch >= '0' && ch <= '9';
}

static bool is_hex_lower(char ch){
    return ch >= 'a' && ch <= 'f';
}

static bool is_hex_upper(char ch){
    return ch >= 'A' && ch <= 'F';
}

static bool is_hexadecimal(char ch){
    return is_dec(ch) || is_hex_lower(ch) || is_hex_upper(ch);
}

static unsigned char from_dec(char ch){
    return ch - '0';
}

static unsigned char from_hexadecimal(char ch){
    if(is_hex_lower(ch)){
        return ch - 'a' + 10;
    }
    else if(is_hex_upper(ch)){
        return ch - 'A' + 10;
    }
    else return from_dec(ch);
}