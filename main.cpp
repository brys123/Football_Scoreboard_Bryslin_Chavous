//Bryslin Chavous
//Programming C++ II
//11/29/2020
//Dr. Tyson McMillan

#include <iostream>
#include <string> 
#include <unistd.h>
using namespace std; 

class Team 
{
  private:
    string name;
    string coachName;
    string homeCity;
    bool homeStatus; 
    int score; 
    int timeoutCount;

  public:
      Team() //default constructor 
      {
        name = "DefaultTeamName";
        coachName = "DefaultCoach";
        homeCity = "DefaultCity";
        homeStatus = false; //visitor = false, home = true
        score = 0;
        timeoutCount = 0;
      }
      void setName(string n) { name = n; } //setters
      void setcoachName(string c) { coachName = c; }
      void sethomeCity(string hc) { homeCity = hc; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setScore(int s) { score = s; }
      void settimeoutCount(bool t) { timeoutCount = t; }

      string getName() const { return name; } //getters
      string getcoachName() const { return coachName;}
      string gethomeCity() const { return homeCity;}
      bool getHomeStatus() const { return homeStatus; }
      int getScore() const { return score; }
      int gettimeoutCount() const { return timeoutCount;}
};

class Scoreboard
{
  private:
    int half; 
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score1 = "\x1b[36;1m"; //score color 
      string score2 = "\x1B[31m"; //score color
      cout << color << "\t\tFOOTBALL_SCOREBOARD" << reset << endl; 
      cout << home.getName() << "\t\t\t" << visitor.getName() << endl; 
      cout << score1 << home.getScore() << reset << "\t\t\t\t\t\t" << //display scores
              score2 << visitor.getScore() << reset << endl;
      cout << home.gettimeoutCount() << "\t\t\t\t\t\t" << //display timeout count
      visitor.gettimeoutCount() << endl;
      
    }
};

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