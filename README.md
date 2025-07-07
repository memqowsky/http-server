# HTTPServer

Prosty serwer HTTP napisany w C++ z wykorzystaniem bibliotek Boost.Asio oraz Boost.Filesystem.  
Serwer obsługuje podstawowe żądania HTTP GET i zwraca zawartość plików z lokalnego katalogu.

---

## Wymagania

- Kompilator C++ z obsługą standardu C++17 (np. g++)
- CMake (3.10 lub nowszy)
- Boost (asio, filesystem)
- System Linux/Unix lub Windows z odpowiednim środowiskiem

---

## Budowanie projektu

1. Sklonuj repozytorium:

git clone <adres_repozytorium>
cd <nazwa_folderu>


2. Utwórz katalog build i przejdź do niego:

mkdir build
cd build


3. Wygeneruj pliki makefile i zbuduj projekt:

cmake ..
make


---

## Uruchomienie serwera

Po zbudowaniu w katalogu `build` powstanie plik wykonywalny `HTTPServer`.

Uruchom serwer, podając port jako argument (np. 8080):

./HTTPServer 8080


Serwer będzie nasłuchiwał na wskazanym porcie i obsługiwał żądania HTTP GET.

---

## Jak działa serwer

- Nasłuchuje na podanym porcie TCP.
- Odbiera żądania HTTP.
- Parsuje linię żądania, rozpoznając metodę (obsługuje tylko GET).
- Pobiera plik z lokalnego systemu plików na podstawie ścieżki z żądania.
- Odczytuje plik i zwraca go w odpowiedzi HTTP z poprawnym nagłówkiem Content-Type.
- W przypadku błędów (np. plik nie istnieje) wypisuje komunikaty na konsolę.

---

## Struktura projektu

- `main.cpp` — punkt startowy aplikacji.
- `HTTPServer.hpp` / `HTTPServer.cpp` — implementacja serwera i obsługi połączeń.
- `FileHandler.hpp` / `FileHandler.cpp` — funkcje do odczytu plików i przygotowania odpowiedzi.
- `CMakeLists.txt` — konfiguracja budowania projektu.

---

## Uwagi

- Serwer jest bardzo prosty i nie obsługuje wielu funkcji HTTP (np. innych metod, nagłówków, wielowątkowości).
- Można go rozbudować o dodatkowe funkcjonalności, takie jak obsługa błędów HTTP, cache, HTTPS itp.
- Wymaga zainstalowanego Boost i CMake.

---

## Kontakt

W razie pytań lub sugestii zapraszam do kontaktu.

