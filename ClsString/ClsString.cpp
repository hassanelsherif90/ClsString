
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;

int main()
{
    clsString String;

    String.SetValue("Hassan Ali Mohamed Ali");
    //String.SetDelim(" ");
    String.Delim = " ";
    /*String.SplitString();*/
    
   /* vector <string> A1 = String.SplitString();

    for (string& S : A1)
    {
        cout << S << endl;
    }

    vector <string> A2 = clsString::SplitString("Ahmed Mohamed", " ");;

    for (string& S : A2)
    {
        cout << S << endl;
    }*/

    cout << String.ReversedString() << endl; 

    String.SetReplaceToString("Hassan");
    String.SetReplaceTo("Mohamed");

    cout << String.RepAllWordsString() << endl;

    /*cout << String.AllLowerString() << endl;
    cout << String.AllUpperString() << endl;
    String.Join_String = "Ahmed";
    cout << String.JoinString() << endl;*/
}

