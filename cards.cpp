// cards.cpp
// Authors: Steve Regala | Angel Gutierrez | 5/8/21
// Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <string>
using namespace std;


CardList::CardList(string value)
{
    name = value;
    head = NULL;
}

CardList::~CardList() 
{
    Card* n = head;
    Card* temp;
    while (n) {
        temp = n -> next;
        delete n;
        n = temp;
    }
}

/*
void CardList::printInOrder() 
{
    Card* n = head;
    while (n) {
        cout << n -> data;
        if (n -> next) {
            cout << endl;
        }
        n = n -> next;
    }
    cout << endl;
}
*/

void CardList::insertCard(string value)
{
    if (!head)
    {
        head = new Card;
        head -> data = value;
        head -> next = NULL;
    }

    else
    {
        Card* n = head;

        while (n -> next)
        {
            n = n -> next;
        }

        n -> next = new Card;
        n -> next -> data = value;
        n -> next -> next = NULL;
    }
}

bool CardList::searchMatch(CardList& value1, CardList& value2) const{

    Card* n1 = value1.head;
    Card* n2 = value2.head;

    while (n1) {

        while (n2) {

            if (n1->data == n2->data)
            {
                cout << value1.name << " picked matching card " << n1->data << endl;
                value1.deleteCard(n1 -> data);
                value2.deleteCard(n2 -> data);
                return true;
            }
            n2 = n2 -> next;

        }
        n2 = value2.head;
        n1 = n1 -> next;
    }

    return false;
}

void CardList::deleteCard(string value)
{    
    Card* current = this -> head;
    Card* pred;
    
    if(current -> data == value)
    {
        this -> head = current -> next;
        delete current;
    }

    else
    {
        while (current)
        {
            if (current -> next -> data == value)
            {
            pred = current;
            break;
            }
            current = current -> next;
        }
        deleteCardHelper(pred, value);
    }
}

void CardList::deleteCardHelper(Card* pred, string value) 
{
    Card* temp;
    temp = pred -> next;
    pred -> next = temp -> next;
    delete temp;
}

bool CardList::operator==(const CardList rhs) const {
    return (head -> data == rhs.head -> data);
}

string CardList::getName() {
    return name;
}

// - return certain functions we want to call for the game to complete

/*
StartGame
    - Already Declared: Alice's name and hand & Bob's name and hand

    - Alice is going first
        - She search's for a card that matches with a card in Bob's hand
            - if there is a match -> delete card -> do Bob's turn
            - if there is not a match -> do Bob's turn
    - Bob is going after Alice
        - He search's for a card that matches with a card in Alice's hand
            - if there is a match -> delete card -> do Alice's turn
            - if there is not a match -> do Bob's turn

    - Repeat this process until both people don't have any matching cards left

    - Print Alice's hand, then print Bob's

*/