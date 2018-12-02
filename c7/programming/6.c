#include <stdio.h>

int main(void)
{

	/* int(4 bytes) = long(4 bytes), and double(8 bytes) = long double(8 bytes)
	 * in this system.
	 */

	printf("size of type int is %lu\n", sizeof(int)); // 4*
	printf("size of type short is %lu\n", sizeof(short)); // 2
	printf("size of type long is %lu\n", sizeof(long)); // 4*
	printf("size of type float is %lu\n", sizeof(float));  // 4
	printf("size of type double is %lu\n", sizeof(double));   // 8*
	printf("size of type long double is %lu\n", sizeof(long double));  // 8*


	return 0;
}

