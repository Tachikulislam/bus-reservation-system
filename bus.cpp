#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

//Passenger details
typedef struct
{
    char name[50];
    int bus_num;
    int num_of_seats;
    int phonenum;
} pd;

//All Functions
void login();
void reservation(void);
void viewdetails(void);
void viewdetailss(void);
void printticket(char name[ ],int,int,int,float);
void specificbus(int);
void displayReservedSeats(void);
void cancelReservation(void);
float charge(int,int);
void exitProgram(void);
void forget();
void registration();
void access();
void Passenger_login();
void cus();
bool cl=true;
bool error = true;
bool reserve = false;

int main()
{
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t";
    string unch = "BUS TICKET RESERVATION SYSTEM";
    for (char ch : unch)
    {
        cout << ch;
        Sleep(150);
    }
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t============================= \n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t         Developed By Team Alpha_001";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================= \n";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Press Enter to Enter the System.....";
    getch();
    system("cls");
    access();
}

//Access Function
void access()
{
    system("cls");
    cout << "\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t=====================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t       Welcome To Our System";
    cout<<"\n\t\t\t\t\t\t\t\t\t=====================================\n";
    cout<<"\n                                 \n";
    cout << "\n\n\n\t\t\t\t\t\t\tPress 1 to Registration\n\n";
    cout << "\t\t\t\t\t\t\tPress 2 to Login\n\n";
    cout << "\t\t\t\t\t\t\tPress 3 to If forget password\n\n\n";
    cout << "\t\t\t\t\t\t\tEnter your option : ";
    int x;
    cin >> x;
    if (x == 1)
    {
        registration();
    }
    else if (x == 2)
    {
        Passenger_login();
    }
    else if (x==3)
    {
        forget();
    }
}

//Registration Function
void registration()
{
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t******** REGISTRATION FORM ******** \n\n";

    string f_name, f_pass, f_id;
    string user_name, user_pass, user_id;
    cout << "\n\n\n\t\t\t\t\t\t| Enter your Username: ";
    cin >> user_name;
    cout << "\n\t\t\t\t\t\t| Enter your Nickname: ";
    cin >> user_id;

    int check = 1;
    ifstream myFile("information.txt");
    while(myFile >> f_name >> f_pass >> f_id)
    {
        if(f_name == user_name)
        {
            check = 0;
            break;
        }
    }
    myFile.close();

    if(check == 0)
    {
        cout<<"\n\n\t\t\t\t\t!!!!!! There already exist a profile with this name !!!!!!"<<endl;
        cout<<"\t\t\t\t\t\t______Please Chose Another Username______\n\n"<<endl;

        char y_n;
        cout << "\t\t\t\t\t\t DO YOU WANT TO REGISTER AGAIN ? (Y/N): ";
        cin >> y_n;
        if (y_n == 'y')
        {
            registration();
        }
        else
        {
            access();
        }
    }
    else
    {
        int alphabate=0, number=0, symbol=0;
        while(true)
        {
            cout << "\n\t\t\t\t\t\t| Enter your Password: ";
            cin >> user_pass;

            if(user_pass.size()>=8)
            {
                for(int i=0; i<user_pass.size(); i++)
                {
                    if(user_pass[i]>='A' && user_pass[i]<='Z' || user_pass[i]>='a' && user_pass[i]<='z') alphabate++;
                    else if(user_pass[i]>='0' && user_pass[i]<='9') number++;
                    else symbol++;
                }
                if(alphabate>0 && number>0 && symbol>0)
                {
                    break;
                }
                else
                {
                    cout << "\033[F\033[K\n\n\n\t\t\t\t\tPassword Must Include Alphabates, Numbers and symbols\n"<<endl;
                    cout << "\033[5A";
                }
            }
            else
            {
                cout << "\033[F\033[K\n\n\n\t\t\t\t\tPassword must include at least 8 character\n"<<endl;
                cout << "\033[5A";
            }
        }
        ofstream myFile("information.txt",ios::app);
        myFile<<"\n"<<user_name<<" "<<user_pass<<" "<<user_id<<" "<<endl;
        myFile.close();

        cout << endl << endl;
        string success_messege = "\t\t\t\t\033[K\t\t REGISTRATION SUCCESSFULL !";
        for (char ch : success_messege)
        {
            cout << ch;
            Sleep(50);
        }
        cout << endl << endl;

        char y_n;
        cout << "\n\t\t\t\t\t\t DO YOU WANT TO LOGIN NOW (Y/N): ";
        cin >> y_n;
        if (y_n == 'y')
        {
            Passenger_login();
        }
        else
        {
            access();
        }
    }

}

