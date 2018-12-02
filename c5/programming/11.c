#include <stdio.h>

int main(void)
{
	int num, div_1, div_2;

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	div_1 = num / 10;
	div_2 = num % 10;

	switch(div_1){
	case 0:
		break;
	case 1:
		switch(num){
		case 11:
			printf("eleven");
			break;
		case 12:
			printf("twelve");
			break;
		case 13:
			printf("thirteen");
			break;
		case 14:
			printf("fourteen");
			break;
		case 15:
			printf("fifteen");
			break;
		case 16:
			printf("sixteen");
			break;
		case 17:
			printf("seventeen");
			break;
		case 18:
			printf("eighteen");
			break;
		case 19:
			printf("nineteen");
			break;
		}
		break;
	case 2:
		printf("twenty-");
		break;
	case 3:
		printf("thirty-");
		break;
	case 4:
		printf("forty-");
		break;
	case 5:
		printf("fifty-");
		break;
	case 6:
		printf("sixty-");
		break;
	case 7:
		printf("seventy-");
		break;
	case 8:
		printf("eighty-");
		break;
	case 9:
		printf("ninty-");
		break;
	}

	if(div_1 != 1)
	{
		switch(div_2){
		case 0:
			printf("zero\n");
			break;
		case 1:
			printf("one\n");
			break;
		case 2:
			printf("two\n");
			break;
		case 3:
			printf("three\n");
			break;
		case 4:
			printf("four\n");
			break;
		case 5:
			printf("five\n");
			break;
		case 6:
			printf("six\n");
			break;
		case 7:
			printf("seven\n");
			break;
		case 8:
			printf("eight\n");
			break;
		case 9:
			printf("nine\n");
			break;
		}
	}

	return 0;
	}
