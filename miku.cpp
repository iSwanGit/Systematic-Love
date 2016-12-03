#include <iostream>
#include <cmath>
using namespace std;

const int HEART_SIZE = 20;
const int HALF_SIZE = HEART_SIZE / 2;

bool is_in_love(int x, int y);

int main() {

	string message = " SYSTEMATIC  LOVE ";
	int message_indent = (HALF_SIZE - (message.length() / 4)) - 1;

	for (int y = 0; y < HEART_SIZE; ++y) {
		for (int x = 0; x < HEART_SIZE; ++x) {
			cout << ((is_in_love(x, y)) ? "vv" : "  ");

			if (y== HALF_SIZE-1) {
				if (x == message_indent) {
					cout << message.c_str();
					x += (message.length() / 2);
				}
			}
		}
		cout << endl;
	}

	return 0;
}

bool is_in_love(int x, int y) {
	const float width = 2.2f;
	const float height = 3.0f;
	const float HEART_COEFFICIENT = 0.7f;

	float check_x = ((static_cast<float>(x) / static_cast<float>(HEART_SIZE)) - 0.5f) * width;
	float check_y = ((static_cast<float>(HEART_SIZE - y) / static_cast<float>(HEART_SIZE)) - 0.4f) * height;

	float top_y = 0.0f;
	float bottom_y = 0.0f;

	if (check_x >= 0) {
		top_y = sqrt(1 - (check_x * check_x)) + (HEART_COEFFICIENT * sqrt(check_x));
		bottom_y = -sqrt(1 - (check_x * check_x)) + (HEART_COEFFICIENT* sqrt(check_x));
	}
	else {
		top_y = sqrt(1 - (check_x * check_x)) + (HEART_COEFFICIENT * sqrt(-check_x));
		bottom_y = -sqrt(1 - (check_x * check_x)) + (HEART_COEFFICIENT * sqrt(-check_x));
	}

	if ((bottom_y <= check_y) && (check_y <= top_y)) {
		return true;
	}
	else return false;
}