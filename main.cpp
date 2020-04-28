#include "multiplicator.h"
#include "number.h"
#include <fstream>
#include <vector>


void test()
{
    std::srand(time(NULL));
    Number num1("7");
    Number num2("9999");
    Number num3("999");
    Number num4("12");
    Number num5("123");
    Number num6("0");
    Number num7("9");
    Number num8("6122152448");
    Number num9("9128371287");


    Number tester_1 = Number::split(num1).first;
    Number tester_2 = Number::split(num1).second;
    std::cout << "Splitted one - digit number: " << tester_1 << " & " << tester_2 << '\n';
    Number tester_3 = Number::split(num4).first;
    Number tester_4 = Number::split(num4).second;
    std::cout << "Splitted two - digit number: " << tester_3 << " & " << tester_4 << '\n';
    Number tester_5 = Number::split(num3).first;
    Number tester_6 = Number::split(num3).second;
    std::cout << "Splitted three - digit number: " << tester_5 << " & " << tester_6 << '\n';
    std::cout << "Two random 10 - digit numbers: " << Multiplicator::randomize(10) << "  &  " << Multiplicator::randomize(10) << '\n';

    std::cout << "GSM 12 * 123 = " << Multiplicator::GSM(num4, num5) << '\n';
    std::cout << "GSM 9999 * 9999 = " << Multiplicator::GSM(num2, num2) << '\n';
    std::cout << "GSM of 2 really big numbers: " << Multiplicator::GSM(num8, num9) << '\n';
    std::cout << "Div&Conq 9999 * 9999 = " << Multiplicator::divConq(num2, num2) << '\n';
    std::cout << "Div&Conq of 2 really big numbers: " << Multiplicator::divConq(num8, num9) << '\n';
    std::cout << "Div&Conq 12 * 123 = " << Multiplicator::divConq(num4, num5) << '\n';
    std::cout << "Karatsuba of 2 really big numbers: " << Multiplicator::karatsuba(num8, num9) << '\n';
    std::cout << "Karatsuba 9999 * 9999 = " << Multiplicator::karatsuba(num2, num2) <<'\n';
    std::cout << "Karatsuba 123 * 12 = " << Multiplicator::karatsuba(num5, num4) << '\n';
}




int main()
{
    test();
    std::srand(time(NULL));
    std::ofstream file;
    int i;
    file.open("/Users/glas/Desktop/test.csv");      //but you need to write your own path to this CSV
    for(i = 1; i < 100; i++)
    {
        Number N = Multiplicator::randomize(i);
        Number M = Multiplicator::randomize(i);
        file << i << ";";
        clock_t start = clock();
        Multiplicator::GSM(N, M);
        clock_t finish = clock();
        double secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                              //GSM

        start = clock();
        Multiplicator::divConq(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                              //Divide&Conquer

        start = clock();
        Multiplicator::karatsuba(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << '\n';                                   //Karatsuba
    }

    for(i = 100; i < 1000; i = i + 100)
    {
        Number N = Multiplicator::randomize(i);
        Number M = Multiplicator::randomize(i);
        file << i << ";";
        clock_t start = clock();
        Multiplicator::GSM(N, M);
        clock_t finish = clock();
        double secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                              //GSM

        start = clock();
        Multiplicator::divConq(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                              //Divide&Conquer

        start = clock();
        Multiplicator::karatsuba(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << '\n';                               //Karatsuba
    }

    for(i = 1000; i < 5000; i = i + 500)
    {
        Number N = Multiplicator::randomize(i);
        Number M = Multiplicator::randomize(i);
        file << i << ";";
        clock_t start = clock();
        Multiplicator::GSM(N, M);
        clock_t finish = clock();
        double secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                        //GSM

        start = clock();
        Multiplicator::divConq(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << ";";                              //Divide&Conquer

        start = clock();
        Multiplicator::karatsuba(N, M);
        finish = clock();
        secSpent = double (finish - start) / (CLOCKS_PER_SEC);
        file << std::fixed << secSpent << '\n';                               //Karatsuba
    }
}
