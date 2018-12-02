#include <stdio.h>

int main(void)
{
	int score;

	printf("Enter numerical grade: ");
	scanf("%d", &score);

	if(score > 100 || score < 0)
		printf("ERROR");

	score /= 10;

	switch(score){
	case 0: case 1: case 2: case 3: case 4: case 5:
		printf("F\n");
		break;
	case 6:
		printf("D\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 9: case 10:
		printf("A\n");
		break;
	}

	return 0;
}