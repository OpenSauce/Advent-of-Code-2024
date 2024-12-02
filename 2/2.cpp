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
    set<int> seen;
    for (int i = 0; i < report.size(); i++)
    {
        if (i == 0 && abs(report[i] - report[i + 1]) > 3)
        {
            seen.insert(i);
        }

        if (report[i] == report[i - 1] || abs(report[i] - report[i - 1]) > 3)
        {
            seen.insert(i);
        }
    }

    for (int i = 1; i < report.size() - 1; i++)
    {
        if (report[i - 1] < report[i] && report[i] > report[i + 1])
        {
            seen.insert(i);
        }

        if (report[i - 1] > report[i] && report[i] < report[i + 1])
        {
            seen.insert(i);
        }
    }

    if (seen.size() > 0) {
        for (int s : report) {
            cout << s << " ";
        }
        cout << " : ";
    for (int s : seen) {
        cout << s << " ";
    }

    cout << endl;
    }

    return seen.size() <= 1;
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
