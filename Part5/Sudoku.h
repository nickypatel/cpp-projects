#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

// TODO: Your Sudoku class goes here:
#include <math.h> 
#include <set>
using std::set;

class Sudoku {
    private:
    vector<vector<set<int>>> board;
    int size;

    public:
    Sudoku(int sizeIn)
    :size(sizeIn) {
        
        if(size == 9){
            set<int> s {1,2,3,4,5,6,7,8,9};
        
        vector <set <int> > inner_v(size, s);

        vector<vector< set <int> > > v (size, inner_v);
        board = v;
        }
        if(size == 16){
            set<int> s {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        
        vector <set <int> > inner_v(size, s);

        vector<vector< set <int> > > v (size, inner_v);
        board = v;
        }
    }

    const int getSquare(int row, int col) const{
        if(board[row][col].size() == 1){
            auto itr = board[row][col].begin();
            return *itr;
        }
        else{return -1;}
    }

    bool hasEmptySquare (){
        for (unsigned int r = 0; r <board.size(); ++r){
            for(unsigned int c = 0; c < board[r].size(); ++c){
                if (board[r][c].empty()){
                    return true;
                }        
            }
        }
        return false;
    }

    bool hasOneValue(int row, int col){
        if (board[row][col].size() == 1){
            return true;
        }
        return false;
    }

    bool isSolved (){
        bool solved = true;
        for (unsigned int r = 0; r <board.size(); ++r){
            for(unsigned int c = 0; c < board[r].size(); ++c){
                if (!hasOneValue(r,c)){
                    solved = false;
                }
            }
        }
        return solved;   
    }
    void simpleSolverLoop (){
        for (unsigned int r = 0; r <board.size(); ++r){
            for(unsigned int c = 0; c < board[r].size(); ++c){
                if (hasOneValue(r,c)){
                    auto itr = board[r][c].begin();
                    int val = *itr;
                    
                
                    for (unsigned int c1 =0; c1 < board[r].size(); ++c1){
                        board[r][c1].erase(val);
                    }
                    for (unsigned int r1 = 0; r1 <board.size(); ++r1){
                        board[r1][c].erase(val);
                    }
                    unsigned int sq = sqrt(size);
                    int colNumber = (c+1) % sq ;
                    
                    switch (colNumber){
                        case 1:
                            for(unsigned int r2 = r; r2 < r2 + sq; ++r2){
                                for (unsigned int c2 = c; c2 < c2 + sq; ++c2){
                                    board[r2][c2].erase(val);
                                }
                            }
                            break;
                        case 2:
                            for(unsigned int r3 = r - 1; r3 < r3 + sq; ++r3){
                                for (unsigned int c3 = c-1; c3 < c3 + sq; ++c3){
                                    board[r3][c3].erase(val);
                                }
                            }
                            break;
                        case 3:
                            for(unsigned int r4 = r - 2; r4 < r4 + sq; ++r4){
                                for (unsigned int c4 = c - 2; c4 < c4 + sq; ++c4){
                                    board[r4][c4].erase(val);
                                }
                            }
                            break;                                                            
                        case 0:
                            for(unsigned int r5 = r - sq + 1; r5 < r5 + sq; ++r5){
                                for (unsigned int c5 = c -sq +1; c5 < c5 + sq; ++c5){
                                    board[r5][c5].erase(val);
                                }
                            }
                            break;
                    }
                    board[r][c].insert(val);
                }        

            }
        }
        
    }
    bool setSquare(int row, int col, int value){
        set<int> newSet;
        newSet.insert(value);
        board[row][col] = newSet;

        while(!isSolved() || !hasEmptySquare()){
            simpleSolverLoop();
        }

        return isSolved();           
        
    }
};


#endif
