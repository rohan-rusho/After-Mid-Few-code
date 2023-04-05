#include <iostream>
#include <ctime>
using namespace std;
int main() {
   int year, month, day = 1;
  time_t t = time(NULL);
tm* timePtr = localtime(&t);
// get today's date
int todayDate = timePtr->tm_mday;
   cout << "Enter year: ";
    cin >> year;
       cout <<"Enter month: ";
   cin >> month;
   // Determine the length of the month
   int days_in_month;
   if (month == 2) {
      if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
         days_in_month = 29;
      } else {
         days_in_month = 28;
      }
   } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      days_in_month = 30;
   } else {
      days_in_month = 31;
   }
   // Determine the day of the week for the first day of the month
   int year_start = year * 365 + (year / 4) - (year / 100) + (year / 400);
   int month_start = 0;
   for (int i = 1; i < month; ++i) {
      if (i == 2) {
         if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            month_start += 29;
         } else {
            month_start += 28;
         }
      } else if (i == 4 || i == 6 || i == 9 || i == 11) {
         month_start += 30;
      } else {
         month_start += 31;
      }
   }
   int day_of_week = (year_start + month_start + day - 1) % 7;
   // Print out the calendar
   cout <<"Su Mo Tu We Th Fr   Sa" << endl;
   for (int i = 0; i < day_of_week; ++i) {
      cout <<"   ";
   }
   for (int i = 1; i <= days_in_month; ++i) {
      if (day_of_week == 6) {
         cout << "  ";
      }
      cout << i <<" ";
      if (i < 10) {
         cout <<" ";
      }
      if (day_of_week == 6 && i != days_in_month) {
         cout << endl;
      }
      day_of_week = (day_of_week + 1) % 7;
   }
   if (day_of_week != 0) {
      cout << endl;
   }
   cout << endl << "Today is " << todayDate << "  of the month." << endl;
   return 0;
}
