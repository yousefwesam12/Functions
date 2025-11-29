#include <iomanip>
#include <iostream>

using namespace std;

short ReadYear()
{
    short Year;
    cout << "Please Enter a year to check?\n";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year%400 == 0) || (Year%100!=0 && Year % 4==0);
}

short NumOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

short NumOfHoursInAYear(short Year)
{
    return NumOfDaysInAYear(Year) * 24;
}

int NumOfMinutesInAYear(short Year)
{
    return NumOfHoursInAYear(Year) * 60;
}

long long NumOfSecondsInAYear(short Year)
{
    return NumOfMinutesInAYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout<<"\nNumber of Days    in Year ["<<Year<<"] is "
        << NumOfDaysInAYear(Year);

    cout<<"\nNumber of Hours   in Year ["<<Year<<"] is "
      << NumOfHoursInAYear(Year);

    cout<<"\nNumber of Minutes in Year ["<<Year<<"] is "
      << NumOfMinutesInAYear(Year);

    cout<<"\nNumber of Seconds in Year ["<<Year<<"] is "
      << NumOfSecondsInAYear(Year);
}