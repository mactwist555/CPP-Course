#include <iostream>
using namespace std;

class ZooKeeper;

class Animal
{
	public:
	Animal();

	friend class ZooKeeper;

	int public_var_animal;

	protected:
	int protected_var_animal;

	private:
	int private_var_animal;
};

class Duck : public Animal
{
	public:
	Duck();

	friend class ZooKeeper;

	int public_var_duck;

	protected:
	int protected_var_duck;

	private:
	int private_var_duck;
};

class ZooKeeper
{
	public:
	void CheckAnimal( Animal& animal );
	void CheckDuck( Duck& duck );
};

int main()
{
	ZooKeeper keeper;
	Animal animal;
	Duck duck;

	cout << "Access to animal?" << endl;
	keeper.CheckAnimal( animal );

	cout << endl << endl << "Access to duck?" << endl;
	keeper.CheckDuck( duck );

	return 0;
}

Animal::Animal()
{
	public_var_animal = 1;
	protected_var_animal = 2;
	private_var_animal = 3;
}



Duck::Duck()
{
	public_var_duck = 4;
	protected_var_duck = 5;
	private_var_duck = 6;
}



void ZooKeeper::CheckAnimal( Animal& animal )
{
	cout << "Public:    " << animal.public_var_animal << endl;
	cout << "Protected: " << animal.protected_var_animal << endl;
	cout << "Private:   " << animal.private_var_animal << endl;
}

void ZooKeeper::CheckDuck( Duck& duck )
{
	cout << "Public Parent:    " << duck.public_var_animal << endl;
	cout << "Protected Parent: " << duck.protected_var_animal << endl;
	cout << "Private Parent:   " << duck.private_var_animal << endl;

	cout << "Public Child:     " << duck.public_var_duck << endl;
	cout << "Protected Child:  " << duck.protected_var_duck << endl;
	cout << "Private Child:    " << duck.private_var_duck << endl;
}
