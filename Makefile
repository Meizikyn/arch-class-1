.PHONY: build clean run

build:
	gcc -o nick_prog nick.c

run:
	@./nick_prog

clean:
	rm nick_prog

