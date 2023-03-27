#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int get_file_info(std::string filename, char separator, std::vector<std::string> &words_vec, int &line_counter, int &column_counter);


int main(int argc, char* argv[]){

    std::string filename;
    char separator;


    // If no argument is given,
    // ask user to write path of file
    if(argc == 1){
        std::cout << "You haven't give me any arguments! \n"
                  << "Please insert path to the file here: ";
        std::cin >> filename;

        std::cout << "Character that separates the words in file "
                  << "(by default it's set to space): ";
        std::cin.get();
        separator = getchar(); 
        
        if(filename == ""){
            std::cout << "File path cannot be empty! Exiting the program..." << std::endl;
            return 1;
        }

        if(separator == '\n')
            separator = ' ';
    }
    else{
        filename  = argv[1];
        
        if(argc > 2)
            separator = argv[2][0];
        else
            separator = ' ';
    }
    
    int row_counter = 0, column_counter = 0;
    std::vector<std::string> words_vec;

    // function - get file info
    int max_length_of_word_in_file = get_file_info(filename, separator, words_vec, row_counter, column_counter);
    

    // Creating horizontal border
    std::string border;
    for(int i = 0; i < (max_length_of_word_in_file + 3.5) * column_counter; i++)
        border += '-';

    std::string spaces;


    // Creating and displaying table
    std::cout << border << std::endl;
    for(int i = 0; i < words_vec.size(); i++){

        for(int j = 0; j <= max_length_of_word_in_file - words_vec[i].length(); j++)
            spaces += ' ';
        

        std::cout << "| " << words_vec[i] << spaces;
        spaces = "";
        
        if((i + 1) % column_counter == 0){
            std::cout << " |\n";
            std::cout << border << std::endl;
        }
    }
}


int get_file_info(std::string filename, char separator, std::vector<std::string> &words_vec, int &line_counter, int &column_counter){
    // Opening file 

    std::fstream file;
    file.open(filename, std::ios::in);
    
    if(!file.good()){
        std::cout << "Cannot open file: " << filename << std::endl;
        return 1;
    }

    std::string line, current_word;
    int length_of_longest_word = 0, current_length = 0;

    int previos_column_counter = 0;
    while(getline(file, line)){
        line_counter++;

        previos_column_counter = column_counter;


        // Correction if separator is not placed at the end of the line
        line += (line[line.length() - 1] == separator) ? '\0' : separator;

        column_counter = 0;
        // Adding word and searching for longest one
        for(char character:line){

            if(character == separator){
                words_vec.push_back(current_word);

                if(current_word.length() > length_of_longest_word)
                    length_of_longest_word = current_word.length();

                current_word = "";

                column_counter++;
            }
            else{
                current_word += character;
            }
        }

        // Checking if number of columns is apprioate
        if(column_counter != previos_column_counter && previos_column_counter != 0){
            std::cout << "Wrong table structure! " 
                      << "Check if number of columns is equal for every row" << std::endl;
            exit(1);
        }
    }

    file.close();

    return length_of_longest_word;
}
