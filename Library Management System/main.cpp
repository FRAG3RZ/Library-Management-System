#include "Patron.h"
#include "Child.h"
#include "Items.h"
#include "Books.h"

void main_menu();

int main() {
	// Declare patrons:
	Patron patron{ "Daniel B", 20 };
	Patron emicka{ "Emicka B", 20 };
	Patron martina{ "Martina B", 52 };

	// Declare Items:
	Items Court_of_thorns_and_roses{ "A Court of Thorns and Roses", "teen", false};
	Items Throne_of_glass{ "Throne of Glass", "teen", false };
	Items Harry_Potter1{ "Harry Potter 1", "children", false };
	Items Harry_Potter2{ "Harry Potter 2", "children", false };
	Items Harry_Potter3{ "Harry Potter 3", "children", false };



	std::cout << "Hello and welcome to our state of the art library managemet system!\nWhat action would you like to perform?: " << std::endl;

	main_menu();

	return 0;
}

void main_menu() {
	while (true) {
		std::cout << "\n==========Main Menu==========\n" << std::endl;
		std::cout << "1. Add patron to the system\n2. Add item to the list of borrowable items\n3. Edit a patron's or item's information\n4. Let a patron borrow an item\n5. Display all patrons\n6. Display all borrowable items\n7. Display patron information\n8. Display item information\n9. Exit application" << std::endl;

		int* choice = new int{};

		std::cin >> *choice;

		std::cin.ignore();

		switch (*choice) {
		case 1: //Add patron
		{
			std::string* temp_name = new std::string{};
			int* temp_age = new int{};

			std::cout << "Please enter the name of the patron: ";

			std::getline(std::cin, *temp_name);

			std::cout << "Please enter the age of the patron: ";

			std::cin >> *temp_age;

			Patron* new_patron = new Patron{ Patron::Patron(*temp_name, *temp_age) };

			bool skip{ false };

			//Check if the patron exists in the system already
			for (size_t i{}; i < Patron::get_num_patrons() - 1; i++) {
				if (*new_patron == *(Patron::get_patrons_vector()[i])) {
					std::cout << "\nSorry, this patron is already in the system" << std::endl;
					delete temp_name;
					delete temp_age;
					new_patron->Patron::~Patron();
					skip = true;
					break;
				}
			}
			if (skip == false) { //Skipped if patron found
				std::cout << "\n==========New patron!==========\n";

				std::cout << "\nAdded a patron named " << new_patron->get_name() << " of age " << new_patron->get_age() << std::endl;

				delete temp_name;
				delete temp_age;
			}
			break;
		}
		case 2: { //Add item
			std::string* temp_name = new std::string{};
			std::string* temp_rating = new std::string{};
			std::cout << "Please enter the name of the item: ";

			std::getline(std::cin, *temp_name);

			std::cout << "Please enter the intended audience: ";

			std::getline(std::cin, *temp_rating);

			//std::cin >> *temp_name >> *temp_rating;

			Items* new_item = new Items{ Items::Items(*temp_name, *temp_rating) };

			std::cout << "\n==========New item!==========\n";

			std::cout << "\nAdded an item named " << new_item->get_name() << " for " << new_item->get_rating() << std::endl;

			delete temp_name;
			delete temp_rating;
			break;
		}
		case 3: { //Edit
			std::cout << "\n==========Edit menu==========\n" << std::endl;

			bool skip{ false };

			std::cout << "Would you like to edit \n\n1. An item's information\n\n2. A patron's information\n\n" << std::endl;

			int choice{};

			std::cin >> choice;

			switch (choice) {
				case 2: {
					std::cout << "\nWhich patron would like to edit?: \n" << std::endl;

					int choice{};
					bool skip{ false };

					for (int i{}; i < Patron::get_num_patrons(); i++) {
						std::cout << i + 1 << ". Patron: " << Patron::get_patrons_vector()[i]->get_name() << "\n" << std::endl;
					}

					std::cin >> choice;

					if (choice > Patron::get_num_patrons()) {
						std::cout << "\nSorry, invalid choice.\n" << std::endl;
						skip = true;
					}
					else {
						std::cout << "\nSelected patron: " << Patron::get_patrons_vector()[choice - 1]->get_name() << "\n" << std::endl;
					}
					if (skip != true) {
						std::cout << *Patron::get_patrons_vector()[choice - 1] << "\n" << std::endl;

						std::cout << "Please enter patron's new name: ";

						std::string new_name{};

						std::cin >> new_name;

						Patron::get_patrons_vector()[choice - 1]->set_name(new_name);

						std::cout << "Please enter patron's new age: ";

						int new_age{};

						std::cin >> new_age;

						Patron::get_patrons_vector()[choice - 1]->set_age(new_age);

						std::cout << "\nhow to You have succesfully editted patron " << Patron::get_patrons_vector()[choice - 1]->get_name() << "\n" << std::endl;
					}
					break;
				}
				case 1: {
					std::cout << "\nWhich item would like to edit?: \n" << std::endl;

					int choice{};
					bool skip{ false };

					for (int i{}; i < Items::get_num_items(); i++) {
						std::cout << i + 1 << ". Item: " << Items::get_items_vector()[i]->get_name() << "\n" << std::endl;
					}

					std::cin >> choice;

					if (choice > Items::get_num_items()) {
						std::cout << "\nSorry, invalid choice.\n" << std::endl;
						skip = true;
					}
					else {
						std::cout << "\nSelected item: " << Items::get_items_vector()[choice - 1]->get_name() << ". Please keep in mind you cannot change borrowed status in this menu.\n" << std::endl;
					}
					if (skip != true) {

						std::cout << *Items::get_items_vector()[choice - 1] << "\n" << std::endl;

						std::cout << "Please enter item's new name: ";

						std::string new_name{};

						std::cin >> new_name;

						Items::get_items_vector()[choice - 1]->change_name(new_name);

						std::cout << "Please enter patron's new inteded audience: ";

						std::string new_rating{};

						std::cin >> new_rating;

						Items::get_items_vector()[choice - 1]->change_rating(new_rating);

						std::cout << "\nYou have succesfully editted item " << Items::get_items_vector()[choice - 1]->get_name() << "\n" << std::endl;
					}
					break;
				}
			}

			break;
		}
		case 4: { //Add assign 

			std::cout << "\n==========Borrow menu==========\n" << std::endl;

			bool skip{ false };

			//Patron choice
			std::cout << "Which patron would like to borrow an item?: \n" << std::endl;

			for (int i{}; i < Patron::get_num_patrons(); i++) {
				std::cout << i + 1 << ". Patron: " << Patron::get_patrons_vector()[i]->get_name() << "\n" << std::endl;
			}

			int* choice1 = new int{};
			std::cin >> *choice1;

			if (*choice1 > Patron::get_num_patrons()) {
				std::cout << "\nSorry, invalid choice.\n" << std::endl;
				skip = true;
			}
			else {
				std::cout << "\nSelected patron: " << Patron::get_patrons_vector()[*choice1 - 1]->get_name() << "\n" << std::endl;
			}

			//Item choice

			int* choice2 = new int{};

			if (skip == false) {
				std::cout << "\n==========Borrow menu==========\n" << std::endl;
				std::cout << "\nWhich item would they like to borrow?: \n" << std::endl;

				for (int i{}; i < Items::get_num_items(); i++) {
					std::cout << i + 1 << ". Item: " << Items::get_items_vector()[i]->get_name() << "\n" << std::endl;
				}

				std::cin >> *choice2;

				if (*choice2 > Items::get_num_items()) {
					std::cout << "\nSorry, invalid choice.\n" << std::endl;
					skip = true;
				}
				else if (Items::get_items_vector()[*choice2 - 1]->get_status() == true){
					skip = true;
					std::cout << "\nSorry, this item is currently being borrowed by another patron, " << Items::get_items_vector()[*choice2 - 1]->get_borrower() << "\n" << std::endl;
				}
				else {
					std::cout << "\nSelected item: " << Items::get_items_vector()[*choice2 - 1]->get_name() << "\n" << std::endl;
				}
			}
			if (skip == false) {
				std::cout << "\nPatron " << Patron::get_patrons_vector()[*choice1 - 1]->get_name() << " succesfully borrowed " << Items::get_items_vector()[*choice2 - 1]->get_name() << std::endl;
				//change patron attributes
				Patron::get_patrons_vector()[*choice1 - 1]->assign_item(Items::get_items_vector()[*choice2 - 1]);
				Patron::get_patrons_vector()[*choice1 - 1]->set_items(1);
				//change item attributes
				Items::get_items_vector()[*choice2 - 1]->change_status(true);
				Items::get_items_vector()[*choice2 - 1]->change_borrower(Patron::get_patrons_vector()[*choice1 - 1]->get_name());
			}

			delete choice1;
			delete choice2;

			break;
		}
		case 5: //Display patrons
			Patron::get_all_patrons();
			break;
		case 6: //Display items
			Items::get_all_items();
			break;
		case 7: { //Display patron info
			std::cout << "\n==========Display menu==========\n" << std::endl;
			std::cout << "Which patron would you like to know more about?: \n" << std::endl;
			int choice{};
			bool skip{ false };

			for (int i{}; i < Patron::get_num_patrons(); i++) {
				std::cout << i + 1 << ". Patron: " << Patron::get_patrons_vector()[i]->get_name() << "\n" << std::endl;
			}

			std::cin >> choice;

			if (choice > Patron::get_num_patrons()) {
				std::cout << "\nSorry, invalid choice.\n" << std::endl;
				skip = true;
			}
			else {
				std::cout << "\nSelected patron: " << Patron::get_patrons_vector()[choice - 1]->get_name() << "\n" << std::endl;
			}

			if (skip == false) {
				if (Patron::get_patrons_vector()[choice - 1]->get_num_items() == 0)
					std::cout << "The selected patron's name is " << Patron::get_patrons_vector()[choice - 1]->get_name() << " and their age is " << Patron::get_patrons_vector()[choice - 1]->get_age() << ". They also have no borrowed items. \n";
				else {
					if (Patron::get_patrons_vector()[choice - 1]->get_num_items() == 1)
						std::cout << "The selected patron's name is " << Patron::get_patrons_vector()[choice - 1]->get_name() << " and their age is " << Patron::get_patrons_vector()[choice - 1]->get_age() << ". They also have one borrowed item: " << Patron::get_patrons_vector()[choice - 1]->get_items_vector()[0]->get_name() << "\n" << std::endl;
					else {
						std::cout << "The selected patron's name is " << Patron::get_patrons_vector()[choice - 1]->get_name() << " and their age is " << Patron::get_patrons_vector()[choice - 1]->get_age() << ". They also have " << Patron::get_patrons_vector()[choice - 1]->get_num_items() << " borrowed items: \n" << std::endl;
						for (auto& item : Patron::get_patrons_vector()[choice - 1]->get_items_vector())
							std::cout << item->get_name() << "\n" << std::endl;
					}
				}
			}

			break;
		}
		case 8: { //Display patron info
			std::cout << "\n==========Display menu==========\n" << std::endl;
			std::cout << "Which item would you like to know more about?: \n" << std::endl;
			int choice{};
			bool skip{ false };

			for (int i{}; i < Items::get_num_items(); i++) {
				std::cout << i + 1 << ". Item: " << Items::get_items_vector()[i]->get_name() << "\n" << std::endl;
			}

			std::cin >> choice;

			if (choice > Items::get_num_items()) {
				std::cout << "\nSorry, invalid choice.\n" << std::endl;
				skip = true;
			}
			else {
				std::cout << "\nSelected item: " << Items::get_items_vector()[choice - 1]->get_name() << "\n" << std::endl;
			}

			if (skip == false) {
				if (Items::get_items_vector()[choice - 1]->get_status() == false)
					std::cout << "\nThe selected item's name is " << Items::get_items_vector()[choice - 1]->get_name() << ". The item is inteded for " << Items::get_items_vector()[choice - 1]->get_rating() << ". The item is currently not borrowed.\n" << std::endl;
				else
					std::cout << "\nThe selected item's name is " << Items::get_items_vector()[choice - 1]->get_name() << ". The item is inteded for " << Items::get_items_vector()[choice - 1]->get_rating() << ". The item is currently being borrowed by " << Items::get_items_vector()[choice - 1]->get_borrower() << "\n" << std::endl; 
				break;
			}
		}
		case 9: //Exit
			std::cout << "Exiting program...";
			return;
		default:
			std::cout << "Invalid choice." << std::endl;
			std::cin.ignore();
			break;
		}
		delete choice;
	}
}
