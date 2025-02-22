package view;

/**
 * MainMenu.java
 * Main menu and start point for the program
 * By Nicholas Verrochi
 */

public class MainMenu extends Menu {

    public MainMenu() {

    }

    @Override
    public void display() {
        System.out.println("Welcome to RPGMaker!");
        System.out.println("Copyright 2024 Nicholas Verrochi\n");

        printGameStatus();

        System.out.println("Please make a selection:");
        System.out.println("1. Load game file");
        System.out.println("2. Create new file");
        System.out.println("3. Export current file");
    }

    @Override
    public boolean makeChoice(int i) {
        return false;
    }

    public void printGameStatus() {

    }
}
