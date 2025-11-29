#include <iostream>

using namespace std;

long long ReadNumber()
{
    long long Number = 0;
    cout<<"Enter a Number? ";
    cin >> Number;

    return Number;
}

string NumberToText(long long Number)
{

    if (Number == 0)
    {
        return "";
    }

    if (Number>=1 && Number <=19)
    {
        string Arr[] =
            {"","One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen"
            ,"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

        return Arr[Number];
    }
    if (Number>=20 && Number<=99)
    {
        string Arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        return Arr[Number/10] + " " + NumberToText(Number%10);
    }
    if (Number>=100 && Number<=199)
    {
        return "One Hundred " + NumberToText(Number%100);
    }
    if (Number>=200 && Number <=999)
    {
        return NumberToText(Number/100) + " Hundreds " + NumberToText(Number%100);
    }
    if (Number>=1000 && Number<=1999)
    {
        return "One Thousands " + NumberToText(Number%1000);
    }
    if (Number>=2000 && Number<=999999)
    {
        return NumberToText(Number/1000) + " Thousands " + NumberToText(Number%1000);
    }
    if (Number>=1000000 && Number<=1999999)
    {
        return "One Million " + NumberToText(Number%1000000);
    }
    if (Number>=2000000 && Number<=9999999)
    {
        return NumberToText(Number/1000000) + " Million " + NumberToText(Number%1000000);
    }
    if (Number>=10000000 && Number<=19999999)
    {
        return "One Billion " + NumberToText(Number%10000000);
    }
    else
    {
        return NumberToText(Number/10000000) + " Billion " + NumberToText(Number%10000000);
    }

}

int main()
{
    cout << NumberToText(ReadNumber()) << endl;
    return 0;
}