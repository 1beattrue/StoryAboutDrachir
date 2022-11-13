#include <iostream>
#include <map>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Hero {
private:
	int health;
	int reputation;
	int strong;
	bool invisibility;
	string location;
	vector <string> inventory;

public:
	Hero(int hp, int rep, int pow, int invis, string loc, vector <string> items) { // конструктор 
		this->health = hp;
		this->reputation = rep;
		this->strong = pow;
		this->invisibility = invis;
		this->location = loc;
		this->inventory = items;
	}

	void setHealth(int hp) { // изменение здоровья
		health = hp;
		cout << "Ваше здоровье: ";
		for (int i = 0; i < health; i++) cout << "<3 ";
		cout << endl;
	}

	int getHealth() { // получение здоровья
		return health;
	}

	void setReputation(int rep) { // изменение репутации
		if (rep < reputation) cout << "Вы совершили плохой поступок. Ваша репутация ухудшилась..." << endl;
		else cout << "Вы совершили хороший поступок! Ваша репутация увеличилась!" << endl;
		cout << "Ваша репутация: " << rep << endl;
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

	void setInvisibility(bool invis) { // изменение невидимости
		if (invis == true) cout << "Теперь у вас есть магия невидимости" << endl;
		invisibility = invis;
	}

	int getInvisibility() { // получение невидимости
		return invisibility;
	}

	void setLocation(string loc) { // изменение локации
		location = loc;
	}

	string getLocation() { // получение локации
		return location;
	}

	void addItemToInventory(string item) { // добавление предмета
		inventory.push_back(item);
	}

	vector <string> getInventory() { // получение инвентаря
		return inventory;
	}
};

class Start { // старт
public:
	Start() {}

	void gameDescription() {
		ifstream fin("gameDescription.txt");
		string s;
		getline(fin, s);
		cout << s << endl;
		while (getline(fin, s)) {
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
			cout << s << endl;
		}
		fin.close();
	}
};

class Finish { // финиш
public:
	Finish() {}

	void nobodyEnding() {
		ifstream fin_nobody_end("nobodyEnding.txt");
		string s;
		getline(fin_nobody_end, s);
		cout << s << endl;
		while (getline(fin_nobody_end, s)) {
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
			cout << s << endl;
		}
		fin_nobody_end.close();
	}

	void badEnding() {
		ifstream fin_bad_end("badEnding.txt");
		string s;
		getline(fin_bad_end, s);
		cout << s << endl;
		while (getline(fin_bad_end, s)) {
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
			cout << s << endl;
		}
		fin_bad_end.close();
	}

	void goodEnding() {
		ifstream fin_good_end("goodEnding.txt");
		string s;
		getline(fin_good_end, s);
		cout << s << endl;
		while (getline(fin_good_end, s)) {
			cout << "Нажмите space, чтобы продолжть" << endl;
			bool flag = true;
			while (flag) {
				switch (_getch()) {
				case 32:
					flag = false;
					break;
				}
			}
			cout << s << endl;
		}
		fin_good_end.close();
	}
};

class Info { // мудрец
private:
	bool visited;

public:
	Info(bool visit) {
		this->visited = visit;
	}

	void dialog(bool visit) {
		if (!visit) {
			ifstream fin1("infoDialog.txt");
			string s;
			getline(fin1, s);
			cout << s << endl;
			while (getline(fin1, s)) {
				cout << "Нажмите space, чтобы продолжть" << endl;
				bool flag = true;
				while (flag) {
					switch (_getch()) {
					case 32:
						flag = false;
						break;
					}
				}
				cout << s << endl;
			}
			fin1.close();
		}
		else {
			cout << "я мудрец и ты уже был здесь" << endl;
		}
	}

	void setVisited(bool visit) {
		visited = visit;
	}

