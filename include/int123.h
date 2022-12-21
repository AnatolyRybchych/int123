#ifndef INT123_H_
#define INT123_H_

#include <stdbool.h>
#include <memory.h>
#include <assert.h>
#include <stdio.h>

//n is byte size, n should be < 0x0fffffffffffffff)
//returns false if overflow
bool intn_parse_hex(size_t n, void *num, const char *str);

//n is byte size
void intn_print_hex(size_t n, const void *num);

//n is byte size, n should be < 0x0fffffffffffffff)
//returns false if overflow
bool intn_mul(size_t n, void *restrict result, const void *restrict first, const void *restrict second);

//n is byte size
//returns false if overflow
bool intn_add(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first & second
void intn_and(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first & second
void intn_nand(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first & ~second
void intn_andn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first & ~second
void intn_nandn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first | second
void intn_or(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first | second
void intn_nor(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first | ~second
void intn_orn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first | ~second
void intn_norn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first ^ second
void intn_xor(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first ^ second 
void intn_nxor(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first ^ ~second
void intn_xorn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = ~first ^ ~second
void intn_nxorn(size_t n, void *result, const void *first, const void *second);

//n is byte size
//result = first << shift
void intn_shl(size_t n, void *result, const void *val, size_t shift);

//n is byte size
//result = first << (shift * 8)
void intn_shl_bytes(size_t n, void *result, const void *val, size_t shift);

//n is byte size
//result = first >> shift
void intn_shr(size_t n, void *result, const void *val, size_t shift);

//n is byte size
//result = first >> (shift * 8)
void intn_shr_bytes(size_t n, void *result, const void *val, size_t shift);

#endif //INT123_H_