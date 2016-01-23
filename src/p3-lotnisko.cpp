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
#include <iostream>

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

public:
	bool startuj();
	bool laduj();
	bool zatankuj();
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
};

/**
 *
 */
class awionetka: public samolot {
public:
	void awionetka() {
		samolot::setNazwa("Jumbojet");
		samolot::setMaxLiczbaPasazerow(1000);
		samolot::setLiczbaPasazerow(5);
		samolot::zatankuj();
	}
};

/**
 *
 *
 */
class jumbojet: public samolot {
public:
	void jumbojet() {
		samolot::setNazwa("Jumbojet");
		samolot::setMaxLiczbaPasazerow(1000);
		samolot::setLiczbaPasazerow(5);
	}
};

/**
 *
 */
class lotnisko {
public:
	static int count_airplain = 100;
	static int max_airplain = 500;
	static int max_passengers = 10000;

	int airplains;
	int passengers;

	samolot **samolot;

	static bool TESTPR = true;

	lotnisko();
	~lotnisko();

	bool isTestpr() const {
		return TESTPR;
	}

	void setTestpr(bool testpr = true) {
		TESTPR = testpr;
	}

	bool addNewPassenger(int p_passengers) {
		if (passengers += p_passengers <= max_passengers) {
			passengers += p_passengers;
			return true;
		} else {
			return false;
		}
	}

	/**
	 *
	 */
	lotnisko::lotnisko() {
		if (TESTPR == true) {
			std::cout << "Konstruktor samolot2" << endl;
		}

		samolot = new jumbojet;
		//samolot1 = new awionetka;

	}

	/**
	 *
	 *
	 */
	lotnisko::~lotnisko() {
		if (TESTPR == true) {
			std::cout << "Destruktor samolot2" << endl;
		}

	}

}

int ile_obiektow = 3;

/**
 *
 * @return
 */
int main() {
	lotnisko okecie;
	lotnisko.TESTPR = true;

	return 0;
}
