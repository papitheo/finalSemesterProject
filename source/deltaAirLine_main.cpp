#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;

class TicketBooking{

    public:
        string passengerName;
        long mobileNumber=0;
        int age=0;
        char sex;
        string departure;
        string arrival;
        char date[20];
        int count=0;

    public:
        void getPassengerInfo(){
            cout<<"Please Enter Your Name: ";
            getline(cin,passengerName);

            cout<<"Please Enter your Mobile Phone NUmber: ";
            cin>>mobileNumber;

            cout<<"Enter your age: ";
            cin>>age;

            cout<<"Enter M if you are a male and F if you are Female: ";
            cin>>sex;

        do{
            cout<<"Delta Airlines has departure stations in the following places. Choose any of these departure points:"<<endl;
            cout<<"1. Spokane\n";
            cout<<"2. Seattle\n";
            cout<<"3. Minnesota\n";
            cout<<"4. Florida\n";
            cout<<"5. San Francisco\n";

            int DepartureChoice;
            cin>> DepartureChoice;

            switch(DepartureChoice){
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
                    departure="Seattle";
                    break;
                default:
                    cout<<"You entered an Invalid choice. Please choose from the Cities provided. 1 through 5"<<endl;
                    count++;
            }

        }while(count!=0); 


        do{

            cout<<"Delta Airlines has arrival stations in the following places. Choose any of these arrival poiunts:"<<endl;
            cout<<"1. Kotoka\n";
            cout<<"2. Heathrow\n";
            cout<<"3. Hamad\n";
            cout<<"4. Istanbul\n";
            cout<<"5. J.F Kennedy\n";

            int DepartureChoice;
            cin>> DepartureChoice;

            switch(DepartureChoice){
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
                    count++;
            }

        }while(count!=0); 

        cout<<"What date do you wish to commernce your journey (MM/DD/YYYY)?";
        cin>>date; 


        }

        void displayInfo(){
            cout<<setw(10)<<passengerName<<setw(10)<<age<<setw(10)<<date<<setw(10)<<sex<<setw(10)<<departure<<setw(10)<<arrival<<setw(10);
        }

        void printToFile(){
            fstream f1;
            f1.open("flightInfo.txt");
            f1<<setw(10)<<passengerName<<setw(10)<<age<<setw(10)<<sex<<setw(10)<<date<<setw(10)<<departure<<setw(10)<<arrival<<setw(10);
            f1.close();
        }





};





int main(){

        
        TicketBooking obj;
        obj.getPassengerInfo();
        obj.displayInfo();
        obj.printToFile();
       



        return 0;
}
