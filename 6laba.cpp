// Реализовать базовый класс (указан в варианте) 
// и унаследовать от него 2 производных класса (обозначим их D1 и D2 для простоты),
// которые будут являться "подкатегориями" базового класса. В эти дочерние классы добавить необходимые соответствующие поля и методы. 

//  От производных классов (от D1 и D2) унаследовать один общий для них производный класс (D12).
//  В производных классах D1 и D2 по-разному переопределить унаследованный метод от базового класса, а в классе D12 этот метод не переопределять. 

// Все производные классы (D1, D2, D12) добавляют по 2-3 поля и по 2-3 метода. Все возможные данные вводятся с клавиатуры с проверкой на корректность

// класс Дизайн - базовый
// класс Монитор - от дизайна
// класс системник - от дизайна
// класс Ноутбук - от монитора и системника

#include <iostream>
#include <string>
using namespace std;


class Design
{
public:
	Design(string c, string m) {
		color = c;
		material = m;
	}

	string getColor() {
		return color;
	}
	string getMaterial() {
		return material;
	}

	void show() {
		cout << "Цвет: " << color << endl;
		cout << "Материал: " << material << endl;
	}

protected:
	string color;
	string material;
};


class Monitor: virtual public Design
{
public:
	Monitor(int h, int w, string c, string m) : Design(c, m)
	{
		height = h;
		width = w;
	}

	int getHeight()
	{
		return height;
	}
	int getWidth()
	{
		return width;
	}
	void show() {
		cout << "Монитор" << endl;
		cout << "Цвет: " << color << endl;
		cout << "Материал: " << material << endl;
		cout << "Высота: " << height << endl;
		cout << "Ширина: " << width << endl;
	}

protected:
	int height;
	int width;
};

class Sistemnic : virtual public Design
{
public:
	Sistemnic(string pr, string vk, string c, string m) :Design(c, m) {
		processor = pr;
		videokarta = vk;
	}

	string GetProcessor() {
		return processor;
	}
	string GetVideokarta() {
		return videokarta;
	}

	void show() {
		cout << "Системник" << endl;
		cout << "Цвет: " << color << endl;
		cout << "Материал: " << material << endl;
		cout << "Процессор: " << processor << endl;
		cout << "Видеокарта: " << videokarta << endl;
	}

protected:
	string processor;
	string videokarta;
};

class Computer : public Monitor, public Sistemnic
{
public:
	Computer(string strana, string Name, string c, string m, string pr, string vk, int h, int w) :Monitor(h, w, c, m), Sistemnic(pr, vk, c, m), Design(c, m) {
		country = strana;
		name = Name;
	}

	string getCountry() {
		return country;
	}

	string getName() {
		return name;
	}

	void show()
	{
		cout << "Компютер" << endl;
		Design::show();
		Monitor::show();
		Sistemnic::show();
		cout << "Страна производитель: " << country << endl;
		cout << "Название модели: " << name << endl;
	}

protected:
	string country;
	string name;

};

int main() {
	setlocale(LC_ALL, "ru");
	int  h, w;
	string c, m,strana,Name;
	string pr;
	string vk;
	Design* ptr[3];
	
	cout << "1. Создать монитор" << endl;
			cout << "color: "; cin >> c;
			cout << "material: "; cin >> m;
			cout << "height: "; cin >> h;
			cout << "width: "; cin >> w;
			Monitor mon(h, w, c, m);
			
		
	cout << "2. Создать системник" << endl;
			cout << "color: "; cin >> c;
			cout << "material: "; cin >> m;
			cout << "processor "; cin >> pr;
			cout << "videokarta: "; cin >> vk;
			Sistemnic sis(pr, vk, c, m);
			
		
	cout << "3. Создать компютер" << endl;
			/*cout << "color: "; cin >> c;
			cout << "material: "; cin >> m;*/
			/*cout << "processor "; cin >> pr;
			cout << "videokarta: "; cin >> vk;
			cout << "height: "; cin >> h;
			cout << "width: "; cin >> w;*/
			cout << "country: "; cin >> strana;
			cout << "Name: "; cin >> Name;
			Computer com(strana, Name, c, m, pr, vk, h, w);

			cout << "Вывод" << endl;
			cout << "_____********************________" << endl;
			mon.show();
			cout << "______***********************_______" << endl;
			sis.show();
			cout << "_______************************______" << endl;
			Computer* pt = &com;
			pt->show();

}
