#include "sorting/sorting.hpp"
#include "timer.hpp"

#include <algorithm>
#include <ctime>

#define FIVE 5000

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    std::ofstream result;
    result.open("../results/quick_result.csv");
    chooseAlgorithm(quickSort, result, false);

    result.open("../results/merge_result.csv");
    chooseAlgorithm(mergeSort, result, false);

    result.open("../results/pess_quick_result.csv");
    chooseAlgorithm(pessQuickSort, result, true);

    result.open("../results/bubble_result.csv");
    chooseAlgorithm(bubbleSort, result, false);

    return 0;
}

void chooseAlgorithm(sortingFunction algorithm, std::ofstream& plik, bool reverse)
{
    int size = FIVE;

    for(int k = 0; k < 25; k++)
    {
        for(int i = 0; i < 20; i++)
        {
            std::vector<int> data_vector(size);

            for(int& j : data_vector)
            {
                j = rand() % 3000000;
            }

            if(reverse == true)
            {
                std::sort(data_vector.begin(), data_vector.end());
                std::reverse(data_vector.begin(), data_vector.end());
            }

            Timer timer;

            timer.start();
            algorithm(data_vector);
            timer.stop();

            if(plik.good())
            {
                plik << timer.sInterval() << " " << size << "\n";
            }
            else
                std::cout << "File error \n";

            size = size + FIVE;
        }
        size = FIVE;
    }
    plik.close();
}