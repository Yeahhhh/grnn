#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstdio>


using namespace std;

void printstring(string &s)
{
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        cout << s[i] << ", ";
    }
}

void print_title1(const int n)
{
    for (int i = 0; i < n * 2; ++i) {
        cout << "a, ";
    }
    cout << "a, ";
    cout << "b\n";
}

void print_title2(const int n)
{
    for (int i = 0; i < n * 2; ++i) {
        cout << "a, ";
    }
    cout << "b\n";
}

void print_title3(const int n)
{
    for (int i = 0; i < n * 2; ++i) {
        cout << "a, ";
    }
    cout << "b\n";
}

void print_test(string &a, string &b, string &c)
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

void print_format1(string &a, string &b, string &c)
{
    printstring(a);
    cout << "6, ";
    printstring(b);
    cout << c << endl;
}

void print_format2(string &a, string &b, string &c)
{
    int n1 = a.length();
    int n2 = b.length();
    if (n1 != n2) {
        cout << "input file format wrong, n1 != n2" << endl;
        exit(EXIT_FAILURE);
    }
    int n = n1;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ", ";
        cout << b[i] << ", ";
    }

    cout << c << endl;
}

void print_format3(string &a, string &b, string &c)
{
    printstring(a);
    printstring(b);
    cout << c << endl;
}






void func2(vector<string> lines)
{
    const int n = lines.size();

#ifdef FORMAT1
    print_title1(lines[0].size());
#endif
#ifdef FORMAT2
    print_title2(lines[0].size());
#endif
#ifdef FORMAT3
    print_title3(lines[0].size());
#endif

    for (int i = 0; i < n; i += 3) {
        string line1 = lines[i + 0];
        string line2 = lines[i + 1];
        string line3 = lines[i + 2];
#ifdef FORMAT1
        print_format1(line1, line2, line3);
#endif
#ifdef FORMAT2
        print_format2(line1, line2, line3);
#endif
#ifdef FORMAT3
        print_format3(line1, line2, line3);
#endif
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
