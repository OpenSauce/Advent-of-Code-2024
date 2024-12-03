#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

int task_two()
{
    ifstream input("input.txt");
    regex r{R"~((mul\((\d+),(\d+)\))|(do\(\))|(don't\(\)))~"};
    int res = 0;
    for (string line; getline(input, line);)
    {
        smatch m;
        string::const_iterator searchStart(line.cbegin());
        bool enabled = true;
        while (regex_search(searchStart, line.cend(), m, r))
        {
            if (m[0] == "do()")
            {
                enabled = true;
            }
            else if (m[0] == "don't()")
            {
                enabled = false;
            }
            else
            {
                if (enabled)
                {
                    res += (stoi(m[2]) * stoi(m[3]));
                }
            }
            searchStart = m.suffix().first;
        }
    }

    return res;
}

int task_one()
{
    ifstream input("input.txt");
    regex r{R"~(mul\((\d+),(\d+)\))~"};
    int res = 0;
    for (string line; getline(input, line);)
    {
        smatch m;
        string::const_iterator searchStart(line.cbegin());
        while (regex_search(searchStart, line.cend(), m, r))
        {
            res += (stoi(m[1]) * stoi(m[2]));
            searchStart = m.suffix().first;
        }
    }

    return res;
}

int main()
{
    cout << task_one() << endl;
    cout << "----------------" << endl;
    cout << task_two() << endl;
    return 0;
}
