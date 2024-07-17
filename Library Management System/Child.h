#pragma once
#include "Patron.h"
class Child :
    public Patron
{
    static int max_borrowed_items;
    bool has_parent_permission;

public:

    void set_permission(bool temp_permission) { has_parent_permission = temp_permission; }

    Child();

    Child(std::string init_name, int temp_age, bool has_parent_permission);

    ~Child() { Patron::~Patron(); };
};

