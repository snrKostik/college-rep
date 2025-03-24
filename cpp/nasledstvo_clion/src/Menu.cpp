#include "../head/Menu.h"

#include "../head/Apartment.h"
#include "../head/Building.h"
#include "../head/Garage.h"
#include "../head/House.h"
#include "D:/.mylibs/lifeEasier.hpp"

chr dummy;
vector<unique_ptr<Building>> buildings;
string error = Err + "Wrong Choice!" + Clr;

chr IsAfterMenuScanFailed( string character )
{
	int errCount = 0;
	scan >> character;

	// Если scan провалился или длина больше одного или ввод не равен 0 или 1
	while ( scan.fail() || character.length() > 1 )
	{
		++errCount;
		scan.clear();
		scan.ignore( scanIgnoreMax, e );
		print << Err << error << Clr;
		scan >> character;
	}
	print << Esc::upLines( errCount * 2 + 1 ) << Esc::cursorlnHome << Esc::untilEnd;
	return character[0];
}

chr IsTypeScanFailed( string character )
{
	int errCount = 0;
	scan >> character;

	// Если scan провалился или длина больше одного или ввод меньше нуля и больше 3
	const bool isType = character != "0" && character != "1" && character != "2" && character != "3";
	while ( scan.fail() || character.length() > 1 || isType )
	{
		++errCount;
		scan.clear();
		scan.ignore( scanIgnoreMax, e );
		print << Err << error << Clr;
		scan >> character;
	}
	print << Esc::upLines( errCount * 2 + 1 ) << Esc::cursorlnHome << Esc::untilEnd;
	return character[0];
}
void Menu::Print()
{
	print << Info << "\n\t  Menu\n"
				<< "1. add Element\n"
				<< "2. Delete Element (by index)\n"
				<< "3. Print all\n"
				<< "4. Compare (choose by ID)\n"
				<< "0. Exit" << Clr << e;
}

chr Menu::GetChoice()
{
	string choice = "0";
	choice = IsAfterMenuScanFailed( choice );
	switch ( choice[0] )
	{
		case '1': {
			print << "Chosen: add Element\n";
			AddElement();
			break;
		}
		case '2': {
			print << "Chosen: delete Element\n";
			DeleteByID();
			break;
		}
		case '3': {
			print << "Chosen: Print All\n";
			PrintAll();
			break;
		}
		case '4': {
			if ( buildings.size() > 0 )
			{
				print << "Chosen: Compare\n";
				print << "Enter ID of first Element: ";
				string IDerror = "Normalno vvedi ";
				int ID1 = -321;
				ID1 = Scan( ID1 );
				while ( ID1 >= buildings.size() || ID1 < 0 )
				{
					print << Err << IDerror << Clr;
					ID1 = Scan( ID1 );
				}
				print << "Enter ID of second Element: ";
				int ID2 = -653;
				ID2 = Scan( ID2 );
				while ( ID2 >= buildings.size() || ID2 < 0 )
				{
					print << Err << IDerror << Clr;
					ID2 = Scan( ID2 );
				}
				print << Esc::upLines( 3 ) << Esc::cursorlnHome << Esc::untilEnd;
				Compare( ID1, ID2 );
				break;
			}
			else
			{
				print << Err << "Sovsem kuku? " << Clr;
				break;
			}
		}
		case '0': {
			return '9';
		}
		default: {
			print << Crit << "Really?" << Clr;
			GetChoice();
		}
	}
	return '0';
}

string AddressScan()
{
	string address = "";
	int addressNumber = 0;
	print << "address (street name): ";
	address = Scan( address );
	scan.clear();
	print << "address (building number):";
	addressNumber = Scan( addressNumber );
	scan.clear();
	return address + ", " + to_string( addressNumber );
}
double SquareScan()
{
	double square = 0;
	print << "Square: ";
	square = Scan( square );

	return square;
}

string whatType = "\nWhat's the type? (Building-0, House-1, Garage-2, Apartment-3) ";

