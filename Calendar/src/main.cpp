#define _CRT_SECURE_NO_WARNINGS // Macro need write here before a #inlcude,, For me
#define COUNT_MONTHS 12
#define COUNT_DAYS_IN_WEEK 7
#define CONVERT_TO_INT std::atoi

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <string>

using std::copy;
using std::string;
using std::atoi;

int main()
{

	char* date = ctime(&now);
	char weekday[3] = {};
	char month[3] = {};
	char day[2] = {};
	char year[4] = {};


	size_t number;
	for (number = 0; number < COUNT_MONTHS - 1; ++number) {
		if (temp == all_months[number]) {
			temp = "\0";
			break;
		}
	}

	const char* week[COUNT_DAYS_IN_WEEK] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
	int week_num[COUNT_DAYS_IN_WEEK] = { 1, 2, 3, 4, 5, 6, 7 };
	int today = CONVERT_TO_INT(day);

	size_t count_days = count_days_in_months[number];
	size_t number_week = 0;

			number_week = i;
			break;
		}
	}
		number_week -= 1;
		if (number_week == 0) {
			number_week = COUNT_DAYS_IN_WEEK;
		}
	}
	printf("\t");
	for (size_t i = 0; i < 3; i++) {
		printf("%c", month[i]);
		if (i == 2) {
			printf("\t");
			for (size_t i = 0; i < 4; i++) {
				printf("%c", year[i]);
			}
		}
	} printf("\nMo Tu We Th Fr Sa Su\n");

	size_t count_day = 0, days_in_week = 0;
	size_t index_days = 0;
		count_day += 1;
		if (count_day > number_week) {
			days_in_week += 1;
			index_days += 1;
			if (index_days < 9) {
				printf("%d  ", index_days);
			}
			else
				printf("%d ", index_days);
		}
		else {
			days_in_week += 1;
			printf("   ");
		}

		if (days_in_week > COUNT_DAYS_IN_WEEK - 1) {
			i = 0;
			days_in_week = 0;
			printf("\n");
		}

		if (index_days == count_days) {
			break;
		}

	}
	system("Pause");
	printf("\nDone!");
	return 0;
}