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
	string _ReplaceToString;
	string _ReplaceTo;
	string _JoinString;

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

	static string ReversedString(string S1, string Delim)
	{
		string S2 = "";
		vector <string> vString;

		vString = SplitString(S1, Delim);

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	string ReversedString()
	{
		return ReversedString(_Value, _delim);
	}

	void SetReplaceToString(string ReplaceToString)
	{
		_ReplaceToString = ReplaceToString;
	}

	string GetReplaceToString()
	{
		return _ReplaceToString;
	}

	__declspec(property(get = GetReplaceToString, put = SetReplaceToString)) string stReplaceToString;
	
	void SetReplaceTo(string ReplaceTo)
	{
		_ReplaceTo = ReplaceTo;
	}

	string GetReplaceTo()
	{
		return _ReplaceTo;
	}

	__declspec(property(get = GetReplaceTo, put = SetReplaceTo)) string stReplaceTo;

	static string ReplaceWordsBuiltinFunctions(string S1, string ReplaceToString, string ReplaceTo)
	{
		short pos = S1.find(ReplaceToString);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, ReplaceToString.length(), ReplaceTo);

			pos = S1.find(ReplaceToString);
		}
		return S1;
	}

	string ReplaceWordsBuiltinFunctions()
	{
		return ReplaceWordsBuiltinFunctions(_Value, _ReplaceToString, _ReplaceTo);
	}

	static string AllLowerString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	string AllLowerString()
	{
		return AllLowerString(_Value);
	}

	static string AllUpperString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	string AllUpperString()
	{
		return AllUpperString(_Value);
	}

	void SetJoinString(string JoinString)
	{
		_JoinString = JoinString;
	}
	
	string GetJoinString()
	{
		return _JoinString;
	}

	__declspec(property(get = GetJoinString, put = SetJoinString)) string Join_String;

	static string JoinString(vector <string > vString, string Delim)
	{
		string S1;
		for (string& S : vString)
		{
			S1 = S1 + S + Delim;
		}
		S1 = S1.substr(0, S1.length() - Delim.length());
		return S1;
	}

	string JoinString()
	{
		return JoinString (SplitString(), _delim);
	}


	static string RepAllWordsString(string S1, string ReplaceToString, string ReplaceTo, vector < string > vString,string Delim, bool Match = true)
	{
		for (string& S : vString)
		{
			if (Match)
			{
				if (S == ReplaceToString)
				{
					S = ReplaceTo;
				}
			}
			else
			{
				if (AllLowerString(S) == AllLowerString(ReplaceToString))
				{
					S = ReplaceTo;
				}
			}

		}

		return JoinString(vString, Delim);
	}

	string RepAllWordsString( )
	{
		return RepAllWordsString(_Value, _ReplaceToString, _ReplaceTo, SplitString(), _delim);
	}

};

