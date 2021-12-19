/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>

/*******************************
 * 1. Declarations              *
 ********************************/

using Word_Freq = std::pair<std::string, int>;

void print_map(std::string_view comment, const std::map<std::string, int>& m)
{
    std::cout << comment;
    for (const auto& [key, value] : m) {
        std::cout << key << " = " << value << "; ";
    }
    std::cout << "\n";
}

bool noChars(const char & c){
    std::string chars {".,!?:\"();)"};
    return (chars.find(c) != std::string::npos);
}

void removeChar(std::string& w){
    w.erase(remove_if(w.begin(),w.end(),noChars),w.end());
}

std::string toLower(std::string& s){
    std::transform(s.begin(), s.end(), s.begin(), tolower);
    return s;
}


// A function to test the tables created by the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);


bool sort (Word_Freq p1, Word_Freq p2){
    if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    };


/*******************************
 * 2. Main function             *
 *******************************/

int main() {
    std::string name{};
    std::cout << "Text file: ";
    std::cin >> name;
    
    std::cout << "name: " << name << '\n';

    std::ifstream in_File{"/Users/isakgreatrex/Desktop/TNG033-labs/lab3\ 2/code/" + name};

    if (!in_File) {
        std::cout << "Could not open input file!!\n";
        return 0;
    }

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    //ADD CODE to build table

   //std::vector<Word_Freq> freq;

    //ADD CODE to build vector freq
    std::string inWord{};
    
    while(in_File >> inWord){
        removeChar(inWord);
        toLower(inWord); //
        table[inWord]++; //add to frequency table
        counter++; // increase counter
    }
    
    auto freq = std::vector<Word_Freq>{std::begin(table), std::end(table)};
    
    std::sort(std::begin(freq), std::end(freq), sort);
    
 //   [](std::pair<std::string, int> a, std::pair<std::string, int> b){
        
        

    /* ************** Testing **************** */

    test(table, freq, name, counter);
}


/*******************************
 * 2. Test implementation      *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"/Users/isakgreatrex/Desktop/TNG033-labs/lab3\ 2/code/out_" + file_name};

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }
    
    assert(total == n);  // test if total number of words is correct
    assert(t == result1);

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    
    assert(v == result2);

    std::cout << "\nPassed all tests successfully!!\n";
}
