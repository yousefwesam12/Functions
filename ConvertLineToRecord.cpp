#include <iostream>
#include <vector>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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

void PrintClientRecord(stClient Client)
{
    cout<<"Account Number: "<<Client.AccountNumber<<endl;
    cout<<"Pin Code      : "<<Client.PinCode<<endl;
    cout<<"Name          : "<<Client.Name<<endl;
    cout<<"Phone         : "<<Client.Phone<<endl;
    cout<<"Account Balance: "<<Client.AccountBalance<<endl;

}

int main()
{
    string LineRecord = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

    cout<<"Line Record is:\n";
    cout<<LineRecord<<endl;

    cout<<"The following is the extracted client record:\n";
    PrintClientRecord(ConvertLineToRecord(LineRecord));
    return 0;
}