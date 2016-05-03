#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#define NSAMPLE 50000

void func2(vector<string> lines)
{
    const int n = lines.size();  // number of lines

    /*
       for (int i = 0; i < n; ++i)
       cout << lines[i] << endl;
       */

    for (int i = 0; i < NSAMPLE; ++i) {
        int l1, l2;  // line 1, line 2
        l1 = rand() % n;
        while (1) {
            l2 = rand() % n;
            if (l2 != l1) break;
        }

        string line1, line2;

        line1 = lines[l1];
        line2 = lines[l1];
        cout << line1 << endl;
        cout << line2 << endl;
        cout << "1" << endl;

        line1 = lines[l1];
        line2 = lines[l2];
        cout << line1 << endl;
        cout << line2 << endl;
        cout << "0" << endl;
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

    while (getline(ifn, line)) lines.push_back(line);

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
