/*
1. 문자를 입력받아 char 배열에 저장한다.
이때, ?, !, .를 만나면 저장을 중단한다.
마지막 기호와 그 위치를 저장한다.

2. 마지막 기호 직전 위치에서부터 스캔을 시작한다.
끝 포인터를 마지막 기호 직전으로 초기화한다.
이 포인터가 가리키는 지점 바로 좌측이 ' '가 될 때까지 포인터를 좌측으로 한 칸씩 움직인다.
포인터가 ' '을 가리키면, 이 지점을 시작 포인터로 정한다.
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
	signed char now_char, char_arr[50], terminate_char;
	signed char *pointer, *start_point, *end_point;

	/* takes a sentence, then saves it to char_arr[50].
	* if getchar() meets '?' or '!' or '.' (the end of a sentence)...
	*   1. save a pointer which indicates right before the end.
	*      (ex. you can? ==> pointer : index [6])
	*   2. save the terminating character ('?', '!', '.')
	*/
	printf("Enter a sentence: ");
	for (pointer = char_arr; pointer < char_arr + 50; pointer++) {
		now_char = getchar();
		if (now_char == '?' || now_char == '!' || now_char == '.') {
			terminate_char = now_char;
			pointer -= 1;
			break;
		}
		*pointer = now_char;
	}

	/* reverses the words in the sentence */
	printf("Reversal of sentence: ");
	for (;;) {
		/* current pointer is indicating the last charcter of a word. (initially, the last character of the last word) */
		end_point = pointer;
		
		/* until left pointer is ' ' and valid, decrease pointer by 1 */
		while (*(pointer - 1) != ' ' && pointer - 1 >= char_arr) {
			pointer--;
		}
		/* pointer now indicates the first character of a word. */


		start_point = pointer;

		/* print the word */
		while (start_point <= end_point) {
			putchar(*start_point);
			start_point++;
		}

		/* if this was not the last word, we must add a space. and... */
		if (pointer != char_arr) {
			putchar(' ');
			/* skip spaces and set pointer to another end of word. */
			pointer--;
			while (*pointer == ' ' && pointer - 1 >= char_arr)
				pointer--;
		}
		/* if this was the last word (pointer == 0), exit the loop. */
		else
			break;
	}
	printf("%c\n", terminate_char);
	return 0;
}