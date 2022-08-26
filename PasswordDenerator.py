possiblePasswordCombinations = []
incompletePasswordCombination = []


def isfindDigit(Character):
    if Character == '*':
        return True
    return False


def IsPasswordIncomplete(word):
    if ('*' in word):
        return True
    return False


def combineLargeAlphabeticArrayToThePassword(letterPlace, word):
    for i in range(65, 91):
        word = list(word)
        # print(chr(i))
        word[letterPlace] = chr(i)
        word=''.join(word)
        if (IsPasswordIncomplete(word)):
            incompletePasswordCombination.append(word)
        else:
            possiblePasswordCombinations.append(word)


def combineSmallAlphabeticArrayToThePassword(letterPlace, word):
    for i in range(97, 122):
        word = list(word)
        # print(chr(i))
        word[letterPlace] = chr(i)
        word=''.join(word)
        if (IsPasswordIncomplete(word)):
            incompletePasswordCombination.append(word)
        else:
            possiblePasswordCombinations.append(word)


def combineNumberArrayToThePassword(letterPlace, word):
    for i in range(0, 10):
        word = list(word)
        word[letterPlace] = str(i)
        word = ''.join(word)
        # print(word)
        if (IsPasswordIncomplete(word)):
            incompletePasswordCombination.append(word)
        else:
            possiblePasswordCombinations.append(word)


def passwordGenerator(password,isNumericPassword,isLargeAlphabeticPassword,isSmallAlphabeticPassword):
    i = 0
    for x in password:
        if (isfindDigit(x)):
            if (isNumericPassword):
                combineNumberArrayToThePassword(i, password)
            if (isLargeAlphabeticPassword):
                combineLargeAlphabeticArrayToThePassword(i, password)
            if (isSmallAlphabeticPassword):
                combineSmallAlphabeticArrayToThePassword(i, password)
            # // if(symbolEntry)
        i = +1

def getBoolresult(message):
    get = input(message)
    if(get.lower() =='y'):
        return True
    return False
def main():
    password = input("Enter the password in the ** format  :")
    isLargeAlphabeticPassword = getBoolresult("Enter the password contains All Upper Case alphabets (y/n) :")
    isSmallAlphabeticPassword = getBoolresult("Enter the password contains All lower Case alphabets (y/n) :")
    isNumericPassword = getBoolresult("Enter the password conatins Numbers (y/n) :")
    # print(isNumericPassword)
    # print(isLargeAlphabeticPassword)
    # print(isSmallAlphabeticPassword)
    
    incompletePasswordCombination.append(password)
    while (not len(incompletePasswordCombination) == 0):
        passwordGenerator(incompletePasswordCombination[0],isNumericPassword,isLargeAlphabeticPassword,isSmallAlphabeticPassword)
        incompletePasswordCombination.remove(incompletePasswordCombination[0])
    print(possiblePasswordCombinations)
main()