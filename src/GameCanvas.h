 /*
 * GameCanvas.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef GAMECANVAS_H_
#define GAMECANVAS_H_

#include "gBaseCanvas.h"
#include "gApp.h"
#include "gImage.h"

    /**
     * Provides the foundation for the user interface of a game.
     * The GameCanvas class is a base class for writing applications that need to handle  events and to issue graphics calls for drawing to the display.
     * Developers will likely make heavy use of the this class.
     *
     * The GameCanvas provides the developer with methods to handle game actions, key events, and pointer events (if supported by the device).
     * Methods are also provided to identify the device's capabilities and mapping of keys to game actions.
     *
     * The game canvas class contains the majority of the functions required by users to program the game.
     * The This class is responsible for the game's fundamental elements, such as drawing or executing the character and determining the number of enemies.
     * The For instance, if you wish to design or draw the game's menu, it is recommended that you create a new canvas class.
     *
     * This class includes a main loop.
     * This loop is often referred to as the main loop or the game loop since it is in control of an application's lifetime.
     * As long as this one iterates, the application will remain viable.
     * Now what do we do during an iteration of this loop? First we process the events from the window, then we update the game, and finally we render the results on the screen.
     * An iteration of the game loop is most often called a frame or a tick. You might have heard of the term frames per second (FPS).
     * This is a measurement of how many loop iterations the game can do during a second.
     * Sometimes, the concept of FPS only accounts for rendering times, but it is not unusual for it to encompass the input processing and logic updates as well.
     * Take care with this code, and be mindful of its efficiency.
     *
     * The way we work with the computer in C++ is very linear.
     * Everything is done in the set order that we give it, and the computer does nothing for us unless we explicitly tell it to.
     * A typical loop will check for input, execute the game logic, and then refresh the user interface.
     */
class GameCanvas : public gBaseCanvas {
public:
	GameCanvas(gApp *root);
	virtual ~GameCanvas();

    /**
     * Any instructions included in this function are achieved when the program begins for the first time.
     * Within the curly brackets is the code you wish to execute once when the application begins.
     * You configure this part by loading the appropriate objects and defining the variables.
     *
     * Conceptually, this might be any sort ofparat preion you're accustomed to in your everyday life.
     * If you're planning a trip abroad, be sure you have a passport.
     *
     * The setup() function ensures that any data that will be used later in the program is properly prepared.
     * Variables declared within setup() are  accessible within other functions.
     */
	void setup();

	/**
	 * This is where most of the game logic will go; including: movement, AI, and animation updates.
	 *
	 * For optimization, it is recommended to create the variables inside your functions in setup(),
	 * because this function runs 60 times per second and never stops.
	 * As a consequence, every new variable added inside the function will be regenerated 60 times per second, resulting in memory overload.
	 * Rather of creating a new variable in a for loop, for example, it is better to utilize one created in the setup () function.
	 *
	 * The fonction is your application's heartbeat.
	 * Any logic that relies on data calculated in the Update function will go here,
	 * for example;
	 * you could place collision logic here that checks for collisions once every entities position has been updated in the Update function.
	 *
	 * To make the most use of this fonction, it must be invoked from several functions.
	 * As a result, the code is much better, cleaner, and has easier access to bugs.
	 */
	void update();

	/**
	 * Responsible for drawing everything, including the games UI.
	 *
	 * It is not recommended to use this function for calculations.
	 * It Calculations can be performed using the setup() function. Due to the fact that some calculations are repeated 2-3 times.
	 * It is recommended that you only use draw commands.
	 *
	 * Coordinate planes must be well know.
	 * For example, the x direction increases to the right on the screen as is known. But the y known in mathematics increases upwards.
	 * It doesn't work like that here.
	 * Y increases downwards. You should pay attention to this. It can be confused most of the time.
	 *
	 * Draws the image from the specified file with its upper left corner at the specified point.
	 * In other words, if a object wants to be drawn in the middle of the screen, the upper left corner of the picture we want to draw comes to the middle of the screen,
	 * as a result, your object does not appear in the middle.
	 * That is, the middle of the object to be drawn should come to the point where you want to draw the object.
	 *
	 * It is recommended to open different functions in draw() for layers as this makes the code more accessible and minimizes complexity.
	 * As a result, the code is much better, cleaner, and has easier access to bugs.
	 */
	void draw();

