#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Items.h"

class Item;

class Patron
{
	static int num_of_patrons;
	static std::vector<Patron*> all_patrons;
	friend class Child;

protected:
	std::string name;
	int num_of_borrowed_items;
	int age;
	std::vector<Items*> borrowed_items;

public:

	void set_items(int temp_num) { num_of_borrowed_items += temp_num; }

	void set_name(std::string temp_name) { name = temp_name; }

	void set_age(int temp_age) { age = temp_age; }

	std::string get_name() const { return name; }

	int get_num_items() const { return num_of_borrowed_items; }

	int get_age() const{ return age; }

	static int get_num_patrons() {
		return num_of_patrons;
	}

	void get_borrowed_items() {
		for (auto& item : borrowed_items)
			std::cout << *item << std::endl;
	}

	static void get_all_patrons() {
		std::cout << "\n==========Displaying Patrons==========\n" << std::endl;
		for (auto& patron : all_patrons)
			std::cout << *patron << std::endl;
	}

	static std::vector<Patron*> get_patrons_vector() {
		return all_patrons;
	}

	std::vector<Items*> get_items_vector() {
		return borrowed_items;
	}

	static Patron get_added_patron() {
		return *(all_patrons)[num_of_patrons - 1];
	}

	friend std::ostream& operator<<(std::ostream &os, Patron& patron) {
		os << "This patron's name is: " << patron.get_name() << "." << " The patron has: " << patron.get_num_items() << " borrowed items." << " The patron is: " << patron.get_age() << " years old." << std::endl;
		return os;
	}

	void assign_item(Items* temp_item) {
		borrowed_items.push_back(temp_item);
	}

	bool operator==(const Patron& other) const {
		// Implement comparison logic based on your class members
		return (this->get_name() == other.get_name() && this->get_age() == other.get_age());
	}

	//No args constructor
	Patron();

	// Name constructor
	Patron(std::string init_name, int temp_age);

	//Destructor
	~Patron();
};

