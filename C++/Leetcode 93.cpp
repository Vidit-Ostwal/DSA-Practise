#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// original_string :- the original string
// index :- index on the original string
// temp_string :- the temporary string in the process
// part_left :- partition left to be done
// final_vector :- vector which have all the child vector
// curr_number :- this will iterate to get the number between the dots

class Solution {
    vector<string> Helper(string original_string, int index, string temp_string, int part_left)
    {
        vector<string> temp_vector;
        if (original_string.length() == index)
        {
            if (part_left == 0)
            {
                // All the conditions have met and therefore pushed to the final vector    
                temp_vector.push_back(temp_string);
            }
            return temp_vector;
        }

        if (part_left == 0)
        {
            // No partition are left to be done
            return temp_vector;
        }

        vector<string> final_vector;
        int curr_number = 0;

        while (index != original_string.length())
        {
            curr_number = curr_number*10 + (original_string[index] - '0');

            if (curr_number >= 0 && curr_number <= 255)
            {
                // Case when the number has met the condition to be between 0 and 255
                string scurr_number = to_string(curr_number);
                
                // First number will not have a "." associated with it 
                string temp22 = (part_left == 4) ? scurr_number : temp_string + "." + scurr_number ; 
                
                vector<string> temp_vect = Helper(original_string, index + 1,temp22, part_left - 1);
                final_vector.insert(final_vector.begin(),temp_vect.begin(),temp_vect.end());
            }
            else
            {
                break;
            }

            if (curr_number == 0)
            {
                // No number can have a leading zero
                break;
            }
            index++;
        }
        return final_vector;
    }
public:
    vector<string> restoreIpAddresses(string original_string) {
        return Helper(original_string,0,"",4);
    }
};