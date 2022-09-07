objects = main.o add.o

main : $(objects)
	cc -o main $(objects)

clean :
	rm main $(objects)
