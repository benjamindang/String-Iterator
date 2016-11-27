# String-Iterator

##This C++ program is designed to implement an interator class WordCrawler. The point of this class is to act as a pointer for a phrase of words, utilizing operator overloading for incrementing and dereferencing functions. An increment of a WordCrawler object is specified to go from one word to the next or previous one. Furthermore, the class is designed using no deep copies so it takes up minimal space. There are 4 non-member functions used throughout the program. These utilize the WordCrawler class to accomplish their specific goal. A quick main function was included to highlight the capabilities of the class.

##The following will be a list of the member and non member functions. More detailed descriptions can be found within the .cpp file.


###Member functions for the WordCrawler class:

Constructor using a string

prefix operator ++, increments the WordCrawler object to the next word

prefix operator --, decrements the WordCrawler object to the previous word

operator +=, increments the WordCrawler object a specified amount of times

operator -=, decrements the WordCrawler object a specified amount of times

dereference operator, returns the string for the current word the WordCrawler object is pointing to.

operator [], returns a specified word in a phrase based on user input

function get_current_word(), returns a pointer to where the WordCrawler is currently pointing

function get_final_char(), returns a poitner to the last character in the user inputted string

function get_first_word(), returns a poitner to the first character in the user inputted string


###Non-member functions used in the program,utilizing the WordCrawler class:

function the_count, returns an int counting the amount of times "the" appears in a user inputted string

function word_count, returns an int counting the amount of words in a user inputted string

function every_other_in, prints every other word of a user inputted string

function print_in_reverse, prints the user inputted string in reverse word order.
