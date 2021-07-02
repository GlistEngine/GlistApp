/*
 * main.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#include "gAppManager.h"
#include "gBaseWindow.h"
#include "gApp.h"

/**
 * Users use this function to start the application.
 * When the application starts, the engine calls this function.
 * Every application must have one main function.
 * No other function in the application can be called main.
 * Main cannot be called from within a application.
 * The address cannot be taken.
 * Cannot be overloaded.
 *
 * @param argc Shows the number of arguments with 0 or positive
 * value sent to the application when the application is run.
 * argv Shows the string of parameters entered by the users.
 *
 * @return Returns 0 because the function checks
 * if the application is running.
 */


int main(int argc, char **argv) {

	gStartEngine(new gApp(), "GlistApp", gBaseWindow::WINDOWMODE_APP, 1280, 720);

	return 0;
}




