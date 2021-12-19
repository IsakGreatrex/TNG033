/*****************************************
 * Lab 3: exercise 2                      *
 * Anagrams table                         *
 ******************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>
#include <set>

// Define a testing function to check the contents of the anagrams table

void test(const std::map<std::string, std::set<std::string>> &t, const std::string &file_name);


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

    std::map<std::string, std::set<std::string>> table;
        
    std::vector<std::string> words{};
    
    std::copy(std::istream_iterator<std::string>{in_File},std::istream_iterator<std::string>{},back_inserter(words));
    
    std::cout << "Antal ord i words: " << words.size() << "\n";
    
    /*auto sortAlfa = [&table](std::string &inWord){
        std::string copy = inWord;
        std::sort(copy.begin(), copy.end());
        //map (key, value)
        table[copy].insert(inWord);
    };*/
    
    std::for_each(words.begin(),words.end(), [&table](std::string &inWord){
        std::string copy = inWord;
        std::sort(copy.begin(), copy.end());
        //map (key, value)
        table[copy].insert(inWord);
    });
    
    /*
    for (auto i : words) {
        std::cout << i << "\n";
    }*/
    
    std::cout << "Anagrams alphabeticly sorted: " << "\n";
   /*
    std::for_each(table.begin(), table.end(),
                  [](const std::pair<std::string, std::set<std::string>> &p){
        std::cout << p.first << "\n";
    });*/
    
    std::for_each(table.begin(), table.end(),
                        [](const std::pair < std::string, std::set<std::string>> &p){
        if (p.second.size() > 1){
            std::cout << "\n" << p.first << " , has  " << p.second.size() << " Anagrams : ";
           std::for_each(p.second.begin(), p.second.end(),
                        [](const std::string &s){
            std::cout << " " << s ;
           });
        }
    });
    
    std::cout << "\n";
    
    
    
    /* ************** Testing **************** */
    test(table, name);

    // Call testing function
}


void test (const std::map<std::string, std::set<std::string>> &t, const std::string &file_name){
    
    std::ifstream file{"/Users/isakgreatrex/Desktop/TNG033-labs/lab3\ 2/code/out_" + file_name};
    
    assert(bool(file) == true);
    
    std::map<std::string, std::set<std::string>> table2;
    
    std::vector<std::string> words2{};
    
    std::copy(std::istream_iterator<std::string>{file},std::istream_iterator<std::string>{},back_inserter(words2));
    
    auto sortAlfa = [&table2](std::string &inWord){
        std::string copy = inWord;
        std::sort(copy.begin(), copy.end());
        //map (key, value)
        table2[copy].insert(inWord);
    };
    
    std::for_each(words2.begin(),words2.end(), sortAlfa);

    
    assert(t == table2);
    
}
