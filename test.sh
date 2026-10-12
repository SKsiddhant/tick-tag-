#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
g++ -std=c++11 -Wall -Wextra -Werror -o /tmp/ttt_test tic_tac_toe.cpp
run() { printf '%s' "$1" | timeout 5 /tmp/ttt_test; }
fail() { echo "FAIL: $1"; exit 1; }

run $'1\n4\n2\n5\n3\n'            | grep -q "Player X wins"    || fail "row win"
run $'1\n2\n4\n3\n7\n'            | grep -q "Player X wins"    || fail "column win"
run $'1\n2\n3\n5\n4\n6\n8\n7\n9\n' | grep -q "draw\|wins"       || fail "full game ends"
run $'1\n2\n3\n5\n4\n6\n8\n7\n9\n' | grep -q "It's a draw"      || fail "draw"
run $'abc\n1\n4\n2\n5\n3\n'       | grep -q "Player X wins"    || fail "recovers from non-numeric input"
run $'0\n10\n1\n1\n'              | grep -q "Cell already occupied" || fail "occupied cell"
run $'1\n'                        | grep -q "game aborted"     || fail "EOF ends game"
echo "all tests passed"
