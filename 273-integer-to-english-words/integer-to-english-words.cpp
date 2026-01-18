class Solution {
public:
    vector<string> word1 = {
        "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
        "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
        "Sixteen","Seventeen","Eighteen","Nineteen"
    };

    vector<string> word2 = {
        "","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
    };

    vector<string> word3 = {"","Thousand","Million","Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return trim(helper(num, 0));
    }

    string helper(int num, int level) {
        if (num == 0) return "";

        string result = "";

        int last = num % 1000;

        if (last >= 100) {
            result += word1[last / 100] + " Hundred ";
            last %= 100;
        }

        if (last >= 20) {
            result += word2[last / 10] + " ";
            last %= 10;
        }

        if (last > 0) {
            result += word1[last] + " ";
        }

        if (!result.empty() && level > 0) {
            result += word3[level] + " ";
        }

        return helper(num / 1000, level + 1) + result;
    }

    string trim(const string& s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && isspace(s[start])) start++;
        while (end >= start && isspace(s[end])) end--;
        return s.substr(start, end - start + 1);
    }
};
