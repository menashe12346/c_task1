cc = gcc
FLAG = -Wall -g

all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec

basicClassification.o: basicClassification.c NumClass.h
	$(cc) $(FLAG) -c $<

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(cc) $(FLAG) -c $<

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(cc) $(FLAG) -c $<

# STATIC LIB
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar rcu $@ $^

loops: libclassloops.a

libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar rcu $@ $^

recursives: libclassrec.a

# DYNAMIC LIB
libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(cc) -shared -o $@ $^

loopd: libclassloops.so

libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(cc) -shared -o $@ $^

recursived: libclassrec.so

# MAIN
main.o: main.c NumClass.h

mains: main.o libclassrec.a
	$(cc) $(FLAG) -o $@ $< libclassrec.a

maindloop: main.o libclassloops.so
	$(cc) $(FLAG) -o $@ $< ./libclassloops.so

maindrec: main.o libclassrec.so
	$(cc) $(FLAG) -o $@ $< ./libclassrec.so

clean:
	rm -f *.so *.o *.a mains maindloop maindrec
