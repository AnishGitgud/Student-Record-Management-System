target = stud_main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o

student: $(target)
	cc $(target) -o student

stud_main.o: stud_main.c
	@cc -c stud_main.c
	@echo "stud_main.o created"

stud_add.o: stud_add.c
	@cc -c stud_add.c
	@echo "stud_add.o created"

stud_del.o: stud_del.c
	@cc -c stud_del.c
	@echo "stud_del.o created"

stud_show.o: stud_show.c
	@cc -c stud_show.c
	@echo "stud_show.o created"

stud_mod.o: stud_mod.c
	@cc -c stud_mod.c
	@echo "stud_mod.o created"

stud_save.o: stud_save.c
	@cc -c stud_save.c
	@echo "stud_save.o created"

clean:
	rm -vr *.o
	@echo "removed object files"
