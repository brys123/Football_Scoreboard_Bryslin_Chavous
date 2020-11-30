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
        name = "Default";
        coachName = "Coach";
        homeCity = "City";
        homeStatus = false; //visitor = false, home = true
        score = 0;
        timeoutCount = 0;
      }
      void setName(string n) { name = n; } //setters
      void setcoachName(string c) { coachName = c; }
      void sethomeCity(string hc) { homeCity = hc; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setScore(int s) { score = s; }
      void settimeoutCount(int t) { timeoutCount = t; }

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
     
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard(){}
    
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    
    
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
      cout << home.gethomeCity() << " " << home.getName() << "\t\t\t" << visitor.gethomeCity() << " " << visitor.getName() << endl;
      cout << "HOME" << "\t\t\t\t\t" << "VISITOR" << endl;
      cout << "\n  Score: " << score1 << home.getScore() << reset << "\t\t\t\t" << //display scores
              "  Score: " << score2 << visitor.getScore() << reset << endl;
      cout << "Timeout: " << home.gettimeoutCount() << "\t\t\t\t" << //display timeout count
              "Timeout: " << visitor.gettimeoutCount() << endl;
      
    }
};