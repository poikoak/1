#include "Word.h"
#include "Sentence.h"
#include "Text.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;



int main() {

	/*Word word("Hello big world!");
	word.Print();
	word._lenght();

	word.set("KEK");
	word.Print();
	word._lenght();
	Word word1("11111!");
	word = word1;
	word.Print();*/
	//word[0]->set("KEK");

	//Sentence sentence("Hello1 big world!");
	//sentence.Print();
	//sentence._lenght();
	//sentence._Set("1111 big1 world!");
	//sentence.Print();
	//sentence._lenght();
	//Sentence Sentence1("122222big world!");
	//sentence = Sentence1;
	//cout << endl;
	//cout << endl;
	//sentence.Print();
	////sentence[1]->Print();
	//Sentence1.Print();

    Text text("Hello new world . Masterflomaste r ! Chamba mamba ?");
	text.Print();
	text._lenght();
	text.Set("111111111111111. Master flomaster! Chamba mamba?");
	text.Print();
	text._lenght();
	Text text12("122222big world!");
	text = text12;
	cout << endl;
	cout << endl;
	text.Print();
	//cout << sentence[2];
	text.SAVE("file.txt");
	
}