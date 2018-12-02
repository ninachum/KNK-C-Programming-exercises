/* Computes a Universal Product Code check digit */

#include <stdio.h>

int main(void)
{
   int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, b,
      first_sum, second_sum, total, check_digit;

   printf("Enter the 12 digits: ");
   scanf("%1d", &d);
   scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
   scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
   scanf("%1d", &b);

   first_sum = d + i2 + i4 + j1 + j3 + j5;
   second_sum = i1 + i3 + i5 + j2 + j4;

   total = 3 * first_sum + second_sum;
   check_digit = 9 - ((total -1) % 10);

   if(check_digit == b)
	   printf("VALID\n");
   else
	   printf("INVALID\n");
   
   return 0;
}