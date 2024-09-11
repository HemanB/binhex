all: convert

convert: convert.o convert_student.o
	gcc -g -o $@ $^

%.o: %.c
	gcc -g -c $*.c

clean:
	rm -f convert.o convert_student.o
	rm -f convert
	rm -f tests/*_diff* tests/*_actual*
	rm -rf __pycache__/
