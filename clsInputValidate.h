#pragma once
#include <iostream>
#include <cctype>
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(int numberBetween, int from, int to)
	{
		if (from > to)
		{
			clsUtil::Swap(from, to);
		}
		return (numberBetween >= from && numberBetween <= to);
	}

	static bool IsNumberBetween(short numberBetween, short from, short to)
	{
		if (from > to)
		{
			clsUtil::Swap(from, to);
		}
		return (numberBetween >= from && numberBetween <= to);
	}

	static bool IsNumberBetween(float numberBetween, float from, float to)
	{
		if (from > to)
		{
			clsUtil::Swap(from, to);
		}
		return (numberBetween >= from && numberBetween <= to);
	}

	static bool IsNumberBetween(double numberBetween, double from, double to)
	{
		if (from > to)
		{
			clsUtil::Swap(from, to);
		}
		return (numberBetween >= from && numberBetween <= to);
	}

	static bool IsDateBetween(clsDate dateBetween, clsDate dateFrom, clsDate dateTo)
	{
		if (!clsDate::IsDate1BeforeDate2(dateFrom, dateTo))
		{
			clsUtil::Swap(dateFrom, dateTo);
		}

		if (clsDate::IsDate1EqualDate2(dateBetween, dateFrom) || clsDate::IsDate1EqualDate2(dateBetween, dateTo))
		{
			return true;
		}

		return((clsDate::IsDate1AfterDate2(dateBetween, dateFrom) && clsDate::IsDate1BeforeDate2(dateBetween, dateTo)));
	}

	static short ReadShortNumber(string message = "Invalid Number, Enter again: \n")
	{
		short num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
		return num;
	}

	static short ReadShortNumberBetween(short form, short to, string message = "Number is not within range, Enter again:\n \n")
	{
		short num = ReadShortNumber();

		while (!(IsNumberBetween(num, form, to)))
		{
			cout << message;
			num = ReadShortNumber();
		}

		return num;
	}

	static int ReadIntNumber(string message = "Invalid Number, Enter again: \n")
	{
		int num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}

		return num;
	}

	static int ReadIntNumberBetween(int form, int to, string message = "Number is not within range, Enter again:\n \n")
	{
		int num = ReadIntNumber();

		while (!(IsNumberBetween(num, form, to)))
		{
			cout << message;
			num = ReadIntNumber();
		}

		return num;
	}

	static double ReadDblNumberBetween(double form, double to, string message = "Number is not within range, Enter again:\n\n")
	{
		double num = ReadIntNumber();
		while (!(IsNumberBetween(num, form, to)))
		{
			cout << message;
			num = ReadIntNumber();
		}

		return num;
	}

	static double ReadDblNumber(string message = "Invalid Number, Enter again: \n")
	{
		double num = 0;
		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
		return num;
	}

	static string ReadString()
	{
		string line;

		getline(cin >> ws, line);

		return line;
	}

	static float ReadFloatNumber(string message = "Invalid Number, Enter again: \n")
	{
		float num = 0;

		while (!(cin >> num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}

		return num;
	}

	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}

};