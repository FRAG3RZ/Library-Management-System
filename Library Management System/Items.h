#pragma once
#include <string>
#include <vector>
#include <iostream>

class Patron;

class Items
{
	static int num_of_items;
	static std::vector<Items*> all_items;
protected:
	bool is_borrowed;
	std::string name;
	std::string rating; 
	std::string borrower;

public:

	void change_status(bool temp_status) { is_borrowed = temp_status; }

	void change_name(std::string temp_name) { name = temp_name; }

	void change_rating(std::string temp_rating) { rating = temp_rating; }

	void change_borrower(std::string temp_name) { borrower = temp_name; }

	std::string get_borrower() { return borrower; }

	std::string get_name() const {return name;}

	bool get_status() const { return is_borrowed; }

	std::string get_rating() const { return rating; }

	static void get_all_items() {
		std::cout << "\n==========Displaying items!==========\n" << std::endl;
		for (auto& item : all_items)
			std::cout << *item << std::endl;
	}

	static std::vector<Items*> get_items_vector() {
		return all_items;
	}

	friend std::ostream& operator<<(std::ostream& os, Items& item) {
		if (item.get_status() == true) {
			os << "This item's name is: " << item.get_name() << ". This item is intended for " << item.get_rating() << ". This item is borrowed by " << item.borrower << std::endl;
		} 
		else
			os << "This item's name is: " << item.get_name() << ". This item is intended for " << item.get_rating() << ". This item is not borrowed." << std::endl;
		return os;
	}

	static int get_num_items() {
		return num_of_items;
	}

	bool operator==(const Items& other) const {
		return (this->get_name() == other.get_name());
	}

	//Constructors and Destructor

	Items();

	Items(std::string temp_name, std::string temp_rating, bool temp_status = false);

	~Items();

};

