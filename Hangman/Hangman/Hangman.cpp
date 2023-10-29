#include <iostream>
#include <vector>
#include "Random.h"

namespace WordList {
    std::vector < std::string> words{
        "mystery", "broccoli", "accountant", "almost",
        "spaghetti", "opinion", "beautiful", "distance",
        "luggage", "dungeon", "monster", "dragon" };

    const std::string& getRandomWord() {

        int rand{ Random::get(0, static_cast<std::size_t>(words.size()) - 1) };

        return words[static_cast<std::size_t>(rand)];
    }
}
class Word {
private: 
    std::string m_word{ WordList::getRandomWord() };
public:

    const std::string& getWord() const { return m_word; }

    const std::string& hideWord() {

        for (int i{ 0 }; i < m_word.length(); i++)
            m_word[i] = '_';

        return m_word;
    }

    std::string replaceLetter(const Word& word, char letter) {

        for (int i{ 0 }; i < word.m_word.length(); i++) {
            if (word.m_word[i] == letter)
                m_word[i] = letter;
        }

        return m_word;
    }

    bool isFound(char letter) {
        for (int i = 0; i < m_word.size(); i++)
            if (m_word[i] == letter)
                return true;

        return false;
    }

};

void Test1() {
    for (int i = 0; i < 20; i++)
        std::cout << WordList::getRandomWord() << " ";
}

std::string replaceLetter(std::string& word, char letter, int& lives) { // overload la fct replace

    for (int i{ 0 }; i < word.length(); i++) {
        if (word[i] == '+'){
            word[i] = letter;
            break;
        }
    }

    lives--;
    return word;
}

void guessWord(std::string& word) {

    for (int i{ 0 }; i < 6; i++) {
        word[i] = '+';
    }
}

char getInput() {
    char letter{};

    while (true) {
        std::cout << "Enter your next letter: ";
        std::cin >> letter;

        if (letter >= 'a' && letter <= 'z') {
            std::cout << "You entered: " << letter << "\n\n";
            return letter;
        }
        else {
            std::cout << "That wasn't a valid input. Try again. \n";
        }
    }
}


int main()
{
    Word word{};
    Word word_cpy{ word };
    std::string guess{"++++++"};
    int lives{ 6 };
    //guessWord(guess);


    std::cout << "Welcome to Hangman!\n";
    std::cout << "The word: " << word_cpy.hideWord() << '\n';
    //std::cout << "  " << word.getWord() << '\n';
    std::cout << "Wrong guesses: " << guess << '\n';
  
    while (true) {
        
        char letter{ getInput() };

        if (word.isFound(letter)) {
            std::cout << "Yes, '" << letter << "' is in the word!\n";
            word_cpy.replaceLetter(word, letter);
        }
        else {
            std::cout << "No, '" << letter << "' is not in the word!\n";
            replaceLetter(guess, letter, lives);

            if (lives == 0) {
                std::cout << "The word was: " << word.getWord();
                std::cout << "\nGame over!\n";
                break;
            }
        }
        
        std::cout << "The word: " << word_cpy.getWord() << "  \n";
        //std::cout << "  " << word.getWord() << '\n';
        std::cout << "Wrong guesses: " << guess << "\n\n";
        
        if (word_cpy.getWord() == word.getWord())
        {
            std::cout << "Game Over!\n";
            std::cout << "The word was: " << word.getWord();
            break;
        }
    }
    
}
    

