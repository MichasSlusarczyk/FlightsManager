#include "Management.h"

Management::Management(){}

bool Management::ManagementManage(std::string configP)
{

	/* TODO LIST */

	/* ZROBIONE
	* -diagram, sprawozdanie
	* -Przetestowaæ program
	* -poprawki
	* -Implementacja listy dwukierunkowej z tamplate (flight)
	* -Sprawdziæ wycieki pamiêci
	* -Podzieliæ metody
	* -Dodaæ walidacje wyboru
	* 
	* -Dopisaæ metody dla Usera
	* -Dopisaæ wyswietlanie biletu
	* -Dopisaæ zapis biletu do pliku
	* 
	* -Uzupe³niæ metody walidacji
	* -Dopracowanie architektury programu
	* -Validation popraw na ify
	* -Load wyj¹tki przy otwieraniu
	* -Udoskonaliæ Load
	* -Konstruktory/Destruktory
	* -Posprz¹taæ includy
	* -Dopisaæ kody b³êdów
	*/

	/*Stworzenie kontrolera do sterowania procesem*/

	/*Stworzenie modelu przechowuj¹cego dane*/
	std::unique_ptr<Model> model = std::make_unique<Model>();

	/*Wczytanie danych z pliku konfiguracyjnego*/
	model->config = std::make_unique<Config>();
	LoadYaml::LoadYamlConfig(model.get()->config.get(), configP);

	/*Wczytanie lotów*/
	model->flights = new List<std::shared_ptr<Flight>>();
	LoadJson::LoadJsonFlights(model.get()->flights, model.get()->config->input);

	
	/*Pozyskanie danych od u¿ytkownika*/
	model->booking = std::make_unique<Booking>();
	User::UserGetData(model.get()->booking.get(), model.get()->flights);


	/*Wykonanie g³ównego algorytmu*/
	Algorithm::AlgorithmMake(&(model.get()->link), model.get()->booking.get(), model.get()->flights);

	/*Posortowanie wyników algorytmu*/
	Algorithm::AlgorithmSortData(&(model.get()->link), model.get()->booking.get(), model.get()->flights);


	/*Przedstawienie wyniku u¿ytkownikowi i ostateczny wybór z propozycji*/
	model->ticket = std::make_unique<Ticket>();
	User::UserFlightChoice(model.get()->booking.get() , &(model.get()->link), model.get()->flights, model.get()->ticket.get(), model.get()->config->currency);

	/*Wyswietlenie biletu*/
	User::UserPrintTicket(model.get()->ticket.get(), model.get()->config->currency);

	/*Zapis biletu do pliku*/
	Save::SaveTicket(model.get()->ticket.get(), model.get()->config->output, model.get()->config->currency);

	/*Zakonczenie programu*/
	User::UserEndProgram();
	
	model->flights->Erase();
	delete model->flights;

    return true;
}
