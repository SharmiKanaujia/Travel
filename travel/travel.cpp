#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
void menu();
class ManageMenu{
    protected:
    string username;
    public:
    ManageMenu()
    {
        system("color 0A");
        cout<<"\n\n\n\n\n\n\n\n\n\n\\t  Entyer your name to continue as an Admin: ";
        cin>>username;
        system("CLS");
        menu();
    }
~ManageMenu(){}

};
class Customers
{
public:
string name, gender, address;
int age, mobileno;
static int cusID;
char all[999];
void getDetails()
{
    ofstream out("old-customers.txt", ios::app);
    {
    cout<<"Enter customer ID: ";
    cin>>cusID;
     cout<<"Enter Name: ";
    cin>>name;
     cout<<"Enter Age: ";
    cin>>age;
     cout<<"Enter Mobile no: ";
    cin>>mobileno;
     cout<<"Enter Address: ";
    cin>>address;
     cout<<"Enter Gender: ";
    cin>>gender;
    }
out << "\nCustomer ID: "<<cusID<<"\nName"<<name<<"\nage"<<age<<"\nMobile Number:"<<mobileno<<"\nddress"<<address<<"\nGender:"<<gender<<endl;
out.close();
cout<< "\nSAVE \nNOTE: We save yyour details for futeure purpose\n"<<endl;
}
void showDetails()
{
ifstream in("old-customers.txt");
{
    if(!in)
    {
        cout<<"File Error"<<endl;
    }
    while(!(in.eof()))
    {
        in.getline(all, 999);
        cout<<all<<endl;
    }
    in.close();
}
}
};
int Customers::cusID;
class Cabs{
    public:
    int carChoice;
    int kilometer;
    float cost=0;
    static float lastcabCost;
    void cabDetails()
    {
        cout<<"We collaborate with fastest safest and smartest cab service around the country"<<endl;
        cout<<"-----------ABC Cabs------------"<<endl;
        cout<<"1. Rent a standard cab - Rs.15 for 1KM"<<endl;
        cout<<"2.  Rent a luxury cab - Rs.25 for 1KM"<<endl;

        cout<<"\nTo calculate the cost for your journey:"<<endl;
        cout<<"Enter which kind of cab you need :";
        cin>>carChoice;
        cout<<"Enter kilometers you have to travel:";
        cin>>kilometer;
        int hireCab;
        if(carChoice==1){
            cost= kilometer*15;
            cout<<"\nYour tour cost:"<<cost<<"rupees for a Standard cab"<<endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to hire other cab: ";
            cin>>hireCab;
            system("CLS");
            if(hireCab==1){
               lastcabCost=cost;
               cout<<"\nYou have successfully hired a Syandard cab"<<endl;
               cout<<"Goto menu and take the receipt"<<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<<"Invalid input! Redirecting to previous menu \nPlease wait!"<<endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }

        }
        else if(carChoice==2){
             cost= kilometer*25;
            cout<<"\nYour tour cost:"<<cost<<"rupees for a Standard cab"<<endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to hire other cab: ";
            cin>>hireCab;
            system("CLS");
            if(hireCab==1){
               lastcabCost=cost;
               cout<<"\nYou have successfully hired a Syandard cab"<<endl;
               cout<<"Goto menu and take the receipt"<<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<<"Invalid input! Redirecting to previous menu \nPlease wait!"<<endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else{
             cout<<"Invalid input! Redirecting to Main menu \nPlease wait!"<<endl;
                Sleep(1100);
                system("CLS");
                menu();
                
        }
        cout<<"\nPress 1 tio Redirect Main menu:";
        cin>>hireCab;
        system("CLS");
        if (hireCab==1){
            menu();
        }
        else{
            menu();
        }
    }
};
float Cabs::lastcabCost;
class Booking{

    public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;
    void hotels(){
        string hotelNo[]={"Avendra","ChoiceYou","ElephantBay"};
        for(int a=0;a<3;a++){
            cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl;
        }
        cout<<"\nCurrently we collaborated with above hotels!"<<endl;
        cout<<"Press any key to back or\nEnter number of the hotel you want to book:";
        cin>>choiceHotel;
        system("CLS");
        if(choiceHotel==1){
            cout<<"-----------WELCOME TO HOTEL AVENDRA-----------\n"<<endl;
            cout<<"The garden, food and beverage. Enjoy all you drink,stay cool and get chilled"<<endl;
            cout<<"Packages offered by Avendra:\n"<<endl;
            cout<<"1.Standard Pack"<<endl;
            cout<<"\tAll basic facilities you need just for: Rs. 5000.00"<<endl;
            cout<<"2.Premium pack"<<endl;
            cout<<"Enjoy Premium:Rs. 10000.00 "<<endl;
             cout<<"3.Luxury pack"<<endl;
            cout<<"Enjoy Luxury :Rs. 15000.00 "<<endl;

            cout<<"\nPress another key to back or\n Enter package number you want to book: ";
            cin>>packChoice;
            if(packChoice==1){
                hotelCost==5000.00;
                cout<<"\nYou have booked standard pack at Avendra"<<endl;
                cout<<"Goto menu and take receipt"<<endl;
            }
            else if(packChoice==2){
                hotelCost==10000.00;
                cout<<"\nYou have booked premium pack at Avendra"<<endl;
                cout<<"Goto menu and take receipt"<<endl;
            }
            else if(packChoice==3){
                hotelCost==15000.00;
                cout<<"\nYou have booked Luxury pack at Avendra"<<endl;
                cout<<"Goto menu and take receipt"<<endl;
            }
            else{
               
                cout<<"\nInvalid input! redirecting to previous menu \n please wait"<<endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
                cout<<"\nPress 1 to redirect main menu: ";
                cin>>gotomenu;
                system("CLS");
                if(gotomenu==1)
                {
                     menu();
                }
                else{
                    menu();
                }
        }
            else{
                  cout<<"\nInvalid input! redirecting to previous menu \n please wait"<<endl;
                Sleep(1100);
                system("CLS");
                menu();
            }

    } 
};

float Booking::hotelCost;
class Charges : public Booking, Cabs, Customers
{
public:
   void printBill(){
    ofstream outf("receipt.txt");
    {
          outf<<"-----------ABC TRAVEL AGENCY-----------"<<endl;
          outf<<"----------Receipt----------"<<endl;
          outf<<"-------------------------------------------------"<<endl;
          outf<<"Customer ID:"<<Customers::cusID<<endl<<endl;
          outf<<"Description\t\t Total"<<endl;
          outf<<"Hotel cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
          outf<<"Travel (cab) cost: \t"<<fixed<<setprecision(2)<<Cabs::lastcabCost<<endl;\
          outf<<"---------------------------------------------------------------"<<endl;
          outf<<"total charge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost<<endl;
          outf<<"-------------------THANK YOU-------------------"<<endl;

    }
    outf.close();
   }

   void showBill(){
    ifstream inf("receipt.txt");
    {
        if(!inf)
        {
            cout<<"File opening error!"<<endl;
    }
    while(!(inf.eof())){
        inf.getline(all,999);
        cout<<all<<endl;
    }
   }
   inf.close();
   }
};

void menu(){

    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout<<"\t\t         *ABC Travels *\n"<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t|\tCustomer Management   -> 1\t|"<<endl;
    cout<<"\t|\tCabs Management       -> 2\t|"<<endl;
    cout<<"\t|\tBookings Management   -> 3\t|"<<endl;
    cout<<"\t|\tCharges & bill        -> 4\t|"<<endl;
    cout<<"\t|\tExit                  -> 5\t|"<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t|--------------------------------------|"<<endl;
    cout<<"\nEnter Your Chouce: "<<endl;
    cin>>mainChoice;
    system("CLS");
    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;
    
    if(mainChoice==1){
        cout<<"------Customers------\n"<<endl;
        cout<<"1. Enter New Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;
        cout<<"\nEnter Choice: ";
        cin>>inChoice;
        system("CLS");
        if(inChoice==1){
            a2.getDetails();

        }
        else if(inChoice==2){
          a2.showDetails();
        }
        else{
              cout<<"\nInvalid input! redirecting to previous menu \n please wait"<<endl;
                Sleep(1100);
                system("CLS");
                menu();
        }
        cout<<"\nPress 1 to Redirect main menu: ";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1){
            menu();

        }
        else{
            menu();
        
        }
    }

else if(mainChoice==2){
    a3.cabDetails();
}
else if(mainChoice==3){
    cout<<"--> Book a luxury Hotel using the system <--"<<endl;

    a4.hotels();
}
else if(mainChoice==4){
    cout<<"-->Get your receipt <--"<<endl;
    a5.printBill();
    cout<<"Your receipt is already printed you can get it from filr path\n"<<endl;
    cout<<"to display the your receipt in the screen , Enter 1: or Enter anothe key to back main menu:";
    cin>>gotoMenu;
    if(gotoMenu==1){
        system("CLS");
        a5.showBill();
        cout<<"\nPress 1 to redirect main menu: ";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1){
            menu();

        }
        else {
            menu();
        }
    }
    else{
        system("CLS");
        menu();
    }
}
else if(mainChoice==5){
    cout<<"--GOOD-BYE--"<<endl;
    Sleep(999);
    system("CLS");
    menu();
}
else{
     cout<<"\nInvalid input! redirecting to previous menu \n please wait"<<endl;
                Sleep(1100);
                system("CLS");
                menu();
}
}





int main()
{
    ManageMenu startObj;

    return 0;
}