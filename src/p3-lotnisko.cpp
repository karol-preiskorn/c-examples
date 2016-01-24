/**
 1. Zaprojektować zestaw trzech klas będących obiektowym odwzorowaniem  , z których jedna będzie klasą główną, reprezentującą cały obiekt i będzie zawierać dwa
 obiekty pozostałych klas (podobiekty; w tym jeden automatyczny i jeden dynamiczny). Podobiekt
 dynamiczny oznacza, że polem obiektu głównego jest wskaźnik na podobiekt (do celów tego projektu w konstruktorze domyślnym ma być inicjowany na zero). Odwzorowanie
 powinno być możliwie realistyczne - dla skomplikowanych obiektów odpowiednio uproszczone. Zaprojektowane klasy będą wykorzystywane w następnym projekcie –
 ewentualnie będą modyfikowane.
 2. Model rozwiązania należy przedstawić prowadzącemu na zajęciach kolejnych (tydzień po otrzymaniu treści projektu). Model powinien określać:
 • nazwy klasy głównej oraz klas reprezentujących podobiekty: dynamiczny oraz automatyczny,
 • przykładowe pola oraz metody dla klas.
 3. We wszystkich konstruktorach i destruktorach wstawić kod drukujący na ekran informację o wywołaniu (warunkowo, pod zmienną kompilacji TESTPR). Wydruki te będą pomocne w czasie śledzenia sekwencji wywołania konstruktorów i destruktorów.
 4. Klasa główna ma zawierać mechanizm określania liczby stworzonych obiektów tego typu
 (statyczne pole klasy), oraz statyczną metodę zwracającą to statyczne pole klasy (chodzi o możliwość uzyskania informacji o braku instancji klasy).
 5. Każda klasa powinna prawidłowo zachowywać się w przypadku kopiowania – realizacja konstruktora kopiującego.
 6. Zaprojektować i zaimplementować dla klas kilka sensownych, różnorodnych operatorów, w tym: jeden jednoargumentowy, jeden dwuargumentowy oraz operator przypisania.
 Zastosować wybrane operatory jako metody klas oraz jako funkcje zaprzyjaźnione z klasami.
 7. Jeżeli jest wybór pomiędzy stosowaniem mechanizmów, funkcji, instrukcji typowych dla
 języka C i C++ proszę stosować odpowiednie konstrukcje właściwe dla C++ np. char* -> string, FILE* -> iostream, ablica w stylu C –> std::vector itp.
 8. Napisać program główny testujący klasę główną i jej podklasy (oddzielny moduł/plik). Dla testów stworzyć obiekty automatyczne, dynamiczne i statyczne (lokalne, globalne) w
 funkcji main i innej funkcji testowej (w trakcie testu powinno powstać co najmniej kilkanaście obiektów). Celem powyższych testów jest między innymi obserwowanie czasu
 życia obiektów oraz zachowanie się funkcji i operatorów przeciążonych. Fragment programu powinien testować kopiowanie obiektów. Program testowy powinien być
 nieinterakcyjny (statyczny) z odpowiednią liczbą wydruków objaśniających, co zaszło w czasie działania programu.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 *
 */
class samolot {
private:
	// cechy samolotu techniczne
	string nazwa;
	int max_liczba_pasazerow; // maxymalna liczba pasażerów
	int liczba_pasazerow; // liczba pasażerów w samolocie
	int waga;
	int dlugosc;
	int paliwo;
	int nr_samolotu;

public:
	static int counter;
	samolot() {
		std::cout << "Konstruktor samolot called" << endl;
		max_liczba_pasazerow = 100;
		nazwa = "Samolot";
		this->dlugosc = 100;
		this->paliwo = 0;
		this->waga = 10;
		this->liczba_pasazerow = 5;
		this->nr_samolotu = samolot::counter++;

	}

	/**
	 * destruktor
	 */
	~samolot() {
		std::cout << "Destruktor samolot called" << endl;

	}

	void print() {
		std::cout << "Samolot " << this->nazwa << ", numer [" << this->nr_samolotu << "], liczba_pasazerow " << this->liczba_pasazerow << endl;
		std::cout << "   pasazerow " << this->liczba_pasazerow << "osob " << endl;
		std::cout << "   waga      " << this->waga << "kg" << endl;
		std::cout << "   paliwo    " << this->paliwo << "ton" << endl;
		std::cout << "   dlugosc   " << this->dlugosc << "m" << endl;
	}

	bool startuj();
	bool laduj();
	int zatankuj(int p_ilosc) {
		paliwo += p_ilosc;
		return (paliwo);
	}
	bool przyjmij_pasazerow();

	int getDlugosc() const {
		return (dlugosc);
	}

