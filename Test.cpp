#include <iostream>
#include <string>
#include <algorithm>

std::string ToLowerRegister(std::string Stroka)
{
    std::transform(Stroka.begin(), Stroka.end(), Stroka.begin(), std::tolower); 
    return Stroka;
}

std::string SymbolReplacement(std::string Stroka)
{
    Stroka=ToLowerRegister(Stroka); //перевод всех символов в нижний регистр

    std::string::iterator firstIt, secondIt; //Создаем два итератора, чтобы можно было как обращаться к элементу, так получить его значение 

    for (firstIt = Stroka.begin(); firstIt != Stroka.end(); firstIt++) //выбираем первый итератор, как элемент сравнения с остальными элементами, начиная со следующего
    {
        for (secondIt = firstIt + 1; secondIt != Stroka.end(); secondIt++)
        {
            auto v = *secondIt;

            if (*secondIt == *firstIt) 
            {
                std::replace(Stroka.begin(), Stroka.end(), v, ')');
            }
        }
    }

    int b = 0;
    for (firstIt = Stroka.begin(); firstIt != Stroka.end(); b++) //замена элементов, не являющимися чьими-то дублями
    {
        if (*firstIt != ')') Stroka[b] = '(';
        firstIt++;
    }
    return Stroka;
}
int main()
{
    std::string Stroka;
    getline(std::cin,Stroka);
    Stroka = SymbolReplacement(Stroka);
    std::cout << Stroka;
    return 0;
}

