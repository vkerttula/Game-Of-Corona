gameoflife: main.o count_neighbors.o generate_year.o load_start_situation.o print_current.o
	gcc -lncurses main.o count_neighbors.o generate_year.o load_start_situation.o print_current.o -o game_of_corona
main.o: main.c header.h
	gcc -c -lncurses main.c
print_current.o: print_current.c header.h
	gcc -c -lncurses print_current.c
generate_year.o: generate_year.c header.h
	gcc -c -lncurses generate_year.c
load_start_situation.o: load_start_situation.c header.h
	gcc -c -lncurses load_start_situation.c
count_neighbors.o: count_neighbors.c header.h
	gcc -c -lncurses count_neighbors.c
clean:
		rm main.o print_current.o generate_year.o load_start_situation.o count_neighbors.o
