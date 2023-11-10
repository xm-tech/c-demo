src = pthread_demo.c

build : 
	gcc -o demo $(src) -lpthread 

run :
	# make run name=maxm age=10
	./demo ${name} ${age}

.PHONY : clean
clean :
	rm -f ./demo
