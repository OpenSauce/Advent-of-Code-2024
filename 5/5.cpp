#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

int task_one()
{
    ifstream input("input.txt");

    map<int, vector<int>> deps;
    vector<vector<int>> correctly_ordered;

    for (string line; getline(input, line);)
    {
        size_t pos;
        if ((pos = line.find("|")) != string::npos)
        {
            string first = line.substr(0, pos);
            string second = line.substr(pos + 1, line.size());

            deps[stoi(second)].push_back(stoi(first));
        }

        if (line.find(",") != string::npos)
        {
            stringstream ss(line);
            string t;

            vector<int> temp;
            set<int> temp_set;
            set<int> lookup;
            bool correct = true;

            while (getline(ss, t, ','))
            {
                int curr_page = stoi(t);
                lookup.insert(curr_page);
            }

            stringstream ns(line);
            while (getline(ns, t, ','))
            {
                int curr_page = stoi(t);
                if (deps.find(curr_page) != deps.end())
                {
                    for (int i : deps[curr_page])
                    {
                        if (lookup.find(i) != lookup.end() && temp_set.find(i) == temp_set.end())
                        {
                            correct = false;
                            break;
                        }
                    }
                }

                temp.push_back(curr_page);
                temp_set.insert(curr_page);
            }

            if (correct)
            {
                correctly_ordered.push_back(temp);
            }
        }
    }

    int res = 0;
    for (auto i : correctly_ordered)
    {
        res += i[i.size() / 2];
    }

    return res;
}

void dfs(map<int, vector<int>> &deps, set<int> &visited, int curr, vector<int> &res, set<int> &needed)
{
    // If we've already passed this number, do nothing
    if (visited.find(curr) != visited.end())
    {
        return;
    }

    // Mark number as processed
    visited.insert(curr);

    // For each dependency, iterate through its dependencies
    for (int i : deps[curr])
    {
        dfs(deps, visited, i, res, needed);
    }

    // If the number is needed (It's actually in the list), add it to the result
    if (needed.find(curr) != needed.end())
    {
        res.push_back(curr);
    }
}

int task_two()
{
    ifstream input("input.txt");

    map<int, vector<int>> deps;
    vector<vector<int>> incorrectly_ordered;

    for (string line; getline(input, line);)
    {
        size_t pos;
        if ((pos = line.find("|")) != string::npos)
        {
            string first = line.substr(0, pos);
            string second = line.substr(pos + 1, line.size());

            deps[stoi(second)].push_back(stoi(first));
        }

        if (line.find(",") != string::npos)
        {
            stringstream ss(line);
            string t;

            vector<int> starting_order;
            set<int> lookup;

            while (getline(ss, t, ','))
            {
                int curr_page = stoi(t);
                lookup.insert(curr_page);
                starting_order.push_back(curr_page);
            }

            vector<int> temp;
            set<int> temp_set;

            stringstream ns(line);
            while (getline(ns, t, ','))
            {
                int curr_page = stoi(t);
                dfs(deps, temp_set, curr_page, temp, lookup);
            }

            // If it's different than the starting order, assume it's incorrect
            for (int i = 0; i < starting_order.size(); i++)
            {
                if (starting_order[i] != temp[i])
                {
                    incorrectly_ordered.push_back(temp);
                    break;
                }
            }
        }
    }

    int res = 0;
    for (auto i : incorrectly_ordered)
    {
        res += i[i.size() / 2];
    }

    return res;
}

int main()
{
    cout << task_one() << endl;
    cout << task_two() << endl;
    return 0;
}
