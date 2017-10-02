#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
 **/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	turn = X;
	for(int i=0; i<BOARDSIZE; i++)
		for(int j=0; j<BOARDSIZE; j++)
			board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
 **/
/*
BUG: toggleTurn() initializes Piece turn to be O when turn was previously X, and vice versa. If turn is equal to X, turn should next be O, else turn should be X. The bug in this function initializes turn to be X when it was previously X, never changing the turn to be O's turn.
*/
Piece TicTacToeBoard::toggleTurn()
{
	if(turn == 'X') {
		turn = O;
		return turn;
	}
	else { // turn == O
		turn = X;
		return turn;
	}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
 **/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if(getWinner() == X || getWinner() == O) {
		return Invalid;
	}
	else if(row > 2 || column > 2) {
		return Invalid;
	}

	if(board[column][row] == Blank) {
		board[column][row] = turn;
		toggleTurn();
		return board[column][row];
	}
	else { // already a piece there
		return board[column][row];
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
 **/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(row > 2 || column > 2) {
		return Invalid;
	}
	else if(board[column][row] == Blank) {
		return Blank;
	}
	else { // already a piece there
		return board[column][row];
	}
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
 **/
Piece TicTacToeBoard::getWinner()
{
	//Piece winner;
	
	// Rows
	for(int i = 0; i < 3; ++i) {
		if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != Blank)) {
			return board[i][0];
		}
	}
	// Columns
	for(int i = 0; i < 3; ++i) {
		if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != Blank)) {
			return board[0][i];
		}
	}

	// Diagonal 1
	if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != Blank)) {
		return board[0][0];
	}
	
	// Diagonal 2
	if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != Blank)) {
		return board[0][2];
	}

	// No winner at this point, check to see if the board is filled
	// If not filled and game is not over, return Invalid
	for(int i=0; i<BOARDSIZE; i++) {
		for(int j=0; j<BOARDSIZE; j++) {
			if(board[i][j] == Blank) {
				return Invalid;
			}
		}
	}

	// Board is filled and no one won
	return Blank;
}
