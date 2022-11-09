#include <iostream>
#include <map>
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

class Map {
private:
	map <string, int> locations = { {"start", 0},  {"info", 1}, 
									{"imp", 2},    {"elf", 3},
									{"sphinx", 4}, {"traveler", 5},
									{"demon", 6},  {"witch", 7}, 
									{"boss", 8},   {"finish", 9} };
public:
	Map(string loc) {
		
	}

	void moveToLocation(string loc) {
		switch (locations[loc]) {
		case 0:
			// переход в локацию старт
			break;
		case 1:
			// переход в локацию инфо
			break;
		case 2:
			// переход в локацию импа
			break;
		case 3:
			// переход в локацию эльфа
			break;
		case 4:
			// переход в локацию сфинкса
			break;
		case 5:
			// переход в локацию путника
			break;
		case 6:
			// переход в локацию демона
			break;
		case 7:
			// переход в локацию волшебницы
			break;
		case 8:
			// переход в локацию сатаны
			break;
		case 9:
			// переход в локацию финиш
			break;
		default:
			cout << "Драчир: Не-е, туда я не пойду";
			break;
		}
	}
};


int main()
{
	Hero Drachir(3, 0, 0, 0, "start");
}