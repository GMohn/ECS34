#include <iostream> 	  			 	 
#include <cctype>
#include "SixMensMorrisBoard.h"

int InputPosition();

int main(int argc, char *argv[]){
    CSixMensMorrisBoard SixMensMorrisBoard;
    std::string InputLine;
    bool Done = false;
    
    while(!Done){
        SixMensMorrisBoard.ResetBoard();
        while(!SixMensMorrisBoard.GameOver()){
            char CurrentTurn = SixMensMorrisBoard.PlayerTurn();
            std::cout<<std::string(SixMensMorrisBoard)<<std::endl;
            std::cout<<"-------------------"<<std::endl;
            if(SixMensMorrisBoard.UnplacedPieces(CurrentTurn)){
                std::cout<<"Player "<<CurrentTurn<<" place a piece> ";
				
                int Position = InputPosition();
                if(!SixMensMorrisBoard.Place(CurrentTurn,Position)){
                    do{
                        std::cout<<"Invalid position, player "<<CurrentTurn<<" place a piece> ";
                        Position = InputPosition();
                    }while(!SixMensMorrisBoard.Place(CurrentTurn,Position));
                }
            }
            else{
                std::cout<<"Player "<<CurrentTurn<<" select a piece to move> ";
                int Position = InputPosition();
                
                if(!SixMensMorrisBoard.CanMove(CurrentTurn,Position)){
                    do{
                        if(CurrentTurn == SixMensMorrisBoard.PlayerAtPosition(Position)){
                            std::cout<<"Invalid, piece has no moves, player "<<CurrentTurn<<" select a piece to move> ";
                        }
                        else{
                            std::cout<<"Invalid position, player "<<CurrentTurn<<" select a piece to move> ";
                        }
                        Position = InputPosition();
                    }while(!SixMensMorrisBoard.CanMove(CurrentTurn,Position));
                }
                std::cout<<"Player "<<CurrentTurn<<" select where to move> ";
                int ToPosition = InputPosition();
                if(!SixMensMorrisBoard.Move(CurrentTurn,Position,ToPosition)){
                    do{
                        std::cout<<"Invalid move, player "<<CurrentTurn<<" select where to move> ";
                        ToPosition = InputPosition();
                    }while(!SixMensMorrisBoard.Move(CurrentTurn,Position,ToPosition));
                }
            }
            if(SixMensMorrisBoard.CanRemove(CurrentTurn)){
                std::cout<<"Player "<<CurrentTurn<<" select an opponent piece to remove> ";
                int Position = InputPosition();
                
                if(!SixMensMorrisBoard.Remove(CurrentTurn,Position)){
                    do{
                        std::cout<<"Invalid position, player "<<CurrentTurn<<" select an opponent piece to remove> ";
                        Position = InputPosition();
                    }while(!SixMensMorrisBoard.Remove(CurrentTurn,Position));
                }
            }
        }
        std::cout<<"Game over, player "<<SixMensMorrisBoard.PlayerTurn()<<" wins!"<<std::endl;
        while(true){
            std::string InputLine;
            std::cout<<"Play again? ";
            std::getline(std::cin, InputLine);
            if(!InputLine.empty() && ((tolower(InputLine[0]) == 'y') || (tolower(InputLine[0]) == 'n'))){
                Done = tolower(InputLine[0]) == 'n';
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}

int InputPosition(){
    std::string InputLine;
    std::getline(std::cin, InputLine);
    try{
        int Position = std::stoi(InputLine,nullptr,16);
        if((0 > Position) || (16 <= Position)){
            return -1;   
        }
        return Position;
    }
    catch(std::exception &E){
        return -1;   
    }
}
