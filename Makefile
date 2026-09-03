target = main.o add.o del.o show.o mod.o file.o

student: $(target)
	cc $(target) -o student

main.o: main.c
	@cc -c main.c
	@echo "main.o created"

add.o: add.c
	@cc -c add.c
	@echo "add.o created"

del.o: del.c
	@cc -c del.c
	@echo "del.o created"

show.o: show.c
	@cc -c show.c
	@echo "show.o created"

mod.o: mod.c
	@cc -c mod.c
	@echo "mod.o created"

file.o: file.c
	@cc -c file.c
	@echo "file.o created"

clean:
	rm -vr *.o
	@echo "removed object files"
