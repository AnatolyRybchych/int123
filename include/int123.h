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
//returns false if overflow
bool intn_mul(void *restrict result, const void *restrict first, const void *restrict second, size_t n);

//n is byte size
//returns false if overflow
bool intn_add(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first & second
void intn_and(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first & second
void intn_nand(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first & ~second
void intn_andn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first & ~second
void intn_nandn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first | second
void intn_or(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first | second
void intn_nor(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first | ~second
void intn_orn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first | ~second
void intn_norn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first ^ second
void intn_xor(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first ^ second 
void intn_nxor(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first ^ ~second
void intn_xorn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = ~first ^ ~second
void intn_nxorn(void *result, const void *first, const void *second, size_t n);

//n is byte size
//result = first << shift
void intn_shl(void *result, const void *val, size_t shift, size_t n);

//n is byte size
//result = first << (shift * 8)
void intn_shl_bytes(void *result, const void *val, size_t shift, size_t n);

//n is byte size
//result = first >> shift
void intn_shr(void *result, const void *val, size_t shift, size_t n);

//n is byte size
//result = first >> (shift * 8)
void intn_shr_bytes(void *result, const void *val, size_t shift, size_t n);

//n is byte size
void print_hex(const void *num, size_t n);



#endif //INT123_H_