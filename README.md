# School Bell Replacement System

## Opis

Ten projekt jest w wersji testowej i ma na celu stworzenie nowego systemu dzwonków szkolnych, który zastąpi obecny system. Program umożliwia obserwację czasu trwania lekcji za pomocą 10 diod LED, które zmieniają się co 5 minut.

## Funkcjonalności

- **Automatyczne dzwonki szkolne**: System automatycznie sygnalizuje początek i koniec lekcji.
- **Wizualizacja czasu lekcji**: 10 diod LED reprezentuje upływ czasu lekcji, zmieniając się co 5 minut.
- **Łatwość konfiguracji**: Możliwość dostosowania czasu trwania lekcji i przerw.

## Wymagania

- **Sprzęt**:
  - Mikrokontroler (np. Arduino)
  - 10 diod LED
  - Rezystory do diod LED
  - Moduł zegara czasu rzeczywistego (RTC)
- **Oprogramowanie**:
  - Arduino IDE (lub inne środowisko programistyczne dla wybranego mikrokontrolera)

## Instalacja

1. Sklonuj repozytorium:
    ```bash
    git clone https://github.com/twoje-repozytorium/school-bell-system.git
    ```
2. Otwórz projekt w Arduino IDE.
3. Upewnij się, że masz zainstalowane wszystkie wymagane biblioteki (np. biblioteka do obsługi RTC).
4. Podłącz mikrokontroler do komputera.
5. Wgraj kod na mikrokontroler.

## Użycie

1. Uruchom system dzwonków, podłączając mikrokontroler do zasilania.
2. System automatycznie rozpocznie odliczanie czasu lekcji i sterowanie diodami LED.
3. Diody LED będą zmieniać się co 5 minut, wizualizując upływ czasu.

## Konfiguracja

Aby dostosować czas trwania lekcji i przerw, edytuj odpowiednie wartości w kodzie:

```cpp
// Przykładowa konfiguracja
const int lessonDuration = 45; // Czas trwania lekcji w minutach
const int breakDuration = 10; // Czas trwania przerwy w minutach
