#include "Books.h"

int Books:: num_of_books{ 0 };

Books::Books() :Books("Unknown name", "Unknown rating", false, "Unknown category") {}

Books::Books(std::string temp_name, std::string temp_rating, bool temp_status, std::string temp_category) :Items::Items(temp_name, temp_rating, temp_status), category{ temp_category } {
	num_of_books++;
}
