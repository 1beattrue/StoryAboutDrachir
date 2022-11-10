#include <iostream>
#include <map>
#include <conio.h>
#include <fstream>
#include <string>
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

	void setLocation(string loc) { // изменение локации
		location = loc;
	}

	string getLocation() { // получение локации
		return location;
	}
};

class Start { // старт
public:
	Start() {}

	void gameDescription() {
		ifstream fin("gameDescription.txt");
		string s;
		while (getline(fin, s)) {
			cout << s << endl;
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
		}
		fin.close();
	}
};

class Info { // мудрец
public:
	Info() {}

	void dialog() {
		ifstream fin1("infoDialog.txt");
		string s;
		while (getline(fin1, s)) {
			cout << s << endl;
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
		}
		fin1.close();
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы пойти налево" << endl;
		cout << "Нажмите 2, чтобы пойти направо" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "imp";
				break;
			case 50:
				return "elf";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Enemy { // враг
protected:
	int strong;
	string loot;
	bool visited;
	bool alive;

public:
	Enemy() {}

	int attack(int hero_strong, int enemy_strong) {
		double win_chance_percent = (hero_strong / enemy_strong) * 100;
		win_chance_percent = (int)win_chance_percent;
		int rnd = rand() % 100;
		cout << win_chance_percent;
		cout << rnd;
		if (win_chance_percent < rnd) return 1;
		else return 0;
	}

	int getStrong() {
		return strong;
	}

	void setLoot(string item) {
		loot = item;
	}

	string getLoot() {
		return loot;
	}

	void setVisited(bool visit) {
		visited = visit;
	}

	bool getVisited() {
		return visited;
	}

	void setAlive(bool al) {
		alive = al;
	}

	bool getAlive() {
		return alive;
	}
};

class Imp : public Enemy {
public: 
	Imp(int pow, string item, bool visit, bool alive) {
		this->strong = pow;
		this->loot = item;
		this->visited = visit;
		this->alive = alive;
	}

	void dialog() {
		cout << "я имп" << endl;
	}

	void deadImp() {
		cout << "я мертвый имп" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти направо" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "sphinx";
				break;
			case 51:
				return "elf";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	restart:
	for (int i = 0; i < 100; i++) cout << "\n\n\n\n\n"; // костыль для очистки консоли
	map <string, int> locations = { {"start", 0},  {"info", 1},
									{"imp", 2},    {"elf", 3},
									{"sphinx", 4}, {"traveler", 5},
									{"demon", 6},  {"witch", 7},
									{"boss", 8},   {"finish", 9} };

	Hero Drachir(1, 0, 8, 0, "start");
	Start start;
	Info info;
	Imp imp(9, "imp's pitchfork", false, true);
	imp.setAlive(true);
	
	while (Drachir.getHealth() > 0) {
		switch (locations[Drachir.getLocation()]) {
			case 0:
				// переход в локацию старт
				start.gameDescription();
				Drachir.setLocation("info");
				break;
			case 1:
				// переход в локацию инфо
				info.dialog();
				Drachir.setLocation(info.moveTo());
				break;
			case 2:
				// переход в локацию импа
				if (!imp.getVisited()) {
					imp.dialog();
					imp.setVisited(true);
					Drachir.setHealth(Drachir.getHealth() - imp.attack(Drachir.getStrong(), imp.getStrong()));
					if (Drachir.getHealth() == 0) break;
					imp.setAlive(false);
				}
				else {
					if (imp.getAlive() == false)imp.deadImp();
				}
				Drachir.setLocation(imp.moveTo());
				break;
			case 3:
				cout << "elf";
				// переход в локацию эльфа
				break;
			case 4:
				cout << "sphinx";
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
		}
	}

	cout << "Увы, Драчир пал смертью храбрых.\nХотите начать заново? Нажмите Enter\nХотите завершить игру? Нажмите Esc" << endl;
	while (true) {
		switch (_getch()) {
		case 13:
			goto restart;
			break;
		case 27:
			exit(0);
		}
	}
}