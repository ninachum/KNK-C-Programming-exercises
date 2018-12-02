#include <stdio.h>

int main(void)
{
	union float_type {
		float read_as_float;
		struct {
			unsigned int fraction : 23;
			unsigned int exponent : 8;
			unsigned int sign : 1;
		} float_bits;
	} example1;

	example1.float_bits.sign = 1;
	example1.float_bits.fraction = 0;
	example1.float_bits.exponent = 128;
	/*
	in visual studio 2017, bit - field packing result is..
	(bits)				11000000 00000000 00000000 00000000
	(owner of the bit)  seeeeeee efffffff ffffffff ffffffff
	it is stored as.. (little - endian)
	(bits)			    00000000 00000000 00000000 11000000
	(owner of the bit)  ffffffff ffffffff efffffff seeeeeee
	*/

	printf("%f\n", example1.read_as_float);
	/*
	the float value is read as (same as packing result.):
	(bits)				11000000 00000000 00000000 00000000
	(owner of the bit)  seeeeeee efffffff ffffffff ffffffff
	*/


	return 0;
}