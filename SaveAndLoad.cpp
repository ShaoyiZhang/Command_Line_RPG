#include<iostream>
#include<string>
#include<istream>
#include<fstream>
#include<vector>

using namespace std;

void Save();
void Load();


string GetNextWord(string &contents, int &index) {
	int size = contents.size();
	if (index >= size) return "";
	string temp = "";
	while ((contents[index] == ' ' || contents[index] == '\n') && index < (size - 1))
		index++;
	for (; index < size; index++) {
		if (contents[index] != ' '&& contents[index] != '\n')
			temp += contents[index];
		else break;
	}
	return temp;
}

void Load() {
	std::ifstream myfile("SAVE_DATA.txt");
	string input = "";
	string temp = "";
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, temp);
			input += temp;
			input += "\n";
		}
	}

	if (input == "")
		return;

	int size = input.size(), i =0;

	string name = "", tp = "";
	int Level = 0, EXP = 0, Attack = 0, Defense = 0, Stamina = 0, Intelligence = 0, HP = 0;
	int TotalHP = 0, TotalMP = 0, MP = 0, coins = 0, holder1 = 0, holder2 = 0;
	vector<int>skills;
	vector<pair<int, int>>Bag;

		GetNextWord(input, i);
		name = GetNextWord(input, i);
		GetNextWord(input, i);
		Level = stoi(GetNextWord(input, i).c_str());
		GetNextWord(input, i);
		EXP = stoi(GetNextWord(input, i).c_str());
		GetNextWord(input, i);
		Attack = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		Defense = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		Stamina = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		Intelligence = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		HP = stoi(GetNextWord(input, i).c_str());
		GetNextWord(input, i);
		TotalHP = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		MP = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		TotalMP = stoi(GetNextWord(input, i).c_str());;
		GetNextWord(input, i);
		coins = stoi(GetNextWord(input, i).c_str());
		GetNextWord(input, i);

		while (i<size) {
			tp = GetNextWord(input, i);
			if (tp == "Bag:")
				break;
			skills.push_back(stoi(tp.c_str()));
		}

		while (i<(size-1)) {
			tp = GetNextWord(input, i);
			int j = 1;
			holder1 = 0; 
			holder2 = 0;
			while (j < tp.size()) {
				if (tp[j] == ',')
					break;
				holder1 = holder1 * 10 + (tp[j] - '0');
				j++;
			}
			j++;
			while (j < tp.size()) {
				if (tp[j] == '>')
					break;
				holder2 = holder2 * 10 + (tp[j] - '0');
				j++;
			}
			Bag.push_back(pair<int,int>(holder1, holder2));

		}
		Bag.pop_back();

		cout << "name = " << name<<endl;
		cout << "level = " << Level << endl;
		cout << "EXP = " << EXP << endl;
		cout << "ATTACK = " << Attack << endl;
		cout << "coins = " << coins << endl;
		for (int i : skills)
			cout << i;
		cout << endl;
		for (pair<int, int> p : Bag)
			cout << p.first<<" "<<p.second<<endl;
		cout << endl;


	

}


int main() {
	Load();
}