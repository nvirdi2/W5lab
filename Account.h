// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: Feb 18th, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      bool isInvalid();

        //Unary member operator

        bool operator ~() const;  
        
        //Type conversion operators

        operator bool() const;   
        operator int() const;   
        operator double() const;   
        
        //Binary member operators

        Account& operator <<(Account& account);   
        Account& operator >>(Account& account);    
        Account& operator =(Account& account);
        Account& operator +=(double vals);    
        Account& operator -=(double vals);    
        Account& operator =(int NUM);   
    };

    //Binary helper operators

    double operator +(const Account& account1, const Account& account2);
    double operator +=(double& val, const Account& account);

}
#endif // SDDS_ACCOUNT_H_
