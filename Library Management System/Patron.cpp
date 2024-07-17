#include "Patron.h"

int Patron::num_of_patrons{0};

std::vector<Patron*> Patron::all_patrons{};

Patron::Patron(std::string init_name, int temp_age) :name{ init_name }, age{ temp_age }, num_of_borrowed_items { 0 } {
	all_patrons.push_back(this);
	num_of_patrons++;
}

Patron::Patron() :Patron("Unknown name", 0) {
}

Patron::~Patron() {
	/*
	for (size_t i{}; i < num_of_patrons; i++) {
		if (this->get_name() == all_patrons[i]->get_name() && this->get_age() == all_patrons[i]->get_age()) {
			all_patrons.erase(all_patrons.begin() + i);
			delete all_patrons[i];
		}
	
	*/
	auto it = std::find(all_patrons.begin(), all_patrons.end(), this);
	if (it != all_patrons.end()) {
		all_patrons.erase(it);
	}
	num_of_patrons--;
}