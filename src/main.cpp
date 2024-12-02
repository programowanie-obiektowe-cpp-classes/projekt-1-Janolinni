#include <iostream>
#include <string>
#include <math.h>

class Frima
{

};

class Pracownik
{
public:
    
    std::string imie;
    
    Pracownik(const std::string& imie):imie (imie) {};
    virtual ~Pracownik() = default;
    virtual void dane_pracownika();

};

class Inz: public Pracownik
{
    std::string wydzial;
    public:
    Inz(const std::string& imie, const std::string& wydzial):Pracownik (imie), wydzial(wydzial) {}; //konstruktor inżyniera
    void dane_pracownika() override {std::cout << "Inz. " << imie << "Wydzial " << wydzial << std::endl; }; 
    };

class Mkt: public Pracownik
{
    int follows;
    public:
    Mkt(const std::string& imie, const int& follows):Pracownik (imie), follows(follows) {};
    void dane_pracownika() override {std::cout << "Mkt. " << imie << "obserwujacy: " << follows << std::endl; };
    };

class Mag: public Pracownik
{
    bool obsl_widl;
    public:
    Mag(const std::string& imie, const bool& obsl_widl):Pracownik (imie), obsl_widl(obsl_widl) {};
    void dane_pracownika() override {std::cout << "Inz. " << imie << "Obsluga wozka widlowego: " << (obsl_widl ? "tak" : "nie") << std::endl; };
    };

