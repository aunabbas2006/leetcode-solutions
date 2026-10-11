// Problem: Substring with Concatenation of All Words
// Difficulty: HARD
// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Approach: Sliding window with frequency maps, iterating through the string to check if fixed-length substrings exactly contain all words from the input array.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) {
            return result;
        }

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;

        if (s.length() < total_len) {
            return result;
        }

        map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        for (int i = 0; i < word_len; ++i) {
            map<string, int> current_window_counts;
            int words_matched_in_window = 0;
            int left_ptr = i;

            for (int j = i; j <= (int)s.length() - word_len; j += word_len) {
                string current_word = s.substr(j, word_len);

                if (counts.find(current_word) == counts.end()) {
                    current_window_counts.clear();
                    words_matched_in_window = 0;
                    left_ptr = j + word_len;
                } else {
                    current_window_counts[current_word]++;

                    if (current_window_counts[current_word] <= counts[current_word]) {
                        words_matched_in_window++;
                    }

                    while (current_window_counts[current_word] > counts[current_word]) {
                        string word_to_remove = s.substr(left_ptr, word_len);
                        current_window_counts[word_to_remove]--;
                        
                        if (current_window_counts[word_to_remove] < counts[word_to_remove]) {
                            words_matched_in_window--;
                        }
                        left_ptr += word_len;
                    }

                    if (words_matched_in_window == num_words) {
                        result.push_back(left_ptr);

                        string word_to_remove = s.substr(left_ptr, word_len);
                        current_window_counts[word_to_remove]--;
                        words_matched_in_window--;
                        left_ptr += word_len;
                    }
                }
            }
        }
        return result;
    }
};