//Passenger Login Function
void Passenger_login()
{
    system("cls");
    string f_name, f_pass, f_id, u_name, u_pass;
    string copy_name;
    int flag = 0;

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t=====================================\n";
    cout << "\t\t\t\t\t\t\t\t\t\t             LOGIN FORM";
    cout << "\n\t\t\t\t\t\t\t\t\t\t=====================================\n\n\n\n";
    cout << "\n\t\t\t\t        Enter Username: ";
    cin >> u_name;
    cout << "\n\t\t\t\t        Enter Password: ";
    cin >> u_pass;

    ifstream myFile("information.txt");

    while (myFile >> f_name >> f_pass >> f_id)
    {
        if (u_name == f_name && u_pass == f_pass)
        {
            copy_name = u_name;
            flag = 1;
            cl = true;
            break;
        }
    }
// Login success or denide
    cout << endl
         << endl;
    if (flag)
    {
        string suc = "\n\n\t\t\t\t\t>_< LOGIN SUCCESSFULL >_<!!!";

        for (char ch : suc)
        {
            cout << ch;
            Sleep(50);
        }
        system("cls");
        cus();
    }
    else
    {
        string unc = "\t\t\t\t\tINVALID USERNAME AND PASSWORD PLEASE TRY AGAIN >_<";
        for (char ch : unc)
        {
            cout << ch;
            Sleep(50);
        }
    }
    getch();
    Passenger_login();
}

