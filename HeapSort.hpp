#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdio>
using namespace std;

class HeapSort{

private:
    std::vector<double> vec;
    std::string plik;
    int liczba{0};
    
public:
    HeapSort(){}
   ~HeapSort(){}

public:
    void implement_random(std::string);
    std::vector<double> get_data(std::string);
    double heap_sort(std::vector<double>& vec, int);
    void data_time(int, double);
    void set_data(std::vector<double>, std::string, int);
    void display_heap_sort(const std::vector<double>& vec, const std::string& text);
};

void HeapSort::implement_random(std::string plik)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 1000);
    
    ofstream file;
    file.open(plik);
 
    for(int i = 0; i < 20000; i++)
    {
        file << dist(mt);
        file << "\n";
    }
    file.close();
}

    vector<double> HeapSort::get_data(std::string plik)
    {
        std::vector<double> vec;
        ifstream file;
        file.open(plik);

        double tmp;

        while(true)
     {
         if(file.good())
            {
                file >> tmp;
                vec.push_back(tmp);
                cout << tmp << "\n";
             }
         else 
          break;

    }
       file.close();
       return vec;

    }

    double HeapSort::heap_sort(std::vector<double>& vec, int liczba)
    {
        std::make_heap(vec.begin(), vec.end());
        double duration{0};
        double start{0};
        start = clock();
        std::sort_heap(vec.begin(), vec.end());
        duration = (clock() - start) / (double)CLOCKS_PER_SEC;
        std::cout << "CZAS: " << duration << "\n";
        return duration;
    }
    void HeapSort::set_data(std::vector<double> vec, std::string plik, int liczba)
    {
        std::ofstream file;

         file.open(plik, std::ofstream::out | std::ofstream::trunc);
    

          for(int i = 0; i < liczba; ++i)
             file << vec[i] << "\n";
          
       file.close();
    }

    void HeapSort::data_time(int number, double val)
    {
        ofstream file;
       
        file.open("heap_time.csv", ios::out | ios::app);
        file << number << "," << val;
        file << "\n";
        file.close();
    }

    void HeapSort::display_heap_sort(const std::vector<double>& vec, const std::string& text)
    {
            cout << text << "\n";
            copy(begin(vec), end(vec), ostream_iterator<double>(cout, " "));
            cout << "\n";
    }