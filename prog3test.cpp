#include <vector>
#include <ctime>        // keep this line if you want to generate different random objects for each run
#include <iostream>
#include <fstream>
#include "stuff3.h"

pair<bool, Stuff3> Decision1(vector<Stuff3>&);
pair<bool, Stuff3> Decision2(vector<Stuff3>&);

int main()
{
   srand(time(0));        // keep this line if you want to generate different random objects for each run
   vector<Stuff3> vec;

   //modification for test file
    ifstream ifile("../test.txt");
    int n;

    ifile >> n;

   for (int i = 0; i < n; i++)
    {
       int num;
       ifile >> num;
        Stuff3 s(false, num, num, num);
        vec.push_back(s);
    }

   for (int i = 0; i < vec.size(); i++)
    {
       cout << vec[i] << endl;
    }

   cout << "-----\n";

   cout << "Decision 1 : " << endl;
   pair<bool, Stuff3> r1 = Decision1(vec);
   if (r1.first)
    cout << " Solution: " << r1.second;
   else
    cout << " No solution: ";

   cout << "\n\nDecision 2 : " << endl;
   pair<bool, Stuff3> r2 = Decision2(vec);
   if (r2.first)
    cout << " Solution: " << r2.second;
   else
    cout << " No solution: ";
   cout << endl;

    return 0;
}