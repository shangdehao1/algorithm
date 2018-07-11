/*
 *
 * Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 * 
 * Example 1:
 *
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 *
 * Output: ["Alaska", "Dad"]
 *
 * Note:
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 *
 *
 */

vector<string> findWords(vector<string>& words) {

    vector<char> temp1{'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P'};
    vector<char> temp2{'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
    vector<char> temp3{'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};

    map<char, int> key_board;
    for(auto temp : temp1){
        key_board[temp] = 1;
    }
    for(auto temp: temp2){
        key_board[temp] = 2;
    }
    for(auto temp : temp3) {
        key_board[temp] = 3;
    }

    vector<string> results;

    for(auto temp : words ) {
        int index = 0;
        bool xx = false;
        for( auto t : temp) {
            if(index == 0 ) {
               index = key_board[t]; 
               xx = true;
            } else {
                if(index != key_board[t]) {
                    xx = false;
                    break;
                }
            }
        }
        if(xx) {
            results.push_back(temp);
        }
    }

    return results;
    
}

