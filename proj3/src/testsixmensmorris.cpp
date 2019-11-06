#ifndef _MSC_VER
#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

//inherit a mock object from protected class
/*class MockClass: public CSixMensMorrisBoard {
	public:
		bool MockMill(char player) { return this->MillCreated(player); }
		static bool MockAdjacent(int from, int to) {
			return AdjacentPositions(from, to); }

};*/
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
	//MockClass Test;

	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 2));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 3));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 9));
	EXPECT_FALSE(Board.CanRemove(SIX_MENS_MORRIS_PLAYER_R));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 10));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 15));
	
	EXPECT_TRUE(Board.CanRemove(SIX_MENS_MORRIS_PLAYER_R));

	
}

TEST(SixMensMorrisBoardTest, MoveTest) {
	// Needs to test that movement is correct
	//test piece on 6 -> 0 and that 0 ! -> 3
	char turn = SIX_MENS_MORRIS_PLAYER_W;
	int unplaced[SIX_MENS_MORRIS_PLAYERS] = { 0,0 };
	char positions[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_EMPTY , SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W , SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R };
	char previous[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R };
	CSixMensMorrisBoard Board(turn, unplaced, positions, previous);
	EXPECT_EQ(Board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
	for (int i = 0; i < SIX_MENS_MORRIS_POSITIONS; i++) {
		EXPECT_EQ(Board.PlayerAtPosition(i), positions[i]);
	}
	EXPECT_TRUE(Board.Move(SIX_MENS_MORRIS_PLAYER_W, 6, 0));
	EXPECT_TRUE(Board.Move(SIX_MENS_MORRIS_PLAYER_R, 2, 9));
	EXPECT_FALSE(Board.Move(SIX_MENS_MORRIS_PLAYER_W, 0, 3));
	EXPECT_EQ(std::string(Board),
		" RU:0 RC:2 >WU:0 WC:3\n"
		"W---------W---------o      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    o----o----W    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"o----o         W----R\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    o----o----o    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"R---------o---------R\n");
	EXPECT_EQ(std::string(Board), Board.ToString());
	
}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
	char turn = SIX_MENS_MORRIS_PLAYER_W;
	int unplaced[SIX_MENS_MORRIS_PLAYERS] = { 0,0 };
	char positions[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_EMPTY , SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W , SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R };
	char previous[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R };
	CSixMensMorrisBoard Board(turn, unplaced, positions, previous);
	EXPECT_EQ(Board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
	for (int i = 0; i < SIX_MENS_MORRIS_POSITIONS; i++) {
		EXPECT_EQ(Board.PlayerAtPosition(i), positions[i]);
	}
	EXPECT_TRUE(Board.Move(SIX_MENS_MORRIS_PLAYER_W, 6, 0));
	EXPECT_TRUE(Board.CanRemove(SIX_MENS_MORRIS_PLAYER_W));
	EXPECT_EQ(std::string(Board),
		" RU:0 RC:1 >WU:0 WC:3\n"
		"W---------W---------W      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    o----o----W    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"o----o         W----o\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    R----o----o    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"R---------o---------R\n");
	EXPECT_EQ(std::string(Board), Board.ToString());

}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
	char turn = SIX_MENS_MORRIS_PLAYER_W;
	int unplaced[SIX_MENS_MORRIS_PLAYERS] = { 0,0 };
	char positions[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_PLAYER_W , SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R , SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY };
	char previous[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_EMPTY , SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R , SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY };
	CSixMensMorrisBoard Board(turn, unplaced, positions, previous);
	EXPECT_TRUE(Board.Remove(SIX_MENS_MORRIS_PLAYER_W, 10));
	EXPECT_TRUE(Board.GameOver());
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
	CSixMensMorrisBoard Board;
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 0));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 2));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 1));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 9));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 3));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 5));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 4));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 11));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 7));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 10));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 6));
	EXPECT_TRUE(Board.Place(SIX_MENS_MORRIS_PLAYER_W, 13));
	EXPECT_EQ(Board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
	EXPECT_TRUE(Board.GameOver());
	EXPECT_EQ(std::string(Board),
		" RU:0 RC:0  WU:0 WC:0\n"
		"R---------R---------W      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    R----R----W    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"R----R         o----W\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    W----W----o    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"W---------o---------o\n");
	//placement -> remove -> game over
	CSixMensMorrisBoard Bo;
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 1));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 0));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 2));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 6));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 9));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 4));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 8));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 12));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 14));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 15));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_R, 5));
	EXPECT_TRUE(Bo.Place(SIX_MENS_MORRIS_PLAYER_W, 13));
        EXPECT_TRUE(Bo.CanRemove(SIX_MENS_MORRIS_PLAYER_W));
        EXPECT_TRUE(Bo.Remove(SIX_MENS_MORRIS_PLAYER_W, 14));


    	EXPECT_TRUE(Bo.GameOver());
 	EXPECT_EQ(std::string(Bo),
		" RU:0 RC:0  WU:0 WC:1\n"
		"W---------R---------R      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    o----W----R    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"W----o         R----R\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    o----o----W    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"W---------o---------W\n");
	
	//placement -> move -> remove -> game over
	CSixMensMorrisBoard B;
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 1));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 0));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 2));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 7));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 9));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 4));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 8));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 12));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 14));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 15));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_R, 5));
	EXPECT_TRUE(B.Place(SIX_MENS_MORRIS_PLAYER_W, 13));
    	EXPECT_TRUE(B.Move(SIX_MENS_MORRIS_PLAYER_R,14,11));
    	EXPECT_TRUE(B.Move(SIX_MENS_MORRIS_PLAYER_W,7,6)); 
    	EXPECT_TRUE(B.CanRemove(SIX_MENS_MORRIS_PLAYER_W));
    	EXPECT_TRUE(B.Remove(SIX_MENS_MORRIS_PLAYER_W, 11));


    	EXPECT_TRUE(B.GameOver());
    	EXPECT_EQ(std::string(B),
		" RU:0 RC:0  WU:0 WC:1\n"
		"W---------R---------R      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    o----W----R    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"W----o         R----R\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    o----o----W    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"W---------o---------W\n");
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
	CSixMensMorrisBoard Board;
	EXPECT_FALSE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, -1));
	EXPECT_FALSE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 16));
	EXPECT_FALSE(Board.Place(SIX_MENS_MORRIS_PLAYER_R, 3798));

}
#endif
