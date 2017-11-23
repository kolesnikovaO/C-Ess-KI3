#include <string>
#include <iostream>

using namespace std;

int main()
{
	string stop_words;
	getline(cin, stop_words);
	string sentence;
	getline(cin, sentence);
	
	bool wordNotEnded = true;
	int commaPrev = -1, comma = 0; //номери минулої коми та поточної коми у реченні (sentence)
	int wordInSentence = 0; //номер першого символу слова, яке шукаємо у sentence
	string stopSymbols = "";//послідовність символів між комами
	string stopWord = ""; //послідовність символів до якої доданий пробіл - тепер це точно слово в реченні

	while (wordNotEnded)
	{
		comma = stop_words.find(',', comma + 1);//шукаємо номер коми у реченні
		if (comma == string::npos) {  //якщо кома не знайдена, значить це останнє слово зі списку
			//substr(<номер минулої коми + 1, кількість символів до кінця списку>)
			stopSymbols = stop_words.substr(commaPrev + 1, stop_words.length() - commaPrev);
			wordNotEnded = false; 
		}
		//якщо кома знайдена, шукаємо слово, що знаходиться між минулою комою і щойно знайденою
		else stopSymbols = stop_words.substr(commaPrev + 1, comma - commaPrev - 1);
		//маємо знайти в sentence слово, а не просто послідовність символів, а слово обов'язково
		//оточене пробілами (з обох боків - всередині речення, тільки зліва - вкінці, тільки справа - на початку)
		//Тож додамо пробіл вкінець(цього достатньо, а якщо слово знаходиться вкінці речення - це перевіремо пізніше)
		stopWord = stopSymbols + " ";

		//шукаємо номер першого символу слова в заданому користувачем рядку (sentence)
		wordInSentence = sentence.find(stopWord);
		//якщо таке слово знайдене і wordInSentence вказує на його перший символ - стираємо його з sentence
		if (wordInSentence != string::npos)
			sentence.erase(wordInSentence, stopWord.length());
		//якщо ні - можливо справа в регістрі, змінимо першу букву шуканого слова на заголовну
		else {
			stopWord[0] = stopWord[0] - 'a' + 'A';
			wordInSentence = sentence.find(stopWord);
			//якщо таке слово знайдене і wordInSentence вказує на його перший символ - стираємо його з sentence
			if (wordInSentence != string::npos)
				sentence.erase(wordInSentence, stopWord.length());
			//якщо ні - напевно це слово знаходиться вкінці речення і знайти його заважає пробіл, що ми додали до шуканого 
			//слова трохи раніше; знову додамо пробіл, але вже перед початком слова
			else {
				stopWord = " " + stopSymbols;
				wordInSentence = sentence.find(stopWord);
				//якщо таке слово знайдене і wordInSentence вказує на його перший символ - стираємо його з sentence
				if (wordInSentence != string::npos)
					sentence.erase(wordInSentence, stopWord.length());
				//якщо ні - можливо справа в регістрі, змінимо першу букву шуканого слова на заголовну
				else {
					stopWord[0] = stopWord[0] - 'a' + 'A';
					wordInSentence = sentence.find(stopWord);
					//якщо таке слово знайдене і wordInSentence вказує на його перший символ - стираємо його з sentence
					if (wordInSentence != string::npos)
						sentence.erase(wordInSentence, stopWord.length());
				}
			}
		}
		commaPrev = comma;
	}


	cout << sentence << "\n";

	
	return 0;
}
