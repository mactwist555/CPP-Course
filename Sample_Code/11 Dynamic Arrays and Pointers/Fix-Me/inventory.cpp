#include "Inventory.hpp"

#include <iostream>
using namespace std;

Inventory::Inventory(int price, int stock, int serial, string loc, string label)
{
	m_price = price;
	m_stock = stock;
	m_serial = serial;
	m_location = loc;
	m_label = label;
}

Food::Food(string exp, bool fridge, string group, int price, int stock, int serial, string loc, string label)
	: Inventory(price, stock, serial, loc, label)
{
	m_expiration = exp;
	m_fridgerated = fridge;
	m_foodGroup = group;
}

Movie::Movie(string rating, string genre, int price, int stock, int serial, string loc, string label)
	:Inventory(price, stock, serial, loc, label)
{
	m_rating = rating;
	m_genre = genre;
}

void Inventory::DisplayInfo()
{
	cout << m_label << "\t $" << m_price << endl;
	
	if (m_stock > 0){
		cout << "In stock" << endl;
	}
	else {
		cout << "On backorder" << endl;
	}
}

void Food::DisplayInfo()
{
	Inventory::DisplayInfo();

	cout << "Food Group: " << m_foodGroup << endl;
}

void Movie::DisplayInfo()
{
	Inventory::DisplayInfo();

	cout << "Genre:  " << m_genre << endl;
	cout << "Rating: " << m_rating << endl;
}
