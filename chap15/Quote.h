#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <iostream>

class Quote {
public:
    Quote() = default;  // reference to 7.1.4
    Quote(const std::string &book, double sales_price):bookNo(book), price(sales_price) {}
    std::string isbn() const;
    virtual double net_price(std::size_t n) const
            {return n * price;}
    virtual ~Quote() = default; // dynamic binding for destructor.
private:
    std::string bookNo; // ISBN number
protected:
    double price = 0.0; // undiscount price
};

class Bulk_quote : public Quote {
public:
    double net_price(std::size_t) const override;
};

#endif