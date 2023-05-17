#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
// #include <cstdlib>
#include <cstring>
// #include <cstdio>
using namespace std;

class TicketBooking
{  

    public:
        string passengerName;
        long long mobileNumber=0;
        int age=0;
        char sex;
        string departure;
        string arrival;
        char date[20];
        int menuChoice=0;
        int departureCount=0,departureChoice=0,arrivalChoice=0,arrivalCounter=0;
        int nameCheckCounter=0,ageCheckCounter=0,sexCheckCounter=0,mobileCheckCount=0;

    public:


void intro () {
    cout << " ======================================================== " << endl; 
    cout << " |              Welcome to Delta Airlines!              |  " << endl; 
    cout << " |                         ^                            |  " << endl; 
    cout << " |                      /    \\                          |  " << endl;
    cout << " |                     //  V \\\\                         |  " << endl; 
    cout << " |                    /   \\|/  \\                        |  " << endl; 
    cout << " |                   ///   v  \\\\\\                       |  " << endl; 
    cout << " |                  /            \\                      |  " << endl; 
    cout << " |                 /              \\                     |  " << endl; 
    cout << " |                /                \\                    |  " << endl; 
    cout << " |               /   /|        |\\   \\                   |  " << endl;
    cout << " |              /   /  \\      /  \\   \\                  |  " << endl;
    cout << " |              \\  /    X    X    \\  /                  |  " << endl;
    cout << " |               \\/    / \\  / \\    \\/                   |  " << endl; 
    cout << " |                   /    V    \\                        |  " << endl; 
    cout << " |                  |           |                       |  " << endl;
    cout << " |                                                      |  " << endl;
    cout << " |                 Let's Start Your                     |  " << endl; 
    cout << " |                 Booking Journey!                     |  " << endl; 
    cout << " |                       :}                             |  " << endl; 
    cout << " ======================================================== " << endl; 

}

void setMenuChoice(){
    cout<<"\n\n";
    cout<<"chooce from the following menu"<<endl;
    cout<<"1. Book a fligt"<<endl;
    cin>>menuChoice;
    cin.ignore(INT_MAX,'\n');
}

void executeMenuChoice(){
    if(menuChoice==1){
            do{
            nameCheckCounter=0;
            cout<<"Please Enter Your Name: "<<endl;
            getline(cin,passengerName);
            if(passengerName.empty()){
                cout<<"Dont leave the space blank";
                cin.ignore();
                nameCheckCounter++;
            } else{
                char checkPassengerName[30];

            strcpy(checkPassengerName,passengerName.c_str());

            for(int i=0;i<strlen(checkPassengerName);i++){
                if(checkPassengerName[i]>=48 && checkPassengerName[i]<=57){
                    cout<<"Sorry, Your Name is in the wrong format"<<endl;
                    nameCheckCounter++;
                    break;
                }
            }
            } 
            }while(nameCheckCounter!=0);



            do{
            mobileCheckCount=0;
            cout<<"Please Enter your Mobile Phone Number: "<<endl;
            if(!(cin>>mobileNumber)){ 
            cout<<"Please make sure all are Numbers!";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            mobileCheckCount++;}

            cin.ignore();
            }while(mobileCheckCount!=0);
       


            
     

            do{
            cin.ignore();
            ageCheckCounter=0;

            cout<<"Enter your age: ";

            if (!(cin >> age))
            {
                cout << "That's not an integer. Try again." << endl;
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                ageCheckCounter++;
            }
            
            else if (age <= 18)
            {
                cout << "You are too young to book a ticket!" << endl;
                cin.ignore();
                ageCheckCounter++;
            }
            else if (age >= 120)
            {
                cout << "Please input a reasonable age." << endl;
                cin.ignore();
                ageCheckCounter++;
            }
            

            }while(ageCheckCounter!=0);


            do
            {
            sexCheckCounter=0;
            cout<<"Enter M if you are a male and F if you are Female: ";
            cin>>sex;
            if(!((sex=='M' || sex=='m') || (sex=='F' || sex=='f'))){
                cout<<"Sex is not in the correct format";
                cin.ignore();
                sexCheckCounter++;
            }

            }while (sexCheckCounter!=0);
            





            do{
           departureCount=0;
            cout<<"Delta Airlines has departure stations in the following places. Choose any of these departure points:"<<endl;
            cout<<"1. Spokane\n";
            cout<<"2. Seattle\n";
            cout<<"3. Minnesota\n";
            cout<<"4. Florida\n";
            cout<<"5. San Francisco\n";

            
            cin>> departureChoice;
             

            switch(departureChoice){
                case 1:
                    departure="Spokane";
                    break;
                case 2:
                    departure="Seattle";
                    break;
                case 3:
                    departure="Minnesota";
                    break;
                case 4:
                    departure="Florida";
                    break;
                case 5:
                    departure="Nanda";
                    break;
                default:
                    cout<<"You entered an Invalid choice. Please choose from the Cities provided. 1 through 5"<<endl;
                    cin.ignore();
                    departureCount++;
                    
            }
            cin.ignore();
            }while(departureCount!=0); 


            do{
            arrivalCounter=0;
            cout<<"Delta Airlines has arrival stations in the following places. Choose any of these arrival poiunts:"<<endl;
            cout<<"1. Kotoka\n";
            cout<<"2. Heathrow\n";
            cout<<"3. Hamad\n";
            cout<<"4. Istanbul\n";
            cout<<"5. J.F Kennedy\n";

            cin>> arrivalChoice;
            

            switch(arrivalChoice){
                case 1:
                    arrival="Kotoka";
                    break;
                case 2:
                    arrival="Heathrow";
                    break;
                case 3:
                    arrival="Hamad";
                    break;
                case 4:
                    arrival="Istanbul";
                    break;
                case 5:
                    arrival="J.F Kennedy";
                    break;
                default:
                    cout<<"You entered an Invalid choice. Please choose from the Cities provided. 1 through 5"<<endl;
                    arrivalCounter++;
                    cin.ignore();
            }
            cin.ignore();
            }while(arrivalCounter!=0); 

        cout<<"What date do you wish to commernce your journey (MM/DD/YYYY)?";
        cin>>date; 


        }
    }
    
void displayInfo(){
    cout<<setw(10)<<passengerName<<setw(10)<<age<<setw(10)<<mobileNumber<<setw(10)<<date<<setw(10)<<sex<<setw(10)<<departure<<setw(10)<<arrival<<"\n\n\n";
        }

