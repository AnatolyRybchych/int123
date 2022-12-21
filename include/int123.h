#ifndef INT123_H_
#define INT123_H_

#include <stdbool.h>
#include <memory.h>
#include <assert.h>
#include <stdio.h>

//n is byte size, n should be < 0x0fffffffffffffff)
//returns false if overflow
bool parse_hex(void *num, size_t n, const char *str);

//n is byte size, n should be < 0x0fffffffffffffff)
bool intn_mul(void *restrict result, const void *restrict first, const void *restrict second, size_t n);

//n is byte size
bool intn_add(void *restrict result, const void *restrict first, const void *restrict second, size_t n);

//n is byte size
void print_hex(const void *num, size_t n);


#endif //INT123_H_