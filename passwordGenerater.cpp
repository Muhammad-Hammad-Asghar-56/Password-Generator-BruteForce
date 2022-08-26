#include <iostream>
using namespace std;
bool numericEntry = true;
bool alphabeticEntry = false;
// bool symbolEntry=false;
const int numericField = 10;

int numericArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char alphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// int symbolArray[]=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

// int possibleOutcomes = 1;
int possibleCombinationCount = 0;
int incompleteCombinationCount = 0;
string possiblePasswordCombination[10000] = {};
string incompletePasswordCombination[10000] = {};
void passwordGenerator(string password);
void combineNumericArrayToThePassword(int letterPlace, string word);
void combineAlphabeticArrayToThePassword(int letterPlace, string word);
bool incompletePassword(string word);
bool isfindDigit(char Character);
main()
{
    string word = "";
    cout << "Enter the Password string (***)  :";
    cin >> word;
    incompletePasswordCombination[incompleteCombinationCount]=word;
    incompleteCombinationCount++;
    // for (int a = 0; a < sizeof(incompletePasswordCombination)/sizeof(incompletePasswordCombination[0]);a++)
    int counts=0;
    while(true)
    {
        counts=0;
        if (incompletePasswordCombination[0] == "" || ! incompletePassword(incompletePasswordCombination[0]))
        {
            break;
        }
        else
        {
            passwordGenerator(incompletePasswordCombination[0]);
        }
        if(counts<=10000){
            break;
        }
    }
    for (int i=0 ;i<sizeof(possiblePasswordCombination)/sizeof(possiblePasswordCombination[0]);i++){
        cout<<possiblePasswordCombination[i];
    }
}
void passwordGenerator(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (isfindDigit(password[i]))
        {
            if (numericEntry)
            {
                combineNumericArrayToThePassword(i, password);
            }
            if (alphabeticEntry)
            {
                combineAlphabeticArrayToThePassword(i, password);
            }
            // if(symbolEntry){}
        }
    }
}
void combineNumericArrayToThePassword(int letterPlace, string word)
{
    for (int i = 0; i < 10; i++)
    {
        word[letterPlace] = numericArray[i];
        if (incompletePassword(word))
        {
            incompletePasswordCombination[incompleteCombinationCount] = word;
            incompleteCombinationCount++;
        }
        else
        {
            possiblePasswordCombination[possibleCombinationCount] = word;
            possibleCombinationCount++;
        }
    }
}
void combineAlphabeticArrayToThePassword(int letterPlace, string word)
{
    for (int i = 0; i < 52; i++)
    {
        word[letterPlace] = alphabet[i];
        if (incompletePassword(word))
        {
            incompletePasswordCombination[incompleteCombinationCount] = word;
            incompleteCombinationCount++;
        }
        else
        {
            possiblePasswordCombination[possibleCombinationCount] = word;
        }
    }
}

//                  This is to check the Validations
bool incompletePassword(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == '*')
        {
            return true;
        }
    }
    return true;
}
bool isfindDigit(char Character)
{
    if (Character == '*')
    {
        return true;
    }
    return false;
}