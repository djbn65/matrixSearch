#include "matrix_search.h"

int main()
{
  int rows, cols, numMatr, sol[4] = {-1};
  string id[2] = {"djbn65", "12534397"}, wrdToFind;
  char** matrix;

  cin >> numMatr;
  for (int i = 0; i < numMatr; ++i)
  {
    sol[0] = -1;
    sol[1] = -1;
    sol[2] = -1;
    sol[3] = -1;
    do
    {
      cin >> rows;
    } while (rows <= 0);

    do
    {
      cin >> cols;
    } while (rows <= 0);

    matrix = build_matrix(rows, cols);

    fill_matrix(rows, cols, matrix);

    cin >> wrdToFind;

    cout << "Searching for \"" << wrdToFind << "\" in matrix " << i+1 << " yields:" << endl;

    matrix_search(sol, wrdToFind, rows, cols, matrix);

    if (sol[0] != -1 && sol[1] != -1 && sol[2] != -1 && sol[3] != -1)
    {
      cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:("
           << sol[2] << "," << sol[3] << ")" << endl << endl;
    }
    else
    {
      cout << "The pattern was not found." << endl << endl;
    }

    delete_matrix(rows, matrix);
  }

  return 0;
}
