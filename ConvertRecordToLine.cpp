 #include <iostream>

 using namespace std;

 struct stClientInfo
 {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
 };

 stClientInfo ReadClient()
 {
    stClientInfo ClientInfo;

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

 string ConvertRecordToLine(stClientInfo Client,string Sep ="#//#")
 {
    string Line = "";

    Line = Client.AccountNumber + Sep;
    Line += Client.PinCode + Sep;
    Line += Client.Name + Sep;
    Line += Client.Phone + Sep;
    Line += to_string(Client.AccountBalance);

    return Line;
 }

 int main()
 {
    stClientInfo ClientInfo = ReadClient();

    cout<<"\n\nClient Record for saving is:\n";
    cout<<ConvertRecordToLine(ClientInfo)<<endl;
 }