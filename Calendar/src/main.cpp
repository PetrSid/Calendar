#define _CRT_SECURE_NO_WARNINGS // Macro need write here before a #inlcude,, For me
#define COUNT_MONTHS 12
#define COUNT_DAYS_IN_WEEK 7

#include <string>
#include <time.h>

using std::copy;
using std::string;
using std::atoi;

int main()
{
	time_t now = time(0); // try and catch
	char* date;
	try {
		date = ctime(&now);
		if (date == nullptr) {
			throw "Error: Date was not found";
		}
	}
	catch (const char* ex) {
		printf("%s", ex);
		exit(EXIT_FAILURE);
	}

	char weekday[3] = {};
	char month[3] = {};
	char day[2] = {};
	char year[4] = {};

	copy(date, date + 3, weekday);
	copy(date + 4, date + 7, month);
	copy(date + 8, date + 10, day);
	copy(date + 20, date + 24, year);

	const char* all_months[COUNT_MONTHS] = { "Dec", "Jan", "Feb", "Mar", "Apr", "May",
											 "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" };
	string temp(month, month + 3);
	size_t number;
	for (number = 0; number < COUNT_MONTHS - 1; ++number) {
		if (temp == all_months[number]) {
			temp = "\0";
			break;
		}
	}
	const char* week[COUNT_DAYS_IN_WEEK] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

	int count_days_in_months[COUNT_MONTHS] = { 31, 31, 29, 31, 30, 31,
											   30, 31, 31, 30, 31, 30 };
	size_t count_days = count_days_in_months[number];
	size_t number_week = 0;

	temp = string(weekday, weekday + 3);
	for (size_t i = 0; i < COUNT_DAYS_IN_WEEK; i++) {
		if (temp == week[i]) {
			number_week = i;
			break;
		}
	}
	for (size_t i = atoi(day); i > 1; --i) {
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
	for (size_t i = 0; i <= COUNT_DAYS_IN_WEEK; i++) {
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