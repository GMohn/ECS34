#ifndef SIXMENSMORRISBOARD_H 	  			 	 
#define SIXMENSMORRISBOARD_H

#include <string>

#define SIX_MENS_MORRIS_PLAYERS     2
#define SIX_MENS_MORRIS_PIECES      6
#define SIX_MENS_MORRIS_POSITIONS   16

#define SIX_MENS_MORRIS_EMPTY       'o'
#define SIX_MENS_MORRIS_PLAYER_R    'R'
#define SIX_MENS_MORRIS_PLAYER_W    'W'

class CSixMensMorrisBoard{
    protected:  
        char DTurn;
        int DUnplacedPieces[SIX_MENS_MORRIS_PLAYERS];
        char DPositions[SIX_MENS_MORRIS_POSITIONS];
        char DPreviousPositions[SIX_MENS_MORRIS_POSITIONS];
        bool MillCreated(char player);
        static bool AdjacentPositions(int from, int to);
        
    public:
        CSixMensMorrisBoard();
        CSixMensMorrisBoard(char turn, const int unplaced[SIX_MENS_MORRIS_PLAYERS], const char positions[SIX_MENS_MORRIS_POSITIONS], const char previous[SIX_MENS_MORRIS_POSITIONS]);
        
        void ResetBoard();
        
        char PlayerTurn() const;
        char PlayerAtPosition(int position) const;
        int UnplacedPieces(char player) const;
        bool GameOver() const;
        
        std::string ToString() const;
        operator std::string() const;
        
        bool Place(char player, int where);
        bool CanRemove(char player);
        bool CanMove(char player, int where);
        bool Move(char player, int from, int to);
        bool Remove(char player, int from);
};


#endif
