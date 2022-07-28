/* 1、假设日期 1969.01.01 用 0 表示，请开发一个函数输出任意日期的整数表示（
日期小于1969.01.01 的用负数表示）。反过来，给定日期的整数表示，
开发一个函数求日期对应的年月日。*/

/**
 * @brief Author Ze-Yin Chen, 2022.7.28
 */
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Calinder{
public:
    Calinder(){
        int base = 0;
        for(int i = 0; i < 1969; ++i){
            if(isLeapYear(i)) base += 366;
            else base += 365;
        }
        base += 1; // 1969.1.1
        m_base_day_ = base;
        m_month_len_ = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
    }
    
    vector<int> m_month_len_; // Record length for each month
    int m_base_day_;          // Record the 1969.01.01 as an int format

    /* Transfer from xxxx.xx.xx to int */
    int dateToInt(string str){
        // split the str by .
        string year, month, day;
        parseDate(str, year, month, day);
        int y = stoi(year), m = stoi(month), d = stoi(day);
        cout << "year :" << y << " month:" << m << " day:" << d << endl;
        int base = 0;
        for(int i = 0; i < y; ++i){
            if(isLeapYear(i)) base += 366;
            else base += 365;
        }

        // Calculate the month part
        for(int i = 0; i < m; ++i){
            base += m_month_len_[i];
        }

        if(isLeapYear(y)) ++base; // Febrary
        
        // Calculate the day
        base += d;
        return base - m_base_day_;
    } 

    /* Parse the date from string format */
    void parseDate(string& str, string& year, string& month, string& day){
        int idx = 0;
        while(str[idx] != '.'){
            ++idx;
        }
        year = str.substr(0, idx);
        int last = idx + 1;
        ++idx;
        while(str[idx] != '.'){
            ++idx;
        }
        month = str.substr(last, idx - last);
        ++idx;
        day = str.substr(idx);
    }


    /* Transfer from int to xxxx.xx.xx */
    string intToDate(int num){
        num = num + m_base_day_;
        int year = 0;
        while(num > 0){
            num -= 365;
            if(num < 0){
                num += 365;
                break;
            }
            if(isLeapYear(year)){
                --num;
                if(num < 0){
                    num += 366;
                    break;
                }
            }
            ++year;
        }
        int month = 0;
        int month_idx = 1;
        while(month < num){
            month += m_month_len_[month_idx];
            if(month > num) {
                month -= m_month_len_[month_idx];
                break;
            }
            if(isLeapYear(year) && month_idx == 2){
                month += 1;
                if(month > num){
                    month -= (m_month_len_[month_idx] + 1);
                    break;
                }
            }
            ++month_idx;
        }
        num -= month;
        int day = num;
        if(day == 0){
            --month_idx;
            if(month_idx == 0){
                month_idx = 12;
                --year;
            }
            day = m_month_len_[month_idx];
            if(isLeapYear(year) && month_idx == 2) ++day;
        }
        string y = to_string(year);
        string m = to_string(month_idx);
        if(month_idx < 10){
            m.insert(m.begin(), '0');
        }
        string d = to_string(day);
        if(day < 10){
            d.insert(d.begin(), '0');
        }
        return y + "." + m + "." +  d;
    }
    

    /* Check is the year a leap year 闰年 */
    inline bool isLeapYear(int year){
        if(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)){
            return false;
        }
        return true;
    }
    
};


int main(){
    Calinder* calinder = new Calinder();
    int date;
    // string date;
    // while(cin >> date){
    //     cout << date << " corresponding to " << calinder->dateToInt(date) << endl;
    // }
    while(cin >> date){
        cout << date << " corresponding to " << calinder->intToDate(date) << endl;
    }
    return 0;
}