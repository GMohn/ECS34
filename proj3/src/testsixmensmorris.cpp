#ifndef _MSC_VER
#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

//inherit a mock object from protected class
class MockClass: public CSixMensMorrisBoard {
	public:
		bool MockMill(char player) { return this->MillCreated(player); }
		static bool MockAdjacent(int from, int to) {
			return AdjacentPositions(from, to); }

};
TEST(SixMensMorrisBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
    CSixMensMorrisBoard Board;
    EXPECT_EQ(Board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R);
	for(int index = 0; index < SIX_MENS_MORRIS_POSITIONS;index++){
		EXPECT_EQ(Board.PlayerAtPosition(index),SIX_MENS_MORRIS_EMPTY);
	}
	EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R),SIX_MENS_MORRIS_PIECES);
	EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W),SIX_MENS_MORRIS_PIECES);
	EXPECT_FALSE(Board.GameOver());
	EXPECT_EQ(std::string(Board), 
                        ">RU:6 RC:0  WU:6 WC:0\n"
                        "o---------o---------o      0---1---2\n"
                        "|         |         |      | 3-4-5 |\n"
                        "|         |         |      6-7   8-9\n"
                        "|    o----o----o    |      | A-B-C |\n"
                        "|    |         |    |      D---E---F\n"
                        "|    |         |    |        LEGEND\n"
                        "o----o         o----o\n"
                        "|    |         |    |\n"
                        "|    |         |    |\n"
                        "|    o----o----o    |\n"
                        "|         |         |\n"
                        "|         |         |\n"
                        "o---------o---------o\n");
	EXPECT_EQ(std::string(Board), Board.ToString());
}

TEST(SixMensMorrisBoardTest, SetBoardTest){
    // Needs to test that setting board is correct
	
    char turn = SIX_MENS_MORRIS_PLAYER_W;
    int unplaced[SIX_MENS_MORRIS_PLAYERS] = {2,3};
    char positions[SIX_MENS_MORRIS_POSITIONS] = {SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                                                 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,
                                                 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                                                 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
                                                 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R};
    char previous[SIX_MENS_MORRIS_POSITIONS] = {SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                                                 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,
                                                 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                                                 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
                                                 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R};
	CSixMensMorrisBoard Board(turn, unplaced, positions, previous);
    EXPECT_EQ(Board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
    for(int i = 0; i < SIX_MENS_MORRIS_POSITIONS; i++){
        EXPECT_EQ(Board.PlayerAtPosition(i), positions[i]);
    }
    EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R),unplaced[0]);
    EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W),unplaced[1]);
    EXPECT_FALSE(Board.GameOver());
    EXPECT_EQ(std::string(Board), 
                        " RU:2 RC:0 >WU:3 WC:0\n"
                        "R---------W---------R      0---1---2\n"
                        "|         |         |      | 3-4-5 |\n"
                        "|         |         |      6-7   8-9\n"
                        "|    o----o----o    |      | A-B-C |\n"
                        "|    |         |    |      D---E---F\n"
                        "|    |         |    |        LEGEND\n"
                        "W----o         o----W\n"
                        "|    |         |    |\n"
                        "|    |         |    |\n"
                        "|    o----o----o    |\n"
                        "|         |         |\n"
                        "|         |         |\n"
                        "R---------o---------R\n");
	EXPECT_EQ(std::string(Board), Board.ToString());

}

TEST(SixMensMorrisBoardTest, ResetBoardTest){
    // Needs to test that resetting to default board is correct
	CSixMensMorrisBoard Board;
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 15));

	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 9));
	EXPECT_EQ(Board.PlayerAtPosition(9), SIX_MENS_MORRIS_PLAYER_W);

	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 8));
	EXPECT_EQ(Board.PlayerAtPosition(8), SIX_MENS_MORRIS_PLAYER_R);

	EXPECT_FALSE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 15));
	EXPECT_EQ(Board.PlayerAtPosition(15), SIX_MENS_MORRIS_PLAYER_R);
	
	Board.ResetBoard();
	EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), SIX_MENS_MORRIS_PIECES);
	EXPECT_EQ(Board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), SIX_MENS_MORRIS_PIECES);
	for (int index = 0; index < SIX_MENS_MORRIS_POSITIONS; index++) {
		EXPECT_EQ(Board.PlayerAtPosition(index), SIX_MENS_MORRIS_EMPTY);
	}
	

}

TEST(SixMensMorrisBoardTest, PlacementTest){
    // Needs to test that normal placement is correct
	CSixMensMorrisBoard Board;
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 0));

	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 6));


	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 3));


	EXPECT_FALSE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 0));
	EXPECT_EQ(Board.PlayerAtPosition(0), SIX_MENS_MORRIS_PLAYER_R);
}

TEST(SixMensMorrisBoardTest, PlacementMillTest){
    // Needs to test that placement creating a mill is correct with removal
	//place at 2,9,15 expect mill created
	CSixMensMorrisBoard Board;
	MockClass Test;

	Board.Place(SIX_MENS_MORRIS_PLAYER_R, 2);
	Board.Place(SIX_MENS_MORRIS_PLAYER_W, 3);
	Board.Place(SIX_MENS_MORRIS_PLAYER_R, 9);
	EXPECT_FALSE(Test.MockMill(SIX_MENS_MORRIS_PLAYER_R));
	Board.Place(SIX_MENS_MORRIS_PLAYER_W, 10);
	Board.Place(SIX_MENS_MORRIS_PLAYER_R, 15);
	//TODO Find how to inherit a protected class
	EXPECT_TRUE(Test.MockMill(SIX_MENS_MORRIS_PLAYER_R));
	Board.Place(SIX_MENS_MORRIS_PLAYER_W, 7);
	//TODO ...
	EXPECT_TRUE(Test.MockMill(SIX_MENS_MORRIS_PLAYER_W));
	
}

TEST(SixMensMorrisBoardTest, MoveTest){
    // Needs to test that movement is correct
	CSixMensMorrisBoard Board;
	//test piece on 6 -> 0 and that 0 ! -> 3
}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
	CSixMensMorrisBoard Board;
}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
	CSixMensMorrisBoard Board;
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
	CSixMensMorrisBoard Board;
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
	CSixMensMorrisBoard Board;
}
#endif
