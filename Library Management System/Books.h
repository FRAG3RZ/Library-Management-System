#pragma once
#include "Items.h"
class Books :
    public Items
{
    int static num_of_books;

private:

    std::string category;

public:

    void set_category(std::string temp) { category = temp; }

    std::string get_category() { return category; }

    Books();

    Books(std::string temp_name, std::string temp_rating, bool temp_status, std::string temp_category);

    ~Books() { num_of_books--; }
};

