#include "MovieHashTable.h"
#include "ActorHashTable.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function prototypes for menu options
void adminMenu(MovieHashTable& movieTable, ActorHashTable& actorTable);
void userMenu(MovieHashTable& movieTable, ActorHashTable& actorTable);
void addNewActor(ActorHashTable& actorTable);
void addNewMovie(MovieHashTable& movieTable);
void addActorToMovie(MovieHashTable& movieTable);
void updateActorDetails(ActorHashTable& actorTable);
void updateMovieDetails(MovieHashTable& movieTable);
void displayActorsByAge(ActorHashTable& actorTable);
void displayRecentMovies(MovieHashTable& movieTable);
void displayMoviesByActor(ActorHashTable& actorTable);
void displayActorsByMovie(MovieHashTable& movieTable);
void displayActorConnections(ActorHashTable& actorTable);

int main() {
    MovieHashTable movieTable;
    ActorHashTable actorTable;

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Administrator Menu\n";
        cout << "2. User Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            adminMenu(movieTable, actorTable);
            break;
        case 2:
            userMenu(movieTable, actorTable);
            break;
        case 3:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void adminMenu(MovieHashTable& movieTable, ActorHashTable& actorTable) {
    while (true) {
        cout << "\nAdministrator Menu:\n";
        cout << "1. Add new actor\n";
        cout << "2. Add new movie\n";
        cout << "3. Add an actor to a movie\n";
        cout << "4. Update actor details\n";
        cout << "5. Update movie details\n";
        cout << "6. Return to main menu\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addNewActor(actorTable);
            break;
        case 2:
            addNewMovie(movieTable);
            break;
        case 3:
            addActorToMovie(movieTable);
            break;
        case 4:
            updateActorDetails(actorTable);
            break;
        case 5:
            updateMovieDetails(movieTable);
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void userMenu(MovieHashTable& movieTable, ActorHashTable& actorTable) {
    while (true) {
        cout << "\nUser Menu:\n";
        cout << "1. Display actors by age range\n";
        cout << "2. Display movies made in the past 3 years\n";
        cout << "3. Display movies an actor starred in\n";
        cout << "4. Display actors in a movie\n";
        cout << "5. Display actor connections\n";
        cout << "6. Return to main menu\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            displayActorsByAge(actorTable);
            break;
        case 2:
            displayRecentMovies(movieTable);
            break;
        case 3:
            displayMoviesByActor(actorTable);
            break;
        case 4:
            displayActorsByMovie(movieTable);
            break;
        case 5:
            displayActorConnections(actorTable);
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void addNewActor(ActorHashTable& actorTable) {
    string name, yearOfBirth, rating;
    cout << "Enter actor's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "Enter year of birth: ";
    cin >> yearOfBirth;
    cout << "Enter actor's rating: ";
    cin >> rating;

    actorTable.insertActor(name, yearOfBirth, rating, "", "", "", 0.0);
    cout << "Actor added successfully.\n";
}

void addNewMovie(MovieHashTable& movieTable) {
    string title, plot;
    int year;
    double rating;

    cout << "Enter movie title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Enter movie plot: ";
    getline(cin, plot);
    cout << "Enter year of release: ";
    cin >> year;
    cout << "Enter movie rating: ";
    cin >> rating;

    movieTable.insertMovie(title, plot, year, rating, {});
    cout << "Movie added successfully.\n";
}

void addActorToMovie(MovieHashTable& movieTable) {
    string movieTitle, actorName, yearOfBirth, rating;

    cout << "Enter movie title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, movieTitle);
    cout << "Enter actor's name: ";
    getline(cin, actorName);
    cout << "Enter actor's year of birth: ";
    cin >> yearOfBirth;
    cout << "Enter actor's rating: ";
    cin >> rating;

    movieTable.addActorToMovie(0, movieTitle, actorName, yearOfBirth, rating);
    cout << "Actor added to movie successfully.\n";
}

void updateActorDetails(ActorHashTable& actorTable) {
    cout << "Feature not yet implemented.\n";
}

void updateMovieDetails(MovieHashTable& movieTable) {
    cout << "Feature not yet implemented.\n";
}

void displayActorsByAge(ActorHashTable& actorTable) {
    int x, y;
    cout << "Enter minimum age: ";
    cin >> x;
    cout << "Enter maximum age: ";
    cin >> y;

    actorTable.displayActorsByYearRange(to_string(2025 - y), to_string(2025 - x));
}

void displayRecentMovies(MovieHashTable& movieTable) {
    movieTable.displayMoviesByYear(3);
}

void displayMoviesByActor(ActorHashTable& actorTable) {
    int age;
    cout << "Enter the age of the actor: ";
    cin >> age;

    // Calculate year of birth based on the age
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);
    int currentYear = 1900 + localTime.tm_year;
    string yearOfBirth = to_string(currentYear - age);

    // Search for actors with the specified year of birth
    bool foundActors = false;
    vector<string> actorNames;

    cout << "Actors with age " << age << ":\n";
    for (int i = 0; i < 101; ++i) { // Assuming 101 buckets in the hash table
        ActorAVLTree* actorTree = actorTable.getBucket(i); // Method to get the tree for each bucket
        if (!actorTree) continue;

        // Search for all actors in the tree with the specified year of birth
        actorTree->findActorsByYearOfBirth(yearOfBirth, actorNames);
    }

    // Display the actors found
    if (actorNames.empty()) {
        cout << "No actors found with the specified age.\n";
        return;
    }

    for (size_t i = 0; i < actorNames.size(); ++i) {
        cout << i + 1 << ". " << actorNames[i] << "\n";
    }

    // Let the user choose an actor
    int choice;
    cout << "Select an actor by entering their number: ";
    cin >> choice;

    if (choice < 1 || choice > actorNames.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    string selectedActor = actorNames[choice - 1];
    cout << "Movies starring " << selectedActor << ":\n";

    // Search for the selected actor and display their movies
    for (int i = 0; i < 101; ++i) {
        ActorAVLTree* actorTree = actorTable.getBucket(i);
        if (!actorTree) continue;

        ActorAVLNode* actorNode = actorTree->searchActor(selectedActor);
        if (actorNode) {
            actorNode->movies->displayMovies();
            return;
        }
    }

    cout << "Movies for the selected actor could not be found.\n";
}

void displayActorsByMovie(MovieHashTable& movieTable) {
    string movieTitle;

    cout << "Enter movie title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, movieTitle);

    movieTable.displayActorsInMovie(0, movieTitle);
}

void displayActorConnections(ActorHashTable& actorTable) {
    cout << "Feature not yet implemented.\n";
}
