#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
//#include "cards.cpp"

using namespace std;

void startGame(CardList& Player1, CardList& Player2, int count);

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files

  CardList Player1("Alice");
  CardList Player2("Bob");
  

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){

    // store line in each node of LinkedList
    // insert function here, insert into LL
    Player1.insertCard(line);

  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){

    // store line in each node of LinkedList
    // insert function here, insert into LL
    Player2.insertCard(line);

  }
  cardFile2.close();

  // Start the game
  int count(0);
  startGame(Player1,Player2, count);  

  return 0;
}

void startGame(CardList& Player1, CardList& Player2, int count)
{  

  if(Player1.searchMatch(Player1, Player2))
  {
    count++;
    return startGame(Player2, Player1, count);
  }

  else{
    
    if(count % 2 == 0)
    {
      cout << Player1;
      cout << Player2;
    }

    else
    {
      cout << Player2;
      cout << Player1;
    }
  }

}