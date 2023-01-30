#pragma once
#include "Header.h"

using namespace std;

int random_ij(int min, int max) {
	int rand_ij;
	random_device rd_i;;
	mt19937 r_i(rd_i());
	uniform_int_distribution<> dist(min, max);
	rand_ij = dist(r_i);

	return rand_ij;
}

class Map
{
private:
	vector <vector <char>> matrix;
	int i_size;
	int j_size;
	int finish;
public:
	Map(int i, int j) : i_size(i), j_size(j)
	{
		matrix.resize(i_size, std::vector<char>(j_size));
		for (int i = 0; i < i_size; i++)
		{
			for (int j = 0; j < j_size; j++)
			{
				if (i == 0 || i == i_size - 1|| j == 0 || j == j_size - 1)
				{
					matrix[i][j] = '#';
				}
				else
				{
					matrix[i][j] = '.';
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			int rand_i = random_ij(1, i_size - 2);
			int rand_j = random_ij(1, j_size - 2);
			matrix[rand_i][rand_j] = '#';
		}
	}

	void set_object(int i, int j, char object) //добавить объект
	{
		matrix[i][j] = object;
	}

	int get_i_size()
	{
		return i_size;
	}

	int get_j_size()
	{
		return j_size;
	}

	char get_object(int i, int j)
	{
		return matrix[i][j];
	}

	void print()
	{
		for (int i = 0; i < i_size; i++)
		{
			for (int j = 0; j < j_size; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	void replace(char object, char new_object) 
	{
		int flag = 0;
		for (int i = 1; i < i_size - 1; i++)
		{
			if (flag == 1) {
				break;
			}
			for (int j = 1; j < j_size - 1; j++) {
				if ((matrix[i][j] == object) && ((object == 'o') || (object == 'c'))) {
					int rand_i;
					int rand_j;
					while (true) {
						rand_i = i + random_ij(-1, 1);
						rand_j = j + random_ij(-1, 1);
						if ((rand_i > 0) && (rand_i < (i_size - 1)) && (rand_j > 0) && (rand_j < (j_size - 1)) && (matrix[rand_i][rand_j] != '#')) {
							if ((matrix[rand_i][rand_j] != '#') && ((matrix[rand_i][rand_j] != 'o') && (matrix[rand_i][rand_j] != 'c'))) {
								if (object == 'o') {
									matrix[rand_i][rand_j] = 'c';
								}
								else {
									matrix[rand_i][rand_j] = 'o';
								}
								matrix[i][j] = new_object;
								break;
							}
						}
					}
					flag = 1;
					break;
				}
				if ((matrix[i][j] == object) && (object == '@')) {
					matrix[i][j] = new_object;
					break;
				}
			}
		}
	}

	void create_monsters() {
		int rand_i = random_ij(1, i_size - 2);
		int rand_j = random_ij(1, j_size - 2);
		matrix[rand_i][rand_j] = 'o';
	}

	bool finish_game() {
		for (int i = 1; i < i_size - 1; i++) {
			for (int j = 1; j < j_size - 1; j++) {
				if ((matrix[i][j] == 'o') || (matrix[i][j] == 'c')) {
					return false;
				}
			}
		}
		return true;
	}
};