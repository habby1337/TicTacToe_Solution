#include <iostream>
#include "colori.h"
#include <string>
#include <Windows.h>

using namespace std;



string square[10] = { "o","1","2","3","4","5","6","7","8","9" };

int checkwin();
void board();
void playernames();
const char esc_char = 27;


string p1, p2;
int p1w, p2w;
string p1c, p2c;


int main()
{
	SetConsoleTitle(TEXT("TIC TAC TOE | Made by @Fede.Tensi"));

	int player = 1, i, choice;

	string mark;
	string curpl, curplc;

	playernames();

	do
	{
		board();

		//player = (player % 2) ? 1 : 2;
		if (player % 2)
		{
			player = 1;
			curpl = p1;
			curplc = p1c;
		}
		else
		{
			player = 2;
			curpl = p2;
			curplc = p2c;
		}

		cout << "Giocatore " << curplc << curpl << colore::reset << ", inserire un numero:  " << curplc;
		cin >> choice;
		cout << colore::reset;

		//mark = (player == 1) ? "X" : "O";
		if (player == 1)
		{
			mark = p1c + "X" + "\033[00m";
		}
		else
		{
			mark = p2c + "O" + "\033[00m";
		}

		if (choice == 1 && square[1] == "1")

			square[1] = mark;
		else if (choice == 2 && square[2] == "2")

			square[2] = mark;
		else if (choice == 3 && square[3] == "3")

			square[3] = mark;
		else if (choice == 4 && square[4] == "4")

			square[4] = mark;
		else if (choice == 5 && square[5] == "5")

			square[5] = mark;
		else if (choice == 6 && square[6] == "6")

			square[6] = mark;
		else if (choice == 7 && square[7] == "7")

			square[7] = mark;
		else if (choice == 8 && square[8] == "8")

			square[8] = mark;
		else if (choice == 9 && square[9] == "9")

			square[9] = mark;
		else
		{
			cout << colore::red << esc_char << "[1m" << "[ERRORE]: " << colore::reset << "Mossa non valida.";

			player--;
			cin.ignore();
			cin.get();
		}
		i = checkwin();

		player++;


		board();

		if (i != -1)
		{
			if (i == 1)
			{
				cout << colore::cyan << "==>" << colore::reset << "Il giocatore " << colore::yellow << esc_char << "[1m" << curpl << colore::reset << " ha " << colore::yellow << esc_char << "[1m" << "vinto" << colore::reset << " la partita ";

				if (curpl == p1)
				{
					p1w++;
				}
				else if (curpl == p2)
				{
					p2w++;
				}
			}
			else
			{
				cout << colore::cyan << "==>" << colore::reset << "Parita'";
			}


			cin.ignore();
			cin.get();

			char a[1];
			cout << colore::cyan << esc_char << "[1m" << "[INFO]: " << colore::reset << "Vuoi continuare? (Y/n): ";
			cin >> a;
			if (a == "N" || a == "n")
			{
				break;
			}
			else
			{
				square[0] = { "o" };
				square[1] = { "1" };
				square[2] = { "2" };
				square[3] = { "3" };
				square[4] = { "4" };
				square[5] = { "5" };
				square[6] = { "6" };
				square[7] = { "7" };
				square[8] = { "8" };
				square[9] = { "9" };
			}
		}
	} while (true);


	return 0;
}


