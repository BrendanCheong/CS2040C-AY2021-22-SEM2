// has one crucial line bug, submitting this verbatim (what for?) will be not be AC

#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("in.txt", "r", stdin);
  vector<string> sounds = {"clank","bong","click","tap","poing","clonk","clack","ping","tip","cloing","tic","cling","bing","pong","clang","pang","clong","tac","boing","boink","cloink","rattle","clock","toc","clink","tuc"};
  int N; cin >> N;
  bool caps_on = false, shift_on = false;
  string text = "";
  while (N--) {
    string sound; cin >> sound;
    if (sound == "whack") // spacebar
      text += " ";
    else if (sound == "bump") // capslock
      caps_on = !caps_on;
    else if (sound == "pop") { // backspace
      // something removed here
        text.pop_back(); // pop the last char of as tring
    }
    else if (sound == "dink") // shift hold down
      shift_on = true;
    else if (sound == "thumb") // shift release
      shift_on = false;
    else {
      bool use_CAPITAL = (caps_on and not shift_on) or (not caps_on and shift_on);
      int i = find(sounds.begin(), sounds.end(), sound) - sounds.begin(); // will always find the sound
      text += (char)((use_CAPITAL ? 'A' : 'a')+i);
    }
  }
  cout << text << '\n';

  return 0;
}



// for those who also know Python
// # sound to char mapper (tedious, but helped by sample input 1)
// stoc = ["clank","bong","click","tap","poing","clonk","clack","ping","tip","cloing","tic","cling","bing","pong","clang","pang","clong","tac","boing","boink","cloink","rattle","clock","toc","clink","tuc"]
// N = int(input())
// ans = []
// capslock, shift = False, False
// for _ in range(N):
//     sound = input()
//     if sound == 'whack': # spacebar
//         ans.append(' ')
//     elif sound == 'bump': # capslock
//         capslock = not capslock
//     elif sound == 'pop': # delete
//         # something removed here
//             ans.pop()
//     elif sound == 'dink': # shift hold down
//         shift = True
//     elif sound == 'thumb': # shift release
//         shift = False
//     else:
//         uppercase = (not capslock and shift) or (capslock and not shift)
//         if uppercase:
//             ans.append(chr(65+stoc.index(sound))) # 65 = 'A'
//         else:
//             ans.append(chr(97+stoc.index(sound))) # 97 = 'a'
// print("".join(ans))