#include "save_and_load.h"

std::filesystem::path save_path{"scores.txt"};


void save_score() {
    // makes it so we can edit the file
    std::ofstream file(save_path, std::ios::app);
    
    // We must make it so the player knows they have to go to the terminal to write their name
    std::string name;
    std::cout << "Enter a name: ";
    std::getline(std::cin, name);

    // Error handling 1! :D
    try {
        file << name << " " << score << std::endl;
        file.close();
    } catch(const std::ofstream::failure& e) {
        std::cerr << "Unable to open file, I think" << std::endl;
        // This is where error handling could be
    }
}

void get_name_and_score(std::vector<std::pair<std::string, int>>& score_list) {

    std::ifstream file(save_path);

    try {
        std::string name;
        int score;

        // Read each line from the file
        while (file >> name >> score) {
            //score_list.push_back(name+" - "+std::to_string(score));
            score_list.push_back({name, score});
        }

        file.close();
    } catch(const std::ofstream::failure& e) {
        // Second error handling! :D
        std::cerr << "Unable to open file." << std::endl;;
    }
}