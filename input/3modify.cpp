#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "parameter0.h"
//#include "parameter1.h"


// std::string.erase
// erases part of the string, reducing its length
void myerase(string &s)
{
    int n = rand() % ERASE_N;

    for (int i = 0; i < n; ++i) {
        if (rand() % ERASE_PROB == 0) {
            int start = rand() % s.length();
            int len = rand() % ERASE_LEN;
            s.erase(start, len);  // safe for overbound
        }
    }
}

// std::string::replace
// replace one character with "0"
void mydelete(string &s)
{
    int n = rand() % DELETE_N;
    for (int i = 0; i < n; ++i) {
        if (rand() % DELETE_PROB == 0) {
            int start = rand() % s.length();
            s.replace(start, 1, "0");  // one character to zero
        }
    }
}

// std::string::replace
// replace a few characters with random character
void myreplace(string &s)
{
    int n = rand() % REPLACE_N;
    for (int i = 0; i < n; ++i) {
        if (rand() % REPLACE_PROB == 0) {
            int start = rand() % s.length();
            int len = rand() % REPLACE_LEN;
            for (int j = 0; j < len; ++j) {
#if 0
                string str = "0";
#endif

#if 1
                stringstream a;
                a << rand() % 4 + 1;  // set {1, 2, 3, 4}
                string str = a.str();
#endif

                s.replace(start + j, 1, str);
            }
        }
    }
}

// std::string::insert
// inserts additional characters into the string
void myinsert(string &s)
{
    int n = rand() % INSERT_N;
    for (int i = 0; i < n; ++i) {
        if (rand() % INSERT_PROB == 0) {
            int start = rand() % s.length();
            int len = rand() % INSERT_LEN;
            for (int j = 0; j < len; ++j) {
#if 0
                string str = "0";
#endif

#if 1
                stringstream a;
                a << rand() % 4 + 1;  // set {1, 2, 3, 4}
                string str = a.str();
#endif

                s.insert(start, str);
            }
        }
    }
}

// making the length exactly STRLEN_MAX
void mylength(string &s)
{
    int n = s.length();
    if (n < STRLEN_MAX) {
        string str = "5";  // 5 means space holder

        for (int i = 0; i < STRLEN_MAX - n; ++i) s.insert(s.length(), str);
    }
    else if (n > STRLEN_MAX) {
        s.erase(STRLEN_MAX, s.length());  // safe for overbound
    }
}

void mymodify(string &s)
{
#if ERASE_PROB != 0
    myerase(s);
#endif
#if DELETE_PROB != 0
    mydelete(s);
#endif
#if REPLACE_PROB != 0
    myreplace(s);
#endif
#if INSERT_PROB != 0
    myinsert(s);
#endif
}

void func2(vector<string> lines)
{
    const int n = lines.size();

    for (int i = 0; i < n; i += 3) {
        string line1 = lines[i + 0];
        string line2 = lines[i + 1];
        string tag = lines[i + 2];

        mymodify(line2);
        mylength(line1);
        mylength(line2);
        cout << line1 << endl;
        cout << line2 << endl;
        cout << tag << endl;
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



