CC= gcc #compiler

TARGET = reversi.out #target file name

all:
	$(CC) -Wall -g -o $(TARGET) endgame.c auxiliares.c board.c free_allocated_memory.c init_output_file.c player_and_AI.c read_args.c undo.c main.c

clean:
	rm $(TARGET)
