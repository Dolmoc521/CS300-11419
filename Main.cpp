#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

// Define the Course class
class Course {
public:
    std::string courseNumber;
    std::string title;
    std::vector<std::string> prerequisites;

    Course(const std::string& number, const std::string& title, const std::vector<std::string>& prereqs)
        : courseNumber(number), title(title), prerequisites(prereqs) {}
};

// Define the BST Node class
class BSTNode {
public:
    Course course;
    std::shared_ptr<BSTNode> left;
    std::shared_ptr<BSTNode> right;

    BSTNode(const Course& c) : course(c), left(nullptr), right(nullptr) {}
};

// Define the BST class
class BST {
public:
    std::shared_ptr<BSTNode> root;

    BST() : root(nullptr) {}

    void insert(const Course& c) {
        root = insert(root, c);
    }

private:
    std::shared_ptr<BSTNode> insert(std::shared_ptr<BSTNode> node, const Course& c) {
        if (node == nullptr) {
            return std::make_shared<BSTNode>(c);
        }
        if (c.courseNumber < node->course.courseNumber) {
            node->left = insert(node->left, c);
        }
        else {
            node->right = insert(node->right, c);
        }
        return node;
    }
};

// Function to load courses from a file into the BST
void loadCourses(const std::string& filePath, BST& bst) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: File cannot be opened." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2) {
            std::cerr << "Error: Line format is incorrect, missing parameters." << std::endl;
            continue;
        }

        std::string courseNumber = tokens[0];
        std::string courseTitle = tokens[1];
        std::vector<std::string> prerequisites(tokens.begin() + 2, tokens.end());

        if (courseNumber.empty() || courseTitle.empty()) {
            std::cerr << "Error: Course number or title is missing." << std::endl;
            continue;
        }

        Course course(courseNumber, courseTitle, prerequisites);
        bst.insert(course);
    }
    file.close();
}

// Function to print courses in alphabetical order
void printCoursesInAlphabeticalOrder(const std::shared_ptr<BSTNode>& node) {
    if (node != nullptr) {
        printCoursesInAlphabeticalOrder(node->left);
        std::cout << "Course Number: " << node->course.courseNumber << std::endl;
        std::cout << "Title: " << node->course.title << std::endl;
        std::cout << "Prerequisites: ";
        for (const auto& prereq : node->course.prerequisites) {
            std::cout << prereq << " ";
        }
        std::cout << std::endl;
        printCoursesInAlphabeticalOrder(node->right);
    }
}

// Function to print information of a specific course
void printCourseInfo(const std::shared_ptr<BSTNode>& node, const std::string& courseNumber) {
    if (node != nullptr) {
        if (node->course.courseNumber == courseNumber) {
            std::cout << "Course Number: " << node->course.courseNumber << std::endl;
            std::cout << "Title: " << node->course.title << std::endl;
            std::cout << "Prerequisites: ";
            for (const auto& prereq : node->course.prerequisites) {
                std::cout << prereq << " ";
            }
            std::cout << std::endl;
            return;
        }
        if (courseNumber < node->course.courseNumber) {
            printCourseInfo(node->left, courseNumber);
        }
        else {
            printCourseInfo(node->right, courseNumber);
        }
    }
    else {
        std::cout << "Course not found." << std::endl;
    }
}

// Main function with menu
int main() {
    BST bst;
    bool dataLoaded = false;
    int option;
    std::string filePath;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Load the file data into the data structure" << std::endl;
        std::cout << "2. Print an alphanumerically ordered list of all the courses" << std::endl;
        std::cout << "3. Print the course title and the prerequisites for any individual course" << std::endl;
        std::cout << "9. Exit the program" << std::endl;
        std::cin >> option;
        std::cin.ignore(); // To ignore newline character left in buffer

        switch (option) {
        case 1:
            std::cout << "Enter the file name: ";
            std::getline(std::cin, filePath);
            loadCourses(filePath, bst);
            dataLoaded = true;
            std::cout << "Data loaded successfully." << std::endl;
            break;
        case 2:
            if (!dataLoaded) {
                std::cerr << "Error: Data not loaded. Please load the file data first." << std::endl;
            }
            else {
                printCoursesInAlphabeticalOrder(bst.root);
            }
            break;
        case 3:
            if (!dataLoaded) {
                std::cerr << "Error: Data not loaded. Please load the file data first." << std::endl;
            }
            else {
                std::cout << "Enter course number to search: ";
                std::string searchCourseNumber;
                std::getline(std::cin, searchCourseNumber);
                printCourseInfo(bst.root, searchCourseNumber);
            }
            break;
        case 9:
            std::cout << "Exiting the program." << std::endl;
            return 0;
        default:
            std::cerr << "Invalid option. Please choose again." << std::endl;
            break;
        }
    }
}
