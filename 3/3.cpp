#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

int task_two()
{
    ifstream input("input.txt");
    regex r{R"~(mul\((\d+),(\d+)\))~"};
    int res = 0;
    for (string line; getline(input, line);)
    {
        string result = "";
        size_t start = 0;
        while (true) {
            size_t nextDont = line.find("don't()", start);
            if (nextDont == string::npos) {
                result += line.substr(start);
                break;
            }
            size_t nextDo = line.find("do()", nextDont + 7);
            if (nextDo == string::npos) {
                result += line.substr(start, nextDont - start);
                break;
            }
            result += line.substr(start, nextDont - start);
            result += "||||||";
            start = nextDo;
        }

        cout << result << endl;
        cout << "----------------" << endl;

        // Handle the "cleansed line"
        smatch m;
        string::const_iterator searchStart(result.cbegin());
        while (regex_search(searchStart, result.cend(), m, r))
        {
            res += (stoi(m[1]) * stoi(m[2]));
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
