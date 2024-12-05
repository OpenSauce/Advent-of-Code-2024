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
                    temp.push_back(curr_page);
                    temp_set.insert(curr_page);
                    continue;
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

int main()
{
    cout << task_one() << endl;
    return 0;
}