//Forget Function
void forget()
{
    string userName, id;
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t=================================\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t          PASSWORD RECOVER  ";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t=================================\n\n\n\n";
    cout << "\n\t\t\t\t\t Enter your username: ";
    cin >> userName;
    cout << "\t\t\t\t\t Enter your Nickname : ";
    cin >> id;

    ifstream myFile("information.txt");

    string f_username, f_id, f_pass;
    int flag = 1;
    while (myFile >> f_username >> f_pass >> f_id)
    {
        if (f_username == userName && f_id == id)
        {
            cout << "\n\n\t\t\t\t\t Your name is: " << f_username;
            cout << "\n\t\t\t\t\t Your password is: " << f_pass << endl
                 << endl;
            flag=1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
            cout<<"\n\n\n\t\t\t\t\tYOUR GIVEN INFORMATION IS WRONG\n\n";
    getch();
    access();
}

//Customer Function
void cus()
{
    if(cl)
    {
        int menu_choice;
start:
        system("cls");
        if(error)
        {
             cout << "\n\n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t\t    BUS TICKET RESERVATION SYSTEM";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================\n";
            cout<<"\n\n\n                                 \n";
            cout<<"\n\t\t\t\t\t\t1.Reserve Tickets\n";
            cout<<"\n\t\t\t\t\t\t2.View All Available Bus\n";
            cout<<"\n\t\t\t\t\t\t3.View Your Reservation Ticket\n";
            cout<<"\n\t\t\t\t\t\t4.Cancel Your Booking\n";
            cout<<"\n\t\t\t\t\t\t5.Exit\n\n\n\n";
            cout<<"\n\n\t\t\t\t\t\t Enter your Choice: ";
            cin >> menu_choice;
            switch (menu_choice)
            {
            case 1:
                reservation();
                break;
            case 2 :
                viewdetails();
                break;
            case 3 :
                displayReservedSeats();
                break;
            case 4 :
                cancelReservation();
                break;
            case 5 :
                exitProgram();

            default:
                system("cls");
                cout << "\nInvalid choice";
                cout << "\nPress Enter to continue.....";
                getch();
            }
        }
    }
}

//Reservation Function
void reservation(void)
{
    char confirm;
    float charges;
    pd passdetails;
    FILE *fp;
    fp=fopen("seats_reserved.txt","a");
    system("cls");

    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t=====================================\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t\t           Reserve Seat  ";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================\n\n\n\n";
    cout<<"\n\t\t\t\t\tEnter Your Name: ";
    fflush(stdin);
    gets(passdetails.name);

start3:
    char phn[15];
    cout<<"\n\t\t\t\t\tEnter Your Phone Number: ";
    cin>>phn;
    int phnn=strlen(phn);
    if(phnn!=11)
    {
        cout<<"\n\t\t\t\t\tEnter a valid Phone Number..\n";
        goto start3;
    }
    passdetails.phonenum=stoi(phn);
    cout<<"\n\t\t\t\t\tPress Enter To View Available Bus... ";
    getch();
    system("cls");
    viewdetailss();
start1:
    bool con=false;
    cout<<"\n\n\n\t\t\t\t\tEnter Bus number: ";
    cin>>passdetails.bus_num;
    if(passdetails.bus_num>=1001 && passdetails.bus_num<=1010)
    {
        con=true;
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tInvalid bus Number! Enter again..... ";
        getch();
        goto start1;
    }

start2:
    cout<<"\n\n\t\t\t\t\tEnter Number of seats: ";
    cin>>passdetails.num_of_seats;
    if(passdetails.num_of_seats>30)
    {
        cout<<"\n\n\t\t\t\t\tYour Seats number are exceed"<<endl;
        goto start2;
    }

    if(con==true)
    {
        charges=charge(passdetails.bus_num,passdetails.num_of_seats);
        printticket(passdetails.name,passdetails.phonenum,passdetails.num_of_seats,passdetails.bus_num,charges);
    }
    cout<<"\n\n\t\t\t\t\tConfirm Ticket (Y/N):>";
start:
    cin>>confirm;
    if(confirm == 'y'||'Y')
    {
        system("cls");
        fprintf(fp,"%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.phonenum,passdetails.num_of_seats,passdetails.bus_num,charges);
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t ========================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t     Reservation Done\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ========================\n\n";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tThanks for using Our System\n";
        cout<<"\n\n\n\t\t\t\t\t\tPress Enter to go back to Main menu.....";
    }
    else
    {
        if(confirm=='n'||'N')
        {
            cout<<"\n\t\t\t\tReservation Not Done!\n\t\t\t\tPress Enter to go back to Main menu!";
        }
        else
        {
            cout<<"\nInvalid choice entered! Enter again----- ";
            getch();
            goto start;
        }
    }
    fclose(fp);
    getch();
    cus();

}

//Calculating the price
float charge(int bus_num,int num_of_seats)
{
    if (bus_num==1001)
    {
        return(1200.0*num_of_seats);
    }
    if (bus_num==1002)
    {
        return(900.0*num_of_seats);
    }
    if (bus_num==1003)
    {
        return(1800.0*num_of_seats);
    }
    if (bus_num==1004)
    {
        return(1400.0*num_of_seats);
    }
    if (bus_num==1005)
    {
        return(1500.0*num_of_seats);
    }
    if (bus_num==1006)
    {
        return(1000.0*num_of_seats);
    }
    if (bus_num==1007)
    {
        return(500.0*num_of_seats);
    }
    if (bus_num==1008)
    {
        return(700.0*num_of_seats);
    }
    if (bus_num==1009)
    {
        return(1200.0*num_of_seats);
    }
    if (bus_num==1010)
    {
        return(2000.0*num_of_seats);
    }
}

//PrintTicket Function
void printticket(char name[],int phonenum,int num_of_seats,int bus_num,float charges)
{
    system("cls");
    time_t timetoday;
    time (&timetoday);
    cout <<"\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t     TICKET\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t================\n\n";
    cout <<"\n\n";
    cout<<"\n\t\t\t\t\tName:\t\t\t"<<name;
    cout<<"\n\t\t\t\t\tPhone Number:\t\t+880"<<phonenum;
    cout<<"\n\t\t\t\t\tNumber Of Seats:\t"<<num_of_seats;
    cout<<"\n\t\t\t\t\tBus Number:\t\t"<<bus_num;

    //Calling the Specific Bus
    specificbus(bus_num);

    cout<<"\n\t\t\t\t\tCharges:\t\t"<<charges<<" tk";
    cout <<"\n\t\t\t\t\tTicket print time:\t"<< asctime(localtime(&timetoday));
}

//View All Buses in Reservation Section
void viewdetailss(void)
{
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t=====================================\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t\t           Reserve Seat  ";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================";
    cout<<"\n\n\t\t\t\t----------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tBus.No\t\tName\t\tCategory\tDestinations\t\tCharges\t    Seats No  Starting Time     Arrival Time \n";
    cout<<"\t\t\t\t----------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t1001\t    ROYAL  Express          A/C         Dhaka to Chittagong     Tk.1200\t\t30\t 9:00AM        \t3:45PM";
    cout<<"\n\t\t\t\t1002\t    DHAKA  Express          Non A/C     Dhaka To Rajshahi       Tk.900\t\t30\t 2:00PM        \t6:30PM";
    cout<<"\n\t\t\t\t1003\t    SELFI  Express          S Coach     Dhaka To Khulna         Tk.1800\t\t30\t 7:00AM        \t4:00PM";
    cout<<"\n\t\t\t\t1004\t    JR Express              A/C         Dhaka To Cox's Bazar    Tk.1400\t\t30\t 3:00PM        \t10:45PM";
    cout<<"\n\t\t\t\t1005\t    BUBT  Express           S Coach     Dhaka To Sajek          Tk.1500\t\t30\t 7:00AM        \t3:15PM";
    cout<<"\n\t\t\t\t1006\t    SHAPLA  Express         A/C         Dhaka To Sylhet         Tk.1000\t\t30\t 9:30AM        \t3:45PM";
    cout<<"\n\t\t\t\t1007\t    AKOTA  Express          Non A/C     Dhaka To Barisal        Tk.500\t\t30\t 1:00PM        \t6:30PM";
    cout<<"\n\t\t\t\t1008\t    BD  Express             A/C         Dhaka To Dinajpur       Tk.700\t\t30\t 4:00PM        \t10:30AM";
    cout<<"\n\t\t\t\t1009\t    UNITY  Express          A/C         Dhaka To Rajshahi       Tk.1200\t\t30\t 3:35PM        \t2:15AM";
    cout<<"\n\t\t\t\t1010\t    ALPHA Express           S Coach     Dhaka To India          Tk.3500\t\t30\t 4:15PM        \t9:30PM";
    cout<<"\n\n\n";
    cout<<"\n\t\t\t\t\tPress Enter to continue..... ";
    getch();
}

//Specific Bus Function
void specificbus(int bus_num)
{
    if (bus_num==1001)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tROYAL  Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Chittagong";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t9AM ";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t3.45PM";
    }
    if (bus_num==1002)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tDHAKA  Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Rajshahi";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t2:00PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t6:30PM ";
    }
    if (bus_num==1003)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tSELFI Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Khulna";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t7:00AM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t4:00PM";
    }
    if (bus_num==1004)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tJR Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Cox's Bazar";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t3:00PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t10:45PM";
    }
    if (bus_num==1005)
    {
        cout<<"\nBus Name:\t\tBUBT Express";
        cout<<"\nDestination:\t\tDhaka to Sajek";
        cout<<"\nStarting Time:\t\t7:00AM";
        cout<<"\nArrival Time:\t\t3:15PM ";
    }
    if (bus_num==1006)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tSHAPLA Express ";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Sylhet";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t9:30AM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t3:45PM";
    }
    if (bus_num==1007)
    {
        cout<<"\n\t\t\t\t\tBusName:\t\tAKOTA Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Barisal";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t1:00PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t6:30PM";
    }
    if (bus_num==1008)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tBD Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Dinajpur";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t4:00PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t10:30AM";
    }
    if (bus_num==1009)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\tUNITY Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to Rajshahi";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t3:35PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t2:15AM";
    }
    if (bus_num==1010)
    {
        cout<<"\n\t\t\t\t\tBus Name:\t\t\tALPHA Express";
        cout<<"\n\t\t\t\t\tDestination:\t\tDhaka to India";
        cout<<"\n\t\t\t\t\tStarting Time:\t\t4:15PM";
        cout<<"\n\t\t\t\t\tArrival Time:\t\t9:30PM";
    }
}