void Menu::AddElement()
{
	print << "Empty/Full ? (0/1): ";

	string isDefaultConstructor = "\0";
	isDefaultConstructor = IsAfterMenuScanFailed( isDefaultConstructor );
	scan.clear();
	scan.ignore();
	print << Esc::cursorUp << Esc::cursorlnHome << Esc::untilEnd;

	if ( isDefaultConstructor != "1" && isDefaultConstructor != "0" )
	{
		scan.clear();
		print << error;
		return;
	}

	print << Esc::cursorUp;
	print << whatType;
	string typeChoice;
	typeChoice = IsAfterMenuScanFailed( typeChoice );
	scan.clear();
	scan.ignore();
	print << Esc::cursorUp << Esc::untilEnd;

	unique_ptr<Building> building;
	switch ( typeChoice[0] )
	{
		case '0':
			if ( isDefaultConstructor == "0" )
				building = make_unique<Building>();
			else
			{
				string address = AddressScan();
				double square = SquareScan();
				building = make_unique<Building>( address, square );
			}
			break;
		case '1':
			if ( isDefaultConstructor == "0" )
				building = make_unique<House>();
			else
			{
				int apartmentAmount = 0;
				string address = AddressScan();
				double square = SquareScan();
				print << "apartment amount: ";
				apartmentAmount = Scan( apartmentAmount );
				building = make_unique<House>( address, square, apartmentAmount );
			}
			break;
		case '2':
			if ( isDefaultConstructor == "0" )
				building = make_unique<Garage>();
			else
			{
				int carAmount = 0;
				string address = AddressScan();
				double square = SquareScan();
				print << "car amount: ";
				carAmount = Scan( carAmount );
				building = make_unique<Garage>( address, square, carAmount );
			}
			break;
		case '3':
			if ( isDefaultConstructor == "0" )
				building = make_unique<Apartment>();
			else
			{
				int apartmentNumber = 0;
				string address = AddressScan();
				double square = SquareScan();
				print << "apartment number: ";
				apartmentNumber = Scan( apartmentNumber );
				building = make_unique<Apartment>( address, square, apartmentNumber );
			}
			break;
		default:
			print << Err << error << Clr;
			scan.clear();
			scan.ignore( scanIgnoreMax, e );
			return;
	}
	buildings.push_back( std::move( building ) );
}

void Menu::DeleteByID()
{
	int IDdelete = 0;
	print << "Delete element bu ID: ";IDdelete = Scan( IDdelete );

	for (int i{0}; i < buildings.size(); ++i)
	{
		if (buildings[i]->getID() == IDdelete)
		{
			buildings.erase( buildings.begin() + i );
			print << Err << "element with ID " << IDdelete << " deleted" << Clr;
			return;
		}
	}
	print << Crit << Err << "element with ID " << IDdelete << " does not exist!!!" << Clr;
}

void Menu::PrintAll()
{
	for ( int i{ 0 }; i < buildings.size(); i++ )
	{
		buildings[i]->PrintInfo();
		print << e;
		if ( buildings.size() > i + 1 ) separator( 25, verticalSep );
	}
}

void Menu::Compare( int ID1, int ID2 )
{
	if ( ID1 < 0 || ID1 >= buildings.size() || ID2 < 0 || ID2 >= buildings.size() )
	{
		print << Err << "Invalid IDs" << Clr << e;
		return;
	}

	if ( ID1 == ID2 )
	{
		print << Info << "Same object:" << Clr << e;
		buildings[ID1]->PrintInfo();
		return;
	}

	Building* building1 = buildings[ID1].get();
	Building* building2 = buildings[ID2].get();

	print << "Comparison:" << e;

	compareAttribute( "Address", building1->getAddress(), building2->getAddress() );
	compareAttribute( "Square", building1->getSquare(), building2->getSquare() );

	if ( House* house1 = dynamic_cast<House*>( building1 ) )
	{
		if ( House* house2 = dynamic_cast<House*>( building2 ) )
		{
			compareAttribute( "Apartment Amount", house1->GetApartmentAmount(), house2->GetApartmentAmount() );
		} else
		{
			print << Err << "Different types: House vs. " << building2->getType() << Clr << e;
		}
	}

	if ( Garage* garage1 = dynamic_cast<Garage*>( building1 ) )
	{
		if ( Garage* garage2 = dynamic_cast<Garage*>( building2 ) )
		{
			compareAttribute( "Car Amount", garage1->GetCarAmount(), garage2->GetCarAmount() );
		} else
		{
			print << Err << "Different types: Garage vs. " << building2->getType() << Clr << e;
		}
	}

	if ( Apartment* apartment1 = dynamic_cast<Apartment*>( building1 ) )
	{
		if ( Apartment* apartment2 = dynamic_cast<Apartment*>( building2 ) )
		{
			compareAttribute( "Apartment Number", apartment1->GetApartmentNumber(), apartment2->GetApartmentNumber() );
		} else
		{
			print << Err << "Different types: Apartment vs. " << building2->getType() << Clr << e;
		}
	}
}

void Menu::compareAttribute( const string& attributeName, const string& value1, const string& value2 )
{
	if ( value1 == value2 )
	{
		print << Success << attributeName << ":\t" << value1 << "\t" << value2 << Clr << e;
	} else
	{
		print << Err << attributeName << ":\t" << value1 << "\t" << value2 << Clr << e;
	}
}

void Menu::compareAttribute( const string& attributeName, double value1, double value2 )
{
	if ( value1 == value2 )
	{
		print << Success << attributeName << ":\t" << value1 << "\t" << value2 << Clr << e;
	} else
	{
		print << Err << attributeName << ":\t\t" << value1 << "\t" << value2 << Clr << e;
	}
}

void Menu::compareAttribute( const string& attributeName, int value1, int value2 )
{
	if ( value1 == value2 )
	{
		print << Success << attributeName << ":\t" << value1 << "\t" << value2 << Clr << e;
	} else
	{
		print << Err << attributeName << ":\t" << value1 << "\t" << value2 << Clr << e;
	}
}
