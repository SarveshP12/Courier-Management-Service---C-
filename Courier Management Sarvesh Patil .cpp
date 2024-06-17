#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int Place_Order(int y)
{
    string Destination;
    string Activity;
    string Month;
    string x;
    string CID;
    string date;
    string Send_name;
    string Send_add;
    int Send_phno;
    string Rec_name;
    string Rec_add;
    string Rec_phno;
    int Cost = 0;
    int weight;
    int distance;
    getline(cin,x);
    cout<<"Enter your Courier ID:";
    getline(cin, CID);
    cout<<"Enter your Name:";
    getline(cin, Send_name);
    cout<<"Enter Receiver's Name:";
    getline(cin, Rec_name);
    cout<<"Enter Receivers Address:";
    getline(cin, Rec_add);
    cout<<"Enter Receivers Phone number:";
    getline(cin,Rec_phno);
    cout<<"Enter date(DD/MM/YYYY):";
    getline(cin,date);
    cout<<"Enter your destination:";
    getline(cin, Destination);
    //cout<<"Enter courier activity:";
    cout<<"Enter the distance till the final destination:";
    cin>>distance;
    if(distance<100)
    {
        Cost = Cost + 500;
    }
    if(100<distance<5000)
    {
        Cost = Cost + 2000;
    }
    if(distance>5000)
    {
        Cost = Cost + 10000;
    }
    cout<<"Enter the weight of the courier:";
    cin>>weight;
    if(weight<50)
    {
        Cost = Cost + 500;
    }
    if(50<weight<100)
    {
        Cost = Cost + 2500;
    }
    if(weight>100)
    {
        Cost = Cost + 5000;
    }
    cout<<"Final amount to be paid:"<<Cost;
    {
    ofstream file("Place_Order.txt",ios::app);
    //file<<"Courier ID:"<<"\t"<<"Sender's Name:"<<"\t"<<"Receiver's Name:"<<"\t"<<"Receiver's Address:"<<"\t"<<"Receiver's Phone number:"<<endl<<endl;
    file<<CID<<"\t"<<Send_name<<"\t"<<Rec_name<<"\t"<<Rec_add<<"\t"<<Rec_phno<<endl;
    file.close();
    }
    {
    ofstream file("Tracker.txt",ios::app);
    file<<CID<<"\t"<<date<<"\t"<<Month<<"\t"<<Destination<<"\t"<<"Order Placed"<<endl;
    file.close();
    }
}

int Update_Track(int u)
{
    int i;
    string Destination;
    string Activity;
    string Month;
    string x;
    string CID;
    string date;
    getline(cin,x);
    cout<<"Enter your Courier ID:";
    getline(cin, CID);
    cout<<"Enter date:";
    getline(cin, date);
    cout<<"Enter your destination:";
    getline(cin, Destination);
    cout<<"Enter courier activity:";
    getline(cin, Activity);
    {
    ofstream file("Tracker.txt",ios::app);
    file<<CID<<'\t'<<date<<'\t'<<Month<<'\t'<<Destination<<'\t'<<Activity<<endl;
    file.close();
    }
}

int Display_Order(int d)
{
    string x;
    getline(cin,x);
    string TCID;
    string user_CID;
    cout<<"Enter your Courier ID:"<<endl;
    getline(cin,user_CID);
    string Tdate;
    string Tmonth;
    string Tdestination;
    string Tactivity;
    ifstream myFile ("Tracker.txt");
    cout<<"CID"<<"\t"<<"Date"<<"\t\t\t"<<"Destination"<<"\t"<<"Courier Activity"<<endl;
    int TCIDyes=0;
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile,TCID,'\t');
            getline(myFile,Tdate,'\t');
            getline(myFile,Tmonth,'\t');
            getline(myFile,Tdestination,'\t');
            getline(myFile,Tactivity);
            if(TCID == user_CID)
            {
            cout<<TCID<<"\t"<<Tdate<<"\t\t"<<Tdestination<<"\t"<<Tactivity<<endl;
            TCIDyes=1;
            }
        }
        if (TCIDyes==0)
        cout<<"Courier ID does not exist..."<<endl;
        myFile.close();
    }

}

int Track_Order(int z)
{
    int n;
    cout<<"Enter your choice:"<<endl;
    cout<<"1 = Track \n2 = Update "<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        int d;
        Display_Order(d);
        return 0;
        break;
    case 2:
        int u;
        Update_Track(u);
        return 0;
        break;
    default:
        cout<<""<<endl;
    }
}
int main()
{
    int i;
    cout<<"Which mode do you want to enter:"<<endl;
    cout<<"Place an Order"<<"\n"<<"Track your Order"<<endl;
    cin>>i;
    switch(i)
    {
    case 1:
        int y;
        Place_Order(y);
        return 0;
        break;
    case 2:
        int z;
        Track_Order(z);
        return 0;
        break;
        default:
        cout<<"\n";
    }
}
