#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main() {
// get the current time
time_t t = time(NULL);
tm* timePtr = localtime(&t);
// get today's date
int todayDate = timePtr->tm_mday;
// get the number of days in the current month
int daysInMonth;
switch (timePtr->tm_mon) {
case 1: // February
if ((timePtr->tm_year + 1900) % 4 == 0) {
daysInMonth = 29;
} else {
daysInMonth = 28;
}
break;
case 3: // April
case 5: // June
case 8: // September
case 10: // November
daysInMonth = 30;
break;
default:
daysInMonth = 31;
break;
}
// get the starting day of the week for the current month
timePtr->tm_mday = 1;
mktime(timePtr);
int startDay = timePtr->tm_wday;
// print the calendar header
cout << " " << setw(10) << left << "Su"
<< setw(3) << left << "Mo"
<< setw(3) << left << "Tu"
<< setw(3) << left << "We"
<< setw(3) << left << "Th"
<< setw(3) << left << "Fr"
<< setw(3) << left << "Sa" << endl;
// print the calendar days
int dayCounter = 1;
for (int i = 0; i < 6; i++) {
for (int j = 0; j < 7; j++) {
if (i == 0 && j < startDay) {
cout << setw(6) << " ";
} else if (dayCounter > daysInMonth) {
cout << setw(3) << " ";
} else {
cout << setw(3) << dayCounter;
dayCounter++;
}
}
cout << endl;
}
// print today's date
cout << endl << "Today is " << todayDate << "th of the month." << endl;
return 0;
}