//Bryslin Chavous
//Programming C++ II
//11/29/2020
//Dr. Tyson McMillan

#include <iostream>
#include <string> 
#include <unistd.h>
#include "classes.h"
using namespace std; 

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl;
      cout << "C = Update Visitor Team Name" << endl; 
      cout << "D = Update Visitor Team Score" << endl;  
      cout << "E = Exit" << endl;
      cout << ">"; 
      cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for teh home team: "; 
        cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Visitor Name Module****" << endl; 
        cout << "\nPlease enter a new name for the visitor team: "; 
        cin >> newName; 
        tTwo.setName(newName);  //set the new name for tTwo        
      }
      else if(userChoice == "D" || userChoice == "d")
      {
        cout << "\nUpdate Visitor Score Module****" << endl; 
        cout << "\nPlease enter a new score for the visitor team: "; 
        cin >> newScore; 
        tTwo.setScore(newScore);  //set the new score for tTwo        
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); 
  
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
}