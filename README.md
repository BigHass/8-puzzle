
<!-- ABOUT THE PROJECT -->
## About The Project
This project implements a customized 8-puzzle problem using the Breadth-First Search algorithm. In this problem, we will have two 4’s and two 5’s, and no 3 or 6. The program will prompt the user to enter the starting position as a string (i.e. 142045578, where 0 is used for space). Then, it will show the initial position and output the sequence of actions that will lead to the goal.


<!-- GETTING STARTED -->

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/bighass/8-puzzle.git
   ```
2. Navigate to the project directory
   ```sh
   cd 8-puzzle
   ```
3. Compile and run the program
   ```sh
    g++ -std=c++11 main.cpp -o main
    ./main
   ```


<!-- USAGE EXAMPLES -->
## Usage

Upon running the program, the user will be prompted to enter the starting position as a string. The program will then show the initial position and output the sequence of actions that will lead to the goal. Additionally, the program will print out the number of generated states and expanded states up to finding the goal state.

   ```sh
    Notic: Valid symbols are "8 7 5 5 4 4 2 1 0"
    having two 4's and two 5's in this problem and no 3 or 6.
    Enter initial state: 142045578
   ```
The program will then output the starting state of the puzzle, and then the sequence of actions that lead to the goal state, along with the number of generated states and expanded states.

  ```sh
  1 4 2
    4 5
  5 7 8

  1 4 2
  4   5
  5 7 8

  1   2
  4 4 5
  5 7 8

    1 2
  4 4 5
  5 7 8

------------Summary------------
Actions taken:  R U L
Elapsed time in seconds: 2 ms
Number of generated nodes: 28
Number of expanded nodes: 7
  ```
## Contributing

Contributions to the project are welcome. If you have any suggestions for improvements or would like to report a bug, please create a new issue on the project's GitHub repository.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

<!-- CONTACT -->
## Contact

Husni Abed - [@husni_abed](https://twitter.com/husni_abed) - husniabed99@gmail.com

Project Link: [Customized 8-puzzle](https://github.com/bighass/8-puzzle)





