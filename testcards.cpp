// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

//#include "cards.h"
//#include "cards.cpp"
#include "testcards.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

  string divider = "--------------------------------------------------";
  cout << endl;

  test_constructor();

  cout << divider << endl << endl;
  test_insertCard();

  cout << divider << endl << endl;
  test_deleteCard();

  cout << divider << endl << endl;
  test_os_operator();

  cout << divider << endl << endl;
  test_double_equals_operator();

  return 0;
}

void test_constructor()
{
  CardList NoName;
  CardList WithName("Yes Name");

  START_TEST("Test Default Constructor and Parametrized Constructor");
  cout << "Player WITHOUT initililized name VS. Player WITH initialized name" << endl;
  cout << endl << "ACTUAL OUTPUT -->";
  cout << NoName;
  cout << WithName << endl;

  cout << "EXPECTED OUTPUT -->" << endl;
  cout << "No Name's Cards:\n";
  cout << endl;
  cout << endl;
  cout << "Yes Name's cards:\n" << endl << endl;

  END_TEST("Default Constructor and Parametrized Constructor");
}

void test_insertCard()
{
  START_TEST("Test insertCard");
  cout << endl;

  cout << "ACTUAL OUTPUT -->" << endl;
  CardList l1("Player 1");
  cout << "Empty List:";
  cout << l1;
  cout << "Appending an element to the empty list: ";
  l1.insertCard("h 4");
  cout << l1 << endl;
  cout << "Appending an element to a one-element list: ";
  l1.insertCard("b 5");
  cout << l1 << endl;

  cout << "EXPECTED OUTPUT -->" << endl;
  cout << "Empty List:\nPlayer 1's cards:" << endl << endl;
  cout << "Appending an element to the empty list:\nPlayer 1's cards:\nh 4" << endl << endl;
  cout << "Appending an element to a one-element list:\nPlayer 1's cards:\nh4\nb5\n" << endl << endl;

  END_TEST("insertCard");
}

void test_deleteCard()
{
  START_TEST("Test deleteCard");
  cout << endl;

  cout <<"ACTUAL OUTPUT -->" << endl;
  CardList l1("Player 1");
  l1.insertCard("f 9");
  l1.insertCard("c 7");
  l1.insertCard("q 3");
  l1.insertCard("a 1");
  cout << "Before deleting any cards:";
  cout << l1 << endl;
  cout << "After deleting the first card:";
  l1.deleteCard("f 9");
  cout << l1 << endl;
  cout << "After deleting the card in the middle card: ";
  l1.deleteCard("q 3");
  cout << l1 << endl;
  cout << "After deleting the last card";
  l1.deleteCard("a 1");
  cout << l1 << endl;

  cout << "EXPECTED OUTPUT -->" << endl;
  cout << "Before deleting any cards:\nPlayer 1's cards:\nf 9\nc 7\nq 3\na 1\n" << endl;
  cout << "After deleting the first card\nPlayer 1's cards:\nc 7\nq 3\na 1\n" << endl;
  cout << "After deleting the card in the middle:\nPlayer 1's cards:\nc 7\na 1\n" << endl;
  cout << "After deleting the last card\nPlayer 1's cards:\nc 7\n" << endl;

  END_TEST("deleteCard");;
}

void test_os_operator()
{
  CardList l1("Player 1");
  l1.insertCard("a 1");
  l1.insertCard("b 2");
  l1.insertCard("c 3");
  l1.insertCard("d 4");

  START_TEST("TEST OS operator");
  cout << endl;
  cout << "Using the overloaded os operator to print out user cards:" << endl << endl;
  cout << "ACTUAL OUTPUT-->";
  cout << l1;

  cout << "\nEXPECTED OUTPUT-->" << endl;
  cout << "Player 1's cards:\na 1\nb 2\nc 3\nd 4\n" << endl;

  END_TEST("OS operator");
}

void test_double_equals_operator()
{
  CardList l1("Player 1");
  CardList l2("Player 2");
  l1.insertCard("h 3");
  l2.insertCard("h 3");

  CardList l3("Player 1");
  CardList l4("Player 2");
  l3.insertCard("a 5");
  l4.insertCard("n 3");

  START_TEST(" Test Double equals operator");
  cout << endl;
  cout << "Using the == operator to determine if cards \"h 3\" and \"h 3\" are the same: " << endl;
  cout<< "ACTUAL OUTPUT-->  ";
  
  if(l1 == l2)
  {
    cout << "TRUE" << endl;
  }
  else {
    cout << "FALSE" << endl;
  }

  cout << "EXPECTED OUTPUT-->  ";
  cout << "TRUE" << endl << endl;

  cout << "Using the == operator to determine if cards \"a 5\" and \"n 3\" are the same: " << endl;
  cout << "ACTUAL OUTPUT-->  ";

  if(l3 == l4)
  {
    cout << "TRUE" << endl;
  }
  else {
    cout << "FALSE" << endl;
  }

  cout << "EXPECTED OUTPUT-->  ";
  cout << "FALSE" << endl << endl;

  END_TEST("Double equals operator");
}

/*
void test_constructor() {
  CardList c1;
  CardList c2("Billy");
  //assertEquals()
  
}

void runAll(){
  test_insertCard();
  test_deleteCard();
  //test_equal();
  //test_card();
}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  //test_equal_single_element_list();
  END_TEST("test_card");
}

void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}

void test_equal_empty_list(){ 
  string testname = "Case 0: [], []";
  CardList l1;
  CardList l2;
  //assertEquals(l1, l2, testname);
}

void test_card_operator_double_equal(){
  // Test to check if == is overloaded for card
}
*/