//
// Created by cookie on 26.04.2020.
//

#ifndef MULTIPLICATION_NUMBER_H_   //
#define MULTIPLICATION_NUMBER_H_

#include <iostream>
#include <string>
#include <ctime>
#include <istream>
#include <sstream>



class Number
{
private:
    std::string _number;
public:
    Number(std::string s)
    {
        _number = s;
    }

    Number(){}

    Number operator + (Number& myNum) const
    {
        long long i, j;
        int sum, remainder = 0;
        std::string copied = _number;
        if(copied.length() < myNum._number.length())
            std::swap(copied, myNum._number);
        j = copied.length() - 1;
        i = myNum._number.length() - 1;
        while(i >= 0)
        {
            sum = (copied[j] - '0') + (myNum._number[i] - '0') + remainder;
            copied[j] = (sum % 10) + '0';
            remainder = sum / 10;
            i--;
            j--;
        }
        while(remainder != 0)
        {
            if(j < 0)
            {
                copied.insert(0, "1");
                remainder = 0;
            }
            else if(j == 0)
            {
                sum = (copied[0] - '0') + remainder;
                if(sum < 10)
                {
                    copied[0] = sum + '0';
                    remainder = 0;
                }
                else
                {
                    copied[0] = '0';
                    copied.insert(0, "1");
                    remainder = 0;
                }
            }
            else if (j > 0)
            {
                sum = (copied[j] - '0') + remainder;
                if(sum < 10)
                {
                    copied[j] = sum + '0';
                    remainder = 0;
                }
                else
                {
                    copied[j] = '0';
                    remainder = 1;
                    j--;
                }
            }
        }
        while((copied.length() != 1) && (copied[0] == '0'))
        {
            copied.erase(copied.begin());
        }
        Number N(copied);
        return N;
    }

    Number operator - (Number& myNum) const
    {
        long long i, j;
        int difference;
        std::string copied = _number;
        if(copied.length() < myNum._number.length())
            std::swap(copied, myNum._number);
        j = copied.length() - 1;
        i = myNum._number.length() - 1;
        while(i >= 0)
        {
            difference = (copied[j] - '0') - (myNum._number[i] - '0');
            if(difference < 0)
            {
                copied[j - 1] = (((copied[j - 1] - '0') - 1) + '0');
                difference = 10 + difference;
                copied[j] = difference + '0';
            }
            else
                copied[j] = (difference + '0');
            j--;
            i--;
        }
        while((copied.length() != 1) && (copied[0] == '0'))
        {
            copied.erase(copied.begin());
        }
        return copied;
    }

    Number& operator = (const Number& myNum)
    {
        _number = myNum._number;
        return *this;
    }

    static std::string getString(Number& myNum)
    {
        return myNum._number;
    }

    const char operator [] (long long i) const
    {
        return _number[i];
    }

    char operator [] (long long i)
    {
        return _number[i];
    }

    friend std::ostream& operator << (std::ostream& out, const Number& myNum)
    {
        for(unsigned long long i = 0; i < myNum._number.length(); i++)
        {
            out << myNum._number[i];
        }
        return out;
    }

    static std::pair<Number, Number> split(Number& myNum)
    {
        std::pair<Number, Number> splitted;
        std::string s1, s2, original;
        original = myNum._number;
        unsigned long long i;
        for(i = 0; i < original.length() / 2; i++)
        {
            s1.push_back(original[i]);
        }
        for(i = original.length() / 2; i < original.length(); i++)
        {
            s2.push_back(original[i]);
        }
        splitted.first._number = s1;
        splitted.second._number = s2;
        return splitted;
    }
};

#endif //MULTIPLICATION_NUMBER_H
