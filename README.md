# README #

* Zaprojektować zestaw trzech klas będących obiektowym odwzorowaniem  , z których jedna będzie klasą główną, reprezentującą cały obiekt i będzie zawierać dwa obiekty pozostałych klas (podobiekty; w tym jeden automatyczny i jeden dynamiczny). Podobiekt dynamiczny oznacza, że polem obiektu głównego jest wskaźnik na podobiekt (do celów tego projektu w konstruktorze domyślnym ma być inicjowany na zero). Odwzorowanie powinno być możliwie realistyczne - dla skomplikowanych obiektów odpowiednio uproszczone. Zaprojektowane klasy będą wykorzystywane w następnym projekcie – ewentualnie będą modyfikowane.
* Model rozwiązania należy przedstawić prowadzącemu na zajęciach kolejnych (tydzień po otrzymaniu treści projektu). Model powinien określać:
 • nazwy klasy głównej oraz klas reprezentujących podobiekty: dynamiczny oraz automatyczny,
 • przykładowe pola oraz metody dla klas.
* We wszystkich konstruktorach i destruktorach wstawić kod drukujący na ekran informację o wywołaniu (warunkowo, pod zmienną kompilacji TESTPR). Wydruki te będą pomocne w czasie śledzenia sekwencji wywołania konstruktorów i destruktorów.
* Klasa główna ma zawierać mechanizm określania liczby stworzonych obiektów tego typu
 (statyczne pole klasy), oraz statyczną metodę zwracającą to statyczne pole klasy (chodzi o możliwość uzyskania informacji o braku instancji klasy).
* Każda klasa powinna prawidłowo zachowywać się w przypadku kopiowania – realizacja konstruktora kopiującego.
* Zaprojektować i zaimplementować dla klas kilka sensownych, różnorodnych operatorów, w tym: jeden jednoargumentowy, jeden dwuargumentowy oraz operator przypisania.
 Zastosować wybrane operatory jako metody klas oraz jako funkcje zaprzyjaźnione z klasami.
 7. Jeżeli jest wybór pomiędzy stosowaniem mechanizmów, funkcji, instrukcji typowych dla
 języka C i C++ proszę stosować odpowiednie konstrukcje właściwe dla C++ np. char* -> string, FILE* -> iostream, ablica w stylu C –> std::vector itp.
 8. Napisać program główny testujący klasę główną i jej podklasy (oddzielny moduł/plik). Dla testów stworzyć obiekty automatyczne, dynamiczne i statyczne (lokalne, globalne) w
 funkcji main i innej funkcji testowej (w trakcie testu powinno powstać co najmniej kilkanaście obiektów). Celem powyższych testów jest między innymi obserwowanie czasu
 życia obiektów oraz zachowanie się funkcji i operatorów przeciążonych. Fragment programu powinien testować kopiowanie obiektów. Program testowy powinien być
 nieinterakcyjny (statyczny) z odpowiednią liczbą wydruków objaśniających, co zaszło w czasie działania programu.
