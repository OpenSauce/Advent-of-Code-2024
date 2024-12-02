#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int task_one()
{
    ifstream input("input.txt");
    vector<int> v1, v2;
    for (string line; getline(input, line);)
    {
        istringstream is(line);
        int a, b;
        is >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int distance = 0;

    for (int i = 0; i < v1.size(); i++)
    {
        distance += abs(v1[i] - v2[i]);
    }

    return distance;
}

int task_two()
{
    ifstream input("input.txt");
    vector<int> v1;
    map<int, int> seen;
    for (string line; getline(input, line);)
    {
        istringstream is(line);
        int a, b;
        is >> a >> b;
        v1.push_back(a);
        seen[b]++;
    }

    int similarity = 0;

    for (int i = 0; i < v1.size(); i++)
    {
        similarity += v1[i] * seen[v1[i]];
    }

    return similarity;
}

int main()
{
    cout << task_one() << endl;
    cout << task_two() << endl;
    return 0;
}
