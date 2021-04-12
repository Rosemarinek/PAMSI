#ifndef SORTING_HPP_
#define SORTING_HPP_

#include <vector>

void bubbleSort(std::vector<int>& tab);
void quickSort(std::vector<int>& tab, int left, int right);
void merge(std::vector<int> &tab, int left, int middle, int right);
void mergeSort(std::vector<int>& tab, int left, int right);

#endif /* SORTING_HPP_ */

