#include <bits/stdc++.h>
using namespace std;

int boardsize, cellsize, solutioncount = 0;
vector<vector<int>> board;
bool printAll = false;

bool check(int ch, int row, int col)
{
  // To check if ch is present in row
  for (int c = 0; c < boardsize; c++)
  {
    if (c != col && board[row][c] == ch)
      return false;
  }
  // To check if ch is present in column
  for (int r = 0; r < boardsize; r++)
  {
    if (r != row && board[r][col] == ch)
      return false;
  }
  // To find the top-left cell of the subgrid containing (row,col)
  int str = (row / cellsize) * cellsize;
  int stc = (col / cellsize) * cellsize;
  for (int dx = 0; dx < cellsize; dx++)
  {
    for (int dy = 0; dy < cellsize; dy++)
    {
      if (dx + str == row && dy + stc == col)
        continue;
      if (board[dx + str][dy + stc] == ch)
        return false;
    }
  }
  return true;
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
    for (int ch = 1; ch <= (boardsize); ch++)
    {
      if (check(ch, row, col))
      {
        board[row][col] = ch;
        rec(row, col + 1);
        board[row][col] = 0;
      }
    }
  }
  else
  {
    int val = board[row][col];
    if (check(val, row, col))
    {
      rec(row, col + 1);
    }
  }
}

void solve()
{
  cout << "Enter the boardsize \n";
  cin >> boardsize;
  cellsize = sqrt(boardsize);
  board.assign(boardsize, vector<int>(boardsize));
  cout << "Enter the board values \n";
  for (int i = 0; i < boardsize; i++)
  {
    for (int j = 0; j < boardsize; j++)
    {
      cin >> board[i][j];
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