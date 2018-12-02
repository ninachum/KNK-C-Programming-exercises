/*
1. 문자를 입력받아 char 배열에 저장한다.
   이때, ?, !, .를 만나면 저장을 중단한다.
   마지막 기호와 그 위치를 저장한다.
 
 2. 마지막 기호 직전 위치에서부터 스캔을 시작한다.
    끝 포인터를 마지막 기호 직전으로 초기화한다.
	이 포인터가 가리키는 지점이 ' '가 될 때까지 포인터를 좌측으로 한 칸씩 움직인다.
	포인터가 ' '을 가리키면, 이 지점의 직전 지점을 시작 포인터로 정한다.
	시작 포인터부터 끝 포인터까지의 글자를 출력한다.
	출력한 단어가 마지막 단어가 아니라면, ' '를 추가로 인쇄한다.
	마지막 단어였다면, ' '를 출력하지 않고 반복문을 탈출한다. 

 3. 끝에 마지막 기호를 출력한다.
 */


/* a program that reverses the words in a sentence:
 * ex) you can do it.  =====>  it do can you.
 */

#include <stdio.h>

int main(void)
{
	unsigned char now_char, char_arr[50], terminate_char;
	int i, j, pointer, start_point, end_point;

	/* takes a sentence, then saves it to char_arr[50].
	 * if getchar() meets '?' or '!' or '.' (the end of a sentence)...
	 *   1. save a pointer which indicates right before the end.
	 *      (ex. you can? ==> pointer : index of [6])
	 *   2. save the terminating character ('?', '!', '.')
	 */
	printf("Enter a sentence: ");
	for (i = 0; i < 50; i++) {
		now_char = getchar();
		if (now_char == '?' || now_char == '!' || now_char == '.') {
			terminate_char = now_char;
			pointer = i - 1;
			break;
		}
		char_arr[i] = now_char;
	}

	/* reverses the words in the sentence */
	printf("Reversal of sentence: ");
	for (;;) {
		/* current pointer is indicating the end of a word. (initially, the last character of the last word) */
		end_point = pointer;

		/* if the pointer is not indcating [0] */
		if (pointer > 0) {

			/* find where the word starts, decreasing pointer by 1 at a time.
			 * if left of current pointer is ' ', we've found the start.
			 * while finding the start, we must make sure that pointer is valid (not below zero).
			 */
			while (char_arr[pointer - 1] != ' ' && pointer - 1 >= 0) {
				pointer--;
			}
			/* pointer now indicates starting point. */
			start_point = pointer;

			/* print the word */
			for (j = start_point; j <= end_point; j++) {
				putchar(char_arr[j]);
			}

			/* if this was not the last word, we must add a space. */
			if (pointer != 0) {
				putchar(' ');
			}

			/* if this was the last word, exit the loop. */ 
			if (pointer == 0) {
				break;
			}

			/* current pointer is indicating starting point of recent word...
			 * we must decrease pointer, skipping spaces, until pointer meet another end of a word.
			 */
			pointer--;
			while (char_arr[pointer] == ' ' && pointer - 1 >= 0) {
				pointer--;
			}

		}
		
		/* if the pointer is indicating [0]...
		 * (it executes only if first word of the sentence begins with a single character.)
		 */
		else if (pointer == 0) {
			putchar(char_arr[pointer]);
			break;
		}
	}
	printf("%c\n", terminate_char);


	return 0;


}