# Animal Guessing Game - C-Programming Language 

This interactive console program was developed as part of the (CSE 121 Advanced Programming with C course) to apply the concepts being taught in this course. It challenges users to think of an animal while the program attempts to guess it by asking a series of yes/no questions. The project incorporates various advanced programming concepts and techniques to create an engaging and intelligent game.

  ## Tools And Concepts
The Animal Guessing Game project showcases proficiency in several key programming concepts and tools:


- **Pointers and Linked Lists:** The project utilizes pointers and linked lists to implement the binary search tree data structure. Pointers are used to create links between nodes, allowing for efficient traversal and manipulation of the tree during the game.

- **File I/O:** The game supports saving and loading game progress from files. File input/output operations are used to store and retrieve the game state, enabling users to resume a game session at a later time.

- **Recursion:** Recursion plays a significant role in the project's implementation. Recursive functions are used for tree traversal, updating the tree based on user responses, and dynamically expanding the tree when new animals or questions are added.

- **DFS (Depth-First Search):** Depth-first search algorithm is employed to navigate the binary search tree during the game. It allows the program to explore the tree structure in a systematic and efficient manner, eliminating incorrect options and making accurate guesses.

- **Binary Search Tree:** The main data structure used in the project is a binary search tree. It provides an organized and efficient way to store and search for animals and questions. The tree structure is dynamically built based on user responses and helps the program make informed guesses.
## Gameplay Flow

The gameplay of the Animal Guessing Game follows a logical flow, providing an engaging experience for users. Here's an overview of how the game progresses:

1. The program prompts the user to think of an animal without revealing their choice.
2. The program starts asking a series of yes/no questions to narrow down the possibilities.
3. Based on the user's responses, the program traverses the binary search tree, eliminating incorrect options at each step.
4. Once the program makes a guess, it asks the user to confirm if the guess is correct or not.
5. If the program guessed correctly, it celebrates its success. Otherwise, it prompts the user to provide the correct animal and a new distinguishing question.
6. The project utilizes recursion to dynamically update the binary search tree based on user feedback and to continue the guessing process efficiently.
