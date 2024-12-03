#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

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
    vector<vector<int>> reports;
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

int task_two()
{
    ifstream input("input.txt");
    vector<vector<int>> reports;
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
        else
        {
            for (int i = 0; i < report.size(); i++)
            {
                vector<int> new_report = report;
                new_report.erase(new_report.begin() + i);
                if (is_report_safe(new_report))
                {
                    safe_reports++;
                    break;
                }
            }
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
