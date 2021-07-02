/*
 * gApp.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef EXAMPLES_TESTEXAMPLE_GAPP_H_
#define EXAMPLES_TESTEXAMPLE_GAPP_H_

#include "gBaseApp.h"

/*
 * The easiest and most reliable method to declare and define global variables is to include an extern declaration of the variable in a header file.
 * The header file is included in the single source file that specifies the variable, as well as in all subsequent source files.
 * The files that include a reference to the variable. One source file per application (and only one source file).
 * The variable is defined. Similarly, just one header file (and only one header file) should include the declarations.
 *
 * The engine is started via Glistapp, however the engine is unable to start Glistapp. As a consequence, the Glistapp may use the engine's capabilities.
 * gApp.h is accessible from any class.
 * You can access the objects created in this class from other classes, which prevents them from interfering with one another.
 * For instance, when we switch from one of the classes we created (ie Menu Canvas, etc.) to another, the setup() function is deleted
 * because it is only called once and is called again when we access it from another class, which can cause bugs.
 *
 * root ->(created object in the gApp.h) This code can be used to access variables from other classes.
 * However, in order to access the object from gApp, the class must include gApp.h.
 * Critical! Only public objects can be accessed.
 */

class gApp : public gBaseApp {
public:
	gApp();
	~gApp();

	/*
	 * Any instructions included in this function are achieved when the program begins for the first time.
	 * Within the curly brackets is the code you wish to execute once when the application begins.
	 * You configure this part by loading the appropriate objects and defining the variables.
	 *
	 * Conceptually, this might be any sort of preparation you're accustomed to in your everyday life.
	 * If you're planning a trip abroad, be sure you have a passport.
	 *
	 * The setup() function ensures that any data that will be used later in the program is properly prepared.
	 * Variables declared within setup() are  accessible within other functions.
	 *
	 */
	void setup();

   /*
    *  This is where most of the game logic will go; including: movement, AI, and animation updates.
    *
	*  For optimization, it is recommended to create the variables inside your functions in setup(),
	*  because this function runs 60 times per second and never stops.
	*  As a consequence, every new variable added inside the function will be regenerated 60 times per second, resulting in memory overload.
	*  Rather of creating a new variable in a for loop, for example, it is better to utilize one created in the setup () function.
	*
	*  The fonction is your application's heartbeat.
	*  Any logic that relies on data calculated in the Update method will go here,
	*  for example;
	*  you could place collision logic here that checks for collisions once every entities position has been updated in the Update function.
	*
	*
	*  To make the most use of this fonction, it must be invoked from several functions.
	*  As a result, the code is much better, cleaner, and has easier access to bugs.
	*/
	void update();
};

#endif /* EXAMPLES_TESTEXAMPLE_GAPP_H_ */
