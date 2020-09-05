/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
999. Available Captures for Rook
On an 8 x 8 chessboard, there is one white rook.
There also may be empty squares, white bishops, and black pawns.
These are given as characters 'R', '.', 'B', and 'p' respectively.
Uppercase characters represent white pieces, and
lowercase characters represent black pieces.

The rook moves as in the rules of Chess:
it chooses one of four cardinal directions (north, east, west, and south),
then moves in that direction until it chooses to stop,
reaches the edge of the board, or captures an opposite colored pawn by
moving to the same square it occupies.
Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

Example 1:

Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],
[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],
[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
In this example the rook is able to capture all the pawns.

Example 2:

Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],
[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],
[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],
[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation:
Bishops are blocking the rook to capture any pawn.

Example 3:

Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],
[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],
[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],
[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation:
The rook can capture the pawns at positions b5, d6 and f5.

Note:

board.length == board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

//less code
class Solution1 {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y;
        for(x=0;x<board.size();++x) {
            for(y=0;y<board[x].size();++y) {
                if(board[x][y]=='R')
                    return capOneDirection(board, x, y, 0, 1) +
                        capOneDirection(board, x, y, 0, -1) +
                        capOneDirection(board, x, y, 1, 0) +
                        capOneDirection(board, x, y, -1, 0);
            }
        }
        return 0;
    }
    int capOneDirection(vector<vector<char>>& board,
        int x,int y,int dx,int dy) {
        while(true) {
            x+=dx;
            y+=dy;
            if(x<0 || x>=board.size() ||
                y<0 || y>=board.size())
                break;
            if(board[x][y]=='p')
                return 1;
            if(board[x][y]=='B')
                break;
        }
        return 0;
    }
};

// more code
class Solution2 {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y,rx=0,ry=0,xx;
        for(x=0;x<board.size();++x) {
            for(y=0;y<board[x].size();++y) {
                if(board[x][y]=='R') rx=x,ry=y;
            }
        }
        int count=0;
        for(x=0;x<board.size();++x) {
            if(x==rx) {
                for(y=ry+1;y<board[x].size();++y) {
                    if(board[x][y]=='p') {
                        ++count;
                        break;
                    }else if(board[x][y]=='B') {
                        break;
                    }
                }
                for(y=ry-1;y>=0;--y) {
                    if(board[x][y]=='p') {
                        ++count;
                        break;
                    }else if(board[x][y]=='B') {
                        break;
                    }
                }
            }
            if(x==ry){
                for(xx=rx+1;xx<board.size();++xx) {
                    if(board[xx][ry]=='p') {
                        ++count;
                        break;
                    }else if(board[xx][ry]=='B') {
                        break;
                    }
                }
                for(xx=rx-1;xx>=0;--xx) {
                    if(board[xx][ry]=='p') {
                        ++count;
                        break;
                    }else if(board[xx][ry]=='B') {
                        break;
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
