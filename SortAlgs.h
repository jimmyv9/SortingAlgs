//
// Created by João Pedro Veloso on 24/10/17.
//

#ifndef INC_3_VELOSO_JOAO_SORTALGS_H
#define INC_3_VELOSO_JOAO_SORTALGS_H

#include <vector>
using namespace std;

class SortAlgs {
public:
    template<class T>
    void nSqSort(vector<T> &a, unsigned count) {
        //insertion sort
        T hold;
        int j;
        for (int i = 1; i < count; i++) {
            hold = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > hold) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = hold;
        }
    }

    template<class T>
    void bubbleSort(vector<T> &a, unsigned count) {
        T hold;
        for (int i = 0; i < count; i++) {
            for (int j = 1; j < count; j++) {
                if (a[j - 1] > a[j]) {
                    hold = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = hold;
                }
            }
        }
    }

    template<class T>
    void nLgNSort(vector<T> &a, unsigned count) {
        if (count > 1) {
            vector<T> list1(count / 2);
            vector<T> list2(count - count / 2);
            int i, j;
            for (i = 0; i < count / 2; i++) {
                list1[i] = a[i];
            }
            for (j = 0; i < count; i++, j++) {
                list2[j] = a[i];
            }
            nLgNSort(list1, count / 2);
            nLgNSort(list2, count - count / 2);
            mergeAux(list1, count / 2, list2, count - count / 2, a, count);
        }
    }

    template<class T>
    void mergeAux(const vector<T> list1, unsigned size1, const vector<T> list2, unsigned size2, vector<T> &a,
                  unsigned count) {
        int i = 0; //goes through list1
        int j = 0; //goes through list2
        int k = 0; //goes through a

        while (i < size1 && j < size2) {
            if (list1[i] <= list2[j]) {
                a[k] = list1[i];
                i++;
            } else {
                a[k] = list2[j];
                j++;
            }
            k++;
        }
        if (i == size1) {
            while (j < size2) {
                a[k] = list2[j];
                k++;
                j++;
            }
        } else {
            while (i < size1) {
                a[k] = list1[i];
                k++;
                i++;
            }
        }
    }

    template<class T>
    void quickSort(vector<T> &a, int first, int last) {
        int pos = split(a, first, last);
        if (first < pos - 1)
            quickSort(a, first, pos-1);
        if (pos < last)
            quickSort(a, pos, last);
    }

    template<class T>
    int split(vector<T> &a, int first, int last) {
        T pivot = a[(first+last)/2];
        int left = first;
        int right = last;

        while (left <= right) {
            while (a[right] > pivot)
                right--;
            while (a[left] < pivot)
                left++;
            if (left <= right) {
                T temp = a[left];
                a[left] = a[right];
                a[right] = temp;
                left++;
                right--;
            }
        }
        return left;
    }
};


#endif //INC_3_VELOSO_JOAO_SORTALGS_H