	void setDlugosc(int dlugosc) {
		this->dlugosc = dlugosc;
	}

	int getLiczbaPasazerow() const {
		return liczba_pasazerow;
	}

	void setLiczbaPasazerow(int liczbaPasazerow) {
		liczba_pasazerow = liczbaPasazerow;
	}

	int getMaxLiczbaPasazerow() const {
		return max_liczba_pasazerow;
	}

	void setMaxLiczbaPasazerow(int maxLiczbaPasazerow) {
		max_liczba_pasazerow = maxLiczbaPasazerow;
	}

	const string& getNazwa() const {
		return nazwa;
	}

	void setNazwa(const string& nazwa) {
		this->nazwa = nazwa;
	}

	int getWaga() const {
		return waga;
	}

	void setWaga(int waga) {
		this->waga = waga;
	}

	int getPaliwo() const {
		return paliwo;
	}

	void setPaliwo(int paliwo) {
		this->paliwo = paliwo;
	}
};

/**
 *
 */
class awionetka: public samolot {
public:
	awionetka() {
		samolot::setNazwa("Awionetka typu 1");
		samolot::setMaxLiczbaPasazerow(10);
		samolot::setLiczbaPasazerow(5);
		samolot::zatankuj(1000);
	}
};

/**
 *
 *
 */
class jumbojet: public samolot {
public:
	jumbojet() {
		samolot::setNazwa("JumboJet");
		samolot::setMaxLiczbaPasazerow(1000);
		samolot::setLiczbaPasazerow(5);
	}

};

/**
 *
 */
class lotnisko {
private:
	static const int max_airplain = 500;
	static const int max_passengers = 10000;
	static int ilosc_lotnisk;
	int airplains;
	int passengers;
	static int count_airplain;
	bool TESTPR;
	static int counter;
	string nazwa;
	samolot *samolot_prt;
public:
	/**
	 * Podobiekt dynamiczny oznacza, że polem obiektu głównego jest wskaźnik na podobiekt (do celów tego projektu w konstruktorze domyślnym ma być inicjowany na zero).
	 * Odwzorowanie powinno być możliwie realistyczne - dla skomplikowanych obiektów odpowiednio uproszczone. Zaprojektowane klasy będą wykorzystywane w następnym projekcie –
	 * ewentualnie będą modyfikowane.
	 */

	samolot *setSamolotPtr(samolot * p_ptr) {
		this->samolot_prt = p_ptr;
		return (this->samolot_prt);
	}

	bool getTestpr() {
		return (TESTPR);
	}

	void setTestpr(bool testpr = true) {
		TESTPR = testpr;
	}

	bool addNewPassenger(int p_passengers) {
		if (passengers += p_passengers <= max_passengers) {
			passengers += p_passengers;
			return (true);
		} else {
			return (false);
		}
	}

	/**
	 *
	 */
	lotnisko() {
		setTestpr(true);

		if (getTestpr() == true) {
			std::cout << "Konstruktor lotnisko called" << endl;
		}
		lotnisko::counter++;
	}

	/**
	 *
	 *
	 */
	~lotnisko() {
		if (getTestpr() == true) {
			std::cout << "Destruktor lotnisko called" << endl;
			//lotnisko::counter++;
		}

	}

	int getCounter() {
		return ((int) lotnisko::counter);
	}

	void setCounter(int p_counter) {
		counter = p_counter;
	}

	void printCounter() {
		std::cout << "Lotnisko licznik samolotów na lotnisku " << getNazwa() << " " << getCounter() << endl;
	}

	const string& getNazwa() {
		return nazwa;
	}

	void setNazwa(const string& nazwa) {
		this->nazwa = nazwa;
	}

	int getPassengers() const {
		return passengers;
	}

	void setPassengers(int passengers) {
		this->passengers = passengers;
	}

	samolot* getSamolotPrt() {
		return samolot_prt;
	}

	void setSamolotPrt(samolot* samolotPrt) {
		samolot_prt = samolotPrt;
	}
};

int ile_obiektow = 3;
int lotnisko::counter = 0;
int samolot::counter = 0;

/**
 * main function
 *
 * @todo test units
 * @todo list of samolot
 *
 * @return
 */
int main() {
	lotnisko okecie;
	okecie.setNazwa("Okęcie");
	okecie.setTestpr(true);
	okecie.setCounter(2);
	okecie.printCounter();

	awionetka a1;
	a1.print();

	jumbojet j1;
	j1.setNazwa("Jakiś")
	j1.print();

	j1.zatankuj(200);
	j1.setLiczbaPasazerow(24);
	j1.print();

	okecie.printCounter();

	return (0);
}