 void printToFile(){
            fstream f1;
            f1.open("flightInfo.csv",ios::app);
            f1<<"Passenger Name"<<","<<"Age"<<","<<"Mobile Number"<<","<<"Sex"<<","<<"Date"<<","<<"Departure"<<","<<"Arrival"<<"\n";
            f1<<passengerName<<","<<age<<","<<mobileNumber<<","<<sex<<","<<date<<","<<departure<<","<<arrival<<"\n";
            f1.close();
        }

void printTicket() {

    cout << "\t\t\t###################################################################################\n";
    cout << "\t\t\t                           DELTA AIRLINE SERVICES                                 \n";
    cout << "\t\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t\t               Name                                  Age                             \n";
    cout << "\t\t\t        "<<passengerName<<"                              "<<age<<"                    \n";
    cout << "\t\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t\tMobile Number : "<<mobileNumber<<"\t\t\t   Date : "<<date<<"              \n";
    cout << "\t\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t\tDeparture : "<<departure<<"\t\t\t          Arrival : "<<arrival<<"\t\t  \n";
    cout << "\t\t\t###################################################################################\n";
}



    };

int main(){

        
        TicketBooking obj;
        obj.intro();
        obj.setMenuChoice();
        obj.executeMenuChoice();
        obj.displayInfo();
        obj.printToFile();
        obj.printTicket();
       



        return 0;

        
}
