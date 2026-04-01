#include<iostream>

#include <sstream>
#include<vector>
#include<fstream>
using namespace std;

int main0()
{
    ifstream input("a.txt");
    string line;
    while ( getline(input, line) )
    {
        cout << line << endl;
    }
    ofstream output("a.txt");
    while ( getline(input, line) ) //Çå¿Õ
    {
        output << line << endl;
    }


    return 0;
}

#include  "vector.h"

int vector_main()
{
    l::test();
    return 0;
}

// int main()
// {
//     // vector_main();
// }