	bool getVisited() {
		return visited;
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
		double win_chance_percent = ((double)hero_strong / enemy_strong) * 100;
		win_chance_percent = (int)win_chance_percent;
		int rnd = rand() % 100;
		cout << win_chance_percent << endl;
		cout << rnd << endl;
		if (win_chance_percent < rnd) {
			cout << "поражение" << endl;
			return 1;
		}
		else {
			cout << "победа" << endl;
			return 0;
		}
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

class Imp : public Enemy { // имп
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
				return "traveler";
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

class Sphinx : public Enemy { // имп
public:
	Sphinx(int pow, string item, bool visit, bool alive) {
		this->strong = pow;
		this->loot = item;
		this->visited = visit;
		this->alive = alive;
	}

	void dialog(bool visit) {
		if (!visit) {
			cout << "я сфинкс" << endl;
		}
		else {
			cout << "я сфинкс и ты уже был здесь" << endl;
		}
	}

	int choice1() {
		cout << "Отгадать загадки или убить?" << endl;
		cout << "Нажмите 1, чтобы начать отгадывать загадки" << endl;
		cout << "Нажмите 2, чтобы попытаться убить Сфинкса" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return 1;
				break;
			case 50:
				return 2;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	int choice2() {
		cout << "Уйти или убить?" << endl;
		cout << "Нажмите 1, чтобы уйти" << endl;
		cout << "Нажмите 2, чтобы попытаться убить Сфинкса" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return 3;
				break;
			case 50:
				return 2;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	bool riddles() {
		cout << "Загадка 1 (ответ 1)" << endl;
		string right_ans1 = "1";
		string user_ans1;
		cin >> user_ans1;
		if (user_ans1 != right_ans1) return false;

		cout << "Загадка 2 (ответ 2)" << endl;
		string right_ans2 = "2";
		string user_ans2;
		cin >> user_ans2;
		if (user_ans2 != right_ans2) return false;

		cout << "Загадка 3 (ответ 3)" << endl;
		string right_ans3 = "3";
		string user_ans3;
		cin >> user_ans3;
		if (user_ans3 != right_ans3) return false;

		return true;
	}

	void deadSphinx() {
		cout << "я мертвый сфинкс" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти налево" << endl;
		cout << "Нажмите 4, чтобы пойти назад" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "demon";
				break;
			case 51:
				return "traveler";
				break;
			case 52:
				return "elf";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Demon : public Enemy { // имп
public:
	Demon(int pow, string item, bool visit, bool alive) {
		this->strong = pow;
		this->loot = item;
		this->visited = visit;
		this->alive = alive;
	}

	void dialog(bool visit) {
		if (!visit) {
			cout << "я демон" << endl;
		}
		else {
			cout << "я демон и ты уже был здесь" << endl;
		}
	}

	void deadDemon() {
		cout << "я мертвый демон" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти налево" << endl;
		cout << "Нажмите 4, чтобы пойти назад" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "boss";
				break;
			case 51:
				return "witch";
				break;
			case 52:
				return "sphinx";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Witch : public Enemy { // имп
public:
	Witch(int pow, string item, bool visit, bool alive) {
		this->strong = pow;
		this->loot = item;
		this->visited = visit;
		this->alive = alive;
	}

	void dialog(bool visit) {
		if (!visit) {
			cout << "я ведьма" << endl;
		}
		else {
			cout << "я ведьма и ты уже был здесь" << endl;
		}
	}

	int choice1() {
		cout << "Отгадать загадки или убить?" << endl;
		cout << "Нажмите 1, чтобы начать отгадывать загадки" << endl;
		cout << "Нажмите 2, чтобы убить Ведьму" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return 1;
				break;
			case 50:
				return 2;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	int choice2() {
		cout << "Уйти или убить?" << endl;
		cout << "Нажмите 1, чтобы уйти" << endl;
		cout << "Нажмите 2, чтобы попытаться убить Ведьму" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return 3;
				break;
			case 50:
				return 2;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	bool riddles() {
		cout << "Загадка 1 (ответ 1)" << endl;
		string right_ans1 = "1";
		string user_ans1;
		cin >> user_ans1;
		if (user_ans1 != right_ans1) return false;

		cout << "Загадка 2 (ответ 2)" << endl;
		string right_ans2 = "2";
		string user_ans2;
		cin >> user_ans2;
		if (user_ans2 != right_ans2) return false;

		cout << "Загадка 3 (ответ 3)" << endl;
		string right_ans3 = "3";
		string user_ans3;
		cin >> user_ans3;
		if (user_ans3 != right_ans3) return false;

		return true;
	}

	void deadWitch() {
		cout << "я мертвая ведьма" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти направо" << endl;
		cout << "Нажмите 4, чтобы пойти назад" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "boss";
				break;
			case 51:
				return "demon";
				break;
			case 52:
				return "traveler";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Npc {
protected:
	bool visited;
	bool alive;

public:
	Npc() {}

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

class Traveler : public Npc {
public:
	Traveler(bool visit, bool alive) {
		this->visited = visit;
		this->alive = alive;
	}

	void dialog(bool visit) {
		if (!visit) {
			cout << "я путник" << endl;
		}
		else {
			cout << "я путник и ты уже был здесь" << endl;
		}
	}

	bool choice() {
		cout << "Нажмите 1, чтобы помочь" << endl;
		cout << "Нажмите 2, чтобы проигнорировать просьбу" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return true;
				break;
			case 50:
				return false;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	void deadTraveler() {
		cout << "я мертвый путник" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти направо" << endl;
		cout << "Нажмите 4, чтобы пойти назад" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "witch";
				break;
			case 51:
				return "sphinx";
				break;
			case 52:
				return "imp";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Elf : public Npc {
public:
	Elf(bool visit, bool alive) {
		this->visited = visit;
		this->alive = alive;
	}

	void dialog(bool visit) {
		if (!visit) {
			cout << "я эльф" << endl;
		}
		else {
			cout << "я эльф и ты уже был здесь" << endl;
		}
	}

	bool choice() {
		cout << "Нажмите 1, чтобы помочь" << endl;
		cout << "Нажмите 2, чтобы проигнорировать просьбу" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return true;
				break;
			case 50:
				return false;
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}

	void deadElf() {
		cout << "я мертвый эльф" << endl;
	}

	string moveTo() {
		cout << "Нажмите 1, чтобы вернуться к мудрецу" << endl;
		cout << "Нажмите 2, чтобы пойти вперед" << endl;
		cout << "Нажмите 3, чтобы пойти налево" << endl;
		while (true) {
			switch (_getch()) {
			case 49:
				return "info";
				break;
			case 50:
				return "sphinx";
				break;
			case 51:
				return "imp";
				break;
			default:
				cout << "Каво?" << endl;
				break;
			}
		}
	}
};

class Boss {
private:
	int strong;

public:
	Boss(int pow) {
		this->strong = pow;
	}

	int attack(int hero_strong, int enemy_strong) {
		double win_chance_percent = ((double)hero_strong / enemy_strong) * 100;
		win_chance_percent = (int)win_chance_percent;
		int rnd = rand() % 100;
		cout << win_chance_percent << endl;
		cout << rnd << endl;
		if (win_chance_percent < rnd) {
			cout << "поражение" << endl;
			return 0;
		}
		else {
			cout << "победа" << endl;
			return 1;
		}
	}

	int getStrong() {
		return strong;
	}

	void dialog() {
		cout << "я босс" << endl;
	}

	void deadBoss() {
		cout << "вы убили босса" << endl;
	}

	string moveTo() {
		cout << "Для продолжения нажмите space" << endl;
		while (true) {
			switch (_getch()) {
			case 32:
				return "finish";
				break;
			}
		}
	}
};


class Map {
private:
	string tmp_location;

public:
	Map() {}

	void showMap(string loc) {
		ifstream fin_map("map.txt");
		vector <string> m;
		string tmp;
		while (getline(fin_map, tmp)) {
			m.push_back(tmp);
		}

		// размещение персонажа
		if (loc == "info") {
			m[21][31] = '<';
			m[21][38] = '>';
		}
		else if (loc == "imp") {
			m[18][21] = '<';
			m[18][25] = '>';
		}
		else if (loc == "elf") {
			m[18][43] = '<';
			m[18][48] = '>';
		}
		else if (loc == "traveler") {
			m[14][17] = '<';
			m[14][24] = '>';
		}
		else if (loc == "sphinx") {
			m[14][36] = '<';
			m[14][43] = '>';
		}
		else if (loc == "witch") {
			m[10][14] = '<';
			m[10][21] = '>';
		}
		else if (loc == "demon") {
			m[10][31] = '<';
			m[10][37] = '>';
		}

		// вывод карты
		cout << endl;
		for (string x : m) {
			cout << x << endl;
		}
		cout << endl;
	}
};

int powerOfHero(vector <string> arg) {
	map <string, int> items = { {"full of holes chain armor", 5},
								{"rusty poleaxe", 5},
								{"imp's pitchfork", 20},
								{"silver sword", 50},
								{"demon armor", 50} };
	int p = 0;
	cout << "Ваш инвентарь:" << endl;
	for (string x : arg) {
		p += items[x];
		cout << x << endl;
	}
	cout << "Ваша сила: " << p << endl;
	return p;
}

int main() {
	setlocale(LC_ALL, "Russian");

	restart:
	for (int i = 0; i < 100; i++) cout << "\n\n\n\n\n"; // костыль для очистки консоли
	
	map <string, int> locations = { {"start", 0},  {"info", 1},     // карта 
									{"imp", 2},    {"elf", 3},
									{"traveler", 4}, {"sphinx", 5},
									{"witch", 6},  {"demon", 7},
									{"boss", 8},   {"finish", 9} };

	Hero Drachir(2, 0, 0, false, "start", {});
	Start start;
	Info info(false);
	Imp imp(9, "imp's pitchfork", false, true);
	Sphinx sphinx(300, "silver sword", false, true);
	Demon demon(79, "demon armor", false, true);
	Witch witch(1, "magic", false, true);
	Traveler traveler(false, true);
	Elf elf(false, true);
	Boss boss(129);
	Finish finish;
	Map gamemap;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	while (Drachir.getHealth() > 0) {
		switch (locations[Drachir.getLocation()]) {
		case 0:
			// переход в локацию старт
			SetConsoleTextAttribute(hConsole, 15);
			start.gameDescription();
			SetConsoleTextAttribute(hConsole, 2);
			Drachir.addItemToInventory("full of holes chain armor");
			Drachir.addItemToInventory("rusty poleaxe");
			Drachir.setStrong(powerOfHero(Drachir.getInventory()));
			Drachir.setLocation("info");
			break;
		case 1:
			// переход в локацию инфо
			SetConsoleTextAttribute(hConsole, 15);
			info.dialog(info.getVisited());
			info.setVisited(true);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(info.moveTo());
			break;
		case 2:
			// переход в локацию импа
			SetConsoleTextAttribute(hConsole, 15);
			if (!imp.getVisited()) {
				imp.dialog();
				imp.setVisited(true);

				if (Drachir.getInvisibility()) {
					SetConsoleTextAttribute(hConsole, 3);
					cout << "Вы можете использовать магию невидимости, нажав 1, либо вступить в сражение, нажав любую другую клавишу" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					switch (_getch()) {
					case 49:
						cout << "Вы стали незаметным для врага. Куда бежать?" << endl;
						Drachir.setInvisibility(false);
						imp.setVisited(false);
						goto skip_imp;
						break;
					}
				}
				int battle = imp.attack(Drachir.getStrong(), imp.getStrong());
				SetConsoleTextAttribute(hConsole, 2);
				Drachir.setHealth(Drachir.getHealth() - battle);
				if (Drachir.getHealth() == 0) break;
				imp.setAlive(false);
				SetConsoleTextAttribute(hConsole, 2);
				Drachir.addItemToInventory(imp.getLoot());
				Drachir.setStrong(powerOfHero(Drachir.getInventory()));
			}
			else {
				if (imp.getAlive() == false)imp.deadImp();
			}
		skip_imp:
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(imp.moveTo());
			break;
		case 3:
			// переход в локацию эльфа
			SetConsoleTextAttribute(hConsole, 15);
			if (elf.getAlive()) {
				elf.dialog(elf.getVisited());
				if (!elf.getVisited()) {
					elf.setVisited(true);
					SetConsoleTextAttribute(hConsole, 3);
					if (elf.choice()) {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setReputation(Drachir.getReputation() + 5);
					}
					else {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setReputation(Drachir.getReputation() - 5);
						elf.setAlive(false);
					}
				}
			}
			else elf.deadElf();
			if (Drachir.getHealth() == 0) break;
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(elf.moveTo());
			break;
		case 4:
			// переход в локацию путника
			SetConsoleTextAttribute(hConsole, 15);
			if (traveler.getAlive()) {
				traveler.dialog(traveler.getVisited());
				if (!traveler.getVisited()) {
					traveler.setVisited(true);
					SetConsoleTextAttribute(hConsole, 3);
					if (traveler.choice()) {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setReputation(Drachir.getReputation() + 5);
					}
					else {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setReputation(Drachir.getReputation() - 5);
						traveler.setAlive(false);
					}
				}
			}
			else traveler.deadTraveler();
			if (Drachir.getHealth() == 0) break;
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(traveler.moveTo());
			break;
		case 5:
			// переход в локацию сфинкса
			SetConsoleTextAttribute(hConsole, 15);
			if (sphinx.getAlive()) {
				sphinx.dialog(sphinx.getVisited());
				int choice;
				if (!sphinx.getVisited()) {
					sphinx.setVisited(true);
					SetConsoleTextAttribute(hConsole, 3);
					choice = sphinx.choice1();
				}
				else {
					SetConsoleTextAttribute(hConsole, 3);
					choice = sphinx.choice2();
				}
				switch (choice) {
				case 1:
					SetConsoleTextAttribute(hConsole, 15);
					if (sphinx.riddles()) {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.addItemToInventory(sphinx.getLoot());
						Drachir.setStrong(powerOfHero(Drachir.getInventory()));
					}
					else {
						cout << "лох" << endl;
					}
					break;
				case 2:
					int battle = sphinx.attack(Drachir.getStrong(), sphinx.getStrong());
					SetConsoleTextAttribute(hConsole, 2);
					Drachir.setHealth(Drachir.getHealth() - battle);
					if (battle == 0) {
						sphinx.setAlive(false);
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.addItemToInventory(sphinx.getLoot());
						Drachir.setStrong(powerOfHero(Drachir.getInventory()));
					}
					break;
				}
			}
			else sphinx.deadSphinx();
			if (Drachir.getHealth() == 0) break;
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(sphinx.moveTo());
			break;
		case 6:
			// переход в локацию волшебницы
			SetConsoleTextAttribute(hConsole, 15);
			if (witch.getAlive()) {
				witch.dialog(witch.getVisited());
				int choice;
				if (!witch.getVisited()) {
					witch.setVisited(true);
					SetConsoleTextAttribute(hConsole, 3);
					choice = witch.choice1();
				}
				else {
					SetConsoleTextAttribute(hConsole, 3);
					choice = witch.choice2();
				}
				switch (choice) {
				case 1:
					SetConsoleTextAttribute(hConsole, 15);
					if (witch.riddles()) {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setInvisibility(true);
					}
					else {
						cout << "лох" << endl;
					}
					break;
				case 2:
					int battle = witch.attack(Drachir.getStrong(), witch.getStrong());
					SetConsoleTextAttribute(hConsole, 2);
					Drachir.setHealth(Drachir.getHealth() - battle);
					if (battle == 0) {
						SetConsoleTextAttribute(hConsole, 2);
						Drachir.setReputation(Drachir.getReputation() - 5);
						witch.setAlive(false);
						Drachir.setInvisibility(true);
					}
					break;
				}
			}
			else witch.deadWitch();
			if (Drachir.getHealth() == 0) break;
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(witch.moveTo());
			break;
		case 7:
			// переход в локацию демона
			SetConsoleTextAttribute(hConsole, 15);
			if (demon.getAlive()) {
				demon.dialog(demon.getVisited());
				demon.setVisited(true);

				if (Drachir.getInvisibility()) {
					SetConsoleTextAttribute(hConsole, 3);
					cout << "Вы можете использовать магию невидимости, нажав 1, либо вступить в сражение, нажав любую другую клавишу" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					switch (_getch()) {
					case 49:
						cout << "Вы стали незаметным для врага. Куда бежать?" << endl;
						Drachir.setInvisibility(false);
						goto skip_demon;
						break;
					}
				}

				int battle = demon.attack(Drachir.getStrong(), demon.getStrong());
				SetConsoleTextAttribute(hConsole, 2);
				Drachir.setHealth(Drachir.getHealth() - battle);
				if (battle == 0) {
					demon.setAlive(false);
					SetConsoleTextAttribute(hConsole, 2);
					Drachir.addItemToInventory(demon.getLoot());
					Drachir.setStrong(powerOfHero(Drachir.getInventory()));
				}
			}
			else demon.deadDemon();
			if (Drachir.getHealth() == 0) break;
		skip_demon:
			SetConsoleTextAttribute(hConsole, 15);
			gamemap.showMap(Drachir.getLocation()); // карта
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(demon.moveTo());
			break;
		case 8:
			// переход в локацию сатаны
			SetConsoleTextAttribute(hConsole, 15);
			boss.dialog();
			SetConsoleTextAttribute(hConsole, 2);
			Drachir.setHealth(boss.attack(Drachir.getStrong(), boss.getStrong()));
			if (Drachir.getHealth() == 0) break;
			SetConsoleTextAttribute(hConsole, 3);
			Drachir.setLocation(boss.moveTo());
			break;
		case 9:
			// переход в локацию финиш
			SetConsoleTextAttribute(hConsole, 15);
			int final_rep = Drachir.getReputation();
			if (final_rep > 5) {
				finish.goodEnding();
			}
			else if (final_rep < -10) {
				finish.badEnding();
			}
			else finish.nobodyEnding();
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Вы прошли игру.\nХотите начать заново? Нажмите Enter\nХотите завершить игру? Нажмите Esc" << endl;
			while (true) {
				switch (_getch()) {
				case 13:
					goto restart;
					break;
				case 27:
					SetConsoleTextAttribute(hConsole, 15);
					exit(0);
				}
			}
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, 12);
	cout << "Увы, Драчир пал смертью храбрых.\nХотите начать заново? Нажмите Enter\nХотите завершить игру? Нажмите Esc" << endl;
	while (true) {
		switch (_getch()) {
		case 13:
			goto restart;
			break;
		case 27:
			SetConsoleTextAttribute(hConsole, 15);
			exit(0);
		}
	}
}