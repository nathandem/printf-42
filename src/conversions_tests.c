#include <stdio.h>

char			*octal_to_str(long long n);
char			*unsigned_octal_to_str(long long n, int size);
char			*decimal_to_str(long long n);
char			*unsigned_decimal_to_str(long long n, int size);
char			*hex_to_str(long long n, char maj);


int				main(void)
{
	// signed int
	/*
	// don't know why but to clang -2147483648 is not an int...
	printf("%s\n", "%d and %i, signed decimal");
	printf("%s %d\n", decimal_to_str(-2147483647), -2147483647);
	printf("%s %d\n", decimal_to_str(-42), -42);
	printf("%s %d\n", decimal_to_str(-1), -1);
	printf("%s %d\n", decimal_to_str(0), 0);
	printf("%s %d\n", decimal_to_str(10), 10);
	printf("%s %d\n", decimal_to_str(2147483647), 2147483647);
	printf("%s %d\n", decimal_to_str(2147483648), 2147483648);  // reverts to min value: -2^31
	printf("\n");
	*/

	// unsigned int
	/*
	printf("%s\n", "%u, unsigned decimal");
	// reverts to max value: 2^32
	printf("%s %u\n", decimal_to_str(-1), -1);
	printf("%s %u\n", decimal_to_str(0), 0);
	printf("%s %u\n", decimal_to_str(42), 42);
	// max value: (2^32)-1
	printf("%s %u\n", decimal_to_str(4294967295), 4294967295);
	// reverts to min value: 0
	printf("%s %u\n", decimal_to_str(4294967296), 4294967296); 
	printf("\n");
	*/


	// IF WE PROVIDE SIGNED VALUES TO UNSIGNED FLAGS,
	// PRINTF CASTS THEM INTO UNSIGNED VALUES
	// like below

	// unsigned decimal
	printf("%s %u\n", unsigned_decimal_to_str((unsigned long long)-1, 3), (unsigned int)-1);
	printf("%s %u\n", unsigned_decimal_to_str((unsigned long long)0, 3), (unsigned int)0);
	printf("%s %u\n", unsigned_decimal_to_str((unsigned long long)42, 3), (unsigned int)42);
	printf("%s %u\n", unsigned_decimal_to_str((unsigned long long)4294967295, 3), (unsigned int)4294967295);
	printf("%s %u\n", unsigned_decimal_to_str((unsigned long long)4294967296, 3), (unsigned int)4294967296);


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
