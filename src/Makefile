LINE = g++ -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors

main: dijkstras ladder

dijkstras: dijkstras.cpp dijkstras_main.cpp dijkstras.h
	$(LINE) dijkstras.cpp dijkstras_main.cpp -o dijkstras

ladder: ladder.cpp ladder_main.cpp ladder.h
	$(LINE) ladder.cpp ladder_main.cpp -o ladder

clean:
	/bin/rm -f dijkstras ladder
