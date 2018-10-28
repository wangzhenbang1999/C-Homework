#include <iostream>
using namespace std;
class robot {
public:
	robot(float x = 0, float y = 0) :x_coord(x), y_coord(y)
	{}
	void display_position()
	{
		cout << x_coord << " " << y_coord << " ";
	}
	int left(float dist);
	int right(float dist);
	int up(float dist);
	int down(float dist);
	void return_to_base();
	int speed_left(float speed, float time);
	int speed_right(float speed, float time);
	int speed_up(float speed, float time);
	int speed_down(float speed, float time);
private:
	float x_coord, y_coord,
		f = 5.0, dist = 0.0;
};

int robot::left(float dist)
{
	float x = x_coord - dist;
	if (x < 0.1)
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			x_coord = 0.1;
			f -= (x_coord - 0.1) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			x_coord = x;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::right(float dist)
{
	float x = x_coord + dist;
	if (x > 99.9)
	{
		if ((99.9 * 2 - x_coord + y_coord) / 2000 < f)
		{
			x_coord = 99.9;
			f -= (99.9 - x_coord) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((dist * 2 + x_coord + y_coord) / 2000 < f)
		{
			x_coord = x;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::down(float dist)
{
	float y = y_coord - dist;
	if (y < 0.1)
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			y_coord = 0.1;
			f -= (y_coord - 0.1) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			y_coord = y;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::up(float dist)
{
	float y = y_coord + dist;
	if (y > 99.9)
	{
		if ((99.9 * 2 + x_coord - y_coord) / 2000 < f)
		{
			y_coord = 99.9;
			f -= (99.9 - y_coord) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((dist * 2 + x_coord + y_coord) / 2000 < f)
		{
			y_coord = y;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
void robot::return_to_base() { x_coord = 0;  y_coord = 0; }
int robot::speed_left(float speed, float time)
{
	dist = speed * time;
	float x = x_coord - dist;
	if (x < 0.1)
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			x_coord = 0.1;
			f -= (x_coord - 0.1) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			x_coord = x;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::speed_right(float speed, float time)
{
	dist = speed * time;
	float x = x_coord + dist;
	if (x > 99.9)
	{
		if ((99.9 * 2 - x_coord + y_coord) / 2000 < f)
		{
			x_coord = 99.9;
			f -= (99.9 - x_coord) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((dist * 2 + x_coord + y_coord) / 2000 < f)
		{
			x_coord = x;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::speed_down(float speed, float time)
{
	dist = speed * time;
	float y = y_coord - dist;
	if (y < 0.1)
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			y_coord = 0.1;
			f -= (y_coord - 0.1) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((x_coord + y_coord) / 2000 < f)
		{
			y_coord = y;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int robot::speed_up(float speed, float time)
{
	dist = speed * time;
	float y = y_coord + dist;
	if (y > 99.9)
	{
		if ((99.9 * 2 + x_coord - y_coord) / 2000 < f)
		{
			y_coord = 99.9;
			f -= (99.9 - y_coord) / 2000;
			return 2;
		}
		else
			return 1;
	}
	else
	{
		if ((dist * 2 + x_coord + y_coord) / 2000 < f)
		{
			y_coord = y;
			f -= dist / 2000;
			return 0;
		}
		else
			return 1;
	}
}
int main()
{
	float xCoord, yCoord, dist, speed, time;
	int result;//存储移动结果

	while (1) {
		cin >> xCoord;
		if (xCoord >= 0 && xCoord <= 99.9) { //只接收0-99.9之间的数字
			break;
		}
		cout << "-1" << endl;
	}

	while (1) {
		cin >> yCoord;
		if (yCoord >= 0 && yCoord <= 99.9) {
			break;
		}
		cout << "-1" << endl;
	}

	robot r1(xCoord, yCoord);

	cin >> dist;
	result = r1.left(dist);
	cout << result << endl;;
	r1.display_position();

	cin >> dist;
	result = r1.down(dist);
	cout << result << endl;
	r1.display_position();

	cin >> dist;
	result = r1.right(dist);
	cout << result << endl;;
	r1.display_position();

	cin >> dist;
	result = r1.up(dist);
	cout << result << endl;;
	r1.display_position();

	cin >> speed;
	cin >> time;
	result = r1.speed_right(speed, time);
	cout << result << endl;;
	r1.display_position();

	cin >> speed;
	cin >> time;
	result = r1.speed_up(speed, time);
	cout << result << endl;;
	r1.display_position();

	cin >> speed;
	cin >> time;
	result = r1.speed_left(speed, time);
	cout << result << endl;;
	r1.display_position();

	cin >> speed;
	cin >> time;
	result = r1.speed_down(speed, time);
	cout << result << endl;;
	r1.display_position();
}

