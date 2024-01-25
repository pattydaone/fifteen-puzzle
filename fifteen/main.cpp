//
//  main.cpp
//  fifteen
//
//  Created by Patrick Howland on 1/15/24.
//

#include <iostream>
#include <array>
#include <algorithm>
#include "random.h"

struct Empty {
    std::size_t row {};
    std::size_t column {};
};

class Fifteen {
public:
    Fifteen() {
        for (int i { 0 }; i < 100000; ++i) {
            int x { Random::get(0, 3) };
            switch (x) {
                case 0:
                    input_w();
                    break;
                case 1:
                    input_a();
                    break;
                case 2:
                    input_s();
                    break;
                case 3:
                    input_d();
                    break;
                default:
                    break;
            }
        }
    }
    
    void run() {
        print_table();
        while (!check_correct()) {
            std::cout << "Please enter your input: ";
            std::cin >> input;
            if (std::find(valid_inputs.begin(), valid_inputs.end(), input) == valid_inputs.end()) {
                std::cout << "Invalid input. Try again\n";
                continue;
            }
            
            switch (input) {
                case 'w':
                    input_w();
                    print_table();
                    break;
                case 'a':
                    input_a();
                    print_table();
                    break;
                case 's':
                    input_s();
                    print_table();
                    break;
                case 'd':
                    input_d();
                    print_table();
                    break;
                    
                default:
                    break;
            }
        }
        std::cout << "You won!\n";
    }
private:
    std::array<std::array<int, 4>, 4> main_arr {{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    }};
    
    const std::array<char, 4> valid_inputs { 'w', 'a', 's', 'd' };
    
    Empty empty {3, 3};
    char input {};
    int swaps_number{ 0 };
    
    bool check_correct() {
        int num { 1 };
        for (std::array<int, 4> i : main_arr) {
            for (int j : i) {
                if (j != num) { return false; }
                ++num;
            }
        }
        return true;
    }
    
    void print_table() {
        for (int i { 0 }; i < main_arr.size(); ++i) {
            std::cout << "| ";
            for (int j { 0 }; j < main_arr[i].size(); ++j) {
                if (main_arr[i][j] == 16) { std::cout << "   "; }
                else if (main_arr[i][j] < 10) { std::cout << " " << main_arr[i][j] << " "; }
                else { std::cout << main_arr[i][j] << " "; }
            }
            std::cout << "|\n";
        }
    }
    
    void input_w() {
        try {
            std::swap(main_arr[empty.row][empty.column], main_arr.at(empty.row + 1).at(empty.column));
            ++empty.row;
        } catch (std::out_of_range) {
            ;
        }
    }
    
    void input_a() {
        try {
            std::swap(main_arr[empty.row][empty.column], main_arr.at(empty.row).at(empty.column + 1));
            ++empty.column;
        } catch (std::out_of_range) {
            ;
        }
    }
    
    void input_s() {
        try {
            std::swap(main_arr[empty.row][empty.column], main_arr.at(empty.row - 1).at(empty.column));
            --empty.row;
        } catch (std::out_of_range) {
            ;
        }
    }
    
    void input_d() {
        try {
            std::swap(main_arr[empty.row][empty.column], main_arr.at(empty.row).at(empty.column - 1));
            --empty.column;
        } catch (std::out_of_range) {
            ;
        }
    }
};

int main(int argc, const char * argv[]) {
    Fifteen test {};
    test.run();
    return 0;
}
