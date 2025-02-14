#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixCharacter = 4, SpecielCharacter = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int from, int to)
	{
		int randNum = rand() % (to - from + 1) + from;
		return randNum;
	}

	static char GetRandomCharacter(enCharType charType)
	{
		if (charType == MixCharacter)
		{
			//Capital/Samll/Digits only
			charType = (enCharType)RandomNumber(1, 3);
		}

		switch (charType)
		{
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(60, 90));
			break;
		}
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::SpecielCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		default:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		}
	}

	static string GenerateWord(enCharType charType, short Length)
	{
		string Word = "";

		for (short i = 0; i < Length; i++)
		{
			Word += GetRandomCharacter(charType);
		}

		return Word;
	}

	static string GenerateKey(enCharType charType = CapitalLetter)
	{
		string key = "";

		for (short i = 1; i <= 3; i++)
		{
			key += GenerateWord(charType, 4) + "-";
		}

		key += GenerateWord(charType, 4);

		return key;
	}

	static void GenerateKeys(short numberOfKeys, enCharType charType)
	{
		for (short i = 1; i <= numberOfKeys; i++)
		{
			cout << "Key[" << i << "] : " << clsUtil::GenerateKey(charType) << endl;
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, Wordlength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType charType, short numberOfKey)
	{
		for (short i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(charType);
		}
	}

	static void Swap(int& A, int& B)
	{
		int temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(short& A, short& B)
	{
		short temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(float& A, float& B)
	{
		float temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(double& A, double& B)
	{
		double temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(char& A, char& B)
	{
		char temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(string& A, string& B)
	{
		string temp;
		temp = A;
		A = B;
		B = temp;
	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}

		return t;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}

};