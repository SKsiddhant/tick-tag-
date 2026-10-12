# Tic-Tac-Toe (C++)

Two-player console Tic-Tac-Toe.

```bash
g++ -std=c++11 -Wall -Wextra -o tic_tac_toe tic_tac_toe.cpp
./tic_tac_toe
```

Players X and O take turns entering a cell number 1-9. Invalid or non-numeric input is rejected and re-asked; closing the input (Ctrl-D / Ctrl-Z) ends the game.

## Tests

`./test.sh` compiles the game and plays scripted games (win, draw, bad input, end of input).
