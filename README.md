# Othello

A playable Othello (Reversi) game written in C with a graphical interface built
on MiniLibX, complete with piece textures and sound effects. Two players take
turns on an 8x8 board, and the game handles the full rules: only legal moves are
allowed, captured lines are flipped in every direction, turns are skipped when a
player has no move, and the winner is decided by piece count at the end.

## Controls

- **Arrow keys** move the cursor around the board.
- **Enter** places a piece on the highlighted square (only if the move is legal).
- **Esc** quits.

## Requirements

Built and tested on **macOS**. It uses MiniLibX (the OpenGL/AppKit version, bundled
in `minilibx_opengl_20191021/`), so it links against the macOS `OpenGL` and
`AppKit` frameworks. A C compiler and `make` are all you need.

MiniLibX and a small `libft` are vendored in the repo and built automatically, so
there are no external dependencies to install.

## Build and run

```sh
make
./Othello
```

`make clean` removes the object files, `make fclean` also removes the binary and
the built libraries, and `make re` rebuilds from scratch.

## Rules recap

Black moves first. A move is legal only if it sandwiches one or more of the
opponent's pieces between the piece being placed and another of your own, in any
of the eight directions. All sandwiched pieces flip to your colour. If you have no
legal move your turn is skipped, and when neither player can move the game ends
and the majority colour wins.

## License

The game code (`src/`, `includes/`) is MIT, see [LICENSE](LICENSE). The bundled
MiniLibX in `minilibx_opengl_20191021/` is third-party and keeps its own license.