	/**
	 * Accepts as an input the unicode representation of the pressed key.
	 *
	 * Fundamentally, computers just deal with numbers.They store letters and other characters by assigning a number for each one.
	 * With a few exceptions, this function  should include only code that changes a keystate. Failure to do so may result bugs.
	 *
	 * @param key The pressed key on the keyboard is represented in unicode.
	 */
	void charPressed(unsigned int key);

	/**
	 * When a key is pressed on the keyboard, this fonction is invoked.
	 *
	 * Fundamentally, computers just deal with numbers.They store letters and other characters by assigning a number for each one.
	 * With a few exceptions, this function  should include only code that changes a keystate. Failure to do so may result bugs.
	 *
	 * Each bit in the returned integer represents a specific key on the device.
	 * A key's bit will be 1 if the key is currently down or has been pressed at least once since the last time this function was called.
	 * The bit will be 0 if the key is currently up and has not been pressed at all since the last time this method was called. This latching behavior ensures that a
	 * rapid key press and release will always be caught by the game loop, regardless of how slowly the loop runs.Gets the states of the physical game keys.
	 *
	 * @param the keycode of which the key has been pressed.
	 */
	void keyPressed(int key);

	/**
	 * When a key is released on the keyboard, this fonction is invoked.
	 *
	 * Fundamentally, computers just deal with numbers.They store letters and other characters by assigning a number for each one.
	 * With a few exceptions, this function should include only code that changes a keystate. Failure to do so may result bugs.
	 *
	 * Each bit in the returned integer represents a specific key on the device.
	 * A key's bit will be 1 if the key is currently down or has been pressed at least once since the last time this method was called.
	 * The bit will be 0 if the key is currently up and has not been pressed at all since the last time this function was called. This latching behavior ensures that a
	 * rapid key press and release will always be caught by the game loop, regardless of how slowly the loop runs.Gets the states of the physical game keys.
	 *
	 * @param the keycode of which the key has been released.
	 */
	void keyReleased(int key);

	/**
	 * When mause is moved while a button is pressed, this fonction runs.
	 *
	 * @param int x The horizontal x coordinate for the mouse location.
	 * @param int y The horizontal y coordinate for the mouse location.
	 */
	void mouseMoved(int x, int y );

	/**
	 * When the mouse is moved while the mouse button is engaged, this function is invoked.
	 *
	 * @param int x The horizontal x coordinate for the mouse location.
	 * @param int y The horizontal y coordinate for the mouse location.
	 * @param int button An integer that indicates, which of the mouse buttons has changed its state.
	 */
	void mouseDragged(int x, int y, int button);

	/**
	 * When any mause button is pressed, the function runs.
	 *
	 * @param int x The horizontal x coordinate for the mouse location.
	 * @param int y The horizontal y coordinate for the mouse location.
	 * @param int button An integer that indicates, which of the mouse buttons has changed its state.
	 */
	void mousePressed(int x, int y, int button);

	/**
	 * Invoked whenever a mouse button is released.
	 *
	 * Triggered in response to a mouse button click, or more precisely, when the mouse button is released.
	 *
	 * @param int x The horizontal x coordinate for the mouse location.
	 * @param int y The horizontal y coordinate for the mouse location.
	 * @param int button an integer that indicates, which of the mouse buttons has changed its state.
	 */
	void mouseReleased(int x, int y, int button);

	/**
	 * When the mouse wheel is scrolled, this function is invoked.
	 *
	 * @param int x The horizontal x coordinate for the mouse location.
	 * @param int y The horizontal y coordinate for the mouse location.
	 */
	void mouseScrolled(int x, int y);

	/**
	 * The mouse cursor has been positioned in coordinate plane.
	 *
	 * When the mouse cursor reaches the current coordinate plane, this function is called once.
	 * It must enter again coordinate plane in order to be called again.
	 */
	void mouseEntered();

	/**
	 * The mouse cursor has departed from the coordinate plane.
	 *
	 * When the mouse cursor out of the current coordinate plane, this function is called once.
	 * It must out  coordinate plane in order to be called again.
	 */
	void mouseExited();

	/**
	 * Notification that the canvas has been made visible.
	 */
	void showNotify();

	/**
	 * Notification that the canvas is no longer visible.
	 */
	void hideNotify();

private:
	gApp* root;
	gImage logo;
};

#endif /* GAMECANVAS_H_ */
