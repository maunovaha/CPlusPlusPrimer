/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 *     Pearson Education, Inc.
 *     Rights and Permissions Department
 *     One Lake Street
 *     Upper Saddle River, NJ  07458
 *     Fax: (201) 236-3290
*/

/* This file defines the Sales_item class used in chapter 1.
 * The code used in this file will be explained in
 * Chapter 7 (Classes) and Chapter 14 (Overloaded Operators)
 * Readers shouldn't try to understand the code in this file
 * until they have read those chapters.
*/

#ifndef SALESITEM_H
// We're here only if SALESITEM_H has not yet been defined
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item {
public:
    // Constructors are explained in section 7.1.4, pages 262-265.
    // Default constructor needed to initialize members of built-in type
    Sales_item() = default;
    Sales_item(const std::string& book_no) : book_no_(book_no) {}
    Sales_item(std::istream& is) { is >> *this; }

    // Operations on Sales_item objects (below)

    // Member binary operator: left-hand operand bound to implicit this pointer
    Sales_item& operator+=(const Sales_item& rhs);

    std::string isbn() const { return book_no_; };
    double avg_price() const;

    // These declarations are explained in section 7.2.1, p. 270 and in chapter 14, 
    // pages 557, 558, 561
    friend std::istream& operator>>(std::istream& in, Sales_item& s);
    friend std::ostream& operator<<(std::ostream& os, const Sales_item& s);
    friend bool operator<(const Sales_item& lhs, const Sales_item& rhs);
    friend bool operator==(const Sales_item& lhs, const Sales_item& rhs);

private:
    std::string book_no_;    // Implicitly initialized to the empty string
    unsigned units_sold_ = 0; // Explicitly initialized
    double revenue_ = 0.0;
};

// Used in Chapter 10
inline bool compare_isbn(const Sales_item& lhs, const Sales_item& rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// Nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs);

inline bool operator==(const Sales_item& lhs, const Sales_item& rhs)
{
    // Must be made a friend of Sales_item
    return lhs.units_sold_ == rhs.units_sold_ &&
        lhs.revenue_ == rhs.revenue_ &&
        lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item& lhs, const Sales_item& rhs)
{
    return !(lhs == rhs); // != Defined in terms of operator==
}

// Assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;

    return *this;
}

// Assumes that both objects refer to the same ISBN
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
    Sales_item ret(lhs); // Copy (|lhs|) into a local object that we'll return
    ret += rhs;          // Add in the contents of (|rhs|)

    return ret; // Return (|ret|) by value
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
    double price;
    in >> s.book_no_ >> s.units_sold_ >> price;

    // Check that the inputs succeeded
    if (in) {
        s.revenue_ = s.units_sold_ * price;
    }
    else {
        s = Sales_item(); // Input failed: Reset object to default state
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold_ << " "
        << s.revenue_ << " " << s.avg_price();

    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold_) {
        return revenue_ / units_sold_;
    }
    
    return 0;
}

#endif