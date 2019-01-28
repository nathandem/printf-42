#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

char			*signed_char_decimal_to_str(char n);
char			*signed_short_decimal_to_str(short n);
char			*signed_int_decimal_to_str(int n);
char			*signed_long_decimal_to_str(long n);
char			*signed_long_long_decimal_to_str(long long n);

char			*signed_dec_to_str(long long n, char size);
char			*unsigned_to_str(t_ull n, char base, char size, char cap);

char			*octal_to_str(long long n);
char			*unsigned_octal_to_str(long long n, int size);
char			*decimal_to_str(long long n);
char			*unsigned_decimal_to_str(long long n, int size);
char			*hex_to_str(long long n, char maj);


int				main(void)
{
	// SIGNED SIZE+CONVERSION HANDLERS
	// only decimals are concerned with signed handlers (not octal or hexa)
	
	// IMPORTANT NOTE: for types different than int (default type C chooses when
	// dealing with numbers), don't forget to cast into the type the handler and
	// printf expects - see char_decimal_to_str tests for examples.

	printf("%s %hhd\n", signed_dec_to_str((char)-129, 1), (char)-129);  // overflow to the top
	printf("%s %hhd\n", signed_dec_to_str((char)-128, 1), (char)-128);
	printf("%s %hhd\n", signed_dec_to_str((char)-42, 1), (char)-42);
	printf("%s %hhd\n", signed_dec_to_str((char)-1, 1), (char)-1);
	printf("%s %hhd\n", signed_dec_to_str((char)0, 1), (char)0);
	printf("%s %hhd\n", signed_dec_to_str((char)1, 1), (char)1);
	printf("%s %hhd\n", signed_dec_to_str((char)42, 1), (char)42);
	printf("%s %hhd\n", signed_dec_to_str((char)127, 1), (char)127);
	printf("%s %hhd\n", signed_dec_to_str((char)128, 1), (char)128);  // overflow to the bottom
	printf("%s %hhd\n", signed_dec_to_str((char)129, 1), (char)129);
	printf("\n");
	
	printf("%s\n", "%hd or %hi, signed short decimal");
	printf("The data passed to my handler here has %lu bytes\n", sizeof(short));
	printf("%s %hd\n", signed_dec_to_str((short)-32769, 2), (short)-32769);  // overflow to the top
	printf("%s %hd\n", signed_dec_to_str((short)-32768, 2), (short)-32768);
	printf("%s %hd\n", signed_dec_to_str((short)-42, 2), (short)-42);
	printf("%s %hd\n", signed_dec_to_str((short)-1, 2), (short)-1);
	printf("%s %hd\n", signed_dec_to_str((short)0, 2), (short)0);
	printf("%s %hd\n", signed_dec_to_str((short)1, 2), (short)1);
	printf("%s %hd\n", signed_dec_to_str((short)32767, 2), (short)32767);
	printf("%s %hd\n", signed_dec_to_str((short)32768, 2), (short)32768);  // overflow to the botton
	printf("\n");	

	printf("%s\n", "%d or %i, signed int decimal");
	printf("The data passed to my handler here has %lu bytes\n", sizeof(42)); // this avoid error!
	printf("%s %d\n", signed_dec_to_str((int)-2147483648, 0), (int)-2147483648);
	printf("%s %d\n", signed_dec_to_str(-42, 0), -42);
	printf("%s %d\n", signed_dec_to_str(-1, 0), -1);
	printf("%s %d\n", signed_dec_to_str(0, 0), 0);
	printf("%s %d\n", signed_dec_to_str(10, 0), 10);
	printf("%s %d\n", signed_dec_to_str(2147483647, 0), 2147483647);
	printf("%s %d\n", signed_dec_to_str((int)2147483648, 0), (int)2147483648);  // reverts to min value: -2^31
	printf("\n");

	printf("%s\n", "%ld or %li, signed long dec");
	printf("The data passed here has %lu bytes\n", sizeof(long));  // 8 bytes in macOS 64bytes
	printf("%s %ld\n", signed_dec_to_str((long)-9223372036854775809, 3), (long)-9223372036854775809);  // overflows
	printf("%s %ld\n", signed_dec_to_str((long)-9223372036854775808, 3), (long)-9223372036854775808);  // clang complains -(2^63) is not an integer, though it is. Strange...
	printf("%s %ld\n", signed_dec_to_str((long)-9223372036854775807, 3), (long)-9223372036854775807);
	printf("%s %ld\n", signed_dec_to_str((long)-42, 3), (long)-42);
	printf("%s %ld\n", signed_dec_to_str((long)0, 3), (long)0);
	printf("%s %ld\n", signed_dec_to_str((long)42, 3), (long)42);
	printf("%s %ld\n", signed_dec_to_str((long)9223372036854775807, 3), (long)9223372036854775807);
	printf("%s %ld\n", signed_dec_to_str((long)9223372036854775808, 3), (long)9223372036854775808);  // overflows
	printf("\n");

	printf("%s\n", "%lld or %lli, signed long long dec");
	printf("Data passed to handlers below are %lu bytes long\n", sizeof(long long));
	printf("%s %lld\n", signed_dec_to_str((long long)-9223372036854775809, 4), (long long)-9223372036854775809);  // overflow to highest value
	printf("%s %lld\n", signed_dec_to_str((long long)-9223372036854775808, 4), (long long)-9223372036854775808);
	printf("%s %lld\n", signed_dec_to_str((long long)-42, 4), (long long)-42);
	printf("%s %lld\n", signed_dec_to_str((long long)0, 4), (long long)0);
	printf("%s %lld\n", signed_dec_to_str((long long)42, 4), (long long)42);
	printf("%s %lld\n", signed_dec_to_str((long long)9223372036854775807, 4), (long long)9223372036854775807);
	printf("%s %lld\n", signed_dec_to_str((long long)9223372036854775808, 4), (long long)9223372036854775808);  // overflow to lowest value
	printf("%s %lld\n", signed_dec_to_str((long long)9223372036854775809, 4), (long long)9223372036854775809);
	printf("\n");

	
	// UNSIGNED HANDLERS

	// IMPORTANT NOTES ON TYPES:
	// need to place `u` or `U` at the end of an integer to have it considered as an unsigned integer!
	// Casting just transform the current value in a unsigned value. But if this 
	// value isn't declared as an unsigned value in the first place with a U at the end of it,
	// is a signed value!
	// https://stackoverflow.com/questions/47206369/why-does-gcc-give-a-warning-when-setting-an-unsigned-long-to-264-1
	// Be aware of the implicit casts C is doing
	// Table of the limits by types
	// http://www.cplusplus.com/reference/climits/
	// ===> when building the code calling these handlers, don't forget to add a cast in case the users
	// don't pass a correct type
	
	// printf("sizeof(9223372036854775807): %lu\n", sizeof(9223372036854775807));  // this is LONG_MAX
	// printf("sizeof(9223372036854775808): %lu\n", sizeof(9223372036854775808U)); // U is needed for the compiler to understand that this value is an unsigned long int
	// printf("sizeof(unsigned long): %lu bytes\n", sizeof(unsigned long));

	/*
	printf("%s %u\n", unsigned_to_str(42U, 10, 0, 0), 42U);
	printf("%s %o\n", unsigned_to_str(42U, 8, 0, 0), 42U);
	printf("%s %x\n", unsigned_to_str(42U, 16, 0, 0), 42U);
	printf("%s %X\n", unsigned_to_str(42U, 16, 0, 1), 42U);

	printf("%s %u\n", unsigned_to_str(-1, 10, 0, 0), -1);
	printf("%s %u\n", unsigned_to_str(0U, 10, 0, 0), 0U);
	printf("%s %u\n", unsigned_to_str(4294967295U, 10, 0, 0), 4294967295U);
	printf("%s %ho\n", unsigned_to_str((unsigned short)65535U, 8, 0, 0), (unsigned short)65535U);
	printf("%s %llx\n", unsigned_to_str(18446744073709551615llU, 16, 4, 0), 18446744073709551615llU);
	printf("%s %lo\n", unsigned_to_str(18446744073709551615lU, 8, 3, 0), 18446744073709551615lU);  // this is ULONG_MAX, a number can't be any bigger in C
	*/

	// pointers handler (unsigned_to_str at float size) -> seems to work
	/*
	char				*char_ptr;
	char_ptr = (char*)'a';
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)'b';
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)'0';
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)48;
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)0;
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)-1;
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	char_ptr = (char*)malloc(3);  // no protection for the test
	char_ptr[0] = 'h';
	char_ptr[1] = 'i';
	char_ptr[2] = 0;
	printf("%s\n", char_ptr);
	printf("%s %lx %p\n", unsigned_to_str((t_ull)char_ptr, 16, 3, 0), (unsigned long)char_ptr, char_ptr);
	*/

	// let's try the big piece: floats!

	return (0);
}
