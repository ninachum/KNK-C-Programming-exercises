/*
1. ���ڸ� �Է¹޾� char �迭�� �����Ѵ�.
   �̶�, ?, !, .�� ������ ������ �ߴ��Ѵ�.
   ������ ��ȣ�� �� ��ġ�� �����Ѵ�.
 
 2. ������ ��ȣ ���� ��ġ�������� ��ĵ�� �����Ѵ�.
    �� �����͸� ������ ��ȣ �������� �ʱ�ȭ�Ѵ�.
	�� �����Ͱ� ����Ű�� ������ ' '�� �� ������ �����͸� �������� �� ĭ�� �����δ�.
	�����Ͱ� ' '�� ����Ű��, �� ������ ���� ������ ���� �����ͷ� ���Ѵ�.
	���� �����ͺ��� �� �����ͱ����� ���ڸ� ����Ѵ�.
	����� �ܾ ������ �ܾ �ƴ϶��, ' '�� �߰��� �μ��Ѵ�.
	������ �ܾ�ٸ�, ' '�� ������� �ʰ� �ݺ����� Ż���Ѵ�. 

 3. ���� ������ ��ȣ�� ����Ѵ�.
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