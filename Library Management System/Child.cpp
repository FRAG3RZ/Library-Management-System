#include "Child.h"

int Child::max_borrowed_items{2};

Child::Child(): Child("Unknown name", 0, false) {
}

Child::Child(std::string init_name, int temp_age, bool temp_permission) : Patron::Patron(init_name, temp_age), has_parent_permission{ temp_permission } {
}
