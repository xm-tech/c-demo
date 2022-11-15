target_build_dir = build
objects = $(target_build_dir)/main.o $(target_build_dir)/utils.o

all : $(target_build_dir) main

$(target_build_dir) : 
	mkdir -p $@ # 此处 $@表示目标文件

# main 是目标文件， $(objects)是依赖文件， cc -o main $(objects) 是生成目标的方法
main : $(objects)
	cc -o main $(objects)

$(target_build_dir)/main.o : main.c
	cc -c main.c
	mv main.o $(target_build_dir)

$(target_build_dir)/utils.o : utils.c
	cc -c utils.c
	mv utils.o $(target_build_dir)

run :
	./main

# clean 是1伪目标(不会生成文件)
.PHONY : clean
clean :
	-rm main && rm -rf $(target_build_dir) && rm -f a.out
