target_build_dir = build
objects = $(target_build_dir)/main.o $(target_build_dir)/utils.o

all : $(target_build_dir) main

$(target_build_dir) : 
	mkdir -p $@

main : $(objects)
	cc -o main $(objects)

$(target_build_dir)/main.o : main.c
	cc -c main.c
	mv main.o $(target_build_dir)

$(target_build_dir)/utils.o : utils.c
	cc -c utils.c
	mv utils.o $(target_build_dir)

.PHONY : clean
clean :
	-rm main && rm -rf $(target_build_dir)
