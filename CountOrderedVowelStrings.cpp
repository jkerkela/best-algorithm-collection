class Solution {
public:
    
    int countVowelStrings(int n) {
        return count_valid_vowel_strings_by_lexic_order(n, 1);
    }
    
    int count_valid_vowel_strings_by_lexic_order(int n, int last_vowel) {
        if(n == 0) {
            return 1;
        }
        
        int result = 0;
        // vowels are represented by integers 1=a, 2=e, 3=i, 4=o, 5=u, 
        // so e.g. for a, there is 4 vowels that can come after being lexicographically sorted 
        for(int i = last_vowel; i <= 5; i++) {
            result += count_valid_vowel_strings_by_lexic_order(n - 1, i);
        }
        return result;
    }
};
