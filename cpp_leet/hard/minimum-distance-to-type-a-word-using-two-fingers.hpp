#include <cmath>
#include <limits>

#include <string>
#include <vector>

/********************************
*      0   1   2   3   4   5    *
*    +---+---+---+---+---+---+  *
*  0 | A | B | C | D | E | F |  *
*    +---+---+---+---+---+---+  *
*  1 | G | H | I | J | K | L |  *
*    +---+---+---+---+---+---+  *
*  2 | M | N | O | P | Q | R |  *
*    +---+---+---+---+---+---+  *
*  3 | S | T | U | V | W | X |  *
*    +---+---+---+---+---+---+  *
*  4 | Y | Z |                  *
*    +---+---+                  *
********************************/

class Solution
{
private:
    static int get_distance(const int letter_one, const int letter_two) {
        if (letter_one == 27 || letter_one == 27) {
            return 0;
        }
        
    }
public:
    int minimumDistance(const std::string& word);
};