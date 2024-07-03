package view;

/**
 * MainMenu.java
 * Main menu and start point for the program
 * By Nicholas Verrochi
 */

public class MainMenu extends Menu {
    @Override
    public void display() {
        System.out.println("Welcome to the game!");
    }

    @Override
    public boolean makeChoice(int i) {
        return false;
    }
}
