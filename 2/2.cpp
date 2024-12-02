#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool is_report_safe(vector<int> report)
{
    for (int i = 1; i < report.size(); i++)
    {
        if (report[i] == report[i - 1] || abs(report[i] - report[i - 1]) > 3)
        {
            return false;
        }
    }

    for (int i = 1; i < report.size() - 1; i++)
    {
        if (report[i - 1] < report[i] && report[i] > report[i + 1])
        {
            return false;
        }

        if (report[i - 1] > report[i] && report[i] < report[i + 1])
        {
            return false;
        }
    }

    return true;
}

int task_one()
{
    ifstream input("input.txt");
    vector<vector<int> > reports;
    for (string line; getline(input, line);)
    {
        istringstream is(line);
        vector<int> levels;
        int num;
        while (is >> num)
        {
            levels.push_back(num);
        }
        reports.push_back(levels);
    }

    int safe_reports = 0;
    for (vector<int> report : reports)
    {
        if (is_report_safe(report))
        {
            safe_reports++;
        }
    }

    return safe_reports;
}

bool is_report_safe_dampener(vector<int> report)
{
    int problems = 0;
    bool increasing = report[1] > report[0];
    for (int i = 1; i < report.size(); i++)
    {
        if (report[i] == report[i - 1] || abs(report[i] - report[i - 1]) > 3)
        {
            problems++;
            i++;
        }

        if (increasing && report[i] < report[i - 1])
        {
            problems++;
            i++;
        }

        if (!increasing && report[i] > report[i - 1])
        {
            problems++;
            i++;
        }
    }

    return problems > 1;
}

int task_two()
{
    ifstream input("input.txt");
    vector<vector<int> > reports;
    for (string line; getline(input, line);)
    {
        istringstream is(line);
        vector<int> levels;
        int num;
        while (is >> num)
        {
            levels.push_back(num);
        }
        reports.push_back(levels);
    }

    int safe_reports = 0;
    for (vector<int> report : reports)
    {
        if (is_report_safe_dampener(report))
        {
            safe_reports++;
        }
    }

    return safe_reports;
}

int main()
{
    cout << task_one() << endl;
    cout << task_two() << endl;
    return 0;
}
