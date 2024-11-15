Movie Data Processor
Overview
This program allows the user to select and process CSV files that contain movie data. The program reads the data, organizes it by year, and generates files for each year that lists the movie titles. The program also allows the user to create directories, set file permissions, and manage files based on specific criteria.

Project Outcomes
This project will help you achieve the following learning outcomes:

Describe the API for different operations related to files and directories.
Describe the API for different operations related to directories.
Understand scopes and types of permissions associated with files and directories.
Features
The program provides the following functionalities:

Directory Handling:
Create directories with specified permissions (rwxr-x---).
Organize files within newly created directories.
File Processing:
Read and process CSV files containing movie data.
Parse the data and categorize movies by their release year.
Write the titles of movies for each year into separate text files.
File and Directory Permissions:
Set appropriate file permissions (rw-r-----) for the year-based text files.
User Interaction:
Present a menu for the user to select which file to process.
Allow the user to choose between processing the largest, smallest, or a user-specified CSV file.
Program Flow
Main Menu
When the program starts, the user will be presented with two choices:

Select file to process
Exit the program
If the user chooses option 1, they are presented with three further choices to select the file:

Pick the largest file with the movies_ prefix and .csv extension.
Pick the smallest file with the movies_ prefix and .csv extension.
Specify the name of the file manually.
File Selection
Largest File: The program will automatically select the largest file that matches the criteria.
Smallest File: The program will automatically select the smallest file that matches the criteria.
User-Specified File: The user enters the name of a file. If the file is found in the current directory, it will be processed; if not, the program will notify the user and allow them to try again.
After selecting the file, the program will display the message:
Now processing the chosen file named <filename>

Processing the File
The program reads the selected file, processes the data, and creates a new directory with the format:
<your_onid>.movies.<random_number>
The random_number is a random number between 0 and 99999, and the directory permissions are set to rwxr-x---.

Within the created directory, the program will:

Parse the CSV file to categorize movies by their release year.
Create one file for each year (named YYYY.txt, where YYYY is the year of release).
Write the movie titles for that year into the corresponding file.
File Permissions
The directory has permissions rwxr-x---, meaning the owner has full access, the group has read and execute access, and others have no access.
The movie year files (YYYY.txt) have permissions rw-r-----, meaning the owner has read and write access, while the group only has read access.
Format of the CSV File
The CSV file should follow this format:

First row contains column headers (e.g., Title, Year, Languages, Rating Value).
Subsequent rows contain the movie data. Each row corresponds to one movie with the following columns:
Title: String containing the movie title (e.g., Iron Man 2).
Year: Four-digit integer (e.g., 2010).
Languages: One or more strings enclosed in square brackets, separated by semicolons (e.g., [English;Portuguese;Spanish]).
Rating Value: A numeric value between 1 and 10 (e.g., 8.7 or 9).
Technologies used
C
Linux 
Moba xterm 
Steps to follow
Clone the repo
git clone https://github.com/yourusername/Multithreading.git
Compile the program
gcc -o smallsh thread.c

Run the program
./thread