/** @file String Iterator.cpp
 @author [Benjamin Dang]
 @date [October 21, 2016]
 
 [This program is designed to implement an interator class WordCrawler. The point of this class is to act as a pointer for a phrase of words, utilizing operator overloading for incrementing and dereferencing functions. An increment of a WordCrawler object is specified to go from one word to the next or previous one. Furthermore, the class is designed using no deep copies so it takes up minimal space. There are 4 non-member functions used throughout the program. These utilize the WordCrawler class to accomplish their specific goal.]
 */
#include <string>
#include <iostream>


/** @class WordCrawler
 @brief Acts as a pointer for a user inputed string
 
 This class is designed to act as a more general pointer type. Instead of incrementing between individual characters or cells, it is designed to increment over individual words. To allow for this, the class heavily relies on operator overloading and the use of char pointers.
 */
class WordCrawler{
public:
    WordCrawler(std::string s);
    
    WordCrawler& operator++();
    WordCrawler& operator--();
    WordCrawler& operator+=(int moves);
    WordCrawler& operator-=(int moves);
    
    std::string operator*();
    std::string operator[](int a);
    
    char* get_current_word() const;
    char* get_final_char() const;
    char* get_first_word() const;
    
private:
    char* first_word;
    char* current_word;
    char* final_char;
    
};

//These four functions each perform their specific role as specified by their names.
int word_count(std::string phrase);
int the_count(std::string phrase);
void every_other_in(std::string phrase);
void print_in_reverse(std::string phrase);

int main() {
    std::string words;
    int word;
    std::cout << "Please input some words:\n";
    std::getline(std::cin, words);
    std::cout << "The total number of words is: " << word_count(words) << std::endl;
    std::cout << "The total number of times 'the' appears is: " << the_count(words) << std::endl;
    std::cout << "Every other word is: "; every_other_in(words); std::cout << std::endl;
    std::cout << "The words in reverse order are: "; print_in_reverse(words); std::cout << std::endl;
    std::cout << "Which word would you like to access? Please input the number of the word in the phrase: ";
    std::cin >> word;
    WordCrawler which_word(words);
    std::cout << which_word[word];
    
    std::cout << std::endl;
    
    return 0;
}

/**Constructor with a std::string parameter
    @param input_phrase is a std::string to be pointed to by the WordCrawler class
 */
WordCrawler::WordCrawler(std::string input_phrase)
{
    first_word = &input_phrase[0];
    current_word = &input_phrase[0];
    final_char = &input_phrase[input_phrase.size()-1];
}

/**Prefix increment operator for a WordCrawler Object. Moves the iterator class object to the next word through advancing its char* pointer
    @return *this returns a reference to the WordCrawler object which points to the next word
 */
WordCrawler& WordCrawler::operator++()
{
    bool next_word = false;
    while(!next_word)
    {
        if(current_word == final_char)
            break;
        current_word++;
        if(*current_word == ' ')
        {
            current_word ++;
            next_word = true;
        }
    }
    return *this;
}

/**Prefix decrement operator for a WordCrawler Object. Moves the iterator clas sobject to the previous word through moving its char* pointer backwards
    @return *this returns a reference to the WordCrawler object which points to the next word
 */
WordCrawler& WordCrawler::operator--()
{
    int space_count = 0;
    bool previous_word = false;
    while(!previous_word)
    {
        if(current_word == first_word)
            break;
        current_word --;
        if(*current_word == ' ')
            space_count++;
        if(space_count == 2)
        {
            current_word++;
            break;
        }
    }
    return *this;
}

/**Plus equals operator for a WordCrawler object. Increments the WordCrawler object by a specified amount of times
 @param moves the amount of times to increment the WordCrawler object
 @return *this returns a reference to the WordCrawler object after its incrementation
 */
WordCrawler& WordCrawler::operator+=(int moves)
{
    for(int i = 0; i < moves; i ++)
    {
        bool next_word = false;
        while(!next_word)
        {
            if(current_word == final_char)
                break;
            current_word++;
            if(*current_word == ' ')
            {
                current_word ++;
                next_word = true;
            }
        }
    }
    return *this;
}
/**Minus equals operator for a WordCrawler object. Decrements the WordCrawler object by a specified amount of times
 @param moves the amount of times to decrement the WordCrawler object
 @return *this returns a reference to the WordCrawler object after its decrementation
 */
