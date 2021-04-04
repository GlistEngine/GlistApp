/*
 * main.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#include "gAppManager.h"
#include "gBaseWindow.h"
#include "gApp.h"


int main(int argc, char **argv) {

	gStartEngine(new gApp(), "GlistApp", gBaseWindow::WINDOWMODE_APP, 960, 540);

	return 0;
}