class Rob: public Pracownik
{
    double rozmiar_buta;
    public:
    Rob(const std::string& imie, const double& rozmiar_buta):Pracownik (imie), rozmiar_buta(rozmiar_buta) {};
    void dane_pracownika() override {std::cout << "Rob. " << imie << "Rozmiar buta: " << rozmiar_buta << std::endl; };
    };

    class Kredyt {
        int pozyczona_wartosc = 0;
        double pieniadze_do_oddania = 0;
        int ilosc_rat = 0;
        int pozostale_raty = 0;
        double oprocentowanie = 0;
        double rata_netto = 0;
        double odsetki = 0;
        double rata_brutto = 0;

        public:

        Kredyt() {};
        Kredyt (int pozyczona_wartosc, int ilosc_rat): 
        pozyczona_wartosc(pozyczona_wartosc), pieniadze_do_oddania(pozyczona_wartosc), ilosc_rat(ilosc_rat), pozostale_raty(ilosc_rat) {
            ksiegowa();
        }
        int get_pozyczona_wartosc() {
            return pozyczona_wartosc;
        }
        void ksiegowa() {
            oprocentowanie=ilosc_rat*2;
            rata_netto = pozyczona_wartosc/ilosc_rat;
            odsetki = rata_netto*oprocentowanie/100;
            rata_brutto = rata_netto+rata_brutto;
    };
    double get_rata_brutto()
    {return rata_brutto;}
    void kredyt_tracker()
    {
        if (pozostale_raty > 0) {pozostale_raty--;
        pieniadze_do_oddania-=rata_netto;}
        else {
            rata_brutto = 0;
        };
        void print_kredyty();{
        std::cout << "Pozyczona wartosc: " << pozyczona_wartosc << std::endl;
        std::cout << "Ilosc rat: " << ilosc_rat << std::endl;
        std::cout << "Rata brutto: " << rata_brutto << std::endl;
        std::cout << "Pozostalo do zaplaty: " << pieniadze_do_oddania << std::endl;
        std::cout << "Pozostalo rat: " << pozostale_raty << std::endl;
        }
    }

    class Firma { 
        int CI = 50;
        int CMkt = 100;
        int CMag = 100;
        int CR = 100;   
        int stan_konta = 75000;
        int miesiac = 0;
        int l_prac = 0;

        int l_inz = 0;
        int wynagrodzenie_inz = 10000;

        int l_mkt = 0;
        int wynagrodzenie_mkt = 7000;

        int l_mag = 0;
        int wynagrodzenie_mag = 5000;

        int l_rob = 0;
        int wynagrodzenie_rob = 6000;

        int cena_produktu = 0;
        int popyt = 0;
        int teoretyczna_produkcja = 0;
        int produkcja = 0;
        int pojemnosc_magazynu = 0;
        int sprzedaze = 0;
        int przychod = 0;

        int wynagrodzenie_total = 0;    //początkowe wartości

        Pracownik* pracownicy[100]; //limit pracowników
        Kredyt* kredyty[5]; //limit kredytów
        int l_kredytow = 0;
        double suma_rat = 0; 

        public:
        Firma() {
        for (int i = 0; i < 100; i++) {
            pracownicy[i] = nullptr;
        }
        for (int i = 0; i < 5; i++) {
            kredyty[i] = nullptr;
        }
        zatrudnij_pracownika(new Inz("Jan", "mechaniczny"));
        zatrudnij_pracownika(new Mkt("Jan", 232));
        zatrudnij_pracownika(new Mag("Jan", true));
        zatrudnij_pracownika(new Rob("Jan", 45.0));
    }

    void zatrudnij_pracownika(Pracownik* nowy_pracownik) {
        pracownicy[l_prac] = nowy_pracownik;
        l_prac++;

        if (dynamic_cast<Inz*>(nowy_pracownik)) l_inz++;
        else if (dynamic_cast<Mkt*>(nowy_pracownik)) l_mkt++;
        else if (dynamic_cast<Mag*>(nowy_pracownik)) l_mag++;
        else if (dynamic_cast<Rob*>(nowy_pracownik)) l_rob++;
    }

    void wez_kredyt(Kredyt* nowy_kredyt) {
        if (l_kredytow < 5) {
            kredyty[l_kredytow] = nowy_kredyt;
            l_kredytow++;
            stan_konta += nowy_kredyt->get_pozyczona_wartosc();
        }
        else {
            std::cout << "Osiagnieto limit kredytow." << std::endl;
        }
    }

    void sumowanie_rat() {
        double wartosc_sumy_rat = 0;
        for (int i=0; i<l_kredytow; i++) {
            wartosc_sumy_rat += kredyty[i]->get_rata_brutto();
            suma_rat = wartosc_sumy_rat;
        }
    }

    void lista_pracownikow() {
        for (int i=0; i<l_prac; i++) {
            pracownicy[i]->dane_pracownika();
        }
    }

    void wyswietl_liczbe_pracownikow_wszystkich_typow() {
        std::cout << std::endl;
        std::cout << "liczba inzynierow: " << l_inz << std::endl;
        std::cout << "liczba magazynierow: " << l_mag << std::endl;
        std::cout << "liczba marketerow: " << l_mkt << std::endl;
        std::cout << "liczba robotnikow: " << l_rob << std::endl;
    }

    void kalkulator_przychodu() {
        cena_produktu = l_inz * CI;
        popyt = l_mkt * CMkt;
        pojemnosc_magazynu = l_mag * CMag;
        teoretyczna_produkcja = l_rob * CR;
        produkcja = std::min(teoretyczna_produkcja, pojemnosc_magazynu);
        sprzedaze = std::min(produkcja, popyt);
        cena_produktu = l_inz * CI;
        przychod = sprzedaze * cena_produktu;
    }

    void wynagrodzenie_pracownikow() {
        double wydatki_inz = l_inz * wynagrodzenie_inz;
         double wydatki_mark = l_mkt * wynagrodzenie_mkt;
        double wydatki_mag = l_mag * wynagrodzenie_mag;
        double wydatki_rob = l_rob * wynagrodzenie_rob;
        wynagrodzenie_total = wydatki_inz + wydatki_mag + wydatki_mark + wydatki_rob;
    }

    // funkcja wyswietlajaca info o produkcji
    void wyswietl_dane_produkcji() {
        std::cout << std::endl << "Szczegolowe dane o produkcji: " << std::endl;
        std::cout << "Popyt: " << popyt << std::endl;
        std::cout << "Produkcja: " << produkcja << std::endl;
        std::cout << "Limit produkcji: " << teoretyczna_produkcja << std::endl;
        std::cout << "Pojemnosc magazynu: " << pojemnosc_magazynu << std::endl;
        std::cout << "Cena produktu: " << cena_produktu << std::endl;
        std::cout << "Liczba sprzedanych produktow: " << sprzedaze << std::endl;
        std::cout << "Miesieczny przychod ze sprzedazy: " << przychod << std::endl;
        std::cout << "Wydatek na pensje pracownikow: " << wynagrodzenie_total << std::endl;
        std::cout << "Wydatek na splate kredytow: " << suma_rat << std::endl;
        std::cout << "Zysk: " << przychod - wynagrodzenie_total << std::endl;
    }

    void zaktualizuj_stan_konta() {
        stan_konta += przychod;
        stan_konta -= wynagrodzenie_total;
        stan_konta -= suma_rat;
    }

    void wyswietl_stan_konta() {
        std::cout << "Stan konta: " << stan_konta << std::endl;
    }

    double get_stan_konta() {
        return stan_konta;
    }

    void zakoncz_miesiac() {
        kalkulator_przychodu();
        wynagrodzenie_pracownikow();
        sumowanie_rat();
        zaktualizuj_stan_konta();
        miesiac++;
        std::cout << std::endl << "Podsumowanie " << miesiac << ". miesiaca:" << std::endl;
        wyswietl_stan_konta();
        wyswietl_liczbe_pracownikow_wszystkich_typow();
        wyswietl_dane_produkcji();
    }
};

class Gra {
private:
    Firma firma;
public:
    double get_stan_konta() {
        return firma.get_stan_konta();
    }
    void opcje() {
        std::cout << std::endl << "Wybierz opcje:\n";
        std::cout << "1. Lista pracownikow\n";
        std::cout << "2. Zatrudnij nowego pracownika\n";
        std::cout << "3. Wez kredyt\n";
        std::cout << "4. Zakoncz miesiac\n";
    }
    void akcja_gracza(int liczba) {
        switch (liczba) {
            case 1: {
                firma.lista_pracownikow();
                break;
            }
            case 2: {
                std::cout << "Wybierz typ pracownika do zatrudnienia:\n";
                std::cout << "1. Inzynier\n2. Marketingowiec\n3. Magazynier\n4. Robotnik\n";
                int typ;
                std::cin >> typ;

                std::string imie;
                std::cout << "Podaj imie pracownika: ";
                std::cin >> imie;

                switch (typ) {
                    case 1: {
                        std::string wydzial;
                        std::cout << "Podaj wydzial, ktory ukonczyl inzynier: ";
                        std::cin >> wydzial;
                        firma.zatrudnij_pracownika(new Inz(imie, wydzial));
                        break;
                    }
                    case 2: {
                        bool obsl_widl;
                        std::cout << "Czy ten magazynier obsluguje wozek widlowy (1 - tak, 0 - nie): ";
                        std::cin >> obsl_widl;
                        firma.zatrudnij_pracownika(new Mag(imie, obsl_widl));
                        break;
                    }
                    case 3: {
                        int obserwujacy;
                        std::cout << "Podaj liczbe obserwujacych: ";
                        std::cin >> obserwujacy;
                        firma.zatrudnij_pracownika(new Mkt(imie, obserwujacy));
                        break;
                    }
                    case 4: {
                        double rozmiarButa;
                        std::cout << "Podaj rozmiar buta: ";
                        std::cin >> rozmiarButa;
                        firma.zatrudnij_pracownika(new Rob(imie, rozmiarButa));
                        break;
                    }
                    default:
                        std::cout << "Nieprawidlowy wybor!\n";
                } 
                break;
            }
            case 3: {
                std::cout << "Podaj wartosc kredytu: ";
                double pozyczona_wartosc;
                std::cin >> pozyczona_wartosc;
                std::cout << "Podaj czas trwania kredytu (w miesiacach): ";
                int czas;
                std::cin >> czas;
                firma.wez_kredyt(new Kredyt(pozyczona_wartosc, czas));
                break;
            }
            case 4: {
                firma.zakoncz_miesiac();
                break;
            }
            default:
                break;
        }
    }
};

int main() {
    Gra gra;
    double warunek_wygranej = 750000;
    int i = 0;
    while (gra.get_stan_konta() > 0 && gra.get_stan_konta() < warunek_wygranej) {
        int wybor = 0;
        while (wybor != 4) {
            gra.opcje();
            std::cin >> wybor;
            gra.akcja_gracza(wybor);
        }
    }

    if(gra.get_stan_konta() >= warunek_wygranej) {
        std::cout << "Wygrales";
    }
    else {
        std::cout << "Zbankrutowales";
    }
    return 0;
    }};