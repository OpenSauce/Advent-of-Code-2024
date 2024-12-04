#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int find_xmas(vector<vector<char>> matrix, int i, int j)
{
    int count = 0;
    // Up
    if (i >= 3 && matrix[i - 1][j] == 'M' && matrix[i - 2][j] == 'A' && matrix[i - 3][j] == 'S')
    {
        count++;
    }

    // Down
    if (i < matrix.size() - 3 && matrix[i + 1][j] == 'M' && matrix[i + 2][j] == 'A' && matrix[i + 3][j] == 'S')
    {
        count++;
    }

    // Left
    if (j >= 3 && matrix[i][j - 1] == 'M' && matrix[i][j - 2] == 'A' && matrix[i][j - 3] == 'S')
    {
        count++;
    }

    // Right
    if (j < matrix[i].size() - 3 && matrix[i][j + 1] == 'M' && matrix[i][j + 2] == 'A' && matrix[i][j + 3] == 'S')
    {
        count++;
    }

    // Up-Left
    if (i >= 3 && j >= 3 && matrix[i - 1][j - 1] == 'M' && matrix[i - 2][j - 2] == 'A' && matrix[i - 3][j - 3] == 'S')
    {
        count++;
    }

    // Up-Right
    if (i >= 3 && j < matrix[i].size() - 3 && matrix[i - 1][j + 1] == 'M' && matrix[i - 2][j + 2] == 'A' && matrix[i - 3][j + 3] == 'S')
    {
        count++;
    }

    // Down-Left
    if (i < matrix.size() - 3 && j >= 3 && matrix[i + 1][j - 1] == 'M' && matrix[i + 2][j - 2] == 'A' && matrix[i + 3][j - 3] == 'S')
    {
        count++;
    }

    // Down-Right
    if (i < matrix.size() - 3 && j < matrix[i].size() - 3 && matrix[i + 1][j + 1] == 'M' && matrix[i + 2][j + 2] == 'A' && matrix[i + 3][j + 3] == 'S')
    {
        count++;
    }

    return count;
}

int task_one()
{
    vector<vector<char>> matrix;
    ifstream input("input.txt");
    for (string line; getline(input, line);)
    {
        matrix.push_back(vector<char>(line.begin(), line.end()));
    }

    int res = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 'X')
            {
                res += find_xmas(matrix, i, j);
            }
        }
    }

    return res;
}

int find_x_mas(vector<vector<char>> matrix, int i, int j)
{
    // Check boundaries
    if (i < 1 || i >= matrix.size() - 1 || j < 1 || j >= matrix[i].size() - 1)
    {
        return 0;
    }

    if ((matrix[i - 1][j - 1] == 'M' && matrix[i + 1][j + 1] == 'S' ||
         matrix[i - 1][j - 1] == 'S' && matrix[i + 1][j + 1] == 'M') &&
        (matrix[i - 1][j + 1] == 'M' && matrix[i + 1][j - 1] == 'S' ||
         matrix[i - 1][j + 1] == 'S' && matrix[i + 1][j - 1] == 'M'))
    {
        return 1;
    }

    return 0;
}

int task_two()
{
    vector<vector<char>> matrix;
    ifstream input("input.txt");
    for (string line; getline(input, line);)
    {
        matrix.push_back(vector<char>(line.begin(), line.end()));
    }

    int res = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 'A')
            {
                res += find_x_mas(matrix, i, j);
            }
        }
    }

    return res;
}

int main()
{
    cout << task_one() << endl;
    cout << task_two() << endl;
    return 0;
}
