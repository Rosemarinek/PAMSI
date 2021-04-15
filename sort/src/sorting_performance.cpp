#include "sorting/sorting.hpp"
#include "timer.hpp"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>

#define FIVE 5000
#define TEN_THOUSAND 10000
#define FIFTY 50000
#define TWO_HUNDRED 200000
#define MILLION 1000000

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int size = FIVE;
    std::ofstream result;
    result.open("../results/quick_result.csv");

    for(int k = 0; k < 20; k++)
    {
        for(int i = 0; i < 20; i++)
        {
            std::vector<int> data_vector(size);

            for(int& j : data_vector)
            {
                j = rand() % 3000000;
            }

            Timer timer;

            timer.start();
            quickSort(data_vector, 0, size - 1);
            timer.stop();
            std::cout << "Quick sort (nlogn) for " << size << " elements in " << timer.sInterval() << "s\n";

            if(result.good())
            {
                result << timer.sInterval() << " " << size << "\n";
            }
            else
                std::cout << "File error \n";

            size = size + FIVE;
        }
        size = FIVE;
    }
    result.close();


    //    std::sort(pq_ten.begin(), pq_ten.end());
    //    std::reverse(pq_ten.begin(), pq_ten.end());

    return 0;
}
