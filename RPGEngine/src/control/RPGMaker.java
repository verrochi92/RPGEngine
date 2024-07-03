package control;

import view.MainMenu;
import view.Menu;

/**
 * RPGMaker.java
 * Starts up the program at main menu
 * By Nicholas Verrochi
 */

public class RPGMaker {
    public static void main(String[] args) {
        Menu mainMenu = new MainMenu();
        mainMenu.display();
    }
}
