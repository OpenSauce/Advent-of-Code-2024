#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
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

    cout << distance << endl;
}
