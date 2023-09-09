#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class clsString
{
private:
	string _Value;
	string _delim;

	


public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void SetDelim(string Delim)
	{
		_delim = Delim;
	}

	string GetDelim()
	{
		return _delim;
	}

	__declspec(property(get = GetDelim, put = SetDelim)) string Delim;

	static vector <string> SplitString(string S1, string delim)
	{
		short pos = 0;
		string sWord;

		vector < string > vString;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = (S1.substr(0, pos));
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + delim.length());

		}

		if (S1 != "")
		{
			vString.push_back(S1);

		}
		return vString;
	}

	vector <string> SplitString()
	{
		return SplitString(_Value, _delim);
	}

	

};

