#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int ReadYear() {
	int year;
	cout << "enter a year : ";
	cin >> year;
	return year;
}
int ReadMonth() {
	int month;
	printf("enter a month : ");
	cin >> month;
	return month;
}
bool Isleap(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) return 1;
	return 0;
}
string GetDayName(int year, int month, int day) {
	string Name;
	int Index;
	int a = floor((14 - month) / 12);
	int y = year - a;
	int m = month + 12 * a - 2;
	Index = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	string arr[] = { "Saterday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	Name = arr[Index];
	return Name;
}
int LastDay(int year, int month) {
	if (Isleap(year) && month == 2) return 29;
	else if (!Isleap(year) && month == 2) return 28;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 12 || month == 10) return 31;
	else return 30;
}
string GetMonthName(int month) {
	string arr[] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return arr[month];
}
int GetFirstDayIntheMonth(int year, int month, int day = 1) {
	int Index;
	int a = floor((14 - month) / 12);
	int y = year - a;
	int m = month + 12 * a - 2;
	Index = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return Index;
}
void PrintHeader(string MonthName) {
	cout << "-------------- " << MonthName << " --------------\n\n";
	cout << left << setw(5) << "Sun" << left << setw(5) << "Mon" << left << setw(5) << "Tue" << left << setw(5) << "Wed" << left << setw(5) << "Thu" << left << setw(5) << "Fri" << left << setw(5) << "Sat";
}
void PrintMonth(int DayIndex, int lastday) {
	int day = 1;
	for (int i = 1; i <= 5; i++) {
		cout << "\n";
		for (int j = 1; j <= 7; j++) {
			if (day > lastday) break;

			if (i == 1 && j < DayIndex + 1) {
				cout << setw(4) << " ";
			}
			else {
				cout << left << setw(4) << day;
				day += 1;
			}

			cout << " ";
		}
	}

}
void RunProgram(int year, int Month) {
	int DayIndex = GetFirstDayIntheMonth(year, Month);
	string MonthName = GetMonthName(Month);
	PrintHeader(MonthName);
	PrintMonth(DayIndex, LastDay(year, Month));
}
int main() {
	int year = ReadYear();
	cout << "\n\n";
	for (int i = 1; i <= 12; i++) {
		RunProgram(year, i);
		cout << "\n\n\n";
	}
	cout << "press any key to quit... ";
	system("pause>0");
	return 0;
}