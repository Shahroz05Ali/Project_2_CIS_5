/* 
 * File:   main.cpp
 * Author: Shahroz Ali
 * Created on May 5, 2021, 1:20 PM
 * Purpose:  Black Jack
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const string crdVal="A234567890JQK"; //cards for the game
    const string crdSymb="CHSD";//symbol for card
    bool  play=false; //variable to check if the play again
    string dealer=""; // dealer hand 
    string Player1=""; // player hand
    char  usrinpt; // what the user is going to input
    int  drawNmb; // draw number
    int  drawSym; // draw symbol
    int  delrSum=0; // dealers total
    int  plyrSum=0; // players total 
    ofstream logfile;
    logfile.open("log.txt");
    //Initialize or input i.e. set variable values
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Welcome to Black Jack"<<endl;
    logfile<<"Welcome to Black Jack"<<endl;
    do{ 
        cout<<"Do you want to play or exit the game"<<endl;
        logfile<<"Do you want to play or exit the game"<<endl;
        cout<<"Hit 1 to play or Hit 2 to quit"<<endl;
        logfile<<"Hit 1 to play or Hit 2 to quit"<<endl;
        cin>>usrinpt;               //get the user input for the response
        if(usrinpt=='1')play=true;  //if you want to play set play to true
        else play=false;
        //Map inputs -> outputs
        if (play){
           drawNmb=rand()%13;
           drawSym=rand()%4;
           if(drawNmb>9){
               delrSum=10;
               
           }else{
               delrSum=drawNmb+1;
           }
           if (drawNmb==9){
              dealer="10 "; 
           }else {
               dealer=crdVal[drawNmb];
               dealer+=" ";
           }
           if (drawSym==0){
               dealer+="Clubs ";
           } else if (drawSym==1){
               dealer+="Hearts ";
           } else if (drawSym==2){
               dealer+="Spade ";
           } else if (drawSym==3){
               dealer+="Diamonds ";
           }
           cout<<"The dealer cards are: "<<dealer<<endl;

           drawNmb=rand()%13;
           drawSym=rand()%4;
            if(drawNmb>9){
               delrSum+=10;
               
           }else{
               delrSum+=drawNmb+1;
           }
           if (drawNmb==9){
              dealer+="10 "; 
           }else {
               dealer+=crdVal[drawNmb];
               dealer+=" ";
           }
           if (drawSym==0){
               dealer+="Clubs ";
           } else if (drawSym==1){
               dealer+="Hearts ";
           } else if (drawSym==2){
               dealer+="Spade ";
           } else if (drawSym==3){
               dealer+="Diamonds ";
           }
           
           for (int i=0; i<2; i++){
                drawNmb=rand()%13;//draw random card
                drawSym=rand()%4;//draw random symbol
                if(drawNmb>9){
                    plyrSum+=10;

                }else{
                    plyrSum+=drawNmb+1;
                }
                if (drawNmb==9){
                   Player1+="10 "; 
                }else {
                    Player1+=crdVal[drawNmb];
                    Player1+=" ";
                }
                if (drawSym==0){
                    Player1+="Clubs ";
                } else if (drawSym==1){
                    Player1+="Hearts ";
                } else if (drawSym==2){
                    Player1+="Spade ";
                } else if (drawSym==3){
                    Player1+="Diamonds ";
                } 
           }
           
           cout<<"Your cards are: "<<Player1<<endl;
           logfile<<"Your cards are: "<<Player1<<endl;
           cout<<"Do you want to draw another card"<<endl;
           logfile<<"Do you want to draw another card"<<endl;
           cout<<"Hit 1 to draw or hit any other thing on keyboard to not draw"<<endl;
           logfile<<"Hit 1 to draw or hit any other thing on keyboard to not draw"<<endl;
           cin>>usrinpt;
           
           while(usrinpt=='1'&& plyrSum<21){
                drawNmb=rand()%13;
                drawSym=rand()%4;
                if(drawNmb>9){
                    plyrSum+=10;

                }else{
                    plyrSum+=drawNmb+1;
                }
                if (drawNmb==9){
                   Player1+="10 "; 
                }else {
                    Player1+=crdVal[drawNmb];
                    Player1+=" ";
                }
                if (drawSym==0){
                    Player1+="Clubs ";
                } else if (drawSym==1){
                    Player1+="Hearts ";
                } else if (drawSym==2){
                    Player1+="Spade ";
                } else if (drawSym==3){
                    Player1+="Diamonds ";
                } 
                cout<<"Your cards are: "<<Player1<<endl;
                logfile<<"Your cards are: "<<Player1<<endl;
                cout<<"Do you want to draw another card"<<endl;
                logfile<<"Do you want to draw another card"<<endl;
                cout<<"Hit 1 to draw or hit any other thing on keyboard to not draw"<<endl;
                logfile<<"Hit 1 to draw or hit any other thing on keyboard to not draw"<<endl;
                cout<<"You can draw as long as the sum is less than 21"<<endl;
                logfile<<"You can draw as long as the sum is less than 21"<<endl;
                cin>>usrinpt;
           }
           if (plyrSum<=21){
               while(delrSum<17){
                    drawNmb=rand()%13;
                    drawSym=rand()%4;
                    if(drawNmb>9){
                        delrSum+=10;

                    }else{
                        delrSum+=drawNmb+1;
                    }
                    if (drawNmb==9){
                       dealer+="10 "; 
                    }else {
                        dealer+=crdVal[drawNmb];
                        dealer+=" ";
                    }
                    switch(drawSym){
                        case 0:dealer+="Clubs ";break;
                        case 1:dealer+="Hearts ";break;
                        case 2:dealer+="Spade ";break;
                        case 3:dealer+="Diamonds ";break;
                    }
                
               }cout<<"The dealer cards are: "<<dealer<<endl;
               logfile<<"The dealer cards are: "<<dealer<<endl;
               if (plyrSum>delrSum || delrSum>21){
                   cout<<"Player 1 wins"<<endl;
                    
               }else if(delrSum>plyrSum){
                   cout<<"Dealer 1 wins"<<endl;

               }else{
                   cout<<"It is a draw"<<endl;
                  
               }
           }
           else{
               cout<<"Dealer Wins"<<endl;
           }
            cout<<"Your cards are: "<<right<<setw(50)<<Player1<<endl;
            logfile<<"Your cards are: "<<right<<setw(50)<<Player1<<endl;
            cout<<"Your Sum is:    "<<right<<setw(50)<<plyrSum<<endl;
            logfile<<"Your Sum is:    "<<right<<setw(50)<<plyrSum<<endl;
            cout<<"Dealer hands:   "<<right<<setw(50)<<dealer<<endl;
            logfile<<"Dealer hands:   "<<right<<setw(50)<<dealer<<endl;
            cout<<"Dealer Sum:     "<<right<<setw(50)<<delrSum<<endl;
            logfile<<"Dealer Sum:     "<<right<<setw(50)<<delrSum<<endl;
            usrinpt='1';
            delrSum=0;
            plyrSum=0;
            dealer="";
            Player1="";
        }else {
            cout<<"Leaving the game now"<<endl;
            logfile<<"Leaving the game now"<<endl;
        }
        
    }while(play);
                
         
    //Display the outputs

    //Exit stage right or left!
    return 0;
}