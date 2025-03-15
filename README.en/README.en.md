# Movie Browser Application "Film-Library"

This application is a graphical interface for viewing movies, with filtering and search capabilities, built using the `graphics.h` library. Users can browse a collection of movies, view their details, and apply filters to narrow down the search according to their preferences.

## Description

The provided code creates an application where users can view movies in a graphical interface. Each movie contains details such as:
- Title
- Directors
- Cast
- Genre
- Year of release
- Duration
- Summary

The application includes filters for:
- Movie genre
- Year of release

Movies are organized in an interactive interface, where users can select filters and view corresponding movies that meet their criteria.

## Files and Functions

The application consists of the following main parts:

1. **Library.h / Library.cpp**:
   - Contains the data structure that represents the movie library, including movies, filters, and various functions for initialization, searching, and applying filters.
   - Within this file, the structure of movies is defined, the library is created, movies are added, and filtering functionality is implemented based on genre or year.

2. **Widgets.h / Widgets.cpp**:
   - These files define the classes for various "widgets" (buttons, checkboxes, filters) responsible for displaying and interacting with the user.
   - Users can interact with the filters to narrow down the movies displayed on the screen.

3. **Main.cpp**:
   - The main code of the application that handles window creation, continuous updating, and redrawing of the graphical interface.
   - In the `main()` function, the application window is created, and updates and drawing are handled through the graphical environment.

4. **Browser.h / Browser.cpp**:
   - Defines the `Browser` class, which manages the main movie browser.
   - Includes methods for updating and displaying movies, as well as interacting with widgets and filters.

5. **Graphics Library**:
   - The `graphics.h` library is used to create the graphical environment and interact with the user.
   - The graphics canvas allows drawing widgets, movies, and scaling for better fitting to the screen.

## Use of SGG

The application uses the **[SGG](https://github.com/cgaueb/sgg)** (Simple Game Graphics Library), which provides tools and methods for creating graphical interfaces and interacting with the user. In this particular case, SGG helps with:
- Window creation and graphics canvas management.
- Drawing interactive elements and applying scaling to fit the window.
- Handling interactions with widgets and filters.

The SGG library offers:
- Window and canvas creation.
- Management of updates and drawing operations.
- Interaction with widgets and filters.

## Features

- **Movie Browsing**: Users can view all available movies.
- **Filters**: Users can filter movies by genre or year of release.
- **Interaction**: Through interactive buttons and checkboxes, users can select the filters they want.
- **Graphical Presentation**: The application uses a graphical interface to display the movies based on selected filters.

## Prerequisites

To run the application, you need to have the `graphics.h` library and **SGG** installed and a compatible environment for running C++ applications. The application has been developed in C++ and requires a compatible environment for graphic execution.

## Installation

1. Download the necessary project files (or clone the repository).
2. Install the `graphics.h` library and **SGG** in your development environment.
3. Compile the code using a tool like `g++` or through your preferred IDE.
4. Run the application and start interacting with the movies and filters!

## Design and Operation

- The application uses a simple GUI that allows the user to browse through movies using buttons and checkboxes.
- Movies are organized in three rows in the graphical window.
- Filters for genre and year allow the user to narrow down the movies shown.
