#include "matrix_search.h"


void get_identity(string my_id[])
{
  cout << endl << "University Username: " << my_id[0] << endl;
  cout << "University SID: " << my_id[1] << endl << endl;
}

char ** build_matrix(int rows, int cols)
{
  char** matrix = new char*[rows];
  for (int i = 0; i < rows; ++i)
  {
    matrix[i] = new char[cols];
  }

  return matrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin.ignore();
      cin.get(matrix[i][j]);
    }
  }

  return;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  bool wrdFound = false, letFound = true;
  int counter = 2;

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == word[0]) //Find first letter
      {
        sol[0] = i;
        sol[1] = j;
        if (word.length() == 1)
        {
          sol[2] = sol[0];
          sol[3] = sol[1];
        }
        else //Begin Process of checking each direction for second letter
        {
          if (sol[0] - 1 >= 0)
          {
            if (matrix[sol[0] - 1][sol[1]] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] - counter][sol[1]] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1]] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1];
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] - 1 >= 0 && sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0] - 1][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0] - counter][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1] + counter] == word[counter])
                 ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0]][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0]][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0]][sol[1] + counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0];
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0] + counter][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1] + counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1]] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && letFound)
              {
                if (matrix[sol[0] + counter][sol[1]] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1]] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1];
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] + counter][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0]][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0]][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0]][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0];
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] - 1 >= 0 && sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0] - 1][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] - counter][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
        }
      }
      else if (matrix[rows-i-1][cols-j-1] == word[0]) //Find first letter from end
      {
        sol[0] = rows-i-1;
        sol[1] = rows-j-1;
        if (word.length() == 1)
        {
          sol[2] = sol[0];
          sol[3] = sol[1];
        }
        else //Begin process of searching each direction from bottom right corner
        {
          if (sol[0] - 1 >= 0)
          {
            if (matrix[sol[0] - 1][sol[1]] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] - counter][sol[1]] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1]] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1];
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] - 1 >= 0 && sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0] - 1][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0] - counter][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1] + counter] == word[counter])
                 ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0]][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0]][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0]][sol[1] + counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0];
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && sol[1] + 1 < cols && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1] + 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && (sol[1] + counter) < cols && letFound)
              {
                if (matrix[sol[0] + counter][sol[1] + counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1] + counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1] + counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1]] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && letFound)
              {
                if (matrix[sol[0] + counter][sol[1]] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1]] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1];
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] + 1 < rows && sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0] + 1][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] + counter) < rows && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] + counter][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] + counter][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] + counter;
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0]][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0]][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0]][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0];
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
          if (sol[0] - 1 >= 0 && sol[1] - 1 >= 0 && !wrdFound)
          {
            if (matrix[sol[0] - 1][sol[1] - 1] == word[1])
            {
              counter = 2;
              letFound = true;
              while (!wrdFound && (sol[0] - counter) >= 0 && (sol[1] - counter) >= 0 && letFound)
              {
                if (matrix[sol[0] - counter][sol[1] - counter] == word[word.length() - 1] && unsigned((counter + 1)) == word.length())
                  wrdFound = true;
                else if (matrix[sol[0] - counter][sol[1] - counter] == word[counter])
                  ++counter;
                else
                  letFound = false;
              }
              if (wrdFound)
              {
                sol[2] = sol[0] - counter;
                sol[3] = sol[1] - counter;
                i = rows;
                j = cols;
              }
            }
          }
        }
      }
      //Stop the for loop halfway through the matrix with different cases for matrix sizes
      if (rows % 2 == 1 && cols % 2 == 0 && i == rows/2 && j == (cols/2 - 1))
      {
        i = rows;
        j = cols;
      }
      else if (cols % 2 == 1 && rows % 2 == 1 && i == rows/2 && j == cols/2)
      {
        i = rows;
        j = cols;
      }
      else if (rows % 2 == 0 && i == (rows/2 - 1) && j == (cols - 1))
      {
        i = rows;
        j = cols;
      }
    }
  }

  return;
}


void print_matrix(int rows, int cols, char **matrix)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return;
}


void delete_matrix(int rows, char **matrix)
{
  for (int i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }

  delete[] matrix;

  return;
}
