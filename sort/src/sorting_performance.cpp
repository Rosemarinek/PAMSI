#include "timer.hpp"
#include "sorting/sorting.hpp"

#include <thread>
#include <iostream>

#define TEN_THOUSAND 10000
#define HUNDRED_THOUSAND 100000
#define MILLION 1000000

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    std::vector<int> b_ten(TEN_THOUSAND);
    std::vector<int> b_hundred(HUNDRED_THOUSAND);
    std::vector<int> b_million(MILLION);

    std::vector<int> q_ten(TEN_THOUSAND);
    std::vector<int> q_hundred(HUNDRED_THOUSAND);
    std::vector<int> q_million(MILLION);

    std::vector<int> m_ten(TEN_THOUSAND);
    std::vector<int> m_hundred(HUNDRED_THOUSAND);
    std::vector<int> m_million(MILLION);

    for(int i = 0; i < TEN_THOUSAND ; i++)
    {
        b_ten[i] = rand();
        q_ten[i]=b_ten[i];
        m_ten[i]=b_ten[i];
    }

    for(int i = 0; i < HUNDRED_THOUSAND ; i++)
    {
        b_hundred[i] = rand();
        q_hundred[i]=b_hundred[i];
        m_hundred[i]=b_hundred[i];
    }

    for(int i = 0; i < MILLION ; i++)
    {
        b_million[i] = rand();
        q_million[i]=b_million[i];
        m_million[i]=b_million[i];
    }

    Timer timer;

    timer.start();
    quickSort(q_ten,0,size(q_ten)-1);
    timer.stop();
    std::cout << "Quick sort for 10 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    quickSort(q_hundred,0,size(q_hundred)-1);
    timer.stop();
    std::cout << "Quick sort for 100 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    quickSort(q_million,0,size(q_million)-1);
    timer.stop();
    std::cout << "Quick sort for 1 000 0000 elements: waited for " << timer.sInterval() << "s\n";

    std::cout<<"\n";

    timer.start();
    mergeSort(q_ten,0,size(q_ten)-1);
    timer.stop();
    std::cout << "Merge sort for 10 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    mergeSort(q_hundred,0,size(q_hundred)-1);
    timer.stop();
    std::cout << "Merge sort for 100 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    mergeSort(q_million,0,size(q_million)-1);
    timer.stop();
    std::cout << "Merge sort for 1 000 0000 elements: waited for " << timer.sInterval() << "s\n";

    std::cout<<"\n";


    timer.start();
    bubbleSort(b_ten);
    timer.stop();
    std::cout << "Bubble sort for 10 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    bubbleSort(b_hundred);
    timer.stop();
    std::cout << "Bubble sort for 100 0000 elements: waited for " << timer.sInterval() << "s\n";

    timer.start();
    bubbleSort(b_million);
    timer.stop();
    std::cout << "Bubble sort for 1 000 0000 elements: waited for " << timer.sInterval() << "s\n";


    return 0;
}
