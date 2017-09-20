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
	ASSERT_NE(tb.toggleTurn(), tb.toggleTurn());
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard tb;
	Piece turn1 = tb.placePiece(0, 1);
	Piece turn2 = tb.placePiece(0, 2);
	ASSERT_NE(turn1, turn2);
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard tb;
	Piece turn1 = tb.placePiece(0,1);
	Piece turn2 = tb.placePiece(0,2);
	Piece get1 = tb.getPiece(0,1);
	Piece get2 = tb.getPiece(0,2);
	if((turn1 == get1) && (turn2 == get2)) {
		ASSERT_TRUE(true);
	} else {
		ASSERT_TRUE(false);
	}
}

TEST(TicTacToeBoardTest, getWinnerr1X)
{
	TicTacToeBoard tb;
	tb.placePiece(0,0);
	tb.placePiece(1,1);
	tb.placePiece(0,1);
	tb.placePiece(2,1);
	tb.placePiece(0,2);
	tb.placePiece(2,2);
	if(tb.getWinner() == 'X') {
		ASSERT_TRUE(true);
	}
}

TEST(TicTacToeBoardTest, getWinnerr2O)
{
	TicTacToeBoard tb;
	tb.placePiece(0,1);
	tb.placePiece(1,0);
	tb.placePiece(2,1);
	tb.placePiece(1,1);
	tb.placePiece(2,2);
	tb.placePiece(1,2);
	if(tb.getWinner() == 'O') {
		ASSERT_TRUE(true);
	}
}
