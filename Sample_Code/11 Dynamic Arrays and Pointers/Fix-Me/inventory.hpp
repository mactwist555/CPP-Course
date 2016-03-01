#ifndef _INVENTORY
#define _INVENTORY

#include <string>
using namespace std;

class Inventory
{
public:
	Inventory(int price, int stock, int serial, string loc, string label);

	string GetLabel() { return m_label;  }
	float GetPrice() { return m_price; }
	int GetStock() { return m_stock; }
	void DisplayInfo();

protected:
	float m_price;
	int m_stock;
	int m_serial;
	string m_location;
	string m_label;
};

class Food : public Inventory
{
public:
	Food(string exp, bool fridge, string group, int price, int stock, int serial, string loc, string label);
	void DisplayInfo();

protected:
	string m_expiration;
	bool m_fridgerated;
	string m_foodGroup;
};

class Movie : public Inventory
{
public:
	Movie(string rating, string genre, int price, int stock, int serial, string loc, string label);
	void DisplayInfo();

protected:
	string m_rating;
	string m_genre;
};

#endif
