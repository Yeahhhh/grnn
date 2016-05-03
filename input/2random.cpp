#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

void func2(vector<string> lines)
{
    const int n = lines.size() / 3;
    std::vector<int> idx(n);
    for (int i = 0; i < n; ++i) idx[i] = i;

    // randomly shuffle the idx array
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(idx.begin(), idx.end(), g);

    for (int i = 0; i < n; ++i) {
        // cout << idx[i] << endl;

        const int base = idx[i] * 3;
        cout << lines[base + 0] << endl;
        cout << lines[base + 1] << endl;
        cout << lines[base + 2] << endl;
    }
}

void func1(const std::string fnpath)
{
    ifstream ifn(fnpath.c_str());
    if (!ifn.is_open()) {
        cout << "Failed to open " << fnpath << endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    vector<string> lines;

    while (getline(ifn, line)) {
        lines.push_back(line);
    }

    if (lines.size() % 3 != 0) {
        cout << "input file format wrong" << endl;
        exit(EXIT_FAILURE);
    }

    func2(lines);

    ifn.close();
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("%s <INPUTFILE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    func1(argv[1]);

    return 0;
}
