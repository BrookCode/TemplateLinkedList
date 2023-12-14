/*

3/7/2023
Assignment 6

This program uses linked list methods. It is tested using a composer class.
Reading from a file, we fill our linked list with Composer objects.
The user can test it by using search, remove, display

Everything is in templates - you can test it by filling the Linked List with
other data types

Note: Function comments provided before definitions
*/

#include <iostream>
#include <string>
#include <fstream>

#include "LinkedList.h"
#include "Composer.h"
using namespace std;

int numberOfLines(ifstream&);
char promptResponse();

int main()
{
	LinkedList<Composer> List1;

	int count;

	string line;
	string name;
	int date;

	ifstream inFile;
	
	inFile.open("composers.txt");

	if (!inFile)
		cout << "File cannot be opened\n";

	else
	{
		count = numberOfLines(inFile);

		inFile.clear();
		inFile.seekg(0);

		for (int i = 0; i < count; i++)
		{
			getline(inFile, line, ',');
			name = line;

			getline(inFile, line);
			date = stoi(line);

			List1.insert(Composer(name, date));
		}
		
		char response;

		do
		{
			response = promptResponse();

			switch (response)
			{
			case 's':

				cout << "Enter a composer's name to search for: ";
				getline(cin, name);

				if (List1.find(Composer(name)))
					cout << "\n\t" << name << " was found in the list\n\n";
				else
					cout << "\n\t" << name << " was not found in the list\n\n";
				break;

			case 'r':
				cout << "Enter a composer's name to remove: ";
				getline(cin, name);

				if (List1.remove(Composer(name)))
					cout << "\n\t" << name 
						 << " was successfully removed from the list\n\n";
				else
					cout << "\n\t" << name << " was not found in the list\n\n";
				break;

			case 'd':
				cout << "\n";
				List1.printList();
				cout << "\n";
				break;

			case 'e':
				cout << "Exiting program\n";
				break;
			}
		} while (response != 'e');
		
		inFile.close();
	}

	return 0;
}

//Takes in ifstream by reference. Returns an integer. Counts how many lines
//in a file
int numberOfLines(ifstream& inFile)
{
	string temp;
	int count = 0;

	while (getline(inFile, temp))
	{
		count++;
	}

	return count;
}

//Takes in nothing. Returns a character variable. Input validation and prompts
//user to make a choice.
char promptResponse()
{
	char ch;
	do {
		cout << "Enter 's' to search, 'r' to remove, 'd' to display," 
			 << " or 'e' to exit : ";
		cin >> ch;
		cin.ignore();
		if (ch != 's' && ch != 'r' && ch != 'd' && ch != 'e') 
		{
			cout << "Invalid input. Please try again.\n";
		}

	} while (ch != 's' && ch != 'r' && ch != 'd' && ch != 'e');

	return ch;
}

/*
Sample Run
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

Claudio Monteverdi - 1643
Henry Purcell - 1695
Antonio Vivaldi - 1741
Johann Sebastian Bach - 1750
George Frideric Handel - 1759
Wolfgang Amadeus Mozart - 1791
Joseph Haydn - 1809
Ludwig van Beethoven - 1827
Franz Schubert - 1828
Felix Mendelssohn - 1847
Frederic Chopin - 1849
Robert Schumann - 1856
Hector Berlioz - 1869
Richard Wagner - 1883
Franz Liszt - 1886
Pyotr Ilyich Tchaikovsky - 1893
Johannes Brahms - 1897
Giuseppe Verdi - 1901
Antonin Dvorak - 1904
Edvard Grieg - 1907
Gustav Mahler - 1911
Claude Debussy - 1918
Camille Saint-Saens - 1921
Giacomo Puccini - 1924
George Gershwin - 1937
Maurice Ravel - 1937
Sergei Rachmaninoff - 1943
Bela Bartok - 1945
Arnold Schoenberg - 1951
Sergei Prokofiev - 1953
Igor Stravinsky - 1971
Dmitri Shostakovich - 1975
Leonard Bernstein - 1990
Aaron Copland - 1990

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Franz Liszt

		Franz Liszt was found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: l
Invalid input. Please try again.
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Hans Max

		Hans Max was not found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: Sergei Prokofiev

		Sergei Prokofiev was successfully removed from the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: Leonardo Dicaprio

		Leonardo Dicaprio was not found in the list

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d

Claudio Monteverdi - 1643
Henry Purcell - 1695
Antonio Vivaldi - 1741
Johann Sebastian Bach - 1750
George Frideric Handel - 1759
Wolfgang Amadeus Mozart - 1791
Joseph Haydn - 1809
Ludwig van Beethoven - 1827
Franz Schubert - 1828
Felix Mendelssohn - 1847
Frederic Chopin - 1849
Robert Schumann - 1856
Hector Berlioz - 1869
Richard Wagner - 1883
Franz Liszt - 1886
Pyotr Ilyich Tchaikovsky - 1893
Johannes Brahms - 1897
Giuseppe Verdi - 1901
Antonin Dvorak - 1904
Edvard Grieg - 1907
Gustav Mahler - 1911
Claude Debussy - 1918
Camille Saint-Saens - 1921
Giacomo Puccini - 1924
George Gershwin - 1937
Maurice Ravel - 1937
Sergei Rachmaninoff - 1943
Bela Bartok - 1945
Arnold Schoenberg - 1951
Igor Stravinsky - 1971
Dmitri Shostakovich - 1975
Leonard Bernstein - 1990
Aaron Copland - 1990

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e
Exiting program

C:\Users\censor\Desktop\Code\Assignment622B\x64\Debug\Assignment622B.exe
(process 9028) exited with code 0.
Press any key to close this window . . .

*/