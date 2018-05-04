#include <iostream>
#include <string>
#include <vector>

#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "BucketSort.hpp"

int main(){
    clock_t start;
    double duration{0};
    std::vector<double> vec_heap;
    std::vector<double> vec_quick;
    std::vector<double> vec_bucket;
    int liczba{0}, decision{0};
    std::string file_before_sort{""};
    std::string file_after_sort{""};
    std::string rozszerzenie{".csv"};

    std::cout << "Podaj nazwe pliku z ktorego odczytac: "; std::cin >> file_before_sort;
    std::cout << "Podaj nazwe pliku do ktorego zapisac: "; std::cin >> file_after_sort;
    file_after_sort  += rozszerzenie;
    file_before_sort += rozszerzenie;
    
    while(true)
    {
            std::vector<double> sorted_time{0.0};
            std::cout << "1. Quick Sort \n";
            std::cout << "2. Heap Sort \n";
            std::cout << "3. Bucket Sort \n";
            std::cout << "4. end \n";
            std::cin >> decision;

    switch(decision)
    {
        case 1: {
                QuickSort quick;
                quick.implement_random(file_before_sort);
                vec_quick = quick.get_data(file_before_sort);
                std::cout << "how many?"; cin >> liczba;
                duration = quick.quick_sort(vec_quick, liczba);
                quick.data_time(liczba, duration);
                quick.set_data(vec_quick, file_after_sort, liczba);
        } break;

        case 2: {
                HeapSort heap;
                heap.implement_random(file_before_sort);
                vec_heap = heap.get_data(file_before_sort);
                std::cout << "how many? "; cin >> liczba;
                duration = heap.heap_sort(vec_heap, liczba);
                heap.data_time(liczba, duration);
                heap.set_data(vec_heap, file_after_sort, liczba);
                heap.display_heap_sort(vec_heap, "HEAP: ");
        } break;

        case 3: {
                BucketSort bucket;
                bucket.implement_random(file_before_sort);
                vec_bucket = bucket.get_data(file_before_sort);
                std::cout << "how many? "; std::cin >> liczba;
                duration = bucket.bucket_sort(vec_bucket, liczba);
                bucket.data_time(liczba, duration);
                bucket.set_data(vec_bucket, file_after_sort, liczba);
                bucket.display_bucket_sort(vec_bucket, "BUCKET: ");
                
        } break;

        case 4: return 0; break;
        default: return 0; break;
    }
    }
}