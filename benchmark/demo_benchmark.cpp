#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

const string setsPath = "C:/Users/EvveKiNG/Desktop/sets";
const string outputPath = "C:/Users/EvveKiNG/Desktop/results/";

string folders[10] = {"/01/",
                      "/02/",
                      "/03/",
                      "/04/", "/05/", "/06/",
                      "/07/", "/08/", "/09/",
                      "/10/"};
string files[14] = {"100", "500", "1000", "5000", "10000", "25000", "50000", "100000",
                   "250000", "500000", "750000", "1000000", "2500000", "5000000"};


void writeResults(string file, long insert_time, long search_time, long delete_time){
    const auto output = string(outputPath);
    std::ofstream out(output + file + "/insert_result.txt", std::ios::app);
    if (out.is_open())
    {
        out << insert_time << std::endl;
    }
    out.close();

    std::ofstream out1(output + file + "/search_result.txt", std::ios::app);
    if (out1.is_open())
    {
        out1 << search_time << std::endl;
    }
    out1.close();

    std::ofstream out2(output + file + "/delete_result.txt", std::ios::app);
    if (out2.is_open())
    {
        out2 << delete_time << std::endl;
    }
    out2.close();
}

int main() {
    // работа с набором данных
    const auto path = string(setsPath);
    string line;
    int c = 0;
    for (auto file : files) {
        for (auto folder : folders) {
            for (int i = 0; i < 1; i++) { // 10 раз прогоняем один и тот же csv файл
                auto input_file_insert = ifstream(path + folder + file + ".csv");
                auto input_file_search = ifstream(path + folder + file + ".csv");
                auto input_file_delete = ifstream(path + folder + file + ".csv");

                AATree *tree = new AATree; // Создание структуры

                // сам бенчмарк, в данном случае создание (добавление)
                auto time_point_before_insert = chrono::steady_clock::now();
                while (getline(input_file_insert, line, ',')) {
                    tree->Add(stoi(line));
                }
                auto time_point_after_insert = chrono::steady_clock::now();
                auto time_diff_insert = time_point_after_insert - time_point_before_insert;
                long insert_time = chrono::duration_cast<chrono::nanoseconds>(time_diff_insert).count();


                // сам бенчмарк, в данном случае создание (поиск)
                auto time_point_before_search = chrono::steady_clock::now();
                while (getline(input_file_search, line, ',')) {
                    tree->Search(stoi(line));
                }
                auto time_point_after_search = chrono::steady_clock::now();
                auto time_diff_search = time_point_after_search - time_point_before_search;
                long search_time = chrono::duration_cast<chrono::nanoseconds>(time_diff_search).count();


                /*
                // сам бенчмарк, в данном случае создание (удаление)
                auto time_point_before_delete = chrono::steady_clock::now();
                while (getline(input_file_delete, line, ',')) {
                    cout << c << endl;
                    c++;
                    tree->Delete(stoi(line));
                }
                auto time_point_after_delete = chrono::steady_clock::now();
                auto time_diff_delete = time_point_after_delete - time_point_before_delete;
                long delete_time = chrono::duration_cast<chrono::nanoseconds>(time_diff_delete).count();

                 */


                delete tree;

                writeResults(file, insert_time, search_time, 0);
            }
        }
    }
}

