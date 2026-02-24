// 3-3 Project One Submission.cpp : Tom Paige January 23, 2026 for submission of Module 3 project.
//

#include <iostream>
#include <string>
using namespace std;

// Gets the initial hour from the user
int InitialHour() {
	int hours;
	cout << "Enter the hours: " << endl;
	cin >> hours;
	return hours;
}

// Gets the initial minute from the user
int InitialMinute() {
	int minutes;
	cout << "Enter the minutes: " << endl;
	cin >> minutes;
	return minutes;
}

// Gets the initial second from the user
int InitialSecond() {
	int seconds;
	cout << "Enter the seconds: " << endl;
	cin >> seconds;
	return seconds;
}

// Displays both the 12-hour and 24-hour clocks
void displayTime(int currHoursClock1, int currHoursClock2, int currMinutesClock, int currSecondsClock, string AmorPm, bool zero1, bool zero2, bool zero3) {

	string minStr;
	string secStr;
	
	// Strings used to add leading zeros to minutes and seconds
	if (currMinutesClock < 10) {
		minStr = "0" + to_string(currMinutesClock);
	}
	else {
		minStr = to_string(currMinutesClock);
	}

	if (currSecondsClock < 10) {
		secStr = "0" + to_string(currSecondsClock);
	}
	else {
		secStr = to_string(currSecondsClock);
	}

	// Case where both clocks need a leading zero for hours
	if (zero1) {
		cout << "********************************" << "          " << "**********************************" << endl;
		cout << "*         12-Hour Clock	       *" << "          " << "*         24-Hour Clock	   *" << endl;
		cout << "*         " << "0" << currHoursClock1 << ":" << minStr << ":" << secStr << " " << AmorPm << "	       *";
		cout << "          " << "*           " << "0" << currHoursClock2 << ":" << minStr << ":" << secStr << "	           *" << endl;
		cout << "********************************" << "          " << "**********************************" << endl;
	}

	// Case where only the 24-hour clock needs a leading zero
	else if (zero2) {
		cout << "********************************" << "          " << "**********************************" << endl;
		cout << "*         12-Hour Clock	       *" << "          " << "*         24-Hour Clock	   *" << endl;
		cout << "*         " << currHoursClock1 << ":" << minStr << ":" << secStr << " " << AmorPm << "	       *";
		cout << "          " << "*           " << "0" << currHoursClock2 << ":" << minStr << ":" << secStr << "	           *" << endl;
		cout << "********************************" << "          " << "**********************************" << endl;
	}

	// Case where only the 12-hour clock needs a leading zero
	else if (zero3) {
		cout << "********************************" << "          " << "**********************************" << endl;
		cout << "*         12-Hour Clock	       *" << "          " << "*         24-Hour Clock	   *" << endl;
		cout << "*         " << "0" << currHoursClock1 << ":" << minStr << ":" << secStr << " " << AmorPm << "	       *";
		cout << "          " << "*           " << currHoursClock2 << ":" << minStr << ":" << secStr << "	           *" << endl;
		cout << "********************************" << "          " << "**********************************" << endl;
	}

	// Case where no leading zeros are needed for hours
	else {
		cout << "********************************" << "          " << "**********************************" << endl;
		cout << "*         12-Hour Clock	       *" << "          " << "*         24-Hour Clock	   *" << endl;
		cout << "*         " << currHoursClock1 << ":" << minStr << ":" << secStr << " " << AmorPm << "	       *";
		cout << "          " << "*           " << currHoursClock2 << ":" << minStr << ":" << secStr << "	           *" << endl;
		cout << "********************************" << "          " << "**********************************" << endl;
	}
}

// Displays the menu and gets the user's choice
int Menu() {
	int Userinput;
	cout << "Input 1-4 from the following Menu to adjust or quit" << endl;
	cout << "*************************" << endl;
	cout << "* 1 - Add One Hour      *" << endl;
	cout << "* 2 - Add One Minute    *" << endl;
	cout << "* 3 - Add One Second    *" << endl;
	cout << "* 4 - Exit Program      *" << endl;
	cout << "*************************" << endl;

	cin >> Userinput;

	return Userinput;
}

