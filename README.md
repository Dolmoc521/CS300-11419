# CS300-11419
#SNHU CS-300 Course Reflection

#1. Problem Statement
The core problem addressed in the projects for this course was to develop a program that efficiently manages and queries course data. The task was to create pseudo code and then implement a simple application that could search for courses and print relevant information, such as course titles and prerequisites. The goal was to build a system that helps users interact with a list of courses, loaded from a file, and retrieve details as needed.

#2. Approach to the Problem
To tackle the problem, I designed a solution that involved several key steps:
Data Loading: I created functionality to read course data from a file. This included parsing the data and handling various edge cases, such as missing or incorrectly formatted entries.
Data Storage: The data was stored in an `unordered_map` to ensure that each course could be uniquely identified by its course number. This data structure was chosen for its efficient average-time complexity for insertions and lookups, which is crucial for handling potentially large datasets.
User Interaction: I implemented a user-friendly menu system to allow users to load data, view courses in alphabetical order, and retrieve specific course information by entering course numbers.
Understanding data structures like `unordered_map` was crucial. They offer efficient ways to manage and query data, which significantly impacts the performance and usability of the application. For instance, using a map allowed for quick lookups of course information, which is essential for real-time user interactions.

#3. Overcoming Roadblocks
During the development of Project 2, I encountered several challenges, primarily related to handling and processing the course data. The most significant roadblock was ensuring that the code correctly loaded and validated the data from the file. Initially, the complexity of parsing and managing prerequisites caused difficulties. However, breaking down the problem into smaller, manageable tasks—such as focusing first on data parsing and then on validation—proved to be an effective strategy. This modular approach made the problem more tractable and helped in systematically addressing each issue.

#4. Expanded Approach to Designing Software
Working on this project has broadened my approach to software design and problem-solving. I gained a deeper appreciation for how well-chosen data structures can simplify complex problems. This project underscored the importance of designing systems that are both efficient and easy to use. It reinforced the idea that thoughtful design and a clear understanding of data structures are vital for creating effective solutions.

#5. Evolution of Code Quality
The project has significantly influenced the way I write code. I learned the importance of maintaining clean and readable code, which is essential for long-term maintainability. Implementing clear comments and using descriptive variable names has become a standard practice in my coding process. This not only improves the readability of the code but also makes it easier for others (and myself) to understand and adapt the code in the future.
In summary, this project has been instrumental in enhancing my programming skills and understanding of software design principles. It has taught me valuable lessons about data structures, problem-solving strategies, and the importance of writing maintainable and adaptable code.
