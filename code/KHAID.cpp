#include <iostream>
#include "clsBinkClien.h"
#include "clsMainScrren.h"
#include "clsLoginScreen.h"
#include "clsUtili.h"
#include "ClsCalculator.h"
using namespace std;
bool Odd(int Number);

int main() {
	
	
	while (true) {

		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

	}

	system("pause>0");
	return 0;


}
