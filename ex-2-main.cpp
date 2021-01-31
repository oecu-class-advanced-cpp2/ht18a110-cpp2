#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi
		�w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
		�ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B

		1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
		�������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e����܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int digit = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					digit = *pos - '0';
				}
				else {
					auto u = unit(*pos);
					value_ += std::max(digit, 1) * u;
					digit = 0;
				}
			}
		}

		/* ----------------------------------------------------------------- */
		/*
		operator+
		2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			mcxi dest(*this);
			dest.value_ += rhs.value_;
			return dest;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string
		���݂̒l�� mcxi �L�@�ɕϊ����܂��B
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::stringstream ss;
			int moji = value_;
			int m, c, x, i = 0;

			// m�̕ϊ� ------------------------------------------------------
			m = moji / 1000;
			if (m == 1) {
				ss << 'm';
			}
			else if (m > 1) {
				ss << m;
				ss << 'm';
			}

			// c�̕ϊ� ------------------------------------------------------
			c = moji % 1000;
			c = c / 100;
			if (c == 1) {
				ss << 'c';
			}
			else if (c > 1) {
				ss << c;
				ss << 'c';
			}

			// x�̕ϊ� ------------------------------------------------------
			x = moji % 100;
			x = x / 10;
			if (x == 1) {
				ss << 'x';
			}
			else if (x > 1) {
				ss << x;
				ss << 'x';
			}

			// i�̕ϊ� ------------------------------------------------------
			i = moji % 10;
			if (i == 1) {
				ss << 'i';
			}
			else if (i > 1) {
				ss << i;
				ss << 'i';
			}

			return ss.str();
		}
	private:
		/* ----------------------------------------------------------------- */
		/*
		unit
		�P�ʂɑΉ�����l���擾���܂��B
		*/
		/* ----------------------------------------------------------------- */
		int unit(char c) {
			switch (c) {
			case 'm': return 1000;
			case 'c': return 100;
			case 'x': return 10;
			case 'i': return 1;
			default:
				break;
			}
			return 0;
		}

	private:
		int value_;
	};
}

// �����̏o�͌��ʂƐ����Ƃ̔�r���s���֐�
void hikaku(std::string ans, int num) {

	// �����̒l���i�[����z��
	std::string answer[10] = { "3x","x","6cx","5m9c9x9i","m","9m9c9x9i","mi","mi","mx","9m9c9x9i" };

	if (ans == answer[num])
	{
		std::cout << "����" << std::endl;
	}
	else if (num > 10) {
		// num�̒l��10�ȏ�
		std::cout << "�Ԉ�������������Ă��܂�" << std::endl;
	}
	else {
		std::cout << "�s����" << std::endl;
	}
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	std::string ans0 = result0.to_string();
	hikaku(ans0, 0);

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	std::string ans1 = result1.to_string();
	hikaku(ans1, 1);

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	std::string ans2 = result2.to_string();
	hikaku(ans2, 2);

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	std::string ans3 = result3.to_string();
	hikaku(ans3, 3);

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	std::string ans4 = result4.to_string();
	hikaku(ans4, 4);

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	std::string ans5 = result5.to_string();
	hikaku(ans5, 5);

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	std::string ans6 = result6.to_string();
	hikaku(ans6, 6);

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	std::string ans7 = result7.to_string();
	hikaku(ans7, 7);

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	std::string ans8 = result8.to_string();
	hikaku(ans8, 8);

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
	std::string ans9 = result9.to_string();
	hikaku(ans9, 9);
}