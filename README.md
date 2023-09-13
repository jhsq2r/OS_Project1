This project is designed to take in up to 3 values with the following format
-n [int] -s [int] -t [int]
Where
-n is the total number of child processes you want to run
-s is the number of child processes that can be alive at once
-t is the number of iterations each child will go through
-h will display a help menu
If one or more values are not provided via command line arguments,
        default values will be used: -n 5 -s 3 -t 3

Example usage: ./oss -n 5 -s 2 -t 3

Git Repos: github.com/jhsq2r/0S_Project1
