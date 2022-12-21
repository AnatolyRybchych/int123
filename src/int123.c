#include <int123.h>

static const char *end_of_hexadecimal(const char *str);
static bool is_dec(char ch);
static bool is_hex_lower(char ch);
static bool is_hex_upper(char ch);
static bool is_hexadecimal(char ch);
static unsigned char from_dec(char ch);
static unsigned char from_hexadecimal(char ch);

bool parse_hex(void *num, size_t n, const char *str){
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