void playernames()
{
	int e, e1;

	cout << endl << endl;
	cout << colore::cyan << "                " << "Benvenuti su Tic Tac Toe " << colore::reset << endl;
	cout << "              " << "Made with " << colore::red << "love" << colore::reset << " by @Fede.Tensi." << colore::reset << endl << endl << endl;


	cout << "> Nome giocatore 1: " << colore::yellow;
	cin >> p1;
	p1[0] = toupper(p1[0]);
	for (int i = 1; i < p1.size(); i++)
	{
		p1[i] = tolower(p1[i]);
	}
	cout << colore::reset;

	cout << endl;
	cout << "Colore:" << endl;
	cout << " 1. Rosso.\n 2. Verde.\n 3. Giallo\n 4. Magenta\n 5. Ciano.\n";
	cout << "Colore: " << colore::yellow;
	cin >> e;
	cout << colore::reset << endl;
	switch (e)
	{
	case 1:
		p1c = "\033[31m";
		break;
	case 2:
		p1c = "\033[32m";
		break;
	case 3:
		p1c = "\033[33m";
		break;
	case 4:
		p1c = "\033[35m";
		break;
	case 5:
		p1c = "\033[36m";
		break;
	default:
		cout << colore::red << "[ERRORE]" << colore::reset << "Opzione non valida, impostando il colore standard!\n";
		system("pause");
		p1c = "\033[31m";
		break;
	}


	cout << "> Nome giocatore 2: " << colore::yellow;
	cin >> p2;
	p2[0] = toupper(p2[0]);
	for (int i = 1; i < p2.size(); i++)
	{
		p2[i] = tolower(p2[i]);
	}
	cout << colore::reset;

	cout << endl;
	cout << "Colore:" << endl;
	cout << " 1. Rosso.\n 2. Verde.\n 3. Giallo\n 4. Magenta\n 5. Ciano.\n";
	cout << "Colore: " << colore::yellow;
	cin >> e1;
	cout << colore::reset << endl;

	if (e1 != e)
	{
		switch (e1)
		{
		case 1:
			p2c = "\033[31m";
			break;
		case 2:
			p2c = "\033[32m";
			break;
		case 3:
			p2c = "\033[33m";
			break;
		case 4:
			p2c = "\033[35m";
			break;
		case 5:
			p2c = "\033[36m";
			break;
		default:
			cout << colore::red << "[ERRORE]" << colore::reset << "Opzione non valida, impostando il colore standard!\n";
			system("pause");
			p2c = "\033[31m";
			break;
		}
	}
	else
	{
		cout << colore::red << "[ERRORE]" << colore::reset << "Colore già utilizzato, impostando il colore standard!\n";
		system("pause");
		p2c = "\033[31m";
	}


}


/*********************************************

	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != "1" && square[2] != "2" && square[3] != "3"
		&& square[4] != "4" && square[5] != "5" && square[6] != "6"
		&& square[7] != "7" && square[8] != "8" && square[9] != "9")

		return 0;
	else
		return -1;
}


void board()
{
	system("cls");
	cout << "\n\n\t    " << colore::cyan << esc_char << "[1m" << "Tic Tac Toe" << colore::reset << "\n\n";

	cout << "          " << p1 << " (" << p1c << esc_char << "[1m" << "X" << colore::reset << ") - " << p2 << " (" << p2c << esc_char << "[1m" << "O" << colore::reset << ")" << endl;
	cout << "Vittorie: " << p1 << colore::yellow << esc_char << "[1m" << " [" << p1w << "]" << colore::reset << " - " << p2 << colore::yellow << esc_char << "[1m" " [" << p2w << "]" << colore::reset << endl << endl;
	cout << endl;

	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << colore::reset << endl;

	cout << "         " << "  " << square[1] << colore::on_grey << "  " << colore::on_white << "|" << colore::reset << "  " << square[2] << "  " << colore::on_white << "|" << colore::reset << "  " << square[3] << endl;
	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << endl;

	cout << "         " << colore::on_white << "_____|_____|_____" << colore::reset << endl;
	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << endl;

	cout << "         " << "  " << square[4] << "  " << colore::on_white << "|" << colore::reset << "  " << square[5] << "  " << colore::on_white << "|" << colore::reset << "  " << square[6] << endl;
	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << endl;

	cout << "         " << colore::on_white << "_____|_____|_____" << colore::reset << endl;
	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << endl;

	cout << "         " << "  " << square[7] << "  " << colore::on_white << "|" << colore::reset << "  " << square[8] << "  " << colore::on_white << "|" << colore::reset << "  " << square[9] << endl;

	cout << "         " << "     " << colore::on_white << "|" << colore::reset << "     " << colore::on_white << "|" << colore::reset << "     " << endl << endl;
}
