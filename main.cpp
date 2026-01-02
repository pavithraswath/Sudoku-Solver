// Sudoku Solver using Backtracking with Bitmask Optimization
// Supports N×N boards (tested for 4×4 and 9×9)

#include <bits/stdc++.h>
using namespace std;

int boardsize, cellsize, solutioncount = 0;
vector<vector<int>> board;
bool printAll = false;

// Bitmasks to track used numbers in rows, columns and subgrids
vector<int> takenRow;
vector<int> takenCol;
vector<vector<int>> takenGrid;

// Returns a bitmask of valid numbers that can be placed at (row,col)
int getchoices(int row, int col)
{
  int taken = takenRow[row] | takenCol[col] | takenGrid[row / cellsize][col / cellsize];
  int fullMask = (1 << (boardsize + 1)) - 2;
  return fullMask & (~taken);
}

// Place a number and update constraint masks
void makemove(int ch, int row, int col)
{
  takenRow[row] ^= (1 << ch);
  takenCol[col] ^= (1 << ch);
  takenGrid[row / cellsize][col / cellsize] ^= (1 << ch);
}

// Remove a number and update constraint masks
void revertmove(int ch, int row, int col)
{
  takenRow[row] ^= (1 << ch);
  takenCol[col] ^= (1 << ch);
  takenGrid[row / cellsize][col / cellsize] ^= (1 << ch);
}

void rec(int row, int col)
{
  if (col == boardsize)
  {
    rec(row + 1, 0);
    return;
  }
  if (row == boardsize)
  {
    solutioncount++;
    if (!printAll && solutioncount > 1)
      return;
    cout << "Solution: "
         << solutioncount << '\n';
    for (int i = 0; i < boardsize; i++)
    {
      for (int j = 0; j < boardsize; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << '\n';
    }
    return;
  }
  if (board[row][col] == 0)
  {
    int chmask = getchoices(row, col);
    // Try all valid candidates using bit manipulation
    while (chmask)
    {
      int pos = chmask & (~(chmask - 1));
      int pos_index = __builtin_ctz(pos);
      board[row][col] = pos_index;
      makemove(pos_index, row, col);
      rec(row, col + 1);
      revertmove(pos_index, row, col);
      board[row][col] = 0;
      chmask ^= pos;
    }
  }
  else
  {
    rec(row, col + 1);
  }
}

void solve()
{
  solutioncount = 0;
  cout << "Enter the boardsize \n";
  cin >> boardsize;
  cellsize = sqrt(boardsize);
  board.assign(boardsize, vector<int>(boardsize));
  takenRow.assign(boardsize, 0);
  takenCol.assign(boardsize, 0);
  takenGrid.assign(cellsize, vector<int>(cellsize, 0));
  cout << "Enter the board values \n";
  for (int i = 0; i < boardsize; i++)
  {
    for (int j = 0; j < boardsize; j++)
    {
      cin >> board[i][j];
      if (board[i][j] != 0)
        makemove(board[i][j], i, j);
    }
  }
  cout << "Should all solutions be printed(type y if yes or n if no) \n";
  char c;
  cin >> c;
  if (c == 'y')
    printAll = true;
  rec(0, 0);
  if (c == 'y')
  {
    cout << "Total number of solutions: " << solutioncount;
  }
}

int main()
{
  solve();
  return 0;
}