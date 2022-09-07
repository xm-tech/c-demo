objdir = obj
objects = $(objdir)/main.o $(objdir)/utils.o

$(objdir) : 
	mkdir -p $@

all : $(objdir) main

main : $(objects)
	cc -o main $(objects)
$(objdir)/utils.o : utils.c
	cc -c utils.c
	mv utils.o $(objdir)/
$(objdir)/main.o : main.c
	cc -c main.c
	mv main.o $(objdir)

.PHONY : clean
clean :
	-rm main && rm -rf $(objdir)
