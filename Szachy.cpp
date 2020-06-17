#include <windows.h>
#include <stdlib.h>
#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<cstdlib>

/*
Maciej Nalewajka
Informatyka Stosowana
2019
*/

using namespace std;
HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );

string szachownica[10][10] = { // Szachownica
	{"  ", "A ", "B ", "C ", "D ", "E ", "F ", "G ", "H ", "  "},
	{"1 ", "W1", "S1", "G1", "H1", "K1", "G2", "S2", "W2", " 1"},
	{"2 ", "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", " 2"},
	{"3 ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " 3"},
	{"4 ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " 4"},
	{"5 ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " 5"},
	{"6 ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", " 6"},
	{"7 ", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", " 7"},
	{"8 ", "w1", "s1", "g1", "h1", "k1", "g2", "s2", "w2", " 8"},
	{"  ", "A ", "B ", "C ", "D ", "E ", "F ", "G ", "H ", "  "},
	};
string staraSzachownica[10][10] = szachownica;

przepisz (){ // Nadpisuje szachownice
	for(int i = 1; i<9; i++){
		for(int j = 1; j<9; j++){
			staraSzachownica[i][j] = szachownica[i][j];
		}
	}
}

int zmien(char k){ // Zmienia litere na cyfre
	if(k == 'a' or k == 'A'){
		return 1;
	}
	if(k == 'b' or k == 'B'){
		return 2;
	}
	if(k == 'c' or k == 'C'){
		return 3;
	}
	if(k == 'd' or k == 'D'){
		return 4;
	}
	if(k == 'e' or k == 'E'){
		return 5;
	}
	if(k == 'f' or k == 'F'){
		return 6;
	}
	if(k == 'g' or k == 'G'){
		return 7;
	}
	if(k == 'h' or k == 'H'){
		return 8;
	}
}

bool sprawdzSzachownice(){ // Sprawdza czy nast�pi�a zmiana w szachownicy
	for(int i = 1; i<9; i++){
		for(int j = 1; j<9; j++){
			if(staraSzachownica[i][j] != szachownica[i][j]){
				return false;
			}
		}
	}
	return true;
}

string znajdz(string f){ // Znajduje figure na szachownicy
	string p = "";
	for(int i = 1; i<9; i++){
		for(int j = 1; j<9; j++){
			if(f == szachownica[i][j]){
				stringstream c1, c2;
				c1 << i;
				c2 << j;
				p += c1.str();
				p += c2.str();
				return p;
			}
		}
	}
}

bool sprawdz(string r, int a){ // Sprawdza czy wprowadzone 4 znaki ruchu s� prawid�owe
	bool ret = false;
	if(r.size() != 4) return ret;
	char tab[] = {'W', 'S', 'G', 'H', 'K', 'P'};
	char tab2[] = {'w', 's', 'g', 'h', 'k', 'p'};
	char tab3[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	char tab4[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	char b;
	if(a == 1){ // a == 1 -> ma�e litery atakuj�
		for(int i = 0; i<6; i++){
			ret = false;
			if(r[0] ==tab[i]){
				b = tab[i];
				ret = true;
				break;
			}
		}
	}
	else{
		for(int i = 0; i<6; i++){
			ret = false;
			if(r[0] ==tab2[i]){
				b = tab2[i];
				ret = true;
				break;
			}
		}
	}
	if(b == 'p' or b == 'P'){
		for(int i = 0; i<8; i++){
			ret = false;
			if(r[1] == tab4[i]){
				ret = true;
				break;
			}
		}
	}
	if(b == 'h' or b == 'H' or b == 'k' or b == 'K'){
		ret = false;
		if(r[1] == 1) ret = true;
	}
	if(b == 'g' or b == 'G' or b == 's' or b == 'S' or b == 'w' or b == 'W'){
		ret = false;
		if(r[1] == 1 or r[1]) ret = true;
	}

	for(int i = 0; i<16; i++){
		ret = false;
		if(r[2] ==tab3[i]){
			ret = true;
			break;
		}
	}
	for(int i = 0; i<8; i++){
		ret = false;
		if(r[3] == tab4[i]){
			ret = true;
			break;
		}
	}
	return ret;
}

wyswietl(string szachownica[10][10]){ // Wy�wietla kolorow� szachownice

	for(int i=0;i<10; i++){
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
		cout << "  ";
		for(int j=0;j<10;j++){
			if((i==0) || (i==9) || (j==0) || (j==9)){
				SetConsoleTextAttribute( hOut, BACKGROUND_RED | BACKGROUND_INTENSITY );
			}
			else{
				if(i%2==1 && j%2 == 1){
					SetConsoleTextAttribute( hOut, BACKGROUND_BLUE );}
				if(i%2==1 && j%2 == 0){
					SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
				}
				if(i%2==0 && j%2 == 1){
					SetConsoleTextAttribute( hOut, BACKGROUND_GREEN );
				}
				if(i%2==0 && j%2 == 0){
					SetConsoleTextAttribute( hOut, BACKGROUND_BLUE );
				}
			}
			cout << szachownica[i][j];
		}
		cout << "\n";
	}
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	cout << endl << endl;
}

string start(){  // Pocz�tkowy opis gry
	string ret = "";
	ret += "Witaj! Oto gra szachy.\n";
	ret+= "Oznaczenie figur:\n";
	ret += "Kr�l -> k1, K1\nHetman -> h1, H1\n";
	ret += "Wie�a -> w1, w2, W1, W2\n";
	ret += "Goniec -> g1, g2, G1, G2\n";
	ret += "Skoczek -> s1, s2, S1, S2\n";
	ret += "Pionek -> p1, p2, p3, p4, p5, p6, p7, p8\n";
	ret += "Pionek -> P1, P2, P3, P4, P5, P6, P7, P8\n";
	ret += "Ruchy odbywaj� si� po wprowadzeniu figury oraz\nmiejsca gdzie ma si� znale�� np.: H1B2\n";
	ret += "Gra ko�czy si� gdy kr�l zostaje zbity.\n";
	ret += "Gracz 1 -> Ma�e litery\n";
	ret += "Gracz 2 -> Du�e litery\n";
	ret += "Zaczyna Gracz 1. Powodzenia!\n\n";
	return ret;
}

int koniec(){  // Sprawdza czy kr�l �yje
	string k1 = "k1";
	string k2 = "K1";
	int ret = 0;
	for(int i = 1; i<9; i++){
		for(int j = 1; j<9; j++){
			if(k1 == szachownica[i][j]){
				ret += 1;
			}
			if(k2 == szachownica[i][j]){
				ret += 2;
			}
		}
	}
	return ret;
}

czyRuchM(string r){ // Wykonuje ruch ma�ymi literami
	char tab[] = {'W', 'S', 'G', 'H', 'P','K'};
	bool po = false;
	string gt = r;
	int num1, num2, num3, num4, r1, r2;
	string c = znajdz(gt.erase(2,2));
	num1 = (int)c[0]-48;  // Obecne po�o�enie x
	num2 = (int)c[1]-48;  // Obecne po�o�enie y
	num3 = (int)r[3]-48;  // Gdzie ma by� x
	num4 = zmien(r[2]); // Gdzie ma by� y
	if(r[0] == 'p'){
		if(num1 == 7){
			if(num3-num1 == -1 and num4 == num2 and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == -2 and szachownica[num3-1][num4] == "  " and szachownica[num3][num4] == "  " and num4 == num2){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == -1 and (num4-num2 == -1 or num4-num2 == 1)){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		else{
			if(num3-num1 == -1 and szachownica[num3][num4] == "  " and num4 == num2){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == -1 and (num4-num2 == -1 or num4-num2 == 1)){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
			}
			}
		}
	}

	if(r[0] == 'w'){
		if(num1 == num3 and num2 != num4){
			po = true;
			int u = num2;
			int y = num4;
			if(num2 < num4){
				u = num4;
				y = num2;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[num3][i] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}


		if(num1 != num3 and num2 == num4){
			po = true;
			int u = num1;
			int y = num3;
			if(num1 < num3){
				u = num3;
				y = num1;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[i][num4] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}

	if(r[0] == 's'){
		if(num3>=num1){
			r1 = num3-num1;
		}
		if(num3<num1){
			r1 = num1-num3;
		}
		if(num4>=num2){
			r2 = num4-num2;
		}
		if(num4<num2){
			r2 = num2-num4;
		}
		if((r1 == 2 and r2 == 1) or (r1 == 1 and r2 == 2)){
			if(szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			else{
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}

	if(r[0] == 'g'){
		int u = num1;
		int y = num3;
		if(num1 < num3){
			u = num3;
			y = num1;
		}
		int z = num2;
		int x = num4;
		if(num2 < num4){
			z = num4;
			x = num2;
		}
		if(num1 != num3 and num2 != num4){
			if(u-y == z-x){
				po = true;
				if(num3 > num1 and num4 > num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 > num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 > num2){
					for(int i = 1; i<u-y; i++){
						if(szachownica[num1-i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1-i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}

			}
		}
		if(po == true and szachownica[num3][num4] == "  "){
			szachownica[num1][num2] = "  ";
			szachownica[num3][num4] = gt;
		}
		if(po == true and szachownica[num3][num4] != "  "){
			string lit = szachownica[num3][num4];
			for(int i = 0; i<6; i++){
				if(lit[0] == tab[i]){
					szachownica[num1][num2] = "  ";
					szachownica[num3][num4] = gt;
				}
			}
		}
	}

	if(r[0] == 'h'){
		if(num1 == num3 and num2 != num4){
			po = true;
			int u = num2;
			int y = num4;
			if(num2 < num4){
				u = num4;
				y = num2;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[num3][i] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		if(num1 != num3 and num2 == num4){
			po = true;
			int u = num1;
			int y = num3;
			if(num1 < num3){
				u = num3;
				y = num1;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[i][num4] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		int u = num1;
		int y = num3;
		if(num1 < num3){
			u = num3;
			y = num1;
		}
		int z = num2;
		int x = num4;
		if(num2 < num4){
			z = num4;
			x = num2;
		}
		if(num1 != num3 and num2 != num4){
			if(u-y == z-x){
				po = true;
				if(num3 > num1 and num4 > num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 > num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 > num2){
					for(int i = 1; i<u-y; i++){
						if(szachownica[num1-i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1-i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}

			}
		}
		if(po == true and szachownica[num3][num4] == "  "){
			szachownica[num1][num2] = "  ";
			szachownica[num3][num4] = gt;
		}
		if(po == true and szachownica[num3][num4] != "  "){
			string lit = szachownica[num3][num4];
			for(int i = 0; i<6; i++){
				if(lit[0] == tab[i]){
					szachownica[num1][num2] = "  ";
					szachownica[num3][num4] = gt;
				}
			}
		}
	}

	if(r[0] == 'k'){
		r1 = num3-num1;
		r2 = num4-num2;
		if(r1 >= -1 and r1 <= 1 and r2 >= -1 and r2 <= 1){
			if(szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			else{
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}
}

czyRuchW(string r){ // Wykonuje ruch du�ymi literami
	char tab[] = {'w', 's', 'g', 'h', 'p','k'};
	bool po = false;
	string gt = r;
	int num1, num2, num3, num4, r1, r2;
	string c = znajdz(gt.erase(2,2));
	num1 = (int)c[0]-48;  // Obecne po�o�enie x
	num2 = (int)c[1]-48;  // Obecne po�o�enie y
	num3 = (int)r[3]-48;  // Gdzie ma by� x
	num4 = zmien(r[2]); // Gdzie ma by� y
	if(r[0] == 'P'){
		if(num1 == 2){
			if(num3-num1 == 1 and szachownica[num3][num4] == "  " and num4 == num2){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == 2 and szachownica[num3-1][num4] == "  " and szachownica[num3][num4] == "  " and num4 == num2){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == 1 and (num4-num2 == -1 or num4-num2 == 1)){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		else{
			if(num3-num1 == 1 and szachownica[num3][num4] == "  " and num4 == num2){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(num3-num1 == 1 and (num4-num2 == -1 or num4-num2 == 1)){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
			}
			}
		}
	}

	if(r[0] == 'W'){
		if(num1 == num3 and num2 != num4){
			po = true;
			int u = num2;
			int y = num4;
			if(num2 < num4){
				u = num4;
				y = num2;
			for(int i = y+1; i<u; i++){
				if(szachownica[num3][i] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}

		if(num1 != num3 and num2 == num4){
			po = true;
			int u = num1;
			int y = num3;
			if(num1 < num3){
				u = num3;
				y = num1;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[i][num4] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}

	if(r[0] == 'S'){
		if(num3>=num1){
			r1 = num3-num1;
		}
		if(num3<num1){
			r1 = num1-num3;
		}
		if(num4>=num2){
			r2 = num4-num2;
		}
		if(num4<num2){
			r2 = num2-num4;
		}
		if((r1 == 2 and r2 == 1) or (r1 == 1 and r2 == 2)){
			if(szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			else{
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}

	if(r[0] == 'G'){
		int u = num1;
		int y = num3;
		if(num1 < num3){
			u = num3;
			y = num1;
		}
		int z = num2;
		int x = num4;
		if(num2 < num4){
			z = num4;
			x = num2;
		}
		if(num1 != num3 and num2 != num4){
			if(u-y == z-x){
				po = true;
				if(num3 > num1 and num4 > num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 > num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 > num2){
					for(int i = 1; i<u-y; i++){
						if(szachownica[num1-i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1-i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}

			}
		}
		if(po == true and szachownica[num3][num4] == "  "){
			szachownica[num1][num2] = "  ";
			szachownica[num3][num4] = gt;
		}
		if(po == true and szachownica[num3][num4] != "  "){
			string lit = szachownica[num3][num4];
			for(int i = 0; i<6; i++){
				if(lit[0] == tab[i]){
					szachownica[num1][num2] = "  ";
					szachownica[num3][num4] = gt;
				}
			}
		}
	}

	if(r[0] == 'H'){
		if(num1 == num3 and num2 != num4){
			po = true;
			int u = num2;
			int y = num4;
			if(num2 < num4){
				u = num4;
				y = num2;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[num3][i] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		if(num1 != num3 and num2 == num4){
			po = true;
			int u = num1;
			int y = num3;
			if(num1 < num3){
				u = num3;
				y = num1;
			}
			for(int i = y+1; i<u; i++){
				if(szachownica[i][num4] != "  "){
					po = false;
					break;
				}
			}
			if(po == true and szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			if(po == true and szachownica[num3][num4] != "  "){
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
		int u = num1;
		int y = num3;
		if(num1 < num3){
			u = num3;
			y = num1;
		}
		int z = num2;
		int x = num4;
		if(num2 < num4){
			z = num4;
			x = num2;
		}
		if(num1 != num3 and num2 != num4){
			if(u-y == z-x){
				po = true;
				if(num3 > num1 and num4 > num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 > num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1+i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 > num2){
					for(int i = 1; i<u-y; i++){
						if(szachownica[num1-i][num2+i] != "  "){
							po = false;
							break;
						}
					}
				}
				if(num3 < num1 and num4 < num2){
					for(int i = 1; i<(u-y); i++){
						if(szachownica[num1-i][num2-i] != "  "){
							po = false;
							break;
						}
					}
				}

			}
		}
		if(po == true and szachownica[num3][num4] == "  "){
			szachownica[num1][num2] = "  ";
			szachownica[num3][num4] = gt;
		}
		if(po == true and szachownica[num3][num4] != "  "){
			string lit = szachownica[num3][num4];
			for(int i = 0; i<6; i++){
				if(lit[0] == tab[i]){
					szachownica[num1][num2] = "  ";
					szachownica[num3][num4] = gt;
				}
			}
		}
	}

	if(r[0] == 'K'){
		r1 = num3-num1;
		r2 = num4-num2;
		if(r1 >= -1 and r1 <= 1 and r2 >= -1 and r2 <= 1){
			if(szachownica[num3][num4] == "  "){
				szachownica[num1][num2] = "  ";
				szachownica[num3][num4] = gt;
			}
			else{
				string lit = szachownica[num3][num4];
				for(int i = 0; i<6; i++){
					if(lit[0] == tab[i]){
						szachownica[num1][num2] = "  ";
						szachownica[num3][num4] = gt;
					}
				}
			}
		}
	}
}

pierwszy(int kto){ // Gracz 1
	cout << "Gracz 1:\n";
	string in="";
	while(sprawdzSzachownice() == true){
		cout << "Podaj ruch: ";
		cin >> in;
		if(sprawdz(in, kto) == true){
			czyRuchM(in);
		}
	}
}

drugi(int kto){ // Gracz 2
	cout << "Gracz 2:\n";
	string in="";
	while(sprawdzSzachownice() == true){
		cout << "Podaj ruch: ";
		cin >> in;
		if(sprawdz(in, kto) == true){
			czyRuchW(in);
		}
	}
}

int random(int n){ // Random
	  int i;
	  i = rand()%8 + 1;
	  return i;
	}

komp(int kto){ // Komputer
	string tab[16] = {"W1", "W2", "S1", "S2", "G1", "G2", "K1", "H1", "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8"};
	char tab2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int tab3[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	while(sprawdzSzachownice() == true){
		string ret = "";
		ret += tab[random(15)];
		ret += tab2[random(7)];
		ret += tab3[random(7)];
		if(sprawdz(ret, kto) == true){
			czyRuchW(ret);


		}
	}
}

gra(){ // Gra z graczem
	int kto = 1;
	while(koniec() == 3){
		if(kto == 1){
			pierwszy(kto);
			przepisz();
			kto = 2;
		}
		wyswietl(szachownica);
		if(kto == 2){
			drugi(kto);
			przepisz();
			kto = 1;
		}
		wyswietl(szachownica);
	}
	if(koniec() == 1){
		cout << "\nKoniec Gry!\nGratulacje! Wygra� Gracz 1!";
	}
	if(koniec() == 2){
		cout << "\nKoniec Gry!\nGratulacje! Wygra� Gracz 2!";
	}
}

gra2(){ // Gra z komputerem
	int kto = 1;
	while(koniec() == 3){
		if(kto == 1){
			pierwszy(kto);
			przepisz();
			kto = 2;
		}
		wyswietl(szachownica);
		if(kto == 2){
			komp(kto);
			przepisz();
			kto = 1;
		}
		wyswietl(szachownica);
	}
	if(koniec() == 1){
		cout << "\nKoniec Gry!\nGratulacje! Wygra� Gracz 1!";
	}
	if(koniec() == 2){
		cout << "\nKoniec Gry!\nGratulacje! Wygra� Komputer!";
	}
}

main(){  // Main
	system("chcp 1250");
	system("CLS");

	cout << start();
	wyswietl(szachownica);

	string o = "0";
	while(o != "1" and o != "2"){
		cout << "\nKomputer -> 1\nGracz 2 -> 2\nZ kim grasz ?  ";
		cin >> o;
		cout << endl;
	}
	if(o == "1"){
		srand(time(0));
		gra2();
	}
	if(o == "2"){
		gra();
	}
}
