#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string FileName = "clientss.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stClient AddClient()
 {
    stClient ClientInfo;

    cout<<"Please Enter Client Data:\n\n";

    cout<<"Enter Account Number? "; 
    getline(cin,ClientInfo.AccountNumber);

    cout<<"Enter PinCode? ";
    getline(cin,ClientInfo.PinCode);

    cout<<"Enter Name? ";
    getline(cin,ClientInfo.Name);

    cout<<"Enter Phone? ";
    getline(cin,ClientInfo.Phone);

    cout<<"Enter AccountBalance? ";
    cin >> ClientInfo.AccountBalance;

    return ClientInfo;
 }

string ConvertRecordToLine(stClient Client,string Sep ="#//#")
 {
    string Line = "";

    Line = Client.AccountNumber + Sep;
    Line += Client.PinCode + Sep;
    Line += Client.Name + Sep;
    Line += Client.Phone + Sep;
    Line += to_string(Client.AccountBalance);

    return Line;
 }

void AddDataLineToFile(string FileName,string Line)
{
    fstream MyFile;
    MyFile.open(FileName,ios::out|ios::app);

    if(MyFile.is_open())
    {
        MyFile << Line << endl;
        
        MyFile.close();
    }

}

void AddNewClient()
{
    stClient Client;
    Client = AddClient();

    AddDataLineToFile(FileName,ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        cout<<"Adding New Client:\n\n";

        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    
    
    } while (toupper(AddMore == 'Y'));
    
}

int main()
{
    AddClients();
    return 0;
}