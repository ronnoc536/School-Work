//Connor Marler
// Programming Languages and Translators
//Feb 17, 2023

#include <iostream>
using namespace std;


string KEYWORDS = "FUNCTIONIFENDFWHILEENDWPRINT";
string DIGITS = "0123456789";
string HEXIDECIMAL = "ABCDEF";
string ALPHABET = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwYyXxZz";

bool isInt(string checkValue)
{
    if(checkValue.length() < 1)
    {
        return false;
    }
    
    if(checkValue[0] == '+' || checkValue[0] == '-')
    {
        checkValue[0] = '1';
    }

    for(auto x : checkValue)
    {
        if((DIGITS.find(x) == string::npos))
        {
            return false;
        }
    }

    return true; 
}

bool isDec(string checkValue)
{
    bool oneDecimal = false;
    bool numEnded = false;

    if(checkValue.length() < 1)
    {
        return false;
    }
    if(checkValue[0] == '+' || checkValue[0] == '-')
    {
        checkValue[0] = '1';
    }
    for(auto x : checkValue)
    {
        if((DIGITS.find(x) == string::npos))
        {
            if(x == '.' && !oneDecimal)
            {
                oneDecimal = true;
                numEnded = false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            numEnded = true;
        }
    }
    if(oneDecimal && numEnded)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSci(string checkValue)
{
    bool oneDecimal = false;
    bool numEnded = false;
    bool exponentialFound = false;
    bool exponent = false;

    if(checkValue.length() < 1)
    {
        return false;
    }

    if(checkValue[0] == '+' || checkValue[0] == '-')
    {
        checkValue[0] = '1';
    }

    for(auto x : checkValue)
    {
        if(!(isdigit(x)))
        {
            if(x == '.' && !oneDecimal && !exponentialFound)
            {
                oneDecimal = true;
                numEnded = false;
            }
            else if(x == 'e' || x == 'E')
            {
                exponentialFound = true;
            }
            else if(exponentialFound && (x == '-' || x == '+'))
            {
                exponent = true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            numEnded = true;
        }
    }
    if(oneDecimal && numEnded && exponentialFound)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isHex(string checkValue)
{
    bool endOfHex = false;
    if(checkValue.length() < 1)
    {
        return false;
    }

    for(auto x : checkValue)
    {
        if(!(isdigit(x)) && HEXIDECIMAL.find(x) == string::npos)
        {
            if(x == 'H')
            {
                endOfHex = true;
            }

            else
            {
                return false;
            }
        }
    }
    return endOfHex;
}

bool isStr(string checkValue)
{
    bool isString = false;
    if(checkValue.length() < 1)
    {
        return false;
    }
    if(checkValue[0] != '"')
    {
        return false;
    }
    for(auto x : checkValue)
    {
        isString = false;
        if(x == '"')
        {
            isString = true;
        }
        else if(x == ' ')
        {
            return false;
        }
    }
    return isString;
}

bool isCharacter(string checkValue)
{
    if(checkValue.length() < 1)
    {
        return false;
    }

    int characterCount = 0;
    for(auto x : checkValue)
    {
        if(isdigit(x) || HEXIDECIMAL.find(x) != string::npos)
        {
            characterCount++;
        }
        else if(x == 'X' && characterCount == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool isIdentifier(string checkValue)
{
    if(checkValue.length() < 1)
    {
        return false;
    }

    if(ALPHABET.find(checkValue[0]) == string::npos)
    {
        return false;
    }

    bool state = false;
    for(auto x : checkValue)
    {
        if(isdigit(x) || ALPHABET.find(x) != string::npos || x == '_')
        {
            state = true;
        }
        else
        {
            return false;
        }
    }
    return state;
}

int main()
{
    string lines;
    cin >> lines;
    cout << lines << endl;

    int i = 0;
    string myText;
    while(cin >> myText)
    {
        i++;
        if(isInt(myText))
        {
            cout << to_string(i)+": Integer\n";
        }
        else if(isDec(myText))
        {
            cout << to_string(i)+": Decimal\n";
        }
        else if(isSci(myText))
        {
            cout << to_string(i)+": Scientific\n";
        }
        else if(isHex(myText))
        {
            cout << to_string(i)+": Hexadecimal\n";
        }
        else if(KEYWORDS.find(myText) != string::npos)
        {
            cout << to_string(i)+": Keyword\n";
        }
        else if(isStr(myText))
        {
            cout << to_string(i)+": String\n";
        }
        else if(isCharacter(myText))
        {
            cout << to_string(i)+": Character\n";
        }
        else if(isIdentifier(myText))
        {
            cout << to_string(i)+": Identifier\n";
        }
        else
        {
            cout << to_string(i) + ": INVALID!\n";
        }
    }
}