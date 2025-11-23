#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

const string FileName = "clientss.txt";

string ReadAccountNumber()
{
    string AccountNumber = "";
    cout<<"Please Enter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

vector <string> SplitString(string S1,string Sep ="#//#")
{
    vector <string> vWords;
    string sWord = " ";
    short Pos = 0;

    while((Pos=S1.find(Sep))!=-1)
    {
        sWord = S1.substr(0,Pos);
        if(sWord!="") vWords.push_back(sWord);

        S1.erase(0,Pos+Sep.length());
    }

    if(S1!="") vWords.push_back(S1);

    return vWords;
}


stClient ConvertLineToRecord(string Line,string Sep="#//#")
{
    stClient Client;
    vector <string> vClientInfo = SplitString(Line);

    Client.AccountNumber = vClientInfo[0];
    Client.PinCode = vClientInfo[1];
    Client.Name = vClientInfo[2];
    Client.Phone = vClientInfo[3];
    Client.AccountBalance = stod(vClientInfo[4]);

    return Client;

}

vector <stClient> LoadDataFromFileToVector(string FileName)
{
    vector <stClient> vClient;

    fstream MyFile;

    MyFile.open(FileName,ios::in);

    if(MyFile.is_open())
    {
        string Line;
        stClient Client;

        while(getline(MyFile,Line))
        {
            Client = ConvertLineToRecord(Line);
            
            vClient.push_back(Client);
        }
    }
    return vClient;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n"; 
    cout << "\nAccout Number: " << Client.AccountNumber; 
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name; 
    cout << "\nPhone        : " << Client.Phone;     
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientUsingAccountNumber(string AccountNumber,stClient &Client)
{
    vector <stClient> vClient = LoadDataFromFileToVector(FileName);

    for(stClient &C : vClient)
    {
        if(C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

int main()

{
    string AccountNumber = ReadAccountNumber();

    stClient Client;

    if(FindClientUsingAccountNumber(AccountNumber,Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout<<"\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }


    return 0;
}