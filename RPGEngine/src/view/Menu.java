package view;

/**
 * Menu.java
 * Interface for menus
 * By Nicholas Verrochi
 */

public abstract class Menu {

    public abstract void display();
    // prints the menu and waits for response

    public abstract boolean makeChoice(int i);
    // makes a numbered menu choice, returns false if out of bounds

}
