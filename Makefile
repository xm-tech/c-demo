objdir = obj
objects = $(objdir)/main.o $(objdir)/utils.o

all : $(objdir) main

$(objdir) : 
	mkdir -p $@

main : $(objects)
	cc -o main $(objects)

$(objdir)/main.o : main.c
	cc -c main.c
	mv main.o $(objdir)

$(objdir)/utils.o : utils.c
	cc -c utils.c
	mv utils.o $(objdir)/

.PHONY : clean
clean :
	-rm main && rm -rf $(objdir)
