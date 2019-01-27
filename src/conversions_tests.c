#include <stdio.h>

char			*signed_char_decimal_to_str(char n);
char			*signed_short_decimal_to_str(short n);
char			*signed_int_decimal_to_str(int n);
char			*signed_long_decimal_to_str(long n);
char			*signed_long_long_decimal_to_str(long long n);

char			*unsigned_int_decimal_to_str(unsigned int n);


char			*unsigned_decimals_to_str(unsigned long long n, char size);

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

	// signed char with char_decimal_to_str -> working :)
	/*
	printf("%s\n", "%hhd or %hhi, signed char decimal");
	printf("The data passed to my handler here has %lu bytes\n", sizeof(char));
	printf("%s %hhd\n", signed_char_decimal_to_str((char)-129), (char)-129);  // overflow to the top
	printf("%s %hhd\n", signed_char_decimal_to_str((char)-128), (char)-128);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)-42), (char)-42);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)-1), (char)-1);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)0), (char)0);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)1), (char)1);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)42), (char)42);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)127), (char)127);
	printf("%s %hhd\n", signed_char_decimal_to_str((char)128), (char)128);  // overflow to the bottom
	printf("%s %hhd\n", signed_char_decimal_to_str((char)129), (char)129);
	printf("\n");
	*/
	
	// signed short with short_decimal_to_str -> working :) 
	/*
	printf("%s\n", "%hd or %hi, signed short decimal");
	printf("The data passed to my handler here has %lu bytes\n", sizeof(short));
	printf("%s %hd\n", signed_short_decimal_to_str((short)-32769), (short)-32769);  // overflow to the top
	printf("%s %hd\n", signed_short_decimal_to_str((short)-32768), (short)-32768);
	printf("%s %hd\n", signed_short_decimal_to_str((short)-42), (short)-42);
	printf("%s %hd\n", signed_short_decimal_to_str((short)-1), (short)-1);
	printf("%s %hd\n", signed_short_decimal_to_str((short)0), (short)0);
	printf("%s %hd\n", signed_short_decimal_to_str((short)1), (short)1);
	printf("%s %hd\n", signed_short_decimal_to_str((short)32767), (short)32767);
	printf("%s %hd\n", signed_short_decimal_to_str((short)32768), (short)32768);  // overflow to the botton
	printf("\n");	
	*/

	// signed int with int_decimal_to_str -> working :)
	/*
	printf("%s\n", "%d or %i, signed int decimal");
	printf("The data passed to my handler here has %lu bytes\n", sizeof(42)); // this avoid error!
	printf("%s %d\n", signed_int_decimal_to_str(-2147483648), -2147483648);
	printf("%s %d\n", signed_int_decimal_to_str(-42), -42);
	printf("%s %d\n", signed_int_decimal_to_str(-1), -1);
	printf("%s %d\n", signed_int_decimal_to_str(0), 0);
	printf("%s %d\n", signed_int_decimal_to_str(10), 10);
	printf("%s %d\n", signed_int_decimal_to_str(2147483647), 2147483647);
	printf("%s %d\n", signed_int_decimal_to_str(2147483648), 2147483648);  // reverts to min value: -2^31
	printf("\n");
	*/

	// signed long with long_decimal_to_str -> working :)
	/*
	printf("%s\n", "%ld or %li, signed long decimal");
	printf("The data passed here has %lu bytes\n", sizeof(long));  // 8 bytes in macOS 64bytes
	printf("%s %ld\n", signed_long_decimal_to_str((long)-9223372036854775809), (long)-9223372036854775809);  // overflows
	printf("%s %ld\n", signed_long_decimal_to_str((long)-9223372036854775808), (long)-9223372036854775808);  // clang complains -(2^63) is not an integer, though it is. Strange...
	printf("%s %ld\n", signed_long_decimal_to_str((long)-9223372036854775807), (long)-9223372036854775807);
	printf("%s %ld\n", signed_long_decimal_to_str((long)-42), (long)-42);
	printf("%s %ld\n", signed_long_decimal_to_str((long)0), (long)0);
	printf("%s %ld\n", signed_long_decimal_to_str((long)42), (long)42);
	printf("%s %ld\n", signed_long_decimal_to_str((long)9223372036854775807), (long)9223372036854775807);
	printf("%s %ld\n", signed_long_decimal_to_str((long)9223372036854775808), (long)9223372036854775808);  // overflows
	printf("\n");
	*/

	// signed long long with long_long_decimal_to_str -> working :)
	/*
	printf("%s\n", "%lld or %lli, signed long long decimal");
	printf("Data passed to handlers below are %lu bytes long\n", sizeof(long long));
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)-9223372036854775809), (long long)-9223372036854775809);  // overflow to highest value
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)-9223372036854775808), (long long)-9223372036854775808);
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)-42), (long long)-42);
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)0), (long long)0);
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)42), (long long)42);
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)9223372036854775807), (long long)9223372036854775807);
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)9223372036854775808), (long long)9223372036854775808);  // overflow to lowest value
	printf("%s %lld\n", signed_long_long_decimal_to_str((long long)9223372036854775809), (long long)9223372036854775809);
	printf("\n");
	*/

	
	// UNSIGNED HANDLERS

	// unsigned int decimal with unsigned_int_decimal_to_str -> working :)
	/*
	printf("%s\n", "%u, unsigned int decimal");
	printf("Data passed to handlers below are %lu bytes long\n", sizeof(unsigned int));
	// unsigned cast doesn't apply here, don't know why
	// printf("-5 casted as an unsigned int: %d\n", (unsigned int)-5);
	printf("%s %u\n", unsigned_int_decimal_to_str((unsigned int)-1), (unsigned int)-1);  // overflows to highest value
	printf("%s %u\n", unsigned_int_decimal_to_str((unsigned int)0), (unsigned int)0);
	printf("%s %u\n", unsigned_int_decimal_to_str((unsigned int)42), (unsigned int)42);
	printf("%s %u\n", unsigned_int_decimal_to_str((unsigned int)4294967295), (unsigned int)4294967295);
	printf("%s %u\n", unsigned_int_decimal_to_str((unsigned int)4294967296), (unsigned int)4294967296);  // overflows to smallest value
	print("\n");
	*/

	/*
	printf("%s %hhu\n", unsigned_decimals_to_str((unsigned char)-1, 1), (unsigned char)-1);  // overflows top
	printf("%s %hhu\n", unsigned_decimals_to_str((unsigned char)0, 1), (unsigned char)0);
	printf("%s %hhu\n", unsigned_decimals_to_str((unsigned char)42, 1), (unsigned char)42);
	printf("%s %hhu\n", unsigned_decimals_to_str((unsigned char)255, 1), (unsigned char)255);
	printf("%s %hhu\n", unsigned_decimals_to_str((unsigned char)256, 1), (unsigned char)256);  // overflows bottom
	printf("\n");

	printf("%s %hu\n", unsigned_decimals_to_str((unsigned short)-1, 2), (unsigned short)-1); // overflows top
	printf("%s %hu\n", unsigned_decimals_to_str((unsigned short)0, 2), (unsigned short)0);
	printf("%s %hu\n", unsigned_decimals_to_str((unsigned short)42, 2), (unsigned short)42);
	printf("%s %hu\n", unsigned_decimals_to_str((unsigned short)65535, 2), (unsigned short)65535);
	printf("%s %hu\n", unsigned_decimals_to_str((unsigned short)65536, 2), (unsigned short)65536);  // overflows bottom
	printf("\n");

	printf("%s %u\n", unsigned_decimals_to_str((unsigned int)-1, 0), (unsigned int)-1);
	printf("%s %u\n", unsigned_decimals_to_str((unsigned int)0, 0), (unsigned int)0);
	printf("%s %u\n", unsigned_decimals_to_str((unsigned int)42, 0), (unsigned int)42);
	printf("%s %u\n", unsigned_decimals_to_str((unsigned int)4294967295, 0), (unsigned int)4294967295);
	printf("%s %u\n", unsigned_decimals_to_str((unsigned int)4294967296, 0), (unsigned int)4294967296);
	printf("\n");
	
	printf("sizeof(unsigned long): %lu bytes\n", sizeof(unsigned long));
	printf("%s %lu\n", unsigned_decimals_to_str((unsigned long)-1, 3), (unsigned long)-1);
	printf("%s %lu\n", unsigned_decimals_to_str((unsigned long)0, 3), (unsigned long)0);
	printf("%s %lu\n", unsigned_decimals_to_str((unsigned long)42, 3), (unsigned long)42);
	printf("%s %lu\n", unsigned_decimals_to_str((unsigned long)18446744073709551615, 3), (unsigned long)18446744073709551615);
	printf("\n");
	*/

	// IMPORTANT NOTES ON TYPES:
	// need to place `u` or `U` at the end of an integer to have it considered as an unsigned integer!
	// Casting just transform the current value in a unsigned value. But if this 
	// value isn't declared as an unsigned value in the first place with a U at the end of it,
	// is a signed value!
	// https://stackoverflow.com/questions/47206369/why-does-gcc-give-a-warning-when-setting-an-unsigned-long-to-264-1
	// Table of the limits by types
	// http://www.cplusplus.com/reference/climits/

	char				*unsigned_long_decimal_to_str(unsigned long n);
	// note: if nb > INT_MAX, the nb is put in a long instead of an int
	// printf("sizeof(9223372036854775807): %lu\n", sizeof(9223372036854775807));  // this is LONG_MAX
	// printf("sizeof(9223372036854775808): %lu\n", sizeof(9223372036854775808U)); // U is needed for the compiler to understand that this value is an unsigned long int
	printf("%s %lu\n", unsigned_long_decimal_to_str(-1lu), -1lu);
	printf("%s %lu\n", unsigned_long_decimal_to_str(0), 0lu);
	printf("%s %lu\n", unsigned_long_decimal_to_str(42), 42lu);
	printf("%s %lu\n", unsigned_long_decimal_to_str(1844674407370955161lU), 1844674407370955161lU);
	// no problem printing out 19figures numbers but 20 doesn't work... WHY?!
	printf("%s %lu\n", unsigned_long_decimal_to_str(18446744073709551615lU), 18446744073709551615lU);
	printf("%s %lu\n", unsigned_long_decimal_to_str(10000000000000000000lU), 10000000000000000000lU);

	// unsigned octal handling
	/*
	printf("%s %o\n", unsigned_octal_to_str((unsigned long long)-2147483647, 3), -2147483647);
	printf("%s %o\n", unsigned_octal_to_str((unsigned long long)-42, 3), -42);
	printf("%s %o\n", unsigned_octal_to_str((unsigned long long)-1, 3), -1);
	printf("%s %o\n", unsigned_octal_to_str((unsigned long long)0, 3), 0);
	printf("%s %o\n", unsigned_octal_to_str((unsigned long long)42, 3), 42);
	printf("%s %d\n", unsigned_octal_to_str((unsigned long long)2147483647, 3), 2147483647);
	printf("\n");
	*/

	// test different sizes with unsigned octal
	/*
	printf("%s %ho\n", unsigned_octal_to_str((unsigned short)-255, 1), (unsigned short)-255);
	printf("%s %ho\n", unsigned_octal_to_str((unsigned short)-42, 1), (unsigned short)-42);
	printf("%s %ho\n", unsigned_octal_to_str((unsigned short)-1, 1), (unsigned short)-1);
	printf("%s %ho\n", unsigned_octal_to_str(0, 1), (unsigned short)0);
	printf("%s %ho\n", unsigned_octal_to_str(42, 1), (unsigned short)42);
	printf("%s %ho\n", unsigned_octal_to_str(255, 1), (unsigned short)255);
	printf("\n");
	*/

	// hexadecimal handling
	/*
	printf("%s %x\n", hex_to_str(-2147483647, 1), -2147483647);
	printf("%s %x\n", hex_to_str(-214748364, 1), -214748364);
	printf("%s %x\n", hex_to_str(0, 0), 1);
	printf("%s %x\n", hex_to_str(0, 1), 1);
	printf("%s %x\n", hex_to_str(42, 0), 42);
	printf("%s %X\n", hex_to_str(42, 1), 42);
	printf("%s %X\n", hex_to_str(1000000, 1), 1000000);
	*/

	return (0);
}
