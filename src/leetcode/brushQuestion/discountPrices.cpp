/*
 * @Author: 辜思学
 * @Description: 2288. 价格减免
 * @Date: 2024-06-18 06:40:25
 */

#include <bits/stdc++.h>

using namespace std;

string discountPrices(string sentence, int discount) {
        string res;
        double discountPrices = (100 - discount) / 100.0;

        for (int i=0; i<sentence.length(); i++)
        {
            string word;
            bool price = true;
            while (i < sentence.length() && sentence[i] != ' ')
            {
                word += sentence[i];
                if (word.length() > 1 && (sentence[i] < '0' || sentence[i] > '9'))
                {
                    price = false;
                }
                
                i++;
            }
            if (word.length() <= 1 || word[0] != '$')
            {
                price = false;
            }

            if (price)
            {
                stringstream decreasePriceStr;
                decreasePriceStr << fixed << setprecision(2) << '$' << stoll(word.substr(1)) * discountPrices;
                res += decreasePriceStr.str();
            }
            else
            {
                res += word;
            }

            if (i < sentence.length())
            {
                res += ' ';
            }
        }

        return res;
    }

int main()
{
    cout << discountPrices("$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999", 5) << endl;
    return 0;
}