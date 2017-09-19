/**
 * Unit Tests for TicTacToeBoard
 **/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

#include <iostream>
using namespace std;

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
   TEST(TicTacToeBoardTest, sanityCheck)
   {
   ASSERT_TRUE(true);
   }
 */

//TEST(TicTacToeBoardTest, sanityCheck)
//{
//	ASSERT_TRUE(false);
//ASSERT_FALSE(true); // failed
//
//}

TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard tb;
	//Piece before = tb.toggleTurn();
	cout << "one: " << tb.toggleTurn() << endl;
	cout << "two: " << tb.toggleTurn() << endl;
	cout << "three: " << tb.toggleTurn() << endl;
	cout << "four: " << tb.toggleTurn() << endl;
	//std::cout << before;
	//Piece result = tb.toggleTurn();
	//cout << result;
	ASSERT_NE(tb.toggleTurn(), tb.toggleTurn());
}
