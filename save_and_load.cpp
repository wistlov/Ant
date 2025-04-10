#include "save_and_load.h"

std::filesystem::path save_path{"scores.txt"};


void save_score() {
    // makes it so we can edit the file
    std::ofstream file(save_path, std::ios::app);
    
    // We must make it so the player knows they have to go to the terminal to write their name
    std::string name;
    std::cout << "Enter a name: ";
    std::getline(std::cin, name);

    // checks if it works. Maybe put error handling here??
    if (file.is_open()) {
        file << name << " " << score << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
        // This is where error handling could be
    }
}

void get_name_and_score(std::vector<std::string>& score_list) {

    std::ifstream file(save_path);

    if (file.is_open()) {
        std::string name;
        int score;

        // Read each line from the file
        while (file >> name >> score) {
            score_list.push_back(name+" - "+std::to_string(score));
        }

        file.close();
    } else {
        std::cerr << "Unable to open file.\n";
        // Second error handling??
    }
}