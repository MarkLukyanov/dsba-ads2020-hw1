//
// Created by cookie on 26.04.2020.
//

#ifndef MULTIPLICATION_MULTIPLICATOR_H
#define MULTIPLICATION_MULTIPLICATOR_H

#include "number.h"

class Multiplicator
{
public:
    static Number randomize(int k)
    {
        std::string almostNumber;
        int i = 0, b;
        b = std::rand() % 10;
        while(b == 0)
            b = std::rand() % 10;
        almostNumber.push_back(b + '0');
        i++;
        while(i < k)
        {
            b = std::rand() % 10;
            almostNumber.push_back(b + '0');
            i++;
        }
        Number myNum(almostNumber);
        return myNum;
    }

    static Number GSM(Number& num1, Number& num2)
    {
        long long i, j, zeros = 0;
        int  product, remainder = 0;
        std::string firstNum, secondNum, helper;
        Number result("0");
        firstNum = Number::getString(num1);
        secondNum = Number::getString(num2);
        if(firstNum.length() < secondNum.length())
            std::swap(firstNum, secondNum);
        for(i = secondNum.length() - 1; i >= 0; i--)
        {
            for(j = firstNum.length() - 1; j >= 0; j--)
            {
                product = (firstNum[j] - '0') * (secondNum[i] - '0') + remainder;
                if(product > 9)
                {
                    if(j == 0)
                    {
                        helper.push_back((product % 10) + '0');
                        helper.push_back((product / 10) + '0');
                    }
                    else
                    {
                        helper.push_back((product % 10) + '0');
                        remainder = product / 10;
                    }
                }
                else
                {
                    helper.push_back(product + '0');
                    remainder = 0;
                }
            }
            std::reverse(helper.begin(), helper.end());
            for(int p = 0; p < zeros; p++)
                helper.push_back('0');
            Number N(helper);
            result = result + N;
            zeros += 1;
            helper.clear();
            remainder = 0;
        }
        return result;
    }

    static Number divConq(Number& num1, Number& num2)
    {
        int i, n, m, p;
        std::string firstNum, secondNum, helper;
        firstNum = Number::getString(num1);
        secondNum = Number::getString(num2);
        Number ac, bc, ad, bd, result;
        n = firstNum.length();
        m = secondNum.length();
        if(n < m)
        {
            while(n != m)
            {
                firstNum.insert(0, "0");
                n++;
            }
            num1 = firstNum;
        }
        else if(n > m)
        {
            while(m != n)
            {
                secondNum.insert(0, "0");
                m++;
            }
            num2 = secondNum;
        }
        n = firstNum.length();
        if(n == 1)
            return GSM(num1, num2);
        Number a = Number::split(num1).first;
        Number b = Number::split(num1).second;
        Number c = Number::split(num2).first;
        Number d = Number::split(num2).second;
        n = (n / 2) + (n % 2);
        ac = divConq(a, c);
        ad = divConq(a, d);
        bc = divConq(b, c);
        bd = divConq(b, d);
        Number sum = ad + bc;
        helper = Number::getString(ac);
        for(i = 0; i < 2 * n; i++)
            helper.push_back('0');
        ac = helper;
        helper = Number::getString(sum);
        for(i = 0; i < n; i++)
            helper.push_back('0');
        sum = helper;
        result = ac + sum +bd;
        return result;
    }

    static Number karatsuba(Number& num1, Number& num2)
    {
        int i, n, m, p;
        std::string firstNum, secondNum, helper;
        firstNum = Number::getString(num1);
        secondNum = Number::getString(num2);
        Number ac, bd, result, sum1, sum2, product;
        n = firstNum.length();
        m = secondNum.length();
        if(firstNum.length() < secondNum.length())
        {
            while(n != m)
            {
                firstNum.insert(0, "0");
                n++;
            }
            num1 = firstNum;
        }
        else if(firstNum.length() > secondNum.length())
        {
            while(m != n)
            {
                secondNum.insert(0, "0");
                m++;
            }
            num2 = secondNum;
        }
        n = firstNum.length();
        if(n == 1)
            return GSM(num1, num2);
        Number a = Number::split(num1).first;
        Number b = Number::split(num1).second;
        Number c = Number::split(num2).first;
        Number d = Number::split(num2).second;
        ac = karatsuba(a, c);
        bd = karatsuba(b, d);
        sum1 = a + b;
        sum2 = c + d;
        product = karatsuba(sum1, sum2);
        n = (n / 2) + (n % 2);
        sum1 = product - ac - bd;
        helper = Number::getString(ac);
        for(i = 0; i < 2 * n; i++)
            helper.push_back('0');
        ac = helper;
        helper = Number::getString(sum1);
        for(i = 0; i < n; i++)
            helper.push_back('0');
        sum1 = helper;
        result = ac + sum1 +bd;
        return result;
    }
};

#endif //MULTIPLICATION_MULTIPLICATOR_H