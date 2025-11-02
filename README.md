# F Students Motivator

https://github.com/user-attachments/assets/bfaa297e-4b6a-4857-82aa-5063cfbd14ac

> Are you an f student? Then this program is for you!

This is a simple C++ program designed to act as a motivator for F students. It triggers specific shell commands (a video and a terminal message) at set intervals: once at startup and again every 30 minutes (at the top of the hour and at the half-hour mark).

## Features

* Immediate Motivation: Runs a set of commands as soon as the program starts.
* Scheduled Motivation: After the initial run, it continuously checks the system time and re-triggers the commands whenever the minute is :00 or :30.
* No-Repeat Guard: Includes logic to ensure the commands are only triggered once per target minute (e.g., it won't run repeatedly from 12:00:00 to 12:00:59).

## How It Works

1. Startup: The launchh() function is called, immediately executing the mpv_command and figlet_command.
2. Main Loop: The program enters an infinite while(true) loop.
3. Time Check: Inside the loop, it gets the current system time and checks the current minute.
4. Trigger: If the current minute is 0 or 30, the program checks if it has already triggered for that specific minute.
5. Execution: If it hasn't triggered yet, it executes both commands and updates the last_triggered_minute variable to prevent re-triggering in the same minute.
6. Sleep: The loop sleeps for 1 second between checks to avoid consuming excessive CPU.

## Dependencies

To compile and run this program as intended, you will need:
* A C++ compiler (like g++)
* mpv (media player)
* figlet (ASCII text generator)
* lolcat (rainbow text colorizer)
* kitty (terminal emulator)
* The video file f_students_video.mp4 in the same directory.

## How to Use

1. Customization

    You can change the commands that get executed by modifying these constants at the top of the main.cpp file:
    ```
    const char *mpv_command = "mpv --volume=150 f_students_video.mp4";
    const char *figlet_command =
        "kitty bash -c \"for i in {1..5}; do figlet ayo lockin woi | lolcat; &";
    ```

2. Compilation

    Compile the program using a C++ compiler. With g++, you can use:
    ```
    g++ main.cpp -o f_students_motivator -std=c++17 -pthread
    ```

    (Note: -std=c++17 is used for modern C++ features, and -pthread is good practice, though not strictly required by this specific code's this_thread usage.)

3. Running

    Execute the compiled binary from your terminal:
    ```
    ./f_students_motivator
    ```

    The program will run in the foreground, and you will see the mpv window and kitty terminal appear at startup, and then again every 30 minutes.
