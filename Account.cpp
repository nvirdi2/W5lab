// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 18th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
    // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
    std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
    //^^That all on top was provided by the teacher^^


   //In order of header file
    bool Account::isInvalid() 
    {
        return (m_number < 0 || m_balance < 0.0);
    }

   //Unary member operator
   
    bool Account::operator ~() const 
    {
        return (m_number == 0);
    }

    //Type conversion operators

    Account::operator bool() const 
    {
        return (m_number >= 10000 && m_number <= 99999 
                    && m_balance >= 0);
    }



    Account::operator int() const  
    {
        return m_number;
    }



    Account::operator double() const 
    {
        return m_balance;
    }

    //Binary member operators

    Account& Account::operator <<(Account& account) 
    {
        if (!this->isInvalid() && !account.isInvalid() 
                && this->m_number != account.m_number) 
        {
            m_balance += account.m_balance;

            account.m_balance = 0;
        } return *this;
    }



    Account& Account::operator >>(Account& account) 
    {
        if (!this->isInvalid() && !account.isInvalid() 
                && this->m_number != account.m_number) 
        {
            account.m_balance += m_balance;

            m_balance = 0;
        } return *this;
    }



    Account& Account::operator =(Account& account) 
    {
        if (!isInvalid() && this->m_number == 0 && this->m_balance == 0.0
                 && account.m_number >= 10000 && account.m_number <= 99999) 
        {
            this->m_number = account.m_number;
            account.m_number = 0;

            this->m_balance = account.m_balance;
            account.m_balance = 0;
        } return *this;
    }



    Account& Account::operator +=(double vals) 
    {
        if (!isInvalid() && vals >= 0) 
        {
            m_balance += vals;
        } return *this;
    }



    Account& Account::operator -=(double vals) 
    {
        if (!isInvalid() && vals >= 0 && m_balance >= vals) 
        {
            m_balance -= vals;
        } return *this;
    }



    Account& Account::operator =(int NUM) 
    {
        if (!isInvalid() && m_number == 0 && m_balance == 0.0) 
        {
            setEmpty();
            if (NUM >= 10000 && NUM <= 99999) 
            {
                m_number = NUM;
            }
        } return *this;
    }



    double operator +(const Account& account1, const Account& account2) 
    {
        if (bool(account1) && bool(account2)) 
        {
          return (double(account1) + double(account2));
        } 
        
        else
        {
            return 0;
        }
    }



    double operator +=(double& val, const Account& account) 
    {
        val += double(account);
        return val;
    }
}