int main() {
	// Variables to store time and menu input
	int hours;
	int minutes;
	int seconds;
	int Userinput;

	// Variables used for display formatting
	int currHoursClock1;
	int currHoursClock2;
	int currMinutesClock;
	int currSecondsClock;
	string AmorPm;

	// Flags used to determine when to print leading zeros for hours
	bool zero1;
	bool zero2;
	bool zero3;

	zero1 = false;
	zero2 = false;
	zero3 = false;

	// Prompt user for initial time
	cout << "Enter current time in 24-hour format (23:59:59) or ((0:0:0) for midnight)" << endl;

	// Get and validate hours input
	hours = InitialHour();
	while (hours < 0 || hours > 23) {
		cout << "Enter a valid hour." << endl;
		hours = InitialHour();
	}

	// Get and validate minutes input
	minutes = InitialMinute();
	while (minutes < 0 || minutes > 59) {
		cout << "Enter a valid minute." << endl;
		minutes = InitialMinute();
	}

	// Get and validate seconds input
	seconds = InitialSecond();
	while (seconds < 0 || seconds > 59) {
		cout << "Enter a valid second." << endl;
		seconds = InitialSecond();
	}

	// Convert 24-hour time to display format
	if (hours >= 0 && hours <= 9) {
		currHoursClock2 = hours;
		zero1 = true;
		zero2 = false;
		zero3 = false;
		currHoursClock1 = hours;
		AmorPm = "AM";
		if (hours == 0) {
			zero1 = false;
			zero2 = true;
			currHoursClock1 = 12;
		}
	}
	else if (hours >= 10 && hours <= 12) {
		zero1 = false;
		zero2 = false;
		zero3 = false;
		currHoursClock2 = hours;
		currHoursClock1 = hours;
		if (hours == 12) {
			AmorPm = "PM";
		}
	}
	else if (hours > 12 && hours <= 23) {
		zero1 = false;
		zero2 = false;
		zero3 = false;
		AmorPm = "PM";
		currHoursClock2 = hours;
		if (hours >= 13 && hours <= 21) {
			zero3 = true;
			currHoursClock1 = (hours - 12);
		}
	}

	// Set minutes and seconds for display
	currMinutesClock = minutes;
	currSecondsClock = seconds;

	// Display the initial time
	displayTime(currHoursClock1, currHoursClock2, currMinutesClock, currSecondsClock, AmorPm, zero1, zero2, zero3);

	// Display menu
	Userinput = Menu();

	// Loop until the user chooses to exit
	while (Userinput != 4) {

		if (Userinput == 1) { // Add one hour
			hours++;

			if (hours == 24) {
				hours = 0;
			}
		}
		else if (Userinput == 2) { // Add one minute
			minutes++;

			if (minutes == 60) {
				minutes = 0;
				hours++;

				if (hours == 24) {
					hours = 0;
				}
			}
		}
		else if (Userinput == 3) { // Add one second
			seconds++;

			if (seconds == 60) {
				seconds = 0;
				minutes++;

				if (minutes == 60) {
					minutes = 0;
					hours++;

					if (hours == 24) {
						hours = 0;
					}
				}
			}
		}
		// Handle invalid menu input
		else {
			cout << "Enter valid number" << endl;
			Userinput = Menu();
			continue;
		}

		// Recalculate display values after time change
		if (hours >= 0 && hours <= 9) {
			currHoursClock2 = hours;
			zero1 = true;
			zero2 = false;
			zero3 = false;
			currHoursClock1 = hours;
			AmorPm = "AM";
			if (hours == 0) {
				zero1 = false;
				zero2 = true;
				currHoursClock1 = 12;
			}
		}
		else if (hours >= 10 && hours <= 12) {
			zero1 = false;
			zero2 = false;
			zero3 = false;
			currHoursClock2 = hours;
			currHoursClock1 = hours;
			if (hours == 12) {
				AmorPm = "PM";
			}
			else {
				AmorPm = "AM";
			}
		}
		else {
			zero1 = false;
			zero2 = false;
			zero3 = false;
			AmorPm = "PM";
			currHoursClock2 = hours;

			if (hours >= 13 && hours <= 21) {
				zero3 = true;
			}
			currHoursClock1 = hours - 12;
		}

		// Update minutes and seconds for display
		currMinutesClock = minutes;
		currSecondsClock = seconds;

		displayTime(currHoursClock1, currHoursClock2, currMinutesClock, currSecondsClock, AmorPm, zero1, zero2, zero3);

		// Show menu again
		Userinput = Menu();
	}

	// Program exit message
	cout << endl;
	cout << "Goodbye!" << endl;
}