//View All Buses
void viewdetails(void)
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\tView All Buses";
    cout<<"\n\n\n\t\t\t\t----------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tBus.No\t\tName\t\tCategory\tDestinations\t\tCharges\t    Seats No  Starting Time     Arrival Time \n";
    cout<<"\t\t\t\t----------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t1001\t    ROYAL  Express          A/C         Dhaka to Chittagong     Tk.1200\t\t30\t 9:00AM        \t3:45PM";
    cout<<"\n\t\t\t\t1002\t    DHAKA  Express          Non A/C     Dhaka To Rajshahi       Tk.900\t\t30\t 2:00PM        \t6:30PM";
    cout<<"\n\t\t\t\t1003\t    SELFI  Express          S Coach     Dhaka To Khulna         Tk.1800\t\t30\t 7:00AM        \t4:00PM";
    cout<<"\n\t\t\t\t1004\t    JR Express              A/C         Dhaka To Cox's Bazar    Tk.1400\t\t30\t 3:00PM        \t10:45PM";
    cout<<"\n\t\t\t\t1005\t    BUBT  Express           S Coach     Dhaka To Sajek          Tk.1500\t\t30\t 7:00AM        \t3:15PM";
    cout<<"\n\t\t\t\t1006\t    SHAPLA  Express         A/C         Dhaka To Sylhet         Tk.1000\t\t30\t 9:30AM        \t3:45PM";
    cout<<"\n\t\t\t\t1007\t    AKOTA  Express          Non A/C     Dhaka To Barisal        Tk.500\t\t30\t 1:00PM        \t6:30PM";
    cout<<"\n\t\t\t\t1008\t    BD  Express             A/C         Dhaka To Dinajpur       Tk.700\t\t30\t 4:00PM        \t10:30AM";
    cout<<"\n\t\t\t\t1009\t    UNITY  Express          A/C         Dhaka To Rajshahi       Tk.1200\t\t30\t 3:35PM        \t2:15AM";
    cout<<"\n\t\t\t\t1010\t    ALPHA Express           S Coach     Dhaka To India          Tk.3500\t\t30\t 4:15PM        \t9:30PM";
    cout<<"\n\n\n\n";
    cout<<"\n\t\t\t\t\tPress Enter to go back to the main menu....";
    getch();
    cus();
}

