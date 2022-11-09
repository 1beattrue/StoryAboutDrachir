#include <iostream>

using namespace std;

class Hero {
private:
	int health;
	int reputation;
	int strong;
	int endurance;
	string location;

public:
	Hero(int hp, int rep, int pow, int end, string loc) { // конструктор 
		this->health = hp;
		this->reputation = rep;
		this->strong = pow;
		this->endurance = end;
		this->location = loc;
	}

	void setHealth(int hp) { // изменение здоровья
		health = hp;
	}

	int getHealth() { // получение здоровья
		return health;
	}

	void setReputation(int rep) { // изменение репутации
		reputation = rep;
	}

	int getReputation() { // получение репутации
		return reputation;
	}

	void setStrong(int pow) { // изменение силы
		strong = pow;
	}

	int getStrong() { // получение силы
		return strong;
	}

	void setEndurance(int end) { // изменение выносливости
		endurance = end;
	}

	int getEndurance() { // получение выносливости
		return endurance;
	}

	void setLocation(int loc) { // изменение локации
		location = loc;
	}

	string getLocation() { // получение локации
		return location;
	}
};


int main()
{
	
}