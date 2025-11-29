#include <iostream>

using namespace std;

short ReadYear()
{
    short Year;
    cout << "Please Enter a year?\n";
    cin >> Year;
    return Year;
}

bool IsLeapYear(short Year)
{
    return (Year%400 == 0) || (Year%100!=0 && Year % 4==0);
}

int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        printf("%d is a leap year.\n",Year);
    }
    else
    {
        printf("%d is not a leap year.\n",Year);

    }
}