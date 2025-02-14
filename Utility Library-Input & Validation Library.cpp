#include <iostream>
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include "clsInputValidate.h"

int main()
{
    clsUtil::Srand();

    cout << "Capital Character: " << clsUtil::GetRandomCharacter(clsUtil::CapitalLetter) << endl;
    cout << "Small Character: " << clsUtil::GetRandomCharacter(clsUtil::SmallLetter) << endl;
    cout << "Special Character: " << clsUtil::GetRandomCharacter(clsUtil::SpecielCharacter) << endl;
    cout << "Digit: " << clsUtil::GetRandomCharacter(clsUtil::Digit) << endl;
    cout << "Mix Character: " << clsUtil::GetRandomCharacter(clsUtil::MixCharacter) << endl << endl;

    cout << "Generate Word: " << clsUtil::GenerateWord(clsUtil::MixCharacter, 10) << endl << endl;

    cout << "Generate Key: " << clsUtil::GenerateKey() << endl << endl;

    cout << "Generate Keys: \n\n";
    clsUtil::GenerateKeys(10, clsUtil::CapitalLetter);

    cout << endl;

    int Array[10];
    clsUtil::FillArrayWithRandomNumbers(Array, 10, 1, 10);

    cout << "Array Number Data: \n";

    for (short i = 0; i < 10; i++)
    {
        cout << Array[i] << endl;
    }

    cout << endl;

    string Array2[10];
    clsUtil::FillArrayWithRandomWords(Array2, 10, clsUtil::CapitalLetter, 5);

    cout << "Array String Data: \n";

    for (short i = 0; i < 10; i++)
    {
        cout << Array2[i] << endl;
    }

    cout << endl;

    string Array3[10];
    clsUtil::FillArrayWithRandomKeys(Array3, 10, clsUtil::CapitalLetter, 5);

    cout << "Array Key Data: \n";

    for (short i = 0; i < 10; i++)
    {
        cout << Array3[i] << endl;
    }

    //Swap Int
    int x = 10, y = 20;
    cout << x << " " << y << endl;
    clsUtil::Swap(x, y);
    cout << x << " " << y << endl << endl;

    //Swap double
    double a = 10.5, b = 20.5;
    cout << a << " " << b << endl;
    clsUtil::Swap(a, b);
    cout << a << " " << b << endl << endl;

    //Swap String
    string s1 = "Ali", s2 = "Ahmed";
    cout << s1 << " " << s2 << endl;
    clsUtil::Swap(s1, s2);
    cout << s1 << " " << s2 << endl << endl;

    //Swap Dates
    clsDate d1(1, 10, 2022), d2(1, 1, 2022);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    clsUtil::Swap(d1, d2);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;

    //Shuffle Array

    //int array
    int Arr1[5] = { 1,2,3,4,5 };
    clsUtil::ShuffleArray(Arr1, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    //string array
    string Arr2[5] = { "Ali","Fadi","Ahmed","Qasem","Khalid" };
    clsUtil::ShuffleArray(Arr2, 5);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    int Arr3[5];
    clsUtil::FillArrayWithRandomNumbers(Arr3, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }


    string Arr4[5];
    clsUtil::FillArrayWithRandomWords(Arr4, 5, clsUtil::MixCharacter, 8);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr4[i] << endl;
    }


    string Arr5[5];
    clsUtil::FillArrayWithRandomKeys(Arr5, 5, clsUtil::MixCharacter, 5);
    cout << "\nArray after filling keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr5[i] << endl;
    }

    cout << "\nText1 " << clsUtil::Tabs(5) << "Text2\n";

    const short EncryptionKey = 2; //this is the key.

    string TextAfterEncryption, TextAfterDecryption;
    string Text = "Omar Al_Sheikh";
    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : ";
    cout << Text << endl;
    cout << "Text After Encryption  : ";
    cout << TextAfterEncryption << endl;
    cout << "Text After Decryption  : ";
    cout << TextAfterDecryption << endl;

    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(20, 9, 2024), clsDate(3, 10, 2024)) << endl;
    cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(3, 10, 2024), clsDate(20, 9, 2024)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int num1 = clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "num1 =" << num1;

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int num2 = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "num2 =" << num2;

    cout << "\nPlease Enter a Double Number:\n";
    double num3 = clsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "num3 =" << num3;

    cout << "\nPlease Enter a Double Number between 1 and 5:\n";
    double num4 = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "num4 =" << num4;

    cout << endl << clsInputValidate::IsValidDate(clsDate(35, 12, 2024)) << endl;

    system("pause>0");

    return 0;
}