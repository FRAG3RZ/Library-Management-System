#include "Items.h"
#include <algorithm>

int Items::num_of_items{0};

std::vector<Items*> Items::all_items{};

Items::Items() :Items("Unknown name item", "Unknown rating", false) {
}

Items::Items(std::string temp_name, std::string temp_rating, bool temp_status) :name{ temp_name }, rating{ temp_rating }, is_borrowed{ temp_status }, borrower{""} {
	all_items.push_back(this);
	num_of_items++;
}

Items::~Items() {
	for (size_t i{}; i < num_of_items; i++) {
		if (this->get_name() == all_items[i]->get_name() && this->get_rating() == all_items[i]->get_rating())
			all_items.erase(all_items.begin() + i);
	}
	num_of_items--;
}