//Display Reserve Seats
void displayReservedSeats()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t==============================\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t        RESERVED SEATS\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t==============================\n\n";
    cout<<"\n\t\t\t\tWrite your name for view your reserve tickets: ";
    char rename[50];
    cin>>rename;
    bool res;
    FILE* fp;
    fp = fopen("seats_reserved.txt", "r");

    if (fp == NULL)
    {
        cout << "\n\t\t\t\tNo seats have been reserved yet.\n";
    }
    else
    {
        char name[50];
        int num_of_seats, bus_num,phone_num;
        float charges;
        while (fscanf(fp, "%s %d %d %d %f", name,&phone_num, &num_of_seats, &bus_num, &charges) != EOF)
        {
            if(strcmp(name,rename)==0)
            {
                cout <<"\n\n\n";
                cout << "\n\t\t\t\tName\t\tPhoneNumber\t\tSeats\t\tBus Number\tCharges\n";
                cout << "\n\t\t\t\t---------------------------------------------------------------------------------\n";
                cout <<"\n\t\t\t\t"<< name <<"\t+880"<<phone_num<<"\t\t "<< num_of_seats <<"\t\t " << bus_num << "\t\t" << charges << "\n";
                res=true;
            }
            else
            {
                res=false;
            }
        }
        fclose(fp);
    }
    if(res==false)
    {
        cout<<"\n\n\n\t\t\t\tInvalid Username"<<endl;

    }
    cout << "\n\n\n\n\t\t\t\tPress Enter to go back to the main menu.... ";
    getch();
    cus();
}

//Cancel Reserve Seats
void cancelReservation()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t================================\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t     CANCEL RESERVED TICKET\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t================================\n\n\n";

    char cancelName[50];
    int busnum;
    bool found = false;
    cout << "\n\t\t\t\t\t\tEnter Passenger's Name to cancel reservation: ";
    cin.ignore();
    cin.getline(cancelName, 50);
    cout<<"\n\t\t\t\t\t\tEnter your Bus Number to cancel reservation: ";
    cin>>busnum;
    FILE* fp;
    FILE* tempFp;
    fp = fopen("seats_reserved.txt", "r");
    tempFp = fopen("temp_seats_reserved.txt", "w");
    if (fp == NULL)
    {
        cout << "\n\t\t\t\t\t\tNo seats have been reserved yet.\n";
    }
    else
    {
        char name[50];
        int num_of_seats, bus_num,phone_num;
        float charges;
        while (fscanf(fp, "%s %d %d %d %f", name,&phone_num, &num_of_seats, &bus_num, &charges) != EOF)
        {
            if (strcmp(name, cancelName) == 0 && busnum==bus_num)
            {
                found = true;
                cout << "\n\t\t\t\t\t\tReservation for " << name <<" and this "<<busnum<<" bus has been canceled.\n";
            }
            else
            {
                fprintf(tempFp, "%s %d %d %d %.2f\n", name,phone_num, num_of_seats, bus_num, charges);
            }
        }
        fclose(fp);
        fclose(tempFp);
        remove("seats_reserved.txt");
        rename("temp_seats_reserved.txt", "seats_reserved.txt");
        if (!found)
        {
            cout<<"\n\t\t\t\t\t\tNo reservation found for "<<cancelName<<"and"<<busnum<<".\n";
        }
    }
    cout << "\n\n\n\n\n\t\t\t\t\t\tPress Enter to go back to the main menu.... ";
    getch();
    cus();
}

//Exit Program
void exitProgram()
{
    system("cls");
    cout <<"\n\n\n";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  =======================================\n\n\n\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t    Exiting the Bus Reservation System...\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t    !Thank you for using the system!\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ====================================\n";
    cout<<" \t\t\t\t\t\t\t\t\t\t        WAIT FOR THE NEXT UPDATE";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t  ====================================\n";
    getch();
    exit(0);
}
