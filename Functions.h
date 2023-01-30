#pragma once
#include "Header.h"
#include "Map.h"

void move(Map map)
{
	int enter;
	int i;
	int j;
	int flag = 0;
	enter = 0;
	i = (map.get_i_size() / 2) - 1;
	j = (map.get_j_size() / 2) - 1;

	for (int k = 0; k < 3; k++) {
		map.create_monsters();
	}
	map.set_object(i, j, '@');
	while (enter != 30)
	{
		map.print();
		map.replace('@', '.');
		enter = _getch(); 

		switch (enter)
		{
		case 72:
			if (map.get_object(i - 1, j) != '#')
			{
				i--;
			}
			break;
		case 75:
			if (map.get_object(i, j - 1) != '#')
			{
				j--;
			}
			break;
		case 77:
			if (map.get_object(i, j + 1) != '#')
			{
				j++;
			}
			break;
		case 80:
			if (map.get_object(i + 1, j) != '#')
			{
				i++;
			}
		default:
			break;
		}

		if (enter != 224) {
			if (flag == 0) {
				for (int k = 0; k < 3; k++) {
					map.replace('o', '.');
				}
				flag = 1;
			}
			else {
				for (int k = 0; k < 3; k++) {
					map.replace('c', '.');
				}
				flag = 0;
			}
		}
		map.set_object(i, j, '@');
		CLS;
		if (map.finish_game()) {
			break;
		}
	}
	map.print();
	cout << "You win!!!" << endl;
}
void start()
{
	Map small_map(10, 10);
	move(small_map);

}