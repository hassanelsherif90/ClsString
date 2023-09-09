
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;

int main()
{
    clsString String;

    String.SetValue("Hassan Ali Mohamed Ali");
    String.SetDelim(" ");
    String.SplitString();

    

    vector <string> A1 = String.SplitString();

    for (string& S : A1)
    {
        cout << S << endl;
    }
   
    vector <string> A2 = clsString::SplitString("Ahmed Mohamed", " ");;

    for (string& S : A2)
    {
        cout << S << endl;
    }
   
}

