#include <stddef.h>
#include <stdio.h>

int main(void)
{
	struct temp{
		char a;
		int b[2];
		float c;
	} tempstruct;

	printf("size of a : %d\n", sizeof(tempstruct.a));
	printf("offset of a : %d\n", offsetof(struct temp, a));
	printf("size of b : %d\n", sizeof(tempstruct.b));
	printf("offset of b : %d\n", offsetof(struct temp, b));
	printf("size of c : %d\n", sizeof(tempstruct.c));
	printf("offset of c : %d\n", offsetof(struct temp, c)); 

	printf("\nsize of tempstruct : %d\n", sizeof(tempstruct));

	/* conclusion : addresses of members of structure is a multiple of 4 bytes.
	 *				a is position 0, size 1.
	 *				b is position 4, size 8.
	 *				c is posttion 12, size 4. so, size of this structure is 16 bytes.
	 */				
	return 0;
}