#include <stdio.h>

enum months { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NEXTYEAR };

int leapyear(int year) {
	// not divisible by 4
	if(year % 4 != 0) {
		return 0;
	}

	if(year % 100 == 0 && year % 400) {
		return 0;
	}
	return 1;
}

int newMonth(int days, int months, int years) {
	if(days == 31 && (months == JAN || months == MAR || months == MAY || months == JUL || months == AUG || months == OCT || months == DEC)) {
		return 1;
	}
	if(days == 30 && (months == APR || months == JUN || months == SEP || months == NOV)) {
		return 1;
	}
	if(days == 28 && months == FEB && !leapyear(years)) {
		return 1;
	}
	if(days == 29 && months == FEB && leapyear(years)) {
		return 1;
	}
	return 0;
}

char* month(int month) {
	switch(month) {
		case JAN: return "Jan";
		case FEB: return "Feb";
		case MAR: return "Mar";
		case APR: return "Apr";
		case MAY: return "May";
		case JUN: return "Jun";
		case JUL: return "Jul";
		case AUG: return "Aug";
		case SEP: return "Sep";
		case OCT: return "Oct";
		case NOV: return "Nov";
		case DEC: return "Dec";
	}
}

int main(void) {
	// start date: Jan 1, 00:00, 1900
	// final hours to check: 2266380
	int hours = 2266380;
	int days = 0;
	int months = 0;
	int years = 1900;

	while(hours > 23) {
		days++;
		hours -= 24;
		if(newMonth(days, months, years)) {
			months++;
			days = 0;
		}
		if(months == NEXTYEAR) {
			years++;
			months = JAN;
		}
	}
	printf("%s %d, %02d:00, %d\n", month(months), days + 1, hours, years);
	return 0;
}