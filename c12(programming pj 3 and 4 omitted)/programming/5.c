/*
1. ���ڸ� �Է¹޾� char �迭�� �����Ѵ�.
�̶�, ?, !, .�� ������ ������ �ߴ��Ѵ�.
������ ��ȣ�� �� ��ġ�� �����Ѵ�.

2. ������ ��ȣ ���� ��ġ�������� ��ĵ�� �����Ѵ�.
�� �����͸� ������ ��ȣ �������� �ʱ�ȭ�Ѵ�.
�� �����Ͱ� ����Ű�� ���� �ٷ� ������ ' '�� �� ������ �����͸� �������� �� ĭ�� �����δ�.
�����Ͱ� ' '�� ����Ű��, �� ������ ���� �����ͷ� ���Ѵ�.
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