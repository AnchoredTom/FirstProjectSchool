# FirstProjectSchool
Summarize the project and what problem it was solving.
This project was about creating a C++ program that simulates both a 12 hour clock and a 24 hour clock at the same time. The program asks the user to enter an initial time and then displays it in both formats side by side. It also allows the user to interact with the clock by adding hours, minutes, or seconds through a menu. The main problem the program solves is converting and maintaining time correctly while updating both clock formats as changes are made.

What did you do particularly well?
I did a good job breaking the program into smaller functions like getting the initial time and displaying the clocks. This made the program easier to follow and reduced clutter in the main function. I also handled user input validation for hours, minutes, and seconds, which helped prevent invalid values from breaking the program. The clock display formatting with leading zeros was another area I handled carefully.

Where could you enhance your code and how this would help?
One area I could improve is reducing repeated logic when converting the time from 24 hour format to 12 hour format. That conversion code appears more than once and could be moved into its own function. This would make the program easier to maintain and reduce the chance of errors. I could also simplify the use of multiple boolean flags for leading zeros to make the code more efficient and readable.

Which parts of the code were most challenging and how you overcame this?
The most challenging part was handling the time rollover when seconds or minutes reached their maximum values. Making sure that seconds correctly rolled into minutes and minutes into hours took careful testing. I overcame this by walking through the logic step by step and testing edge cases like midnight and hour changes. Re running the program and checking the output helped me catch and fix mistakes.

What skills from this project are transferable?
This project helped me improve my understanding of functions, conditionals, loops, and input validation. I also learned how to manage program state as values change over time. These skills will transfer well to other C++ projects and future coursework where programs need to respond to user input and update values correctly.

How you made the program maintainable, readable, and adaptable.
I used clear function names and variable names so it is easy to understand what each part of the program does. I also kept the formatting consistent and separated logic into different sections. Because the program is organized into functions, it would be easier to update or expand later, such as adding new menu options or changing how the clock is displayed.
