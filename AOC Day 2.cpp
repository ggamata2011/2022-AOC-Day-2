#include <iostream>
#include <string>
//Use for file input and output
#include <fstream>
#include <algorithm>

using namespace std;

int Play(char Opp,char You);
int PredictedPlay(char Opp,char You);

int main()
{
//Input filestream
ifstream file;

char Opponent;
char Response;
int totalScore = 0;
int part2Score = 0;

file.open("input.txt");

while(file >> Opponent >> Response){

 //cout << "Opponent:" << Opponent << " Response:" << Response << endl;
 totalScore += Play(Opponent,Response);
 part2Score += PredictedPlay(Opponent,Response);
}

cout << "\nYour Score is:" << totalScore;
cout << "\nUpdated Score with updated rules is:" << part2Score;

}

// Simple Function to check Results and Return score
int Play(char Opp,char You)
{
  //Opponent Plays    Player Plays   Shape
  //   A                  X           Rock(1)
  //   B                  Y           Paper(2)
  //   C                  Z           Scissors(3)

  //All Plays that Opponent May Make
  switch(Opp){
  //Your Plays

  //Opponent Plays Rock
  case 'A':
      //Your Play
      switch(You){
      case 'X':
        //Draw Rock and Rock
        return 1+3;
      break;
      case 'Y':
        // Win Rock Loses to Paper
        return 2+6;
      break;
      case 'Z':
        //Lose Rock wins to Scissors
        return 3+0;
      break;
      }
  break;

  //Opponent Plays Paper
  case 'B':
     //Your Play
     switch(You){
     case 'X':
          //Lose, Paper beats Rock
          return 1+0;
     break;
     case 'Y':
         //Draw, Paper vs Paper
         return 2+3;
     break;
     case 'Z':
         //Win Paper Loses to Scissors
         return 3+6;
     break;
     }
  break;

  //Opponent Plays scissors
  case 'C':
      //Your Play
      switch(You){
      case 'X':
          //Win, Scissors Loses to Rock
          return 1+6;
      break;
      case 'Y':
          //Lose, Scissors wins to Paper
          return 2+0;
      break;
      case 'Z':
          //Draw, Scissors vs Scissors
          return 3+3;
      break;
      }
  break;
  }
}

// Simple Function to check Results and Return score
//Updated with new Rule set
int PredictedPlay(char Opp,char You)
{
  //Opponent Plays    Player Plays    Means         Hints:
  //   A                  X           Need Loss     Rock(1)
  //   B                  Y           Need Draw     Paper(2)
  //   C                  Z           Need Win      Scissors(3)

  //All Plays that Opponent May Make
  switch(Opp){
  //Your Plays

  //Opponent Plays Rock
  case 'A':
      //Your Play
      switch(You){
      case 'X':
        //Need Loss, pick scissors
        return 3+0;
      break;
      case 'Y':
        //Need Draw, pick rock
        return 1+3;
      break;
      case 'Z':
        //Need Win, pick paper
        return 2+6;
      break;
      }
  break;

  //Opponent Plays Paper
  case 'B':
     //Your Play
     switch(You){
     case 'X':
          //Need Loss, pick Rock
          return 1+0;
     break;
     case 'Y':
         //Need Draw, pick paper
         return 2+3;
     break;
     case 'Z':
         //Need Win, pick scissors
         return 3+6;
     break;
     }
  break;

  //Opponent Plays scissors
  case 'C':
      //Your Play
      switch(You){
      case 'X':
          //Need Loss, pick paper
          return 2+0;
      break;
      case 'Y':
          //Need Draw, pick scissors
          return 3+3;
      break;
      case 'Z':
          //Need Win, pick rock
          return 1+6;
      break;
      }
  break;
  }


}



