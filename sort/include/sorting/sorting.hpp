#ifndef SORTING_HPP_
#define SORTING_HPP_

#include <vector>
#include <iostream>
#include <fstream>

void bubbleSort(std::vector<int>& tab);
void quickSort(std::vector<int>& tab);
void pessQuickSort(std::vector<int>& tab);
void mergeSort(std::vector<int>& tab);

typedef void (*sortingFunction)(std::vector<int>&);
void chooseAlgorithm(sortingFunction algorithm, std::ofstream& plik, bool reverse);

#endif /* SORTING_HPP_ */

