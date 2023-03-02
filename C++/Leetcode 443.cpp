class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> temp;

        int st = 0;
        int length = 0;
        while (st < chars.size())
        {
            int curr_st = st;
            int count = 0;

            while (st < chars.size() && chars[st] - 'a' == chars[curr_st] - 'a')
            {
                count++;
                st++;
            }
            temp.push_back(chars[curr_st]);
            length++;
            if (count > 1)
            {
                string temp_count = to_string(count);

                for (int i = 0; i < temp_count.length(); i++)
                {
                    temp.push_back(temp_count[i]);
                }
                // temp.push_back(to_string(count));
                length += ((to_string(count).length()));
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << "  ";
        }

        // chars = vector<int>(temp.begin(),temp.end());
        for (int i = 0; i < min(chars.size(),temp.size()); i++)
        {
            chars[i] = temp[i];
        }

        for (int i = chars.size(); i < temp.size(); i++ )
        {
            chars.push_back(temp[i]);
        }
        return length;
    }
};