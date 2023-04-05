#include <iostream>
#include <ctime> // for time()
#include <chrono> // for chrono library
#include <unistd.h>
using namespace std;
int main() {
// Get the current time
time_t now = time(0);
tm *local_time = localtime(&now);
// Print the current time
cout << "Current time: ";
cout << local_time->tm_hour << ":";
cout << local_time->tm_min << ":";
cout << local_time->tm_sec << endl;
// Create a loop to update the clock every second
while (true) {
// Get the current time
now = time(0);
local_time = localtime(&now);
// Clear the console and print the new time
system("cls");
cout << "Current time: ";
cout << local_time->tm_hour << ":";
cout << local_time->tm_min << ":";
cout << local_time->tm_sec << endl;
// Wait for one second before updating the clock again
sleep(1);
}
return 0;
}