WordCrawler& WordCrawler::operator-=(int moves)
{
    for(int i = 0; i < moves; i++)
    {
        int space_count = 0;
        bool previous_word = false;
        while(!previous_word)
        {
            if(current_word == first_word)
                break;
            current_word --;
            if(*current_word == ' ')
                space_count++;
            if(space_count == 2)
            {
                current_word++;
                break;
            }
        }
    }
    return *this;
}

/**Dereference operator for a WordCrawler object. Derefences the object by returning the specific word its current_word private variable is pointing to
    @return printed_word a std::string that contains the word that is being pointed to by the priavte variable current_word
 */
std::string WordCrawler::operator*()
{
    std::string printed_word;
    if(*current_word == ' ')
        current_word++;
    while(*current_word != ' ')
    {
        printed_word.push_back(*current_word);
        if(current_word == final_char)
            break;
        ++current_word;
    }
    return printed_word;
}

/**Square bracket operator for a WordCrawler object.
    @param location integer input specifying which word in the sentence to return, assuming the first word is the 0th word
    @return **this dereferences the WordCrawler object pointing to the right word
 */

std::string WordCrawler::operator[](int location)
{
    current_word = first_word;
    for(int i = 0; i < location-1; i++)
    {
        bool next_word = false;
        while(!next_word)
        {
            if(current_word == final_char)
                break;
            current_word++;
            if(*current_word == ' ')
            {
                current_word ++;
                next_word = true;
            }
        }
    }
    std::string printed_word;
    if(*current_word == ' ')
        current_word++;
    while(*current_word != ' ')
    {
        printed_word.push_back(*current_word);
        if(current_word == final_char)
            break;
        ++current_word;
    }
    return printed_word;
}

/**Member function to access the private char pointer current_word outside of member functions
    @return current_word returns the pointer to where the WordCrawler object is currently pointing to
 */
char* WordCrawler::get_current_word() const
{
    return current_word;
}

/**Member function to access the private char pointer final_char outside of member functions
    @return final_char returns the pointer to where the last char of the string that WordCrawler is pointing to.
 */
char* WordCrawler::get_final_char() const
{
    return final_char;
}

/**Member function to access the private char pointer first_word outside of member functions
 @return first_word returns the pointer to where the first word of the string that WordCrawler is pointing to.
 */
char* WordCrawler::get_first_word() const
{
    return first_word;
}

/**Non-member function that counts the amount of words in a user inputed phrase
    @param phrase user inputed string
    @return number_of_words the number of words in the string, assumes there is a space between every word
 */
int word_count(std::string phrase)
{
    int number_of_words = 1;
    for(int i = 0; i < phrase.size(); i++)
    {
        if(phrase[i] == ' ')
        {
            number_of_words++;
        }
    }
    return number_of_words;
}

/**Non-member function that counts the amount of time the specific string 'the' appears in the user inputted phrase. Assumes if the three letter word 'the' appears in another word counts, not just the on its own.
    @param phrase user inputed string
    @return the_count integer number of the amount of times 'the' appears in the phrase
 */
int the_count(std::string phrase)
{
    int number_of_the = 0;
    for( int i = 0; i < phrase.size(); i++)
    {
        if((phrase[i] == 't' && phrase[i+1] == 'h') && phrase[i +2] == 'e')
        {
            if(i == phrase.size() - 3)
                number_of_the++;
            else
                number_of_the++;
        }
    }
    return number_of_the;
}

/**Non-member function that utilizes a WordCrawler object to print every other word in the user inputed phrase
    @param phrase user inputted string
 */
void every_other_in(std::string phrase)
{
    WordCrawler phrase_pointer(phrase);
    while(phrase_pointer.get_current_word() != phrase_pointer.get_final_char())
    {
        std::cout<< *phrase_pointer << " ";
        ++phrase_pointer;
    }
    
}

/**Non-member function that utilizes a WordCrawler objec to print the user inputed string in reverse order
    @param phrase user inputed string
 */
void print_in_reverse(std::string phrase)
{
    bool first_word = false;
    WordCrawler phrase_pointer(phrase);
    int word_amount = word_count(phrase);
    for(int i =1; i < word_amount; i++)
    {
        ++phrase_pointer;
    }
    while(!first_word)
    {
        std::cout << *phrase_pointer << " ";
        if(phrase_pointer.get_current_word() == phrase_pointer.get_first_word())
            break;
        --phrase_pointer;
        if(phrase_pointer.get_current_word() == phrase_pointer.get_first_word())
        {
            std::cout << *phrase_pointer << " ";
            first_word = true;
        }
    }
}
