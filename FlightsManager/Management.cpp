#include "Management.h"

Management::Management(){}

bool Management::ManagementManage(std::string configP)
{

	/* TODO LIST */

	/* ZROBIONE
	* -diagram, sprawozdanie
	* -Przetestowa� program
	* -poprawki
	* -Implementacja listy dwukierunkowej z tamplate (flight)
	* -Sprawdzi� wycieki pami�ci
	* -Podzieli� metody
	* -Doda� walidacje wyboru
	* 
	* -Dopisa� metody dla Usera
	* -Dopisa� wyswietlanie biletu
	* -Dopisa� zapis biletu do pliku
	* 
	* -Uzupe�ni� metody walidacji
	* -Dopracowanie architektury programu
	* -Validation popraw na ify
	* -Load wyj�tki przy otwieraniu
	* -Udoskonali� Load
	* -Konstruktory/Destruktory
	* -Posprz�ta� includy
	* -Dopisa� kody b��d�w
	*/

	/*Stworzenie kontrolera do sterowania procesem*/

	/*Stworzenie modelu przechowuj�cego dane*/
	std::unique_ptr<Model> model = std::make_unique<Model>();

	/*Wczytanie danych z pliku konfiguracyjnego*/
	model->config = std::make_unique<Config>();
	LoadYaml::LoadYamlConfig(model.get()->config.get(), configP);

	/*Wczytanie lot�w*/
	model->flights = new List<std::shared_ptr<Flight>>();
	LoadJson::LoadJsonFlights(model.get()->flights, model.get()->config->input);

	
	/*Pozyskanie danych od u�ytkownika*/
	model->booking = std::make_unique<Booking>();
	User::UserGetData(model.get()->booking.get(), model.get()->flights);


	/*Wykonanie g��wnego algorytmu*/
	Algorithm::AlgorithmMake(&(model.get()->link), model.get()->booking.get(), model.get()->flights);

	/*Posortowanie wynik�w algorytmu*/
	Algorithm::AlgorithmSortData(&(model.get()->link), model.get()->booking.get(), model.get()->flights);


	/*Przedstawienie wyniku u�ytkownikowi i ostateczny wyb�r z propozycji*/
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
