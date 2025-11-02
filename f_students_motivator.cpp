#include <bits/stdc++.h>
using namespace std;

// change as you like
const char *mpv_command = "mpv --volume=150 f_students_video.mp4";
const char *figlet_command =
    "kitty bash -c \"for i in {1..5}; do figlet ayo lockin woi | lolcat; &";

// launch function
int launchh() {
  system(mpv_command);
  system(figlet_command);
  return 0;
}

// main function
int main() {
  launchh();
  int last_triggered_minute = -1; // variable to record the last minute the
                                  // alarm went off, -1 means never.
  while (true) { // start an infinite loop to keep checking the time.
    auto now = chrono::system_clock::now(); // get the current system time.
    time_t now_c = chrono::system_clock::to_time_t(
        now); // convert 'chrono' time to the simpler 'time_t' format.
    tm *local_time =
        localtime(&now_c); // convert 'time_t' to a 'tm' struct containing time
                           // details (hour, minute, etc).
    int current_minute = local_time->tm_min; // get the current minute value.
    if (current_minute == 0 ||
        current_minute == 30) { // check if the current minute is 0 or 30.
      if (current_minute != last_triggered_minute) { // check if the alarm has
                                                     // not sounded this minute.
        last_triggered_minute =
            current_minute; // mark that the alarm has sounded this minute.
        system(mpv_command);
        system(figlet_command);
      }
    } else {
      last_triggered_minute = -1;
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
  return 0;
}