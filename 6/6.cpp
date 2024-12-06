#include <iostream>
#include <fstream>
#include <set>

using namespace std;

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

Direction rotate(Direction dir)
{
    switch (dir)
    {
    case UP:
        return RIGHT;
    case RIGHT:
        return DOWN;
    case DOWN:
        return LEFT;
    case LEFT:
        return UP;
    }
}

int task_one(string path)
{
    vector<vector<char>> matrix;
    ifstream input(path);
    pair<int, int> pos;
    Direction current_direction = UP;

    int i = 0;
    for (string line; getline(input, line);)
    {
        vector<char> row;
        int j = 0;
        for (char c : line)
        {
            if (c == '^')
            {
                pos = {i, j};
            }
            row.push_back(c);
            j++;
        }
        matrix.push_back(row);
        i++;
    }

    int res = 1;
    matrix[pos.first][pos.second] = 'X';
    while (pos.first > 0 && pos.first < matrix.size() - 1 && pos.second > 0 && pos.second < matrix[pos.first].size() - 1)
    {
        switch (current_direction)
        {
        case UP:
            if (matrix[pos.first - 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.first--;
            if (matrix[pos.first][pos.second] != 'X')
            {
                res++;
            }
            matrix[pos.first][pos.second] = 'X';
            break;
        case DOWN:
            if (matrix[pos.first + 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.first++;
            if (matrix[pos.first][pos.second] != 'X')
            {
                res++;
            }
            matrix[pos.first][pos.second] = 'X';
            break;
        case LEFT:
            if (matrix[pos.first][pos.second - 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.second--;
            if (matrix[pos.first][pos.second] != 'X')
            {
                res++;
            }
            matrix[pos.first][pos.second] = 'X';
            break;
        case RIGHT:
            if (matrix[pos.first][pos.second + 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.second++;
            if (matrix[pos.first][pos.second] != 'X')
            {
                res++;
            }
            matrix[pos.first][pos.second] = 'X';
            break;
        }
    }

    return res;
}

bool will_create_loop(vector<vector<char>> matrix, pair<int, int> obstacle, pair<int, int> pos)
{
    Direction current_direction = UP;
    matrix[obstacle.first][obstacle.second] = '#';
    set<tuple<int, int, Direction>> visited;
    while (pos.first > 0 && pos.first < matrix.size() - 1 && pos.second > 0 && pos.second < matrix[pos.first].size() - 1)
    {
        if (visited.find({pos.first, pos.second, current_direction}) != visited.end())
        {
            return true;
        }
        visited.insert({pos.first, pos.second, current_direction});
        switch (current_direction)
        {
        case UP:
            if (matrix[pos.first - 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.first--;
            break;
        case DOWN:
            if (matrix[pos.first + 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.first++;
            break;
        case LEFT:
            if (matrix[pos.first][pos.second - 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.second--;
            break;
        case RIGHT:
            if (matrix[pos.first][pos.second + 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            pos.second++;
            break;
        }
    }
    return 0;
}

int task_two(string path)
{
    vector<vector<char>> matrix;
    ifstream input(path);
    pair<int, int> starting_pos;
    Direction current_direction = UP;

    int i = 0;
    for (string line; getline(input, line);)
    {
        vector<char> row;
        int j = 0;
        for (char c : line)
        {
            if (c == '^')
            {
                starting_pos = {i, j};
            }
            row.push_back(c);
            j++;
        }
        matrix.push_back(row);
        i++;
    }

    pair<int, int> pos = starting_pos;
    set<pair<int, int>> obstacles;

    while (pos.first > 0 && pos.first < matrix.size() - 1 && pos.second > 0 && pos.second < matrix[pos.first].size() - 1)
    {
        switch (current_direction)
        {
        case UP:
            if (matrix[pos.first - 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            if (will_create_loop(matrix, {pos.first - 1, pos.second}, starting_pos))
            {
                obstacles.insert({pos.first - 1, pos.second});
            }
            pos.first--;
            break;
        case DOWN:
            if (matrix[pos.first + 1][pos.second] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            if (will_create_loop(matrix, {pos.first + 1, pos.second}, starting_pos))
            {
                obstacles.insert({pos.first + 1, pos.second});
            }
            pos.first++;
            break;
        case LEFT:
            if (matrix[pos.first][pos.second - 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            if (will_create_loop(matrix, {pos.first, pos.second - 1}, starting_pos))
            {
                obstacles.insert({pos.first, pos.second - 1});
            }
            pos.second--;
            break;
        case RIGHT:
            if (matrix[pos.first][pos.second + 1] == '#')
            {
                current_direction = rotate(current_direction);
                break;
            }
            if (will_create_loop(matrix, {pos.first, pos.second + 1}, starting_pos))
            {
                obstacles.insert({pos.first, pos.second + 1});
            }
            pos.second++;
            break;
        }
    }

    return obstacles.size();
}

int main()
{
    const string path = "input.txt";
    cout << task_one(path) << endl;
    cout << task_two(path) << endl;
    return 0;
}
