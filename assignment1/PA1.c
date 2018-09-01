#include <stdio.h>
#include <stdlib.h>

// takes an int representing the year, and returns an int representing the day of the week of Jan 1 of that year
// throughout this entire project, 0=Sunday, 1=Monday, ..., 6=Saturday
// source for this algorithm: https://stackoverflow.com/questions/478694/what-is-the-easiest-algorithm-to-find-the-day-of-week-of-day-zero-of-a-given-yea#478992
int getFirstDay(int year) {
	return (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
}

// takes an int representing the year, and an int representing the month
// throughout this entire project, 0=January, 1=February, ..., 11=December
// prints out the month name and returns the number of days in that month
int printMonthName(int year, int month) {
	switch(month) {
		case 0:
			printf("\nJanuary %d\n\n", year);
			return 31;
		case 1:
			printf("\nFebruary %d\n\n", year);
			// find out if it's a leap year
			int isLeap = 0; // 1 if the selected year is a leap year, 0 if it is not
			if (year % 4 == 0) {
				isLeap = 1;
				if (year % 100 == 0) {
					isLeap = 0;
					if (year % 400 == 0) {
						isLeap = 1;
					}
				}
			}
			if (isLeap) return 29;
			else return 28;
		case 2:
			printf("\nMarch %d\n\n", year);
			return 31;
		case 3:
			printf("\nApril %d\n\n", year);
			return 30;
		case 4:
			printf("\nMay %d\n\n", year);
			return 31;
		case 5:
			printf("\nJune %d\n\n", year);
			return 30;
		case 6:
			printf("\nJuly %d\n\n", year);
			return 31;
		case 7:
			printf("\nAugust %d\n\n", year);
			return 31;
		case 8:
			printf("\nSeptember %d\n\n", year);
			return 30;
		case 9:
			printf("\nOctober %d\n\n", year);
			return 31;
		case 10:
			printf("\nNovember %d\n\n", year);
			return 30;
		case 11:
			printf("\nDecember %d\n\n", year);
			return 31;
	}

	// something went wrong if control gets here, return -1 as an error
	return -1;
}

// takes an int representing the year, an int representing the month, and an int representing the day of the week that month starts on
// returns the day of the week the next month starts on
int printMonth(int year, int month, int startDay) {
	int numDays = printMonthName(year, month); // prints month name and stores number of days in the month
	// print day headings
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// print leading whitespace
	for (int w = 0; w < startDay; w++) {
		printf("     ");
	}

	// print day numbers
	for (int d = 1; d <= numDays; d++) {
		printf("%5d", d);
		startDay = (startDay + 1) % 7; // increment startDay to keep track of what day of the week it is
		if (startDay == 0 && d != numDays) {
			// print the newline between weeks when startDay wraps around to Sunday
			printf("\n");
		}
	}

	printf("\n");
	return startDay; // return startDay because it not holds the starting day of the next month
	
}

// takes an int representing the year and an int representing the day of the week of Jan 1 of that year
// prints out a 12 month calendar for that year
void printCalendar(int year, int startDay) {
	for (int month = 0; month < 12; month++) {
		startDay = printMonth(year, month, startDay);
	}

	printf("\n");
}

int main(int argc, char *argv[]) {
	int year; // positive integer representing the year
	int curDay; // represents a day of the week, where 0=Sunday, 1=Monday, ..., 6=Saturday

	printf("                         MONTHLY CALENDAR\n\n");

	printf("Please enter year for this calendar: ");
	scanf("%d", &year);

	// check to make sure the year is valid
	if (year < 1583) {
		printf("Years before 1583 did not use the current Gregorian calendar. Exiting...\n");
		exit(1);
	}

	printf("\n  ***    CALENDAR for %d    ***\n", year);

	curDay = getFirstDay(year);

	printCalendar(year, curDay);

	return 1;
}
