void questions(int num)
{
	int words = 0;
	ifstream fin;
	ofstream stuff;
	stuff.open("new_test.txt");
	fin.open("question.txt", ios::in);
	char str[20];
	char my_character,num2;

	while (!fin.eof()) {

		fin.get(my_character);
		cout << my_character;
		if (my_character == ' ') {
			words++;
			if (words == 7) {
				cin.getline(str, 20);
				fin.get(num2);
				if (num == num2) {
					stuff << str;
				}
			}
		}
		
	}
	
}
