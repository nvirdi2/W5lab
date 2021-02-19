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
    bool Account::isInvalid()  //"Invalid Empty State" which is why we need a isInvalid function
    { 
        return (m_number < 0 || m_balance < 0.0);
    }

   //Unary member operator
   
    bool Account::operator ~() const 
    {
        return (m_number == 0);         //if account number is zero then it will return else skip over
    }

    //Type conversion operators

    Account::operator bool() const 
    {
        return (m_number >= 10000 && m_number <= 99999       //Returns is account number and balance is valid
                    && m_balance >= 0);
    }



    Account::operator int() const  
    {
        return m_number;        //return account number
    }



    Account::operator double() const 
    {
        return m_balance;      //return balance value
    }

    //Binary member operators

    Account& Account::operator <<(Account& account) 
    {
        if (!this->isInvalid() && !account.isInvalid() 
                && this->m_number != account.m_number) 
        {
            m_balance += account.m_balance;       //sum and equal

            account.m_balance = 0;       //account number will be 0
        } return *this;           //return current object
    }



    Account& Account::operator >>(Account& account) 
    {
        if (!this->isInvalid() && !account.isInvalid() 
                && this->m_number != account.m_number) 
        {
            account.m_balance += m_balance;      //sum and equal

            m_balance = 0;       //balance will be 0
        } return *this;        //return current object
    }



    Account& Account::operator =(Account& account) 
    {
        if (!isInvalid())
        {
            if(this->m_number == 0 && this->m_balance == 0.0
                 && account.m_number >= 10000 && account.m_number <= 99999) 
            {
                this->m_number = account.m_number;       //move account one to the other
                account.m_number = 0;          //right side set as 0

                this->m_balance = account.m_balance;   //move balance one to the other
                account.m_balance = 0;       //right side set as 0
            }
        } return *this;      //return current object
    }



    Account& Account::operator +=(double vals) 
    {
        if (!isInvalid() && vals >= 0) 
        {
            m_balance += vals;
        } return *this;       //return current object
    }



    Account& Account::operator -=(double vals) 
    {
        if (!isInvalid())
        {
            if (vals >= 0 && m_balance >= vals) 
            {
                m_balance -= vals;      //balance will reduce by a double val
            } 
        } return *this;    //return current object
    }



    Account& Account::operator =(int NUM) 
    {
        if (!isInvalid() && m_number == 0 && m_balance == 0.0) 
        {
            setEmpty();            //set account number empty
            if (NUM >= 10000 && NUM <= 99999) 
            {
                m_number = NUM;      //account number will equal to integer number
            }
        } return *this;     //return current object
    }



    double operator +(const Account& account1, const Account& account2) 
    {
        if (bool(account1) && bool(account2))   //if account 1 and account 2 is bool
        {
          return (double(account1) + double(account2));   //double return
        } 
        
        else
        {
            return 0;    //return nothing
        }
    }



    double operator +=(double& val, const Account& account) 
    {
        val += double(account);     //double will be sumed upand equal to double of account
        return val;      //return double
    }
}
