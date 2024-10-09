#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

int main() {
    // 1. Ask user for string
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Convert input to uppercase
    for (char &c : input) {
        c = toupper(c);
    }

    // 2. Create a counter for each character (ASCII values 0-127)
    std::vector<int> counts(128, 0);

    // 3. Iterate over each character and count occurrences
    for (char c : input) {
        counts[static_cast<int>(c)]++;
    }

    // 4. Find character with highest counter
    int maxCount = 0;
    char mostHighest = '\0';
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            mostHighest = static_cast<char>(i);
        }
    }

    // 5. Print character and its count
    if (maxCount > 0) {
        std::cout << "'" << mostHighest << "' " << maxCount << std::endl;
    } else {
        std::cout << "No characters found." << std::endl;
    }

    return 0;
}