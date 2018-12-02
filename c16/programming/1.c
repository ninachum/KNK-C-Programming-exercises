#include <stdio.h>
#define COUNTRIES 32

struct dialing_code {
	char *country;
	int code;
};

const struct dialing_code country_codes[COUNTRIES] = {
	{"Argentina",            54}, {"Bangladesh",     889},
    {"Brazil",               55}, {"Burma (Myanmar)", 95},
    {"China",                86}, {"Colombia",        57},
    {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
    {"Ethiopia",            251}, {"France",          33},
    {"Germany",              49}, {"India",           91},
    {"Indonesia",            62}, {"Iran",            98},
    {"Italy",                39}, {"Japan",           81},
    {"Mexico",               52}, {"Nigeria",        234},
    {"Pakistan",             92}, {"Philippines",     63},
    {"Poland",               48}, {"Russia",           7},
    {"South Africa",         27}, {"South Korea",     82},
    {"Spain",                34}, {"Sudan",          249},
    {"Thailand",             66}, {"Turkey",          90},
    {"Ukraine",             380}, {"United Kingdom",  44},
    {"United States",         1}, {"Vietnam",         84}};

int main(void)
{
	int i, input;

	printf("Enter international code: ");
	scanf("%d", &input);

	for (i = 0; i < COUNTRIES; i++)
		if (input == country_codes[i].code) {
			printf("Corresponding country is : %s\n", country_codes[i].country);
			break;
		}
	if (i == COUNTRIES)
		printf("ERROR.\n");

	return 0;
}
