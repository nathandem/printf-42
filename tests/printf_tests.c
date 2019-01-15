#include <stdio.h>

int			main(void)
{
	char		*str;
	int			*int_arr;

	// Conversions without no flag (but min width field and precision)
	printf("--- csp ---\n");
	
	// c CONVERSION - CHARS (promoted to int by stdarg)
	printf(":%c:\n", 'c');
	// min width field: applies
	printf(":%5c:\n", 'c');
	// precision: possible but doesn't make sense
	printf(":%.c:\n", 'c');

	// s CONVERSION - STRING
	// min field width behaves as expected
	// precision however cuts all the letters after the precision nb
	printf(":%s:\n", "hello you");
	// min field width of 10
	printf(":%10s:\n", "hello you");
	// max 10 characters
	printf(":%.10s:\n", "hello you");
	// min width of 10, max 3 characters
	printf(":%10.3s:\n", "hello you");
	// spaces to make the min field width are on the right 
	printf(":%-15s:\n", "Hello, world!");
	// funky tests
	printf("%s\n", "%s"); // %s should be able to print `%s`

	// p CONVERSION - HEXADECIMAL
	// note: `%p` seems only to work on pointers, char pointers even
	printf(":%p:\n", str);
	printf(":%p:\n", int_arr);

	// invalid tests, or rather valid strings but with only the 1st type
	// of the directive considered
	printf("%cs\n", 'c');
	printf("%sc\n", "hello world!");


	/* ------------------------------------------------------------- */

	// Conversions diouxX with flags hh, h, l, ll (and MDF and precision)
	// input: int (except if modified by a flag hh, h, l or ll)
	printf("\n--- diouxX ---\n");

	// d (or i) CONVERSIONS (decimal)
	// regular output without modifier
	printf(":%d:\n", 2);
	printf(":%i:\n", 2);

	// set a minimum field width of 3
	printf(":%3d:\n", 2);
	printf(":%3i:\n", 2);

	// set a minimum field width of 3 but fill with 0 instead of spaces
	printf(":%0d:\n", 2);
	printf(":%03i:\n", 2);

	// h, hh, l, ll flags takes signed inputs with di
	printf("-> h, hh, l, ll flags\n");
	// h takes a short
	printf("flag h :%hd:\n", (short)2);
	// hh takes a (signed) char
	printf("flag hh :%hhd:\n", (char)2);
	// l takes a long
	printf("flag l :%5ld:\n", (long)2);
	// ll takes a long long
	printf("flag ll :%lld:\n", (long long)2);

	// invalid cases, because excessive nb of size flags. Errors in comment
	printf("%lld\n", (long)12); // -Wformat warning, beucause `ll` expects a long long
	printf("%llld\n", (long)14); // printf warns that the conversion `l` doesn't exists
	printf("%hld", (long)15); // invalid conversion specifier
	// -> in short, I believe it's fine to only accepts valid inputs (e.g. not the 3 above)

	// o CONVERSION (unsigned octal)
	printf("17 in octal is :%o:\n", (unsigned int)17);

	// u CONVERSION (unsigned decimal)
	// WHAT IS THE POINT OF u APART FROM HAVING UNSIGNED RES WITH H, HH, L, LL FLAGS?
	printf("17 with the conversion u is: %u\n", 17);

	// x CONVERSION (hexa)
	printf("15 with the conversion x is: %x\n", 15);
	printf("17 with the conversion x is: %x\n", 17);

	// X CONVERSION (hexa, with letters in capital case)
	printf("15 with the conversion X is: %X\n", 15);
	printf("17 with the conversion x is: %x\n", 17);

	// h, hh, l, ll flags takes unsigned inputs with ouxX
	printf("%hu\n", (unsigned short)17);
	printf("%hhu\n", (unsigned char)17);
	printf("%lu\n", (unsigned long)17);
	printf("%llu\n", (unsigned long long)17);


	/* ------------------------------------------------------------- */

	// FLOATS
	printf(":%f:\n", 15.3);

	// min field width applies to the entire float (whole numbers + '.' + decimal nbs)
	// precision only concerns the decimal part of the number
	printf(":%7.3f:\n", 15.3);


	/* ---------------------------------------------------------- */

	// #0- + FLAGS
	printf("\n--- #0- + flags ---\n");

	// `#` flag
	printf("-> # flag\n");
	// no effect on csp and diu and should be banned: unexpected behavior
	// for `o` # increases precision of the conversion to include a 0 before res
	printf("%#o\n", 14);
	// for `xX` conversions, no 0 res have the string `0x` (or `0X`) prepended to it
	printf("%#x\n", 14);
	printf("%#X\n", 14);
	printf("%##X\n", 14); // >1 # == 1 #

	// `0` flag
	printf("-> 0 flag\n");
	// effect: fill with left space with `0` instead of spaces,
	// makes only sense if used in conjunction with a minimum field width
	// like in the examples below
	// banned on letters and pointers: csp because of undefined behavior
	// use only on diouxX
	printf("%03c\n", 'c'); // undefined behavior, what to do about it?
	printf("%03s\n", "hello world!"); // undefined behavior, what to do about it?
	printf("%03p\n", str); // undefined behavor, what to do about it?
	printf("%03d\n", 123);
	printf("%03o\n", 14);
	printf("%003u\n", 14); // note: placing one or more 0 doesn't make a difference
	printf("%03x\n", 14);
	printf("%03X\n", 14);
	// note: if a precision is given to a numeric conversion (diouxX), 0 flag ignored 
	printf("%03.3u is just like %.3d\n", 14, 14);

	// `-` flag
	// effect: place the spaces of the min width field on the right
	// note: `-` and `0` flags are incompatible, `0` is ignored, only `-` applies
	printf("-> - flag\n");
	printf(":%-5d:\n", 14);
	printf(":%--5d:\n", 14); // putting more `-` than one as the same effect as one

	// ` ` (space)
	// effect: leave a blank before a postive nb created by a signed conversion
	// applies to: di and f
	printf("-> ` ` flag\n");
	printf(":% s:\n", "hello world!"); // no effect on strings
	printf(":%  d:\n", 14);
	printf(":% o:\n", 14);
	printf(":% x:\n", 14);

	// `+`
	// effect: place a + sign before a number produced by a sign conversion
	// applies to: di and f
	printf("-> `+` flag\n");
	printf(":%+d:\n", 14);
	printf(":%+o:\n", 14); // undefined behavior, what to do about it?
	// note: if both ` ` and `+` are present, only `+` applies
	printf(":% +d:\n", 14);

	// invalid case: only a flag. Don't handle that, throws an error
	printf("%+\n");


	/* ------------------------------------------------------------- */

	// special case: %%
	printf("\njust a %%\n");

	// also, don't forget the special characters -> handled by write
	printf(":\t:");


	/* ------------------------------------------------------------- */

	// Complex cases
	printf("\n--- complex tests to handle ---\n");
	// special characters are actually handled by write, so it's not complex
	printf("My\tfavorite\nnumbers are \t%d and \t%f.\n", 3, 3.14);
	// some emojis here -> must handle utf-8
	printf("héhé  😎  \n");
	printf("%#05.5x\n", 13);
	printf("%5.5x\n", 13);
	printf("%#+05.3d\n", 13);
	printf("%+#05.3d\n", 13); // note: seems like no ordering required for #0- + flags
	// excessive combinations like the following must work
	printf("%#+ ++ ## 05.3d\n", 13);
	printf("%#+l ++ ## 05.3d\n", 13);

	// error cases, these under all segfault but don't fail at compilation
	// not as many stdarg than % in the format string
	printf("no stdarg provided %6.7"); // -> segfault
	// no conversion flag provided
	printf("no conversion flag provided %6.7 s the top", 14); // -> segfault

	return (0);
}
