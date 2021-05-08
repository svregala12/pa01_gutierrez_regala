//cards.h
//Authors: Angel Gutierrez | Steve Regala | 5/6/21
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

struct Card 
{
    string data;
    Card* next;
};


class CardList {

    public:
        // constructor --> initialize head to NULL and initialize name
        CardList(string value);

        // destructor
        ~CardList();

        // print the remaining cards left
        void printInOrder();

        // insert
        void insertCard(string value);

        // search
        bool searchMatch(CardList& value1, CardList& value2) const;

        // delete
        void deleteCard(string value);
        void deleteCardHelper(Card* temp, string value);

        // operator <<
        friend std::ostream& operator<<(std::ostream& os, const CardList& input) {
           Card* n = input.head;
           os << input.name << " picked matching card " << n -> data;
           return os;
        }

        // operator ==
        bool operator==(const CardList rhs) const;

        // get the count of nodes of each player
        int countCards();

        //get name
        string getName();

    private:
        string name;
        Card* head;
        //void clear(Card* n);
};



#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP principles using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.

/*

To-do's:

- How many classes would we need? --> possibly 2
    - Card class and CardList

- Card struct/class (LinkedList) --> this is the NODE
    - first card --> head of the linkedlist
    - last card --> tail of the LL
    - next pointer to traverse through the list
    - a Node struct inside the class that consists of "int data" and "Node* next"

    - functions (public)
        - constructor
        - destructor
        - Two overloaded operators
            - << and ==


- CardList Class
    - within this class, there is the struct called Card
    - insert function
    - search function
    - delete function

- Player Class?



Questions
    - Is our approach appropriate (2 classes, 1 struct inside a class)
    - What's the point of the overload operator, elaborate on this please, both << and ==
    - How are we supposed to store each card into a node, since each card is either (1) number/number or (2) number/letter
        - Could we possibly treat each card as a string, regardless of the integer value?
    - Is Card a class

    - Our design would be 2 classes: Cardlist and Player (Card struct within Cardlist)
        - How would the two classes interact?
        - Possibility: Have an overall class: Player. And inside the Cardlist
    
    - Clarify on what they mean when they say to have multiple classes --> how would they interact?

*/

/* player class 
    - would use the interface created for it to play the game
    - use the container of cards to play the game
    - represents the deck of cards in your hands
    - user/player -> container of the cards
    - class that would use cardlist and card to play the game
    - Player that owns the hand of cards